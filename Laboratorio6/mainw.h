#ifndef MAINW_H
#define MAINW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>
#include <QFileDialog>
#include <QKeyEvent>
#include <list>
#include "fisica.h"
#include "intro.h"
#include "pend.h"
#include "objetos.h"

namespace Ui {
class MainW;
}

class MainW : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainW(QWidget *parent = 0);
    void keyReleaseEvent(QKeyEvent *event);
    ~MainW();

private slots:
    void Actualizar();

    void Crear();

    void Cerrar();

    void on_actionSalir_triggered();

    void on_actionReiniciar_triggered();

    void on_actionCrear_triggered();

    void Zoom_in();

    void Zoom_out();

    void Moved();

    void Pendulo();

    void C_Pendulo(QPoint a);

    void on_checkBox_toggled(bool checked);

private:
    Ui::MainW *ui;
    Intro *dato=Q_NULLPTR;
    QGraphicsScene *scene=Q_NULLPTR;
    QGraphicsScene *scene2=Q_NULLPTR;
    QTimer *timer=Q_NULLPTR;
    std::list < fisica*> sistema;
    std::list < Pend*> sistema2;
    std::list < Objetos*> sistema3;
    QString name_save, name_read;
    int cuerpos=0, cuerpos2=0, zoom=0;
    double scale=1.2;
};

#endif // MAINW_H
