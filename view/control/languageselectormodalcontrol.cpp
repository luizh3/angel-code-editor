#include "languageselectormodalcontrol.h"

#include <QDebug>

#include <singleton/generalconfigsingleton.h>

void LanguageSelectorModalControl::doStart() {

    qInfo() << "LanguageSelectorModalControl::doStart";

    QMetaObject::invokeMethod( this, &LanguageSelectorModalControl::onSelect, Qt::ConnectionType::QueuedConnection );

    qInfo() << "LanguageSelectorModalControl::doStart";
}

void LanguageSelectorModalControl::onSelect() {

    qInfo() << "LanguageSelectorModalControl::onSelect";

    LanguageModel* language = select<LanguageModel>( GeneralConfigSingleton::instance().languages( false ), []( LanguageModel* language ) {
        return new SelectionDTO( language->idLanguage(), language->dsName(), language->dsIcon(), static_cast<QObject*>( language ) );
    });

    emit selected( language );

    qInfo() << "LanguageSelectorModalControl::onSelect";
}
