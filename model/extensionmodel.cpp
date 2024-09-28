#include "extensionmodel.h"

ExtensionModel::ExtensionModel() :
    _dsName( "" ),
    _dsIcon( "" ),
    _pattern(){}

QString ExtensionModel::dsName() const
{
    return _dsName;
}

void ExtensionModel::setDsName( const QString& dsName ) {
    _dsName = dsName;
}

QString ExtensionModel::dsIcon() const {
    return _dsIcon;
}

void ExtensionModel::setDsIcon( const QString& dsIcon ) {
    _dsIcon = dsIcon;
}

QRegularExpression ExtensionModel::pattern() const {
    return _pattern;
}

void ExtensionModel::setPattern( const QRegularExpression& pattern ) {
    _pattern = pattern;
}
