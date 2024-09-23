#include "generalconfigsingleton.h"

GeneralConfigSingleton::~GeneralConfigSingleton() {
    qDeleteAll( _languages );
}

GeneralConfigSingleton &GeneralConfigSingleton::instance() {
    static GeneralConfigSingleton generalConfigSingleton;
    return generalConfigSingleton;
}

QList<LanguageModel*> GeneralConfigSingleton::languages( const bool isCopy ) const {

    if( !isCopy ){
        return _languages;
    }

    return QList<LanguageModel*>(_languages);

}

void GeneralConfigSingleton::setLanguages( const QList<LanguageModel*>& languages) {
    _languages = languages;
}
