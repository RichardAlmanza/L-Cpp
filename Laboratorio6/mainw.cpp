#include "mainw.h"
#include "ui_mainw.h"

MainW::MainW(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainW)
{
    ui->setupUi(this);
    dato=new Intro(this);
    dato->hide();
    connect(dato,SIGNAL(ingresa()),this,SLOT(Crear()));
    connect(dato,SIGNAL(cancela()),this,SLOT(Cerrar()));
    connect(ui->grafica,SIGNAL(Zoomin()),this,SLOT(Zoom_in()));
    connect(ui->grafica,SIGNAL(Zoomout()),this,SLOT(Zoom_out()));
    connect(ui->grafica,SIGNAL(draggmouse()),this,SLOT(Moved()));
    connect(ui->grafica_2,SIGNAL(release_left()),this,SLOT(Pendulo()));
    connect(ui->grafica_2,SIGNAL(release_right(QPoint)),this,SLOT(C_Pendulo(QPoint)));
    scene=new QGraphicsScene;
    scene2=new QGraphicsScene;
    timer=new QTimer;
    ui->grafica->setScene(scene);
    ui->grafica_2->setScene(scene2);
    scene->setSceneRect(-500,-250,1002,502);
    scene2->setSceneRect(0,0,1002,502);
    connect(timer,SIGNAL(timeout()),this,SLOT(Actualizar()));
    timer->setSingleShot(false);
    timer->start(1);
}

void MainW::keyReleaseEvent(QKeyEvent *event)//Para tab lab 4
{
    if(ui->tabWidget->currentIndex()==0)
    {
        if(event->key()==Qt::Key_Space)
            scene->setSceneRect(-500,-250,1002,502);
    }
}

MainW::~MainW()
{
    delete ui;
}


void MainW::Actualizar()
{
    if(ui->tabWidget->currentIndex()==0)
    {
        for(std::list<fisica*>::iterator it=sistema.begin(); it!=sistema.end();++it)
            (*it)->calc_a(&sistema);
        for(std::list<fisica*>::iterator it=sistema.begin(); it!=sistema.end();++it)
            (*it)->actualizar();
    }
    else if(ui->tabWidget->currentIndex()==1)
    {
        for(std::list<Pend*>::iterator it=sistema2.begin();it!=sistema2.end();++it)
            (*it)->actualizar();
        for(std::list<Objetos*>::iterator it=sistema3.begin();it!=sistema3.end();++it)
            (*it)->girar();
    }
}

void MainW::Crear()
{
    dato->hide();
    int n=dato->getvalor(); bool all=false;
    if(n!=-1)
    {
        name_read=QFileDialog::getOpenFileName(this,tr("Archivo de Cuerpos"), ".//cuerpos//new//sistema.txt","Text File (*.txt)");
        QStringList lista;
        QFile file(name_read);
        lista=name_read.split("\/");
        name_read=lista.back();
        if(n==0)
            all=true;
        if(file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            while(all || n>0)
            {
                if(!all)
                    n--;
                name_save=file.readLine(1000);
                lista=name_save.split(",");
                if(lista.size()>=6)
                {
                    sistema.push_back(new fisica((lista.at(0)).toDouble(),(lista.at(1)).toDouble(),(lista.at(2)).toDouble(),(lista.at(3)).toDouble(),(lista.at(4)).toDouble(),(lista.at(5)).toDouble()));
                    scene->addItem(sistema.back());
                }
                else
                {
                    break;
                }
            }
            file.close();
        }
    }
    else
    {
        qDebug()<<name_read;
        name_save=QFileDialog::getSaveFileName(this,tr("Guardar"),QString(".//cuerpos//save//%1").arg(name_read),"Text File (*.txt)");
        QFile file(name_save);
        QTextStream out(&file);
        if(file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            for(std::list<fisica*>::iterator it=sistema.begin(); it!=sistema.end();++it)
                (*it)->save(&out);
        }
        file.close();
    }
    connect(timer,SIGNAL(timeout()),this,SLOT(Actualizar()));
}

void MainW::Cerrar()
{
    dato->hide();
    connect(timer,SIGNAL(timeout()),this,SLOT(Actualizar()));
}

void MainW::on_actionSalir_triggered()
{
    this->close();
}

void MainW::on_actionReiniciar_triggered()
{
    if(ui->tabWidget->currentIndex()==0)
    {
        cuerpos=0;
        sistema.clear();
        scene=new QGraphicsScene;
        ui->grafica->setScene(scene);
        ui->grafica->scale(pow(scale,zoom),pow(scale,zoom));
        zoom=0;
        scene->setSceneRect(-500,-250,1002,502);
    }
    else if(ui->tabWidget->currentIndex()==1)
    {
        cuerpos2=0;
        sistema2.clear();
        scene2=new QGraphicsScene;
        ui->grafica_2->setScene(scene2);
        scene2->setSceneRect(0,0,1002,502);
    }
}

void MainW::on_actionCrear_triggered()
{
    if(ui->tabWidget->currentIndex()==0)
    {
        disconnect(timer,SIGNAL(timeout()),this,SLOT(Actualizar()));
        dato->show();
    }
}

void MainW::Zoom_in()//Para tab lab 4
{
    ui->grafica->scale(scale,scale);
    zoom--;
}


void MainW::Zoom_out()//Para tab lab 4
{
    ui->grafica->scale(1/scale,1/scale);
    zoom++;
}

void MainW::Moved()//Para tab lab 4
{
    QRectF *rec= new QRectF(scene->sceneRect());
    rec->translate((ui->grafica->get_P_move()).x()*pow(scale,zoom),(ui->grafica->get_P_move()).y()*pow(scale,zoom));
    scene->setSceneRect(*rec);
}

void MainW::Pendulo()
{
    QPoint *punto1=new QPoint(),*punto2=new QPoint();
    *punto1=ui->grafica_2->get_P_ini();
    *punto2=ui->grafica_2->get_P_fin();
    double dist=sqrt(pow(punto1->x()-punto2->x(),2)+pow(punto1->y()-punto2->y(),2));
    if(dist>=5)
    {
        sistema2.push_back(new Pend(atan2(punto2->y()-punto1->y(),punto2->x()-punto1->x()),dist,punto1->x(),punto1->y(),ui->vel_ang->value()));
        sistema3.push_back(new Objetos(sistema2.back()));
        scene2->addItem(sistema3.back());
        if(!(ui->checkBox->isChecked()))
            sistema3.back()->setOpacity(0);
        scene2->addItem(sistema2.back());
    }
}

void MainW::C_Pendulo(QPoint a)
{
    QPoint *punto1=new QPoint(a.x(),a.y()),*punto2=new QPoint();
    *punto1=ui->grafica_2->get_P_ini();
    *punto2=ui->grafica_2->get_P_fin();
    double dist=sqrt(pow(punto1->x()-punto2->x(),2)+pow(punto1->y()-punto2->y(),2));
    if(dist>=5)
    {
        sistema2.push_back(new Pend(atan2(punto2->y()-punto1->y(),punto2->x()-punto1->x()),dist,punto1->x(),punto1->y(),ui->vel_ang->value()));
        sistema3.push_back(new Objetos(sistema2.back()));
        scene2->addItem(sistema3.back());
        if(!(ui->checkBox->isChecked()))
            sistema3.back()->setOpacity(0);
        scene2->addItem(sistema2.back());
    }
}

void MainW::on_checkBox_toggled(bool checked)
{
    if(checked)
    {
        for(std::list<Objetos*>::iterator it=sistema3.begin();it!=sistema3.end();++it)
            (*it)->setOpacity(1);
    }
    else
    {
        for(std::list<Objetos*>::iterator it=sistema3.begin();it!=sistema3.end();++it)
            (*it)->setOpacity(0);
    }
}
