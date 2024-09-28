#ifndef FOLDERREPOSITORY_H
#define FOLDERREPOSITORY_H

#include <model/filemodel.h>
#include <model/extensionmodel.h>

class FolderRepository {
public:
    QList<FileModel*> toFiles( const QString& dsPath, int& nrCurrentIdentifier ) const;
private:
    QString dsIcon( const QList<ExtensionModel*>& extensions, const QString& dsFile, const bool isFolder ) const;
};

#endif // FOLDERREPOSITORY_H
