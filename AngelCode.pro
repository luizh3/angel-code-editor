QT += quick

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        helper/filehelper.cpp \
        main.cpp \
        model/highlightermodel.cpp \
        model/languagemodel.cpp \
        repository/completerrepository.cpp \
        repository/generalconfigsrepository.cpp \
        repository/highlighterrepository.cpp \
        singleton/generalconfigsingleton.cpp \
        view/control/syntaxhighlightercontrol.cpp \
        view/control/textcompletercontrol.cpp \
        view/control/textdocumenthandlercontrol.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH = $$PWD/Theme

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

CONFIG( debug, debug|release ) {
    DESTDIR = build/debug
}

CONFIG( release, debug|release ) {
    DESTDIR = build/release
}

OBJECTS_DIR = $$DESTDIR/.obj
MOC_DIR = $$DESTDIR/.moc
RCC_DIR = $$DESTDIR/.qrc
UI_DIR = $$DESTDIR/.u

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    helper/filehelper.h \
    model/highlightermodel.h \
    model/languagemodel.h \
    repository/completerrepository.h \
    repository/generalconfigsrepository.h \
    repository/highlighterrepository.h \
    singleton/generalconfigsingleton.h \
    view/control/syntaxhighlightercontrol.h \
    view/control/textcompletercontrol.h \
    view/control/textdocumenthandlercontrol.h
