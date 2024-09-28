#include "foldercontrol.h"

#include <repository/folderrepository.h>

void FolderControl::open( const QString& dsPath ) {

    qDeleteAll( _files );

    int nrCurrentIdentifier = 1;

    _files = FolderRepository().toFiles( dsPath, nrCurrentIdentifier);

    emit filesChanged( QVariant::fromValue( _files ) );
}
