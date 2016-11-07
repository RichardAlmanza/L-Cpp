#ifndef INTRO_H
#define INTRO_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class Intro;
}

class Intro : public QDialog
{
    Q_OBJECT

public:
    explicit Intro(QWidget *parent = 0);
    ~Intro();
    int getvalor();

signals:
    void ingresa();

private slots:
    void Datoingresado();
    void Cancelado();

private:
    Ui::Intro *ui;
    int valor=0;
};

#endif // INTRO_H
