#ifndef QVISTA_H
#define QVISTA_H
#include <QGraphicsView>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QDebug>

class QVista : public QGraphicsView
{
    Q_OBJECT
public:
    explicit QVista(QWidget *parent = Q_NULLPTR);
    explicit QVista(QGraphicsScene *scene, QWidget *parent = Q_NULLPTR);
    ~QVista();
    void wheelEvent(QWheelEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    QPoint get_P_move();
    QPoint get_P_ini();
    QPoint get_P_fin();

signals:
    void Zoomin();
    void Zoomout();
    void draggmouse();
    void release_left();
    QPoint release_right(QPoint);

private:
    QPoint PO,PO2,PM,PF;
};

#endif // QVISTA_H
