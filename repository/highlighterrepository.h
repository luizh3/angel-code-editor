#ifndef HIGHLIGHTERREPOSITORY_H
#define HIGHLIGHTERREPOSITORY_H

#include <QJsonDocument>

#include <model/highlightermodel.h>

class HighlighterRepository {
public:
    QList<HighlighterModel*> rules( const QString& dsFile ) const;
private:
    QJsonDocument readRulesByFile( const QString& dsFile ) const;
    QList<HighlighterModel*> toRules( const QJsonDocument& document ) const;
};

#endif // HIGHLIGHTERREPOSITORY_H
