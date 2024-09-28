#ifndef GENERALCONFIGSINGLETON_H
#define GENERALCONFIGSINGLETON_H

#include <QList>

#include <model/languagemodel.h>
#include <model/extensionmodel.h>

class GeneralConfigSingleton {
public:
    ~GeneralConfigSingleton();

    static GeneralConfigSingleton& instance();

    QList<LanguageModel*> languages( const bool isCopy = true ) const;
    void setLanguages( const QList<LanguageModel*>& languages );

    QList<ExtensionModel*> extensions() const;
    void setExtensions( const QList<ExtensionModel*>& extensions );

private:
    QList<LanguageModel*> _languages;
    QList<ExtensionModel*> _extensions;
};

#endif // GENERALCONFIGSINGLETON_H
