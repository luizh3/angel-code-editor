#ifndef GENERALCONFIGSREPOSITORY_H
#define GENERALCONFIGSREPOSITORY_H

#include <model/languagemodel.h>

class GeneralConfigsRepository {
public:
    static QList<LanguageModel*> languages();
};

#endif // GENERALCONFIGSREPOSITORY_H
