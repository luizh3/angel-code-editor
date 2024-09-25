#ifndef SELECTIONDTO_H
#define SELECTIONDTO_H

#include <QObject>
#include <QString>

class SelectionDTO : public QObject {
    Q_OBJECT
    Q_PROPERTY( int idOption READ idOption WRITE setIdOption NOTIFY idOptionChanged FINAL )
    Q_PROPERTY( QString dsOption READ dsOption WRITE setDsOption NOTIFY dsOptionChanged FINAL )
    Q_PROPERTY( QString dsIcon READ dsIcon WRITE setDsIcon NOTIFY dsIconChanged FINAL )
    Q_PROPERTY( bool isSelected READ isSelected WRITE setIsSelected NOTIFY isSelectedChanged FINAL )
public:
    explicit SelectionDTO( const int idOption, const QString& dsOption, const QString& dsIcon, QObject* model );
    ~SelectionDTO();

    int idOption() const;
    void setIdOption( int idOption );

    QString dsOption() const;
    void setDsOption( const QString &dsOption );

    QString dsIcon() const;
    void setDsIcon( const QString &dsIcon );

    QObject* model() const;
    void setModel( QObject* model );

    bool isSelected() const;
    void setIsSelected( bool isSelected );

    template<typename Model>
    static QList<SelectionDTO*> toSelection( QList<Model*> models, std::function<SelectionDTO*(Model* model)> toCallback ) {

        QList<SelectionDTO*> selectionsDTO = {};

        std::transform( models.begin(), models.end(), std::back_inserter( selectionsDTO ), toCallback );

        return selectionsDTO;
    }

    template<typename Model>
    static Model* selected( QList<SelectionDTO*> selectiosDTO ) {

        auto iterator = std::find_if( selectiosDTO.cbegin(), selectiosDTO.cend(), []( const SelectionDTO* selectionDTO ) {
            return selectionDTO->isSelected();
        } );

        if( iterator == selectiosDTO.cend() ){
            return nullptr;
        }

        QObject* model = static_cast<SelectionDTO*>( *iterator )->model();

        qDeleteAll( selectiosDTO );

        return dynamic_cast<Model*>( model );
    }

signals:
    void idOptionChanged();
    void dsOptionChanged();
    void dsIconChanged();

    void isSelectedChanged();

private:
    QObject* _model;
    int _idOption;
    bool _isSelected;
    QString _dsOption;
    QString _dsIcon;
};

#endif // SELECTIONDTO_H
