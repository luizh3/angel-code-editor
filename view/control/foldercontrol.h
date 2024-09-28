#ifndef FOLDERCONTROL_H
#define FOLDERCONTROL_H

#include <QObject>
#include <QVariant>

#include <model/filemodel.h>

class FolderControl : public QObject {
    Q_OBJECT
public:
    Q_INVOKABLE void open( const QString& dsPath );
signals:
    void filesChanged( const QVariant& files );
private:
    QList<FileModel*> _files;
};

#endif // FOLDERCONTROL_H
