#ifndef MAINW_H
#define MAINW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>
#include <list>
#include "fisica.h"
#include "intro.h"

namespace Ui {
class MainW;
}

class MainW : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainW(QWidget *parent = 0);
    ~MainW();


private slots:
    void on_actionEmpezar_triggered();

    void on_actionSalir_triggered();

    void Crear();

    void Actualizar();

    void on_actionReinicar_triggered();

private:
    Ui::MainW *ui;
    Intro *dato=Q_NULLPTR;
    QGraphicsScene *scene=Q_NULLPTR;
    QTimer *timer=Q_NULLPTR;
    std::list < fisica*> sistema;
    int cuerpos=0;
};

#endif // MAINW_H
