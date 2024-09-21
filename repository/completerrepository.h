#ifndef COMPLETERREPOSITORY_H
#define COMPLETERREPOSITORY_H

#include <QSet>
#include <QJsonDocument>

class CompleterRepository {
public:
    QSet<QString> words( const QString& dsFile ) const;
private:
    QJsonDocument readWordsByFile( const QString& dsFile ) const;
    QSet<QString> toWords( const QJsonDocument& document ) const;
};

#endif // COMPLETERREPOSITORY_H
