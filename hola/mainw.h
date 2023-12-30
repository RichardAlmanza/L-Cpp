#ifndef MAINW_H
#define MAINW_H

#include <QMainWindow>

namespace Ui {
class MainW;
}

class MainW : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainW(QWidget *parent = 0);
    ~MainW();

private:
    Ui::MainW *ui;
};

#endif // MAINW_H
