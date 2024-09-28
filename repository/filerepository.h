#ifndef FILEREPOSITORY_H
#define FILEREPOSITORY_H

#include <QFile>
#include <QString>
#include <QTextStream>

class FileRepository {
public:
    FileRepository();
    ~FileRepository();

    void setFilePath( const QString& dsFilePath );
    QString read();
    void write( const QString& dsText );
private:
    QString _dsFilePath;
    QFile _file;
    QTextStream _textStream;
};

#endif // FILEREPOSITORY_H
