#include "completerrepository.h"

#include <QFile>
#include <QJsonArray>

#include <helper/filehelper.h>

QSet<QString> CompleterRepository::words( const QString& dsFile ) const {
    return toWords( readWordsByFile( dsFile ) );
}

QJsonDocument CompleterRepository::readWordsByFile( const QString& dsFile ) const {

    const QString dsPath = FileHelper::toAbsolutePath( { "config", "language" , "completer", dsFile } );

    QFile file( dsPath );

    if ( !file.open( QIODevice::ReadOnly | QIODevice::Text ) ) {

        qInfo() << "HighlighterRepository::readWordsByFile [ERROR]" << file.error();

        throw std::runtime_error("Failed on open Completer config");
    }

    QTextStream stream( &file );

    QString dsJson = stream.readAll();

    QJsonDocument json = QJsonDocument::fromJson( dsJson.toUtf8() );

    file.close();

    return json;

}

QSet<QString> CompleterRepository::toWords( const QJsonDocument& document ) const {

    QSet<QString> words = {};

    const QVariantList wordsVariant = document["words"].toArray().toVariantList();

    for( const QVariant& wordVariant : wordsVariant ) {
        words.insert( wordVariant.toString() );
    }

    return words;

}
