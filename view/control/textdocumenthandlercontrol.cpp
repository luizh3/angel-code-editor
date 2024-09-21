#include "textdocumenthandlercontrol.h"

#include <QQuickTextDocument>

#include <repository/highlighterrepository.h>

TextDocumentHandlerControl::TextDocumentHandlerControl() {}

QQuickTextDocument* TextDocumentHandlerControl::textDocument() const {
    return _textDocument;
}

void TextDocumentHandlerControl::setTextDocument( QQuickTextDocument* textDocument ) {

    if ( _textDocument == textDocument ) {
        return;
    }

    _sqlSyntaxHighlighter.reset( new SyntaxHighlighterControl( textDocument->textDocument(), HighlighterRepository().rules("sql.json") ) );

    _textDocument = textDocument;

    emit textDocumentChanged();
}
