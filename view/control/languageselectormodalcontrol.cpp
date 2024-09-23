#include "languageselectormodalcontrol.h"

#include <QEventLoop>

#include <singleton/generalconfigsingleton.h>



void LanguageSelectorModalControl::doStart() {

    QList<SelectionDTO*> languagesDTO = toSelectionDTO( GeneralConfigSingleton::instance().languages( false ) );

    QEventLoop wait;
    QObject::connect( this, &LanguageSelectorModalControl::confirmed, &wait, &QEventLoop::exit );

    emit languages( QVariant::fromValue( languagesDTO ) );

    const bool isConfirmed = wait.exec();

    if( !isConfirmed ){
        qDeleteAll( languagesDTO );
        return;
    }

    // LanguageModel* language = SelectionDTO::selected<LanguageModel>( languagesDTO );

}

QList<SelectionDTO*> LanguageSelectorModalControl::toSelectionDTO( const QList<LanguageModel*>& languages ) const {
    return SelectionDTO::toSelection<LanguageModel>( languages, []( LanguageModel* language ) {
        return new SelectionDTO( language->idLanguage(), language->dsName(), language->dsIcon(), static_cast<QObject*>( language ) );
    } );
}
