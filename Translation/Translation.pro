#-------------------------------------------------
#
# Project created by QtCreator 2016-02-23T17:57:45
#
#-------------------------------------------------

QT += widgets core gui xml

TEMPLATE = app

SOURCES += main.cpp\
    languagetranslatorexe.cpp \
    IniFile.cpp

HEADERS  +=  languagetranslatorexe.h \
    IniFile.h

FORMS    += languagetranslatorexe.ui

win32:{
    contains(DEFINES, WIN64):{
        CONFIG(release, debug|release):{
            DESTDIR = $$PWD/../Bin/Release/X64
        }
        else:CONFIG(debug, debug|release):{
            DESTDIR = $$PWD/../Bin/Debug/X64
        }
    }
    else:{
        CONFIG(release, debug|release):{
            DESTDIR = $$PWD/../Bin/Release/X86
        }
        else:CONFIG(debug, debug|release):{
            DESTDIR = $$PWD/../Bin/Debug/X86
        }
    }
}

unix:!macx:{
}

macx:{
}
