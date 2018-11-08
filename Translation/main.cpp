#include <QApplication>
#include "languagetranslatorexe.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LanguageTranslatorExe w;

    w.show();

    return a.exec();
}
