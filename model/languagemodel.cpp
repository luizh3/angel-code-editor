#include "languagemodel.h"

LanguageModel::LanguageModel() {}

QString LanguageModel::dsName() const {
    return _dsName;
}

void LanguageModel::setDsName( const QString &dsName ) {
    _dsName = dsName;
}

QString LanguageModel::dsIcon() const {
    return _dsIcon;
}

void LanguageModel::setDsIcon( const QString &dsIcon ) {
    _dsIcon = dsIcon;
}

QString LanguageModel::dsCompleteFile() const {
    return _dsCompleteFile;
}

void LanguageModel::setDsCompleteFile( const QString& dsCompleteFile ) {
    _dsCompleteFile = dsCompleteFile;
}

QString LanguageModel::dsHighlightFile() const {
    return _dsHighlightFile;
}

void LanguageModel::setDsHighlightFile( const QString& dsHighlightFile ) {
    _dsHighlightFile = dsHighlightFile;
}
