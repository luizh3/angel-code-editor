#include "generalconfigsrepository.h"

#include <QDebug>
#include <QSettings>

#include <helper/filehelper.h>

QList<LanguageModel*> GeneralConfigsRepository::languages() {

    qInfo() << "GeneralConfigsRepository::languages";

    const QString dsPath = FileHelper::toAbsolutePath( { "config", "general.ini" } );

    QList<LanguageModel*> languages = {};

    QSettings settings( dsPath, QSettings::IniFormat );

    settings.beginGroup("languages");

    const int nrRegisters = settings.beginReadArray("language");

    for (int i = 0; i < nrRegisters; ++i) {
        settings.setArrayIndex(i);

        LanguageModel* language = new LanguageModel();
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
