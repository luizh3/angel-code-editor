#ifndef CONTROL_H
#define CONTROL_H

#include <QObject>
#include <QVariant>
#include <QEventLoop>

#include "dto/selectiondto.h"

class Control : public QObject {
    Q_OBJECT
protected:
    bool waitConfirm() const;

    template<typename Model>
    Model* select( const QList<Model*>& models, std::function<SelectionDTO*(Model* model)> callbackConverter ) {

        QList<SelectionDTO*> dtos = toSelectionDTO<Model>( models, callbackConverter );

        emit selectOption( QVariant::fromValue( dtos ) );

        const bool isConfirmed = waitConfirm();

        if( !isConfirmed ){
            qDeleteAll( dtos );
            return nullptr;
        }

        return SelectionDTO::selected<Model>( dtos );
    }

    template<typename Model>
    QList<SelectionDTO*> toSelectionDTO( const QList<Model*>& models, std::function<SelectionDTO*(Model* model)> callbackConverter ) const {
        return SelectionDTO::toSelection<Model>( models, callbackConverter );
    };
signals:
    void confirmed( const bool isConfirmed );
    void selectOption( const QVariant& options );
};

#endif // CONTROL_H
