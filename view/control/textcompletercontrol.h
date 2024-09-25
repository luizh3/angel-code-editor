#ifndef TEXTCOMPLETERCONTROL_H
#define TEXTCOMPLETERCONTROL_H

#include <QObject>
#include <QPoint>
#include <QQuickTextDocument>

#include <model/languagemodel.h>

class TextCompleterControl : public QObject {
    Q_OBJECT
    Q_PROPERTY( QStringList sugestions READ sugestions WRITE setSugestions NOTIFY sugestionsChanged FINAL );
    Q_PROPERTY( QPoint currentPosition READ currentPosition WRITE setCurrentPosition NOTIFY currentPositionChanged FINAL )
    Q_PROPERTY( QQuickTextDocument* textDocument READ textDocument WRITE setTextDocument NOTIFY textDocumentChanged FINAL )
public:
    TextCompleterControl();

    QStringList sugestions() const;
    void setSugestions( const QStringList &sugestions );

    QPoint currentPosition() const;
    void setCurrentPosition( QPoint currentPosition );

    QQuickTextDocument* textDocument() const;
    void setTextDocument( QQuickTextDocument* textDocument );

    Q_INVOKABLE void completeSugestion( const QString& word );
    Q_INVOKABLE void languageChanged( const LanguageModel* language );

signals:
    void sugestionsChanged();
    void currentPositionChanged();
    void textDocumentChanged();

private:
    QQuickTextDocument* _textDocument;
    QPoint _currentPosition;
    QStringList _sugestions;
    QSet<QString> _wordList;

    QStringList wordsByPart( const QString& part ) const;
    QStringList suggestionsByLineAndPosition() const;
};

#endif // TEXTCOMPLETERCONTROL_H
