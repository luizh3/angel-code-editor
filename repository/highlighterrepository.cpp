#include "highlighterrepository.h"

#include <QFile>
#include <QJsonArray>

#include <helper/filehelper.h>

QList<HighlighterModel*> HighlighterRepository::rules( const QString& dsFile ) const {
    return toRules( readRulesByFile( dsFile ) );
}

QJsonDocument HighlighterRepository::readRulesByFile( const QString& dsFile ) const  {

    const QString dsPath = FileHelper::toAbsolutePath( { "config", "language" , "highlighter", dsFile } );

    QFile file( dsPath );

    if ( !file.open( QIODevice::ReadOnly | QIODevice::Text ) ) {

        qInfo() << "HighlighterRepository::readRulesByFile [ERROR]" << file.error();

        throw std::runtime_error("Failed on open Highlighter config");
    }

    QTextStream stream( &file );

    QString dsJson = stream.readAll();

    QJsonDocument json = QJsonDocument::fromJson( dsJson.toUtf8() );

    file.close();

    return json;
}

QList<HighlighterModel*> HighlighterRepository::toRules( const QJsonDocument& document ) const {

    const QJsonArray rulesJson = document["rules"].toArray();

    QList<HighlighterModel*> rules = {};

    for( const QJsonValue& ruleJson : rulesJson ) {

        HighlighterModel* highlighterModel = new HighlighterModel();

        QTextCharFormat format;
        format.setForeground( QColor( ruleJson["color"].toString() ) );
        highlighterModel->setFormat( format );

        highlighterModel->setPattern( QRegularExpression( ruleJson["regex"].toString() ) );

        QStringList words = {};

        QVariantList wordsJson = ruleJson["words"].toArray().toVariantList();

        std::transform( wordsJson.begin(), wordsJson.end(), std::back_inserter( words ), []( const QVariant& wordJson ) {
            return wordJson.toString();
        });

        highlighterModel->setWords( words );

        rules.append( highlighterModel );
    }

    return rules;

}
