/********************************************************************************
** Form generated from reading UI file 'languagetranslatorexe.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LANGUAGETRANSLATOREXE_H
#define UI_LANGUAGETRANSLATOREXE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LanguageTranslatorExe
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QToolButton *toolbtn_excel;
    QLabel *label;
    QToolButton *toolbtn_qt;
    QLabel *label_4;
    QComboBox *comboBox;
    QLineEdit *lineEdit_excel;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_qml;
    QToolButton *toobtn_qml;
    QLineEdit *lineEdit_qt;
    QLineEdit *lineEdit_qml_2;
    QToolButton *toobtn_qml_2;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidget_select;
    QListWidget *listWidget_receive;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushbtn_Ok;
    QPushButton *pushbtn_Cancle;

    void setupUi(QWidget *LanguageTranslatorExe)
    {
        if (LanguageTranslatorExe->objectName().isEmpty())
            LanguageTranslatorExe->setObjectName(QStringLiteral("LanguageTranslatorExe"));
        LanguageTranslatorExe->resize(600, 600);
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        LanguageTranslatorExe->setFont(font);
        verticalLayout = new QVBoxLayout(LanguageTranslatorExe);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        toolbtn_excel = new QToolButton(LanguageTranslatorExe);
        toolbtn_excel->setObjectName(QStringLiteral("toolbtn_excel"));
        toolbtn_excel->setFont(font);

        gridLayout->addWidget(toolbtn_excel, 1, 2, 1, 1);

        label = new QLabel(LanguageTranslatorExe);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        toolbtn_qt = new QToolButton(LanguageTranslatorExe);
        toolbtn_qt->setObjectName(QStringLiteral("toolbtn_qt"));
        toolbtn_qt->setFont(font);

        gridLayout->addWidget(toolbtn_qt, 2, 2, 1, 1);

        label_4 = new QLabel(LanguageTranslatorExe);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        comboBox = new QComboBox(LanguageTranslatorExe);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setFont(font);

        gridLayout->addWidget(comboBox, 0, 1, 1, 2);

        lineEdit_excel = new QLineEdit(LanguageTranslatorExe);
        lineEdit_excel->setObjectName(QStringLiteral("lineEdit_excel"));
        lineEdit_excel->setEnabled(false);
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(9);
        font1.setBold(true);
        font1.setWeight(75);
        lineEdit_excel->setFont(font1);

        gridLayout->addWidget(lineEdit_excel, 1, 1, 1, 1);

        label_2 = new QLabel(LanguageTranslatorExe);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(LanguageTranslatorExe);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        lineEdit_qml = new QLineEdit(LanguageTranslatorExe);
        lineEdit_qml->setObjectName(QStringLiteral("lineEdit_qml"));
        lineEdit_qml->setEnabled(false);
        lineEdit_qml->setFont(font1);

        gridLayout->addWidget(lineEdit_qml, 3, 1, 1, 1);

        toobtn_qml = new QToolButton(LanguageTranslatorExe);
        toobtn_qml->setObjectName(QStringLiteral("toobtn_qml"));
        toobtn_qml->setFont(font);

        gridLayout->addWidget(toobtn_qml, 3, 2, 1, 1);

        lineEdit_qt = new QLineEdit(LanguageTranslatorExe);
        lineEdit_qt->setObjectName(QStringLiteral("lineEdit_qt"));
        lineEdit_qt->setEnabled(false);
        lineEdit_qt->setFont(font1);

        gridLayout->addWidget(lineEdit_qt, 2, 1, 1, 1);

        lineEdit_qml_2 = new QLineEdit(LanguageTranslatorExe);
        lineEdit_qml_2->setObjectName(QStringLiteral("lineEdit_qml_2"));
        lineEdit_qml_2->setEnabled(false);
        lineEdit_qml_2->setFont(font1);

        gridLayout->addWidget(lineEdit_qml_2, 4, 1, 1, 1);

        toobtn_qml_2 = new QToolButton(LanguageTranslatorExe);
        toobtn_qml_2->setObjectName(QStringLiteral("toobtn_qml_2"));
        toobtn_qml_2->setFont(font);

        gridLayout->addWidget(toobtn_qml_2, 4, 2, 1, 1);

        label_5 = new QLabel(LanguageTranslatorExe);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 4, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        listWidget_select = new QListWidget(LanguageTranslatorExe);
        listWidget_select->setObjectName(QStringLiteral("listWidget_select"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        listWidget_select->setFont(font2);

        horizontalLayout->addWidget(listWidget_select);

        listWidget_receive = new QListWidget(LanguageTranslatorExe);
        listWidget_receive->setObjectName(QStringLiteral("listWidget_receive"));
        listWidget_receive->setFont(font2);

        horizontalLayout->addWidget(listWidget_receive);


        verticalLayout->addLayout(horizontalLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 0, 1, 1);

        pushbtn_Ok = new QPushButton(LanguageTranslatorExe);
        pushbtn_Ok->setObjectName(QStringLiteral("pushbtn_Ok"));

        gridLayout_2->addWidget(pushbtn_Ok, 0, 1, 1, 1);

        pushbtn_Cancle = new QPushButton(LanguageTranslatorExe);
        pushbtn_Cancle->setObjectName(QStringLiteral("pushbtn_Cancle"));

        gridLayout_2->addWidget(pushbtn_Cancle, 0, 2, 1, 1);


        verticalLayout->addLayout(gridLayout_2);


        retranslateUi(LanguageTranslatorExe);

        QMetaObject::connectSlotsByName(LanguageTranslatorExe);
    } // setupUi

    void retranslateUi(QWidget *LanguageTranslatorExe)
    {
        LanguageTranslatorExe->setWindowTitle(QApplication::translate("LanguageTranslatorExe", "Form", Q_NULLPTR));
        toolbtn_excel->setText(QApplication::translate("LanguageTranslatorExe", "...", Q_NULLPTR));
        label->setText(QApplication::translate("LanguageTranslatorExe", "\347\277\273\350\257\221\345\275\223\345\211\215\347\250\213\345\272\217:", Q_NULLPTR));
        toolbtn_qt->setText(QApplication::translate("LanguageTranslatorExe", "...", Q_NULLPTR));
        label_4->setText(QApplication::translate("LanguageTranslatorExe", "qm\350\276\223\345\207\272\347\233\256\345\275\225:", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("LanguageTranslatorExe", "HiteTouchPro", Q_NULLPTR)
         << QApplication::translate("LanguageTranslatorExe", "IdeaMax", Q_NULLPTR)
         << QApplication::translate("LanguageTranslatorExe", "HiteTouchPPTHelper", Q_NULLPTR)
        );
        label_2->setText(QApplication::translate("LanguageTranslatorExe", "excel\346\226\207\344\273\266\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("LanguageTranslatorExe", "QT\346\211\200\345\234\250\347\233\256\345\275\225:", Q_NULLPTR));
        toobtn_qml->setText(QApplication::translate("LanguageTranslatorExe", "...", Q_NULLPTR));
        toobtn_qml_2->setText(QApplication::translate("LanguageTranslatorExe", "...", Q_NULLPTR));
        label_5->setText(QApplication::translate("LanguageTranslatorExe", "\345\267\245\347\250\213\347\233\256\345\275\225:", Q_NULLPTR));
        pushbtn_Ok->setText(QApplication::translate("LanguageTranslatorExe", "\347\241\256\345\256\232", Q_NULLPTR));
        pushbtn_Cancle->setText(QApplication::translate("LanguageTranslatorExe", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LanguageTranslatorExe: public Ui_LanguageTranslatorExe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LANGUAGETRANSLATOREXE_H
