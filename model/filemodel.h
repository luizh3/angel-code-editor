#ifndef FILEMODEL_H
#define FILEMODEL_H

#include <QList>
#include <QObject>

class FileModel : public QObject {
    Q_OBJECT
    Q_PROPERTY( int idFile READ idFile WRITE setIdFile NOTIFY idFileChanged FINAL )
    Q_PROPERTY( QList<FileModel*> files READ files WRITE setFiles NOTIFY filesChanged FINAL )
    Q_PROPERTY( bool isFolder READ isFolder CONSTANT )
    Q_PROPERTY( QString dsName READ dsName WRITE setDsName NOTIFY dsNameChanged FINAL )
    Q_PROPERTY( QString dsIcon READ dsIcon WRITE setDsIcon NOTIFY dsIconChanged FINAL )
    Q_PROPERTY( QString dsPath READ dsPath WRITE setDsPath NOTIFY dsPathChanged FINAL )
public:
    FileModel();

    QList<FileModel*> files() const;
    void setFiles( const QList<FileModel*>& files );

    bool isFolder() const;

    QString dsName() const;
    void setDsName( const QString& dsName );

    QString dsIcon() const;
    void setDsIcon( const QString& dsIcon );

    QString dsPath() const;
    void setDsPath( const QString& dsPath );

    int idFile() const;
    void setIdFile(int idFile);

signals:
    void filesChanged();
    void dsNameChanged();
    void dsIconChanged();
    void dsPathChanged();
    void idFileChanged();

private:
    int _idFile;
    QString _dsPath;
    QString _dsIcon;
    QString _dsName;
    QList<FileModel*> _files;
};

#endif // FILEMODEL_H
