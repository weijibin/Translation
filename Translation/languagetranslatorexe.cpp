#include "languagetranslatorexe.h"
#include "ui_languagetranslatorexe.h"
#include <QApplication>
#include <QFile>
#include <QDomDocument>
#include <QTextStream>
#include <QDebug>
#include <QString>
#include <atlbase.h>
#include <atlstr.h>
#include <QProcess>
#include <QMessageBox>
#include "IniFile.h"

#import "./ImportFile/MSO.DLL" rename("RGB","MSORGB"),rename("DocumentProperties","MSODocumentProperties"),rename_namespace("Office")
using namespace Office;
#import "./ImportFile/VBE6EXT.olb" rename_namespace("VBE6")
using namespace VBE6;
//EXCEL
#import "./ImportFile/EXCEL9.OLB" rename("IFont","MSExcelIFont"),rename("IPicture","MSExcelIPicture"),rename("ReplaceText","ExcelReplaceText"),rename("CopyFile","ExcelCopyFile"),rename("RGB","ExcelRGB"),rename("DialogBox","DialogBoxEx"),rename_namespace("MSExcel")
CComPtr<MSExcel::_Application>      m_ExcelApp;

void findAndFillData( QDomDocument& doc, QDomElement& elementTS, QString strID, QString strTranslation ) {
    QDomNodeList listSource = elementTS.elementsByTagName( "source" );
    for( int i = 0 ; i < listSource.size() ; i ++ ) {
        QDomNode node = listSource.at( i ).lastChild();
        if( node.toText().data() == strID ) {
            QDomNode parent = node.parentNode().parentNode();
            QDomNodeList list = parent.toElement().elementsByTagName( "translation" );
            if( list.size() == 1 )
                parent.removeChild( list.at( 0 ) );
            QDomElement translation = doc.createElement( "translation" );
            QDomText text = doc.createTextNode( strTranslation );
            translation.appendChild( text );
            parent.appendChild( translation );
        }
    }
}

bool connectExcel() {
    if( m_ExcelApp )
        return true;
    HRESULT hRet = m_ExcelApp.CoCreateInstance( __uuidof(MSExcel::Application), NULL, CLSCTX_SERVER );
    if( FAILED( hRet ) || NULL == m_ExcelApp ) {
        if( m_ExcelApp ) {
            m_ExcelApp.Release();
            m_ExcelApp = NULL;
        }
        return false;
    } else {
        return true;
    }
}

bool disConnectExcel() {
    try {
        if( NULL != m_ExcelApp ) {
            m_ExcelApp.Release();
            m_ExcelApp = NULL;
        }
    } catch(...) {
        return false;
    }
    return true;
}

bool openExcelFile( QDomDocument& doc, QDomElement& elementTS, MSExcel::_WorkbookPtr pWorkbook, QString strColumn ) {
    try {
        MSExcel::SheetsPtr pSheets;
        pWorkbook->get_Sheets(&pSheets);
        long nNum = 0;
        pSheets->get_Count(&nNum);
        _variant_t vt;
        vt.vt = VT_I2;
        vt.iVal = 1;
        MSExcel::_WorksheetPtr pWorkSheet = pSheets->GetItem(vt);
        MSExcel::RangePtr UsedRange = pWorkSheet->GetUsedRange(0);
        int iColCnt = UsedRange->GetColumns()->GetCount();
        int iRowCnt = UsedRange->GetRows()->GetCount();
        for( int i = 2 ; i <= iColCnt ; i++ ) {
            _variant_t vData = UsedRange->Item[1][i];
            CString str = vData;
            QString qStr = QString::fromWCharArray( str.GetBuffer() );
            if( qStr == strColumn ) {
                for( int j = 2 ; j <= iRowCnt ; j ++ ) {
                    _variant_t id = UsedRange->Item[j][1];
                    _variant_t tran = UsedRange->Item[j][i];
                    findAndFillData( doc, elementTS, QString::fromWCharArray( CString( id ).GetBuffer() ), QString::fromWCharArray( CString( tran ).GetBuffer() ) );
                }
                break;
            }
        }
    } catch(...) {
        return false;
    }
    return true;
}


LanguageTranslatorExe::LanguageTranslatorExe(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LanguageTranslatorExe)
{
    ui->setupUi(this);

   CIniFile ini;
   QString iniFile = QFileInfo(QApplication::applicationDirPath(),"config.ini").absoluteFilePath();

   if(QFile::exists(iniFile))
   {
       ini.OpenIniFile(iniFile.toUtf8().data());

       filename_excel = QString::fromStdString(ini.ReadString("Default","excelfile",""));
       filename_qt= QString::fromStdString(ini.ReadString("Default","qt",""));
       filename_qml = QString::fromStdString(ini.ReadString("Default","qml",""));
       filename_trans = QString::fromStdString(ini.ReadString("Default","trans",""));
       ui->lineEdit_excel->setText(filename_excel);
       ui->lineEdit_qml->setText(filename_qml);
       ui->lineEdit_qt->setText(filename_qt);
       ui->lineEdit_qml_2->setText(filename_trans);
   }

    strLanguage <<"en_US"<<"zh_CN"<<"mn"
                <<"ja"<<"he"<<"ar"
                <<"ca"<<"cs"<<"da"
                <<"de"<<"en"<<"es"
                <<"fa"<<"fi"<<"fr"
                <<"gl"<<"hu"<<"it"
                <<"ko"<<"lt"<<"pl"
                <<"pt"<<"ru"<<"sk"
                <<"sl"<<"sv"<<"uk";
	for (auto b : strLanguage)
	{
     auto c  =new QListWidgetItem(b,ui->listWidget_select);
        ui->listWidget_select->insertItem(ui->listWidget_select->count(),c);
    }

}

LanguageTranslatorExe::~LanguageTranslatorExe()
{
   QString iniFile = QFileInfo(QApplication::applicationDirPath(),"config.ini").absoluteFilePath();
   CIniFile ini;
   ini.WriteString("Default","excelfile",ui->lineEdit_excel->text().toStdString().c_str());
   ini.WriteString("Default","qt",ui->lineEdit_qt->text().toStdString().c_str());
   ini.WriteString("Default","qml",ui->lineEdit_qml->text().toStdString().c_str());
   ini.WriteString("Default","trans",ui->lineEdit_qml_2->text().toStdString().c_str());
   ini.WriteIniFile(iniFile.toStdString().c_str());
   delete ui;
}

void LanguageTranslatorExe::ShowOpenFile(QString strState,bool AccandDir)
{
    QFileDialog dlg(this,"OpenFileName2");
    dlg.resize(400,300);
    if(!AccandDir)
        dlg.setAcceptMode(QFileDialog::AcceptOpen);
	else
		dlg.setFileMode(QFileDialog::Directory);
	dlg.setNameFilter(strState);
	dlg.exec();
	QStringList files = dlg.selectedFiles();
	if (!files.isEmpty()) {
		filename = files.at(0);
	}
}

void LanguageTranslatorExe::on_toolbtn_excel_clicked()
{
    ShowOpenFile("excel Files(*.xls);;All Files(*.*)",false);
    filename_excel=filename;
    ui->lineEdit_excel->setText(filename_excel);
}

void LanguageTranslatorExe::on_toolbtn_qt_clicked()
{
     ShowOpenFile("Qt Files(*.exe *.h *.cpp);;All Files(*.*)",true);
     filename_qt=filename;
     ui->lineEdit_qt->setText(filename_qt);
}

void LanguageTranslatorExe::on_toobtn_qml_clicked()
{
     ShowOpenFile("QM Files(*.qm);;All Files(*.*)",true);
     filename_qml=filename;
     ui->lineEdit_qml->setText(filename_qml);
}

void LanguageTranslatorExe::on_listWidget_select_currentTextChanged(const QString &currentText)
{
    QListWidgetItem *Ritem=new QListWidgetItem(currentText,ui->listWidget_receive);
    ui->listWidget_receive->addItem(Ritem);
}

void LanguageTranslatorExe::on_pushbtn_Cancle_clicked()
{
    this->close();
}

void LanguageTranslatorExe::on_pushbtn_Ok_clicked() {

    QString strTmp;

    int nLanguageCount = ui->listWidget_receive->count();
    strTmp = QString("selected language count():%1").arg(nLanguageCount);
    QMessageBox::information(this, strTmp, strTmp );

    if(nLanguageCount == 0)
    {
        strTmp = QString("selected language fail");
        QMessageBox::information(this, strTmp, strTmp );
        return;                
    }

    QMessageBox::information(this, "filename_trans dir", filename_trans );

    QString ts = filename_trans + "\\Test_Cross_Translation.ts";
    qDebug()<<"ts:"<<ts;

    QFile info(ts);
    bool bExists = info.exists();
    if(bExists)
        QFile::remove(ts);

    /// start lupdate
    QProcess ps;
    QString program = filename_qt + "\\lupdate.exe";
    QStringList list;
    list << filename_trans + "\\Chemistry"
         << filename_trans + "\\Common"
         << filename_trans + "\\Complexor"
//         << filename_trans + "\\Device"
         << filename_trans + "\\Figure"
         << filename_trans + "\\Foundation"
//         << filename_trans + "\\FoundationPreAndTeaching"
         << filename_trans + "\\GeneralTool"
         << filename_trans + "\\UIElement"
//         << filename_trans + "\\HiteTouchPro"
         << filename_trans + "\\Literature"
         << filename_trans + "\\Mathematics"
         << filename_trans + "\\MindMap"
         << filename_trans + "\\Media"
         << filename_trans + "\\Physics"
         << filename_trans + "\\Resource"
         << filename_trans + "\\Strokes"
         << filename_trans + "\\TextBox"
//         << filename_trans + "\\3DTools\\3dtoolDialog"
         << filename_trans + "\\UIFactory"
         << filename_trans + "\\UIPreAndTeaching"
//         << filename_trans + "\\IdeaMax"
         << filename_trans + "\\Model"
//         << filename_trans + "\\ObjAnimationCore"
         << filename_trans + "\\BaseText"
         << filename_trans + "\\HHScenarioControlActions"
         << filename_trans + "\\HHControllerAction"
         << filename_trans + "\\Utility"
         << filename_trans + "\\UISchoolTeaching"
         << filename_trans + "\\UIPreProperty"
         << filename_trans + "\\DrafPaper"
         << filename_trans + "\\BasicGraph"
         << filename_trans + "\\ScreenCapture"
         << filename_trans + "\\CloudCenter"
         << filename_trans + "\\HHAnimation"
         << filename_trans + "\\HHScenarioPreparing"
         << filename_trans + "\\HHScenarioTeaching"
         << filename_trans + "\\HHClassActivity"
         << filename_trans + "\\HHChineseCharacter"
         << filename_trans + "\\HHMathSubject"
         << "-ts" << ts;

    QMessageBox::information(this, "source code dir", "list[0] Path:" + list.at(0) );

    ps.start( program, list );
    ps.waitForFinished();

    /// fill data from excel
    if( !connectExcel() )
    {
        strTmp = QString("connectExcel fail");
        QMessageBox::information(this, strTmp, strTmp );
        return;
    }

	CComVariant vTrue((short)TRUE), vtFalse((short)FALSE), vOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);
	MSExcel::WorkbooksPtr pWorkbooks;
	m_ExcelApp->get_Workbooks(&pWorkbooks);
	BSTR bsname = SysAllocString((OLECHAR*)filename_excel.data());
	MSExcel::_WorkbookPtr pWorkbook;
	pWorkbooks->raw_Open(_bstr_t(bsname), vOptional, vTrue, vOptional,
		vOptional, vOptional, vOptional, vOptional, vOptional, vOptional, vtFalse,
		vtFalse, vtFalse, 0, &pWorkbook);

    QString strDestLanguage;
    for( int i = 0 ; i < nLanguageCount ; i ++ ) {

        strDestLanguage = ui->listWidget_receive->item(i)->text();
//        strTmp = QString("strDestLanguage:%1").arg(strDestLanguage);;
//        QMessageBox::information(this, strTmp, strTmp );

        qDebug()<<"strTmp:"<<strTmp;

        /// open ts file
        QFile xmlFile( ts );
        if( !xmlFile.open( QIODevice::ReadWrite ) )
        {
            strTmp = QString("xmlFile.open fail");
            qDebug()<<"strTmp:"<<strTmp;
            return;
        }
        QDomDocument doc;
        if( !doc.setContent( &xmlFile, false ) )
        {
            strTmp = QString("doc.setContent fail");
            qDebug()<<"strTmp:"<<strTmp;
            xmlFile.close();
            return;
        }

        QDomElement elementTS = doc.documentElement();
        if( !openExcelFile( doc, elementTS, pWorkbook, strDestLanguage ) )
        {
            strTmp = QString("openExcelFile fail");
            qDebug()<<"strTmp:"<<strTmp;
            xmlFile.close();
            return;
        }

        xmlFile.close();
        /// save ts file
        if( !xmlFile.open( QIODevice::WriteOnly | QIODevice::Truncate ) )
        {
            strTmp = QString("xmlFile.open fail");
            qDebug()<<"strTmp:"<<strTmp;
            return;
        }

        QTextStream out( &xmlFile );
        doc.save( out, 4 );
        xmlFile.close();
        /// start lrelease
        program = filename_qt + "\\lrelease.exe";
        list.clear();
        list << ts << "-qm" << filename_qml + "\\" + ui->comboBox->currentText() + "_" + strDestLanguage + ".qm";

        qDebug()<<"list:"<<list;

        ps.start( program, list );
        ps.waitForFinished();

//        QMessageBox::information(this, "dest dir", ui->comboBox->currentText() + "_" + strDestLanguage + ".qm" );
    }

	pWorkbooks->raw_Close();
    disConnectExcel();

    QMessageBox::information(this, "", "Translation end." );
}

void LanguageTranslatorExe::on_toobtn_qml_2_clicked()
{
    ShowOpenFile("QM Files(*.qm);;All Files(*.*)",true);
    filename_trans=filename;
    ui->lineEdit_qml_2->setText(filename_trans);
}

void LanguageTranslatorExe::on_listWidget_receive_clicked(const QModelIndex &index)
{
    QList<QListWidgetItem*> list = ui->listWidget_receive->selectedItems();

    if(list.size() == 0)
        return;

    QListWidgetItem* sel = list[0];
    if (sel)
    {
        int r = ui->listWidget_receive->row(sel);
        ui->listWidget_receive->takeItem(r);
    }
}
