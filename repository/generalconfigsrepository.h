#ifndef GENERALCONFIGSREPOSITORY_H
#define GENERALCONFIGSREPOSITORY_H

#include <model/languagemodel.h>
#include <model/extensionmodel.h>

class GeneralConfigsRepository {
public:
    static QList<LanguageModel*> languages();
    static QList<ExtensionModel*> extensions();
};

#endif // GENERALCONFIGSREPOSITORY_H
