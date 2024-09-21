#ifndef TEXTDOCUMENTHANDLERCONTROL_H
#define TEXTDOCUMENTHANDLERCONTROL_H

#include <memory>

#include <QObject>

#include "syntaxhighlightercontrol.h"

class QQuickTextDocument;
class TextDocumentHandlerControl : public QObject{
    Q_OBJECT
    Q_PROPERTY( QQuickTextDocument* textDocument READ textDocument WRITE setTextDocument NOTIFY textDocumentChanged FINAL )
public:
    TextDocumentHandlerControl();

    QQuickTextDocument* textDocument() const;
    void setTextDocument( QQuickTextDocument* textDocument );

signals:
    void textDocumentChanged();

private:
    QQuickTextDocument* _textDocument;
    std::unique_ptr<SyntaxHighlighterControl> _sqlSyntaxHighlighter;
};

#endif // TEXTDOCUMENTHANDLERCONTROL_H
