#ifndef SYNTAXHIGHLIGHTERCONTROL_H
#define SYNTAXHIGHLIGHTERCONTROL_H

#include <QJsonDocument>
#include <QSyntaxHighlighter>

#include <model/highlightermodel.h>

class SyntaxHighlighterControl : public QSyntaxHighlighter {
    Q_OBJECT
public:
    explicit SyntaxHighlighterControl( QTextDocument* textDocument, const QList<HighlighterModel*>& rules );
    ~SyntaxHighlighterControl();
protected:
    void highlightBlock( const QString& text );
private:
    const QList<HighlighterModel*> _rules;

    QJsonDocument getConfigs( const QString& dsFile ) const;
    void configsToRules( const QJsonDocument& document );

};

#endif // SYNTAXHIGHLIGHTERCONTROL_H
