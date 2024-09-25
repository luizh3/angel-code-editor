#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlEngine>

#include <model./languagemodel.h>

#include <view/control/textdocumenthandlercontrol.h>
#include <view/control/textcompletercontrol.h>
#include <view/control/languageselectormodalcontrol.h>

#include <singleton/generalconfigsingleton.h>
#include <repository/generalconfigsrepository.h>

void loadConfigurations() {
    GeneralConfigSingleton::instance().setLanguages( GeneralConfigsRepository::languages() );
}

int main(int argc, char *argv[]) {
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    qmlRegisterType<TextDocumentHandlerControl>("Control.TextDocumentHandlerControl", 1, 0, "TextDocumentHandlerControl" );
    qmlRegisterType<TextCompleterControl>("Control.TextCompleterControl", 1, 0, "TextCompleterControl" );
    qmlRegisterType<LanguageSelectorModalControl>("Control.LanguageSelectorModalControl", 1, 0, "LanguageSelectorModalControl" );

    qRegisterMetaType<LanguageModel*>("LanguageModel*");
    qRegisterMetaType<const LanguageModel*>("const LanguageModel*");

    QCoreApplication::setOrganizationName("AngelCodeStudio");
    QCoreApplication::setOrganizationDomain("AngelCodeStudio");
    QCoreApplication::setApplicationName("AngelCodeStudio");

    loadConfigurations();

    QQmlApplicationEngine engine;
    engine.addImportPath(":/components");
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
