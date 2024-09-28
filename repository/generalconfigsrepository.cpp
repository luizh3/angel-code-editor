#include "generalconfigsrepository.h"

#include <QDebug>
#include <QSettings>
#include <QQmlEngine>

#include <helper/filehelper.h>

QList<LanguageModel*> GeneralConfigsRepository::languages() {

    qInfo() << "GeneralConfigsRepository::languages";

    const QString dsPath = FileHelper::toAbsolutePath( { "config", "general.ini" } );

    QList<LanguageModel*> languages = {};

    QSettings settings( dsPath, QSettings::IniFormat );

    settings.beginGroup("languages");

    const int nrRegisters = settings.beginReadArray("language");

    for (int index = 0; index < nrRegisters; ++index) {
        settings.setArrayIndex(index);

        LanguageModel* language = new LanguageModel();
        language->setIdLanguage( index + 1 );
        language->setDsName( settings.value("name").toString() );
        language->setDsIcon( settings.value("nameIcon").toString() );
        language->setDsCompleteFile( settings.value("completeFile").toString() );
        language->setDsHighlightFile( settings.value("highlightFile").toString() );

        languages.append( language );
    }

    settings.endArray();

    settings.endGroup();

    qInfo() << "GeneralConfigsRepository::languages";

    return languages;
}

QList<ExtensionModel*> GeneralConfigsRepository::extensions() {

    qInfo() << "GeneralConfigsRepository::extensions";

    const QString dsPath = FileHelper::toAbsolutePath( { "config", "general.ini" } );

    QList<ExtensionModel*> extensions = {};

    QSettings settings( dsPath, QSettings::IniFormat );

    settings.beginGroup("iconsExtensions");

    const int nrRegisters = settings.beginReadArray("extension");

    for (int index = 0; index < nrRegisters; ++index) {
        settings.setArrayIndex(index);

        ExtensionModel* extension = new ExtensionModel();
        extension->setDsName( settings.value("name").toString() );
        extension->setDsIcon( settings.value("nameIcon").toString() );
        extension->setPattern( QRegularExpression( settings.value("regex").toString() ) );

        extensions.append( extension );
    }

    settings.endArray();

    settings.endGroup();

    qInfo() << "GeneralConfigsRepository::extensions";

    return extensions;

}
