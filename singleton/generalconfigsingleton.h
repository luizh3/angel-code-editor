#ifndef GENERALCONFIGSINGLETON_H
#define GENERALCONFIGSINGLETON_H

#include <QList>

#include <model/languagemodel.h>

class GeneralConfigSingleton {
public:
    ~GeneralConfigSingleton();

    static GeneralConfigSingleton& instance();

    QList<LanguageModel*> languages() const;
    void setLanguages( const QList<LanguageModel*>& languages );

private:
    QList<LanguageModel*> _languages;
};

#endif // GENERALCONFIGSINGLETON_H
