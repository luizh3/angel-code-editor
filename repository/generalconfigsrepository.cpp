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

        QQmlEngine::setObjectOwnership( language, QQmlEngine::CppOwnership );

        languages.append( language );
    }

    settings.endArray();

    settings.endGroup();

    qInfo() << "GeneralConfigsRepository::languages";

    return languages;

}
