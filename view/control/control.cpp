#include "control.h"

#include <QEventLoop>

#include <QDebug>

bool Control::waitConfirm() const {

    QEventLoop wait;
    QObject::connect( this, &Control::confirmed, &wait, &QEventLoop::exit );

    const bool isConfirmed = wait.exec();

    qInfo() << "Control::waitConfirm [IS_CONFIRMED]" << isConfirmed;

    return isConfirmed;
}
