#include "languagemodel.h"

#include <QQmlEngine>

LanguageModel::LanguageModel() :
    _idLanguage( 0 ),
    _dsName( "" ),
    _dsIcon( "" ),
    _dsCompleteFile( "" ),
    _dsHighlightFile( "" ){

    QQmlEngine::setObjectOwnership( this, QQmlEngine::CppOwnership );
}

LanguageModel::LanguageModel( LanguageModel& language ) :
    QObject(),
    _idLanguage( language.idLanguage() ),
    _dsName( language.dsName() ),
    _dsIcon( language.dsIcon() ),
    _dsCompleteFile( language.dsCompleteFile() ),
    _dsHighlightFile( language.dsHighlightFile() ){}

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

int LanguageModel::idLanguage() const {
    return _idLanguage;
}

void LanguageModel::setIdLanguage( int idLanguage ) {
    _idLanguage = idLanguage;
}
