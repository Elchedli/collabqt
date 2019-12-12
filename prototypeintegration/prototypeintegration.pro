QT       += core gui sql multimedia serialport
QT       += core gui sql network printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    acceuil.cpp \
    amine.cpp \
    amine/local.cpp \
    amine/locataire.cpp \
    chedli.cpp \
    chedli/arduino.cpp \
    chedli/modifierchedli.cpp \
    chedli/sponsor.cpp \
    connection.cpp \
    dhafer.cpp \
    dhafer/historique.cpp \
    dhafer/modifier.cpp \
    dhafer/stat.cpp \
    dhafer/vols.cpp \
    login.cpp \
    mailing/emailaddress.cpp \
    mailing/mimeattachment.cpp \
    mailing/mimecontentformatter.cpp \
    mailing/mimefile.cpp \
    mailing/mimehtml.cpp \
    mailing/mimeinlinefile.cpp \
    mailing/mimemessage.cpp \
    mailing/mimemultipart.cpp \
    mailing/mimepart.cpp \
    mailing/mimetext.cpp \
    mailing/quotedprintable.cpp \
    mailing/smtpclient.cpp \
    main.cpp \
    mainwindow.cpp \
    Employe.cpp \
    qcustomplot.cpp \
    Moetaz.cpp

HEADERS += \
    acceuil.h \
    amine.h \
    amine/local.h \
    amine/locataire.h \
    chedli.h \
    chedli/arduino.h \
    chedli/modifierchedli.h \
    chedli/sponsor.h \
    connection.h \
    dhafer.h \
    dhafer/historique.h \
    dhafer/modifier.h \
    dhafer/stat.h \
    dhafer/vols.h \
    login.h \
    mailing/SmtpMime \
    mailing/emailaddress.h \
    mailing/mimeattachment.h \
    mailing/mimecontentformatter.h \
    mailing/mimefile.h \
    mailing/mimehtml.h \
    mailing/mimeinlinefile.h \
    mailing/mimemessage.h \
    mailing/mimemultipart.h \
    mailing/mimepart.h \
    mailing/mimetext.h \
    mailing/quotedprintable.h \
    mailing/smtpclient.h \
    mailing/smtpexports.h \
    mainwindow.h \
    Employe.h \
    qcustomplot.h \
    Moetaz.h

FORMS += \
    acceuil.ui \
    amine.ui \
    chedli.ui \
    chedli/modifierchedli.ui \
    dhafer.ui \
    dhafer/modif.ui \
    dhafer/modification.ui \
    dhafer/modifier.ui \
    mainwindow.ui \
    Moetaz.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES += \
    dhafer/hiso.txt \
    dhafer/histo.txt
