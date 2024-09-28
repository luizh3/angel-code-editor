#include "generalconfigsingleton.h"

GeneralConfigSingleton::~GeneralConfigSingleton() {
    qDeleteAll( _languages );
    qDeleteAll( _extensions );
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

QList<ExtensionModel*> GeneralConfigSingleton::extensions() const {
    return _extensions;
}

void GeneralConfigSingleton::setExtensions( const QList<ExtensionModel*>& extensions) {
    _extensions = extensions;
}
