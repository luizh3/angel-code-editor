#include "textcompletercontrol.h"

#include <QTextBlock>

#include <repository/completerrepository.h>

namespace {
constexpr const char EMPTY_CHARACTER = ' ';
}

TextCompleterControl::TextCompleterControl() {
    _wordList = CompleterRepository().words( "sql.json" );
}

QStringList TextCompleterControl::sugestions() const {
    return _sugestions;
}

void TextCompleterControl::setSugestions( const QStringList &sugestions ) {
    if ( _sugestions == sugestions ) {
        return;
    }
    _sugestions = sugestions;
    emit sugestionsChanged();
}

QPoint TextCompleterControl::currentPosition() const {
    return _currentPosition;
}

void TextCompleterControl::setCurrentPosition( QPoint currentPosition ) {
    if ( _currentPosition == currentPosition ){
        return;
    }

    _currentPosition = currentPosition;

    setSugestions( suggestionsByLineAndPosition() );

    emit currentPositionChanged();
}

QQuickTextDocument *TextCompleterControl::textDocument() const {
    return _textDocument;
}

void TextCompleterControl::setTextDocument( QQuickTextDocument* textDocument ) {
    if ( _textDocument == textDocument ) {
        return;
    }

    _textDocument = textDocument;
    emit textDocumentChanged();
}

void TextCompleterControl::completeSugestion( const QString& word ) {

    QTextBlock currentLine = _textDocument->textDocument()->findBlockByLineNumber( _currentPosition.y() );

    const QChar lastCharacter = !currentLine.text().isEmpty() ? currentLine.text().back() : QChar( EMPTY_CHARACTER );

    QTextCursor cursor ( currentLine );
    cursor.setPosition( _currentPosition.x() );

    if( lastCharacter != EMPTY_CHARACTER ) {

        cursor.movePosition( QTextCursor::PreviousWord );

        cursor.select( QTextCursor::WordUnderCursor );

        cursor.removeSelectedText();
    }

    cursor.insertText( word );

}

QStringList TextCompleterControl::wordsByPart( const QString& part ) const {

    if( part.isEmpty() ) {
        return {};
    }

    QStringList values = {};

    for( const QString& word : _wordList ) {

        const QString partWord = word.mid( 0, part.length() );
        const bool isMatch = partWord.toUpper() == part.toUpper();

        if( isMatch ) {
            values.append( word );
        }

    }

    return values;
}

QStringList TextCompleterControl::suggestionsByLineAndPosition() const {

    if( !_textDocument ) {
        return {};
    }

    QTextBlock currentLine = _textDocument->textDocument()->findBlockByLineNumber( _currentPosition.y() );

    QString currentText = currentLine.text();

    const int indexBreakLine = currentText.lastIndexOf( " ", _currentPosition.x() - 1 );

    const bool hasIndexBreakLine = indexBreakLine != -1;

    QString currentWord = currentText.mid( hasIndexBreakLine ? indexBreakLine : 0, _currentPosition.x() - indexBreakLine );

    return wordsByPart( currentWord.trimmed() );

}
