#include "filemodel.h"

#include <QQmlEngine>

FileModel::FileModel() :
    _idFile( 0 ),
    _dsPath( "" ),
    _dsIcon( "" ),
    _dsName( "" ),
    _files( {} ){

    QQmlEngine::setObjectOwnership( this, QQmlEngine::CppOwnership );
}

QList<FileModel*> FileModel::files() const {
    return _files;
}

void FileModel::setFiles( const QList<FileModel*>& files ) {

    if ( _files == files ) {
        return;
    }

    _files = files;
    emit filesChanged();
}

bool FileModel::isFolder() const {
    return !_files.isEmpty();
}

QString FileModel::dsName() const {
    return _dsName;
}

void FileModel::setDsName( const QString& dsName ) {

    if (_dsName == dsName) {
        return;
    }

    _dsName = dsName;
    emit dsNameChanged();
}

QString FileModel::dsIcon() const {
    return _dsIcon;
}

void FileModel::setDsIcon( const QString &dsIcon ) {

    if (_dsIcon == dsIcon) {
        return;
    }

    _dsIcon = dsIcon;
    emit dsIconChanged();
}

QString FileModel::dsPath() const {
    return _dsPath;
}

void FileModel::setDsPath( const QString& dsPath ) {

    if (_dsPath == dsPath) {
        return;
    }

    _dsPath = dsPath;
    emit dsPathChanged();
}

int FileModel::idFile() const {
    return _idFile;
}

void FileModel::setIdFile( int idFile ) {

    if ( _idFile == idFile ) {
        return;
    }

    _idFile = idFile;
    emit idFileChanged();
}
