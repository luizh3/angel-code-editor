QT += quick

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        helper/filehelper.cpp \
        main.cpp \
        model/extensionmodel.cpp \
        model/filemodel.cpp \
        model/highlightermodel.cpp \
        model/languagemodel.cpp \
        repository/completerrepository.cpp \
        repository/filerepository.cpp \
        repository/folderrepository.cpp \
        repository/generalconfigsrepository.cpp \
        repository/highlighterrepository.cpp \
        singleton/generalconfigsingleton.cpp \
        view/control/control.cpp \
        view/control/dto/selectiondto.cpp \
        view/control/foldercontrol.cpp \
        view/control/languageselectormodalcontrol.cpp \
        view/control/syntaxhighlightercontrol.cpp \
        view/control/textcompletercontrol.cpp \
        view/control/textdocumenthandlercontrol.cpp

RESOURCES += qml.qrc \
    icons.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
message($$PWD/components)
QML_IMPORT_PATH = $$PWD/components

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    helper/filehelper.h \
    model/extensionmodel.h \
    model/filemodel.h \
    model/highlightermodel.h \
    model/languagemodel.h \
    repository/completerrepository.h \
    repository/filerepository.h \
    repository/folderrepository.h \
    repository/generalconfigsrepository.h \
    repository/highlighterrepository.h \
    singleton/generalconfigsingleton.h \
    view/control/control.h \
    view/control/dto/selectiondto.h \
    view/control/foldercontrol.h \
    view/control/languageselectormodalcontrol.h \
    view/control/syntaxhighlightercontrol.h \
    view/control/textcompletercontrol.h \
    view/control/textdocumenthandlercontrol.h
