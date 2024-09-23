#include "selectiondto.h"

SelectionDTO::SelectionDTO( const int idOption, const QString& dsOption, const QString& dsIcon, QObject* model ):
    _model( model ),
    _idOption( idOption ),
    _isSelected( false ),
    _dsOption( dsOption ),
    _dsIcon( dsIcon ){}

int SelectionDTO::idOption() const {
    return _idOption;
}

void SelectionDTO::setIdOption( int idOption ) {

    if ( _idOption == idOption ) {
        return;
    }

    _idOption = idOption;
    emit idOptionChanged();
}

QString SelectionDTO::dsOption() const {
    return _dsOption;
}

void SelectionDTO::setDsOption( const QString &dsOption ) {

    if ( _dsOption == dsOption ) {
        return;
    }

    _dsOption = dsOption;
    emit dsOptionChanged();
}

QString SelectionDTO::dsIcon() const {
    return _dsIcon;
}

void SelectionDTO::setDsIcon( const QString& dsIcon ) {

    if ( _dsIcon == dsIcon ) {
        return;
    }

    _dsIcon = dsIcon;
    emit dsIconChanged();
}

QObject* SelectionDTO::model() const {
    return _model;
}

void SelectionDTO::setModel( QObject* model ) {
    _model = model;
}

bool SelectionDTO::isSelected() const {
    return _isSelected;
}

void SelectionDTO::setIsSelected( bool isSelected ) {

    if ( _isSelected == isSelected ) {
        return;
    }

    _isSelected = isSelected;
    emit isSelectedChanged();
}

