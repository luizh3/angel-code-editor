#ifndef LANGUAGESELECTORMODALCONTROL_H
#define LANGUAGESELECTORMODALCONTROL_H

#include "control.h"

#include <model/languagemodel.h>

class LanguageSelectorModalControl : public Control {
    Q_OBJECT
public:
    Q_INVOKABLE void doStart();
private:
    void onSelect();
signals:
    void selected( const LanguageModel* language );
};

#endif // LANGUAGESELECTORMODALCONTROL_H
