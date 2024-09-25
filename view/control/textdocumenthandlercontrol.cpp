#include "textdocumenthandlercontrol.h"

#include <QQuickTextDocument>

#include <repository/highlighterrepository.h>

TextDocumentHandlerControl::TextDocumentHandlerControl() :
     _textDocument( nullptr ),
    _language( nullptr ) {}

QQuickTextDocument* TextDocumentHandlerControl::textDocument() const {
    return _textDocument;
}

void TextDocumentHandlerControl::setTextDocument( QQuickTextDocument* textDocument ) {

    if ( _textDocument == textDocument ) {
        return;
    }

    _textDocument = textDocument;

    onSyntaxHighlitherChanged();

    emit textDocumentChanged();
}

void TextDocumentHandlerControl::languageChanged( const LanguageModel* language ) {

    _language = language;

    onSyntaxHighlitherChanged();
}

void TextDocumentHandlerControl::onSyntaxHighlitherChanged() {

    if( !_textDocument || !_language ) {
        return;
    }

    QList<HighlighterModel*> rules = HighlighterRepository().rules( _language->dsHighlightFile() );

    _sqlSyntaxHighlighter.reset( new SyntaxHighlighterControl( _textDocument->textDocument(), rules ) );

}
