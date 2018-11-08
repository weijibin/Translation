#ifndef LANGUAGETRANSLATOREXE_H
#define LANGUAGETRANSLATOREXE_H

#include <QWidget>
#include <QFile>
#include <QFileDialog>
#include <QListWidgetItem>
#include <QStringList>

namespace Ui {
class LanguageTranslatorExe;
}

class LanguageTranslatorExe : public QWidget
{
    Q_OBJECT

public:
    explicit LanguageTranslatorExe(QWidget *parent = 0);
    ~LanguageTranslatorExe();
   // QListWidgetItem *item[20];
public:
    QStringList strLanguage;

    QString filename;
    QString filename_excel;
    QString filename_qt;
    QString filename_qml;
    QString filename_trans;

public:
    void ShowOpenFile(QString strState,bool AccandDir);
private slots:
    void on_toolbtn_excel_clicked();

    void on_toolbtn_qt_clicked();

    void on_toobtn_qml_clicked();

    void on_listWidget_select_currentTextChanged(const QString &currentText);

    void on_pushbtn_Cancle_clicked();

    void on_pushbtn_Ok_clicked();

    void on_toobtn_qml_2_clicked();

    void on_listWidget_receive_clicked(const QModelIndex &index);

private:
    Ui::LanguageTranslatorExe *ui;
};

#endif // LANGUAGETRANSLATOREXE_H
