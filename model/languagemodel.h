#ifndef LANGUAGEMODEL_H
#define LANGUAGEMODEL_H

#include <QString>
#include <QObject>

class LanguageModel : public QObject {
    Q_OBJECT
    Q_PROPERTY( QString dsName READ dsName CONSTANT );
    Q_PROPERTY( QString dsIcon READ dsIcon CONSTANT );
    Q_PROPERTY( QString dsCompleteFile READ dsCompleteFile CONSTANT );
    Q_PROPERTY( QString dsHighlightFile READ dsHighlightFile CONSTANT );
public:
    LanguageModel();
    LanguageModel( LanguageModel& language );

    QString dsName() const;
    void setDsName( const QString& dsName );

    QString dsIcon() const;
    void setDsIcon( const QString& dsIcon );

    QString dsCompleteFile() const;
    void setDsCompleteFile( const QString& dsCompleteFile );

    QString dsHighlightFile() const;
    void setDsHighlightFile( const QString& dsHighlightFile );

    int idLanguage() const;
    void setIdLanguage( int idLanguage );

private:
    int _idLanguage;
    QString _dsName;
    QString _dsIcon;
    QString _dsCompleteFile;
    QString _dsHighlightFile;
};

#endif // LANGUAGEMODEL_H
