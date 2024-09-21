#include "highlightermodel.h"

HighlighterModel::HighlighterModel() :
    _pattern(),
    _format(),
    _words() {}

QRegularExpression HighlighterModel::pattern() const {
    return _pattern;
}

void HighlighterModel::setPattern( const QRegularExpression& pattern ) {
    _pattern = pattern;
}

QTextCharFormat HighlighterModel::format() const {
    return _format;
}

void HighlighterModel::setFormat( const QTextCharFormat& format ) {
    _format = format;
}

QStringList HighlighterModel::words() const {
    return _words;
}

void HighlighterModel::setWords( const QStringList& words ) {
    _words = words;
}
