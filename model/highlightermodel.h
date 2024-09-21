#ifndef HIGHLIGHTERMODEL_H
#define HIGHLIGHTERMODEL_H

#include <QTextCharFormat>
#include <QRegularExpression>

class HighlighterModel {
public:
    HighlighterModel();

    QRegularExpression pattern() const;
    void setPattern( const QRegularExpression& pattern );

    QTextCharFormat format() const;
    void setFormat( const QTextCharFormat& format );

    QStringList words() const;
    void setWords( const QStringList& words );

private:
    QRegularExpression _pattern;
    QTextCharFormat _format;
    QStringList _words;
};

#endif // HIGHLIGHTERMODEL_H
