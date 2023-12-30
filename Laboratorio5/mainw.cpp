#include "mainw.h"
#include "ui_mainw.h"

MainW::MainW(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainW),
    cuerpos(0)
{
    ui->setupUi(this);
    dato=new Intro(this);
    connect(dato,SIGNAL(ingresa()),this,SLOT(Crear()));
    dato->hide();
    scene=new QGraphicsScene;
    timer=new QTimer;
    ui->grafica->setScene(scene);
    scene->setSceneRect(0,0,1002,502);
    scene->addRect(scene->sceneRect());
    connect(timer,SIGNAL(timeout()),this,SLOT(Actualizar()));
    timer->setSingleShot(false);
    timer->start(1);
}

MainW::~MainW()
{
    delete ui;
}


void MainW::Crear()
{
    int valor=(dato->getvalor());
    double *ptr=new double [8];
    for(int i=0; i<valor;i++)
    {
        *ptr=rand()%900+31;
        *(ptr+1)=rand()%400+52;
        *(ptr+2)=rand()%300;
        *(ptr+3)=(rand()%180)*3.141598/180;
        *(ptr+4)=rand()%26+5;
        *(ptr+5)=rand()%551+50;
        *(ptr+6)=0;
        *(ptr+7)=(float(rand()%10001)/20000)+0.5;
        sistema.push_back(new fisica(*ptr,*(ptr+1),*(ptr+2),*(ptr+3),*(ptr+4),*(ptr+5),*(ptr+6),*(ptr+7)));
        scene->addItem(sistema.back());
        cuerpos++;
        qDebug()<<"Cuerpos creados "<<"<< "<<cuerpos<<" >>";
    }
}

void MainW::Actualizar()
{
    for(std::list<fisica*>::iterator it=sistema.begin(); it!=sistema.end();++it)
        (*it)->actualizar();
}

void MainW::on_actionEmpezar_triggered()
{
    dato->show();
}

void MainW::on_actionSalir_triggered()
{
    this->close();
}

void MainW::on_actionReinicar_triggered()
{
    cuerpos=0;
    sistema.clear();
    scene=new QGraphicsScene;
    ui->grafica->setScene(scene);
    scene->setSceneRect(0,0,1002,502);
    scene->addRect(scene->sceneRect());
}
