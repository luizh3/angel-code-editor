#include "syntaxhighlightercontrol.h"

#include <QJsonArray>
#include <QString>
#include <QRegularExpressionMatchIterator>

#include <helper/filehelper.h>

SyntaxHighlighterControl::SyntaxHighlighterControl( QTextDocument* parent, const QList<HighlighterModel*>& rules )
    : QSyntaxHighlighter( parent ),
    _rules( rules )
{}

SyntaxHighlighterControl::~SyntaxHighlighterControl() {
    qDeleteAll( _rules );
}

void SyntaxHighlighterControl::highlightBlock( const QString &text ) {

    for( const HighlighterModel* rule : qAsConst( _rules ) ) {

        QRegularExpressionMatchIterator current = rule->pattern().globalMatch( text.toUpper() );

        while ( current.hasNext() ) {

            QRegularExpressionMatch match = current.next();

            QStringList words = rule->words();

            const QString matchWord = match.captured( 0 );

            if( words.isEmpty() || words.contains( matchWord, Qt::CaseSensitivity::CaseInsensitive ) ) {
                setFormat( match.capturedStart(), match.capturedLength(), rule->format() );
            }
        }
    }
}

