#ifndef TEXTDOCUMENTHANDLERCONTROL_H
#define TEXTDOCUMENTHANDLERCONTROL_H

#include <memory>

#include <QObject>
#include <QMutex>
#include <QVariant>

#include <model/languagemodel.h>

#include <repository/filerepository.h>

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

    Q_INVOKABLE void readFile( const QVariant& file );
    Q_INVOKABLE void writeFile();

signals:
    void textDocumentChanged();

private:
    QQuickTextDocument* _textDocument;
    const LanguageModel* _language;
    std::unique_ptr<SyntaxHighlighterControl> _sqlSyntaxHighlighter;
    QMutex _mutex;
    FileRepository _fileRepository;

    void onSyntaxHighlitherChanged();
};

#endif // TEXTDOCUMENTHANDLERCONTROL_H
