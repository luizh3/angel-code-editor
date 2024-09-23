#ifndef LANGUAGESELECTORMODALCONTROL_H
#define LANGUAGESELECTORMODALCONTROL_H

#include <QObject>
#include <QVariant>

#include <model/languagemodel.h>

#include "dto/selectiondto.h"

class LanguageSelectorModalControl : public QObject {
    Q_OBJECT
public:
    Q_INVOKABLE void doStart();
signals:
    void languages( const QVariant& languages );
    void confirmed( const bool isConfimed );
private:
    QList<SelectionDTO*> toSelectionDTO( const QList<LanguageModel*>& languages ) const;
};

#endif // LANGUAGESELECTORMODALCONTROL_H
