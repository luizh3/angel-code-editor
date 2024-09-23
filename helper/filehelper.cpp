#include "filehelper.h"

#include <QDir>
#include <QDebug>
#include <QCoreApplication>

QString FileHelper::absolutePathApplication() {

    const QList<QString> DIRECTORYS_INVALIDS = {
        "/debug",
        "/build"
    };

    QString path = QDir::fromNativeSeparators( QCoreApplication::applicationDirPath());

    for( const QString& current: DIRECTORYS_INVALIDS ){
        path.replace( current, "" );
    }

    return QDir::toNativeSeparators( path );

}

QString FileHelper::toAbsolutePath( const QList<QString>& directorys, const QString& path ) {

    qInfo() << "FileHelper::toAbsolutePath [DIRECTORYS]" << directorys << "[PATH]" << path;

    QString currentPath = path;

    for( const QString& directory : directorys ){
        currentPath.append( QString( "/%0" ).arg( directory ) );
    }

    const QString result = QDir::toNativeSeparators( currentPath );

    qInfo() << "FileHelper::toAbsolutePath [RETURN]" << result;

    return result;

}
