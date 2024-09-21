#ifndef FILEHELPER_H
#define FILEHELPER_H

#include <QString>

class FileHelper {
public:
    FileHelper();

    static QString absolutePathApplication();
    static QString toAbsolutePath( const QList<QString>& directorys, const QString& path = absolutePathApplication() );

};

#endif // FILEHELPER_H
