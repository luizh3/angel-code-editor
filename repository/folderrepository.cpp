#include "folderrepository.h"

#include <QDir>
#include <QDebug>

#include <singleton/generalconfigsingleton.h>

 QList<FileModel*> FolderRepository::toFiles( const QString& dsPath, int& nrCurrentIdentifier ) const {

    // TODO change this, valid if FolderDialog return without file:///
    QDir dir( QString( dsPath ).replace( "file:///", "" ) );
    dir.setSorting( QDir::DirsFirst );

    const QStringList allEntries = dir.entryList( QDir::AllEntries | QDir::NoDotAndDotDot );

    QList<ExtensionModel*> extensions = GeneralConfigSingleton::instance().extensions();

    QList<FileModel*> files = {};

    for ( const QString& dsFile : allEntries ) {

        const QString dsPath = dir.absoluteFilePath(dsFile);

        QFileInfo fileInfo( dsPath );

        const bool isDir = fileInfo.isDir();

        FileModel* file = new FileModel();
        file->setIdFile( nrCurrentIdentifier );
        file->setDsName( dsFile );
        file->setDsPath( dsPath );
        file->setDsIcon( dsIcon( extensions, dsFile, isDir ) ) ;

        files.append( file );

        nrCurrentIdentifier++;

        qInfo() << "FolderRepository::toFiles [DS_PATH]" << dsPath << "[DS_NAME]" << dsFile << "[IS_DIR]" << isDir;

        if ( isDir ) {
            file->setFiles( toFiles( fileInfo.absoluteFilePath(), nrCurrentIdentifier ) );
            continue;
        }

    }

    return files;
 }

 QString FolderRepository::dsIcon( const QList<ExtensionModel*>& extensions, const QString& dsFile, const bool isFolder ) const {

    auto iterator = std::find_if( extensions.cbegin(), extensions.cend(), [dsFile]( const ExtensionModel* extension ) {
         return extension->pattern().match( dsFile ).hasMatch();
     } );

    if( iterator != extensions.cend() ){
        return ( *iterator )->dsIcon();
    }

    // TODO change this for use dynamic icons

    if( isFolder ) {
        return "folder.png";
    }

    return "file.png";

 }
