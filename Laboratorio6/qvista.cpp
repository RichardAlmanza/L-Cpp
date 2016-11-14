#include "qvista.h"

QVista::QVista(QWidget *parent)
    :QGraphicsView(parent)
{

}

QVista::QVista(QGraphicsScene *scene, QWidget *parent)
    :QGraphicsView(scene, parent)
{

}

QVista::~QVista()
{
    this->close();
}

void QVista::wheelEvent(QWheelEvent *event)
{
    QPoint numDegrees = event->angleDelta() / 8;
    if (!numDegrees.isNull())
    {
        QPoint numSteps = numDegrees / 15;
        if(numSteps.y()<0)
            emit Zoomout();
        else
            emit Zoomin();
    }
}

void QVista::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons()==Qt::LeftButton)
    {
        PF=event->pos();
        PM.setX(PO2.x()-PF.x());
        PM.setY(PO2.y()-PF.y());
        emit draggmouse();
    }
    else
        PO=event->pos();
    PO2=event->pos();
}

void QVista::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->buttons()!=Qt::LeftButton)
        emit release_left();
}

QPoint QVista::get_P_move()
{
    return PM;
}

QPoint QVista::get_P_ini()
{
    return PO;
}

QPoint QVista::get_P_fin()
{
    return PF;
}


