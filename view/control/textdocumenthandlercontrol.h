#ifndef TEXTDOCUMENTHANDLERCONTROL_H
#define TEXTDOCUMENTHANDLERCONTROL_H

#include <memory>

#include <QObject>

#include <model/languagemodel.h>

#include "syntaxhighlightercontrol.h"

class QQuickTextDocument;
class TextDocumentHandlerControl : public QObject {
    Q_OBJECT
    Q_PROPERTY( QQuickTextDocument* textDocument READ textDocument WRITE setTextDocument NOTIFY textDocumentChanged FINAL )
public:
    TextDocumentHandlerControl();

    QQuickTextDocument* textDocument() const;
    void setTextDocument( QQuickTextDocument* textDocument );

    Q_INVOKABLE void languageChanged( const LanguageModel* language );

signals:
    void textDocumentChanged();

private:
    QQuickTextDocument* _textDocument;
    const LanguageModel* _language;
    std::unique_ptr<SyntaxHighlighterControl> _sqlSyntaxHighlighter;

    void onSyntaxHighlitherChanged();
};

#endif // TEXTDOCUMENTHANDLERCONTROL_H
