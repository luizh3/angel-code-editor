#ifndef EXTENSIONMODEL_H
#define EXTENSIONMODEL_H

#include <QRegularExpression>

class ExtensionModel {
public:
    ExtensionModel();

    QString dsName() const;
    void setDsName( const QString& dsName );

    QString dsIcon() const;
    void setDsIcon( const QString& dsIcon );

    QRegularExpression pattern() const;
    void setPattern( const QRegularExpression& pattern );

private:
    QString _dsName;
    QString _dsIcon;
    QRegularExpression _pattern;
};

#endif // EXTENSIONMODEL_H
