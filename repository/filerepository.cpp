#include "filerepository.h"

#include <QDebug>

FileRepository::FileRepository():
    _dsFilePath(""),
    _file(),
    _textStream() {}

FileRepository::~FileRepository() {
    _file.close();
}

void FileRepository::setFilePath( const QString& dsFilePath ) {

    if( _file.isOpen() ){
        _file.close();
    }

    _dsFilePath = dsFilePath;

    _file.setFileName( dsFilePath );

    if(!_file.open( QIODevice::ReadWrite | QIODevice::Text )) {
        qCritical() << "FileRepository::setFilePath falha ao abrir arquivo";
    }

}

QString FileRepository::read() {

    QString resultText = "";

    QTextStream textStream(&_file);

    while( !textStream.atEnd() ) {
        resultText.append( textStream.readLine() );
        resultText.append( "\n" );
    }

    qInfo() << "InputCodeService::writeText [RETURN]" << resultText;

    return resultText;

}

void FileRepository::write( const QString& dsText ) {

    if( !_file.isOpen() ){
        return;
    }

    // Clear text from file
    _file.resize( 0 );

    QTextStream textStream( &_file );

    textStream << dsText;

}
