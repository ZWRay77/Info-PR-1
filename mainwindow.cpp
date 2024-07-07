#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "city.h"
#include "dialog.h"
#include "street.h"
#include "dijkstra.h"
#include "motorway.h"
#include "mapio.h"

#include <QDebug>
#include <QMessageBox>
#include <QRandomGenerator>
#include <QMouseEvent>
#include <QGraphicsView>
#include <QPoint>
#include <QGraphicsItem>
#include <QRect>
#include <QSize>
#include <QFileDialog>
#include <QStandardPaths>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(&scene);
    mapio = new MapIoNrw();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_test_clicked()
{
    qDebug()<<"Sie haben den Knopf geklickt.";

    QString str;
    str=ui->lineEdit_test->text();
    QString str1;
    str1=QString("der von Ihnen eingegebene Text ist:%1.").arg(str);
    qDebug()<<str1;

    int a;
    bool ok;
    a=str.toInt(&ok);
    if(ok==true)
    {
        qDebug()<<"Ist Zahl:"<< a;
        a=a+4;
        qDebug()<<"a+4="<<a;
    }
    else{
        qDebug()<<"Der eingegebene Text ist keine Zahl.";
    }

    int x=0;
    int y=0;
    x=rand()*9/RAND_MAX;
    y=rand()*9/RAND_MAX;
    scene.addRect(x,y,30,10,QPen(Qt::yellow),QBrush(Qt::yellow,Qt::SolidPattern));
    scene.addRect(x,y-10,30,10,QPen(Qt::blue),QBrush(Qt::blue,Qt::SolidPattern));

    City city1=City("city1",200,100);
    city1.draw(scene);

}


void MainWindow::on_actionExit_triggered()
{
    close();
}


void MainWindow::on_actionClear_Scene_triggered()
{
    scene.clear();
}


void MainWindow::on_actionAbout_triggered()
{
    QMessageBox msgBox;
    msgBox.about(this,"the Application","this programm is from Wangrui");
}


void MainWindow::on_testDrawCityButton_clicked()
{
    City newCity1=City("newCity1",100,200);
    newCity1.draw(scene);

    City newCity2=City("newCity2",200,100);
    newCity2.draw(scene);

    qDebug()<<"Zwei Staedte werden gezeichnet.";
}

void MainWindow::on_tesDrawtMapButton_clicked()
{
    //some Cities for testing
    City *c1 = new City("c1", 20, 50);
    City *c2 = new City("c2", 234, 125);
    City *c3 = new City("c3", -284, 243);
    City *c4 = new City("c4", -203, 50);
    City *c5 = new City("c5", 200, -100);
    map.addCity(c1);
    map.addCity(c2);
    map.addCity(c3);
    map.addCity(c4);
    map.addCity(c5);
    //some Streets to connect
    Street *s1 = new Street(c1, c2);
    Street *s2 = new Street(c2, c3);
    Street *s3 = new Street(c3, c4);
    Street *s4 = new Street(c4, c5);
    Street *s5 = new Street(c5, c1);
    Street *s6 = new Street(c1, c3);
    Street *s7 = new Street(c2, c4);
    Street *s8 = new Street(c3, c5);
    Street *s9 = new Street(c4, c1);
    Street *s10 = new Street(c5, c2);
    map.addStreet(s1);
    map.addStreet(s2);
    map.addStreet(s3);
    map.addStreet(s4);
    map.addStreet(s5);
    map.addStreet(s6);
    map.addStreet(s7);
    map.addStreet(s8);
    map.addStreet(s9);
    map.addStreet(s10);
    map.draw(scene);
}


void MainWindow::on_testDrawStreetButton_clicked()
{
    City *c1 = new City("c1", 20,50);
    City *c2 = new City("c2", 200, 100);
    Street *s1 = new Street(c1, c2);
    c1->draw(scene);
    c2->draw(scene);
    s1->draw(scene);
}

void MainWindow::on_checkBoxTest_clicked()
{
    if(ui->checkBoxTest->isChecked()==true)
    {
        ui->testDrawCityButton->hide();
        ui->tesDrawtMapButton->hide();
        ui->testDrawStreetButton->hide();
        ui->testAbstractMap->hide();
        ui->testDijkstra->hide();
    }
    else if(ui->checkBoxTest->isChecked()==false)
    {
        ui->testDrawCityButton->show();
        ui->tesDrawtMapButton->show();
        ui->testDrawStreetButton->show();
        ui->testAbstractMap->show();
        ui->testDijkstra->show();
    }
}


void MainWindow::on_AddCity_clicked()
{
    Dialog newDialog;

    int i = newDialog.exec();
    qDebug()<<"Der Rueckgabewert:"<<i;

    if (i==1) {
        City*gorad=newDialog.newCity();
        map.addCity(gorad);
        gorad->draw(scene);
    }

    else
    {
        qDebug()<<"Keine neue Stadt wurde hinzugefuegt.";
    }


}


void MainWindow::on_fillMap_clicked()
{
    mapio->fillMap(map);
    map.draw(scene);
}


void MainWindow::on_AddStreet_clicked()
{
    Dialog newDialog;
    int i = newDialog.exec();
    qDebug() << "Der Rückgabewert: " << i;

    if (i == 1)
    {
        QString Name1 = newDialog.getCity1Name();
        QString Name2 = newDialog.getCity2Name();

        if(map.findCity(Name1) == nullptr || map.findCity(Name2) == nullptr)
        {
            qDebug() << "please enter valid cities!";
            return;
        }
        else
        {
            City* newCity1 = map.findCity(Name1);
            City* newCity2 = map.findCity(Name2);

            Street* strasse1 = new Street(newCity1, newCity2);
            if(map.addStreet(strasse1))
            {
                strasse1->draw(scene);
            }
        }
    }
    else
    {
        qDebug() << "No new street has been added!";
    }
}



void MainWindow::on_testAbstractMap_clicked()
{
    Map testMap;
    City *a = new City("a", 0, 0);
    City *b = new City("b", 0, 100);
    City *c = new City("c", 100, 300);
    Street *s = new Street(a, b);
    Street *s2 = new Street(b, c);


    qDebug() << "MapTest: Start Test of the Map";
    {
        qDebug() << "MapTest: adding wrong street";
        bool t1 = testMap.addStreet(s);
        if (t1) {
            qDebug() << "-Error: Street should not bee added, if cities have not been added.";
        }
    }

    {
        qDebug() << "MapTest: adding correct street";
        testMap.addCity(a);
        testMap.addCity(b);
        bool t1 = testMap.addStreet(s);
        if (!t1) {
            qDebug() << "-Error: It should be possible to add this street.";
        }
    }

    {
        qDebug() << "MapTest: findCity";
        City* city = testMap.findCity("a");
        if (city != a)
            qDebug() << "-Error: City a could not be found.";

        city = testMap.findCity("b");
        if (city != b)
            qDebug() << "-Error: City b could not be found.";

        city = testMap.findCity("c");
        if (city != nullptr)
            qDebug() << "-Error: If city could not be found 0 should be returned.";
    }

    testMap.addCity(c);
    testMap.addStreet(s2);

    {
        qDebug() << "MapTest: getOppositeCity";
        const City *city = testMap.getOppositeCity(s, a);
        if (city != b)
            qDebug() << "-Error: Opposite city should be b.";

        city = map.getOppositeCity(s, c);
        if (city != nullptr)
            qDebug() << "-Error: Opposite city for a city which is not linked by given street should be 0.";
    }

    {
        qDebug() << "MapTest: streetLength";
        double l = testMap.getLength(s2);
        double expectedLength = 223.6;
        // compare doubles with 5% tolerance
        if (l < expectedLength * 0.95 || l > expectedLength *1.05)
            qDebug() << "-Error: Street Length is not equal to the expected.";

    }

    {
        qDebug() << "MapTest: getStreetList";
        QVector<Street*> streetList1 = testMap.getStreetList(a);
        QVector<Street*> streetList2 = testMap.getStreetList(b);
        if (streetList1.size() != 1) {
            qDebug() << "-Error: One street should be found for city a.";
        }
        else if (*streetList1.begin() != s) {
            qDebug() << "-Error: The wrong street has been found for city a.";
        }

        if (streetList2.size() != 2)
            qDebug() << "-Error: Two streets should be found for city b.";
    }

    qDebug() << "MapTest: End Test of the Map.";
}


void MainWindow::on_addMotorWay_clicked()
{
    City*newCity1=new City("CoolCity1",10,20);
    City*newCity2=new City("CoolCity2",80,10);
    Motorway*way1=new Motorway(newCity1,newCity2);
    newCity1->draw(scene);
    newCity2->draw(scene);
    way1->draw(scene);
}


void MainWindow::on_testDijkstra_clicked()
{
    Map testMap;
    City*a=new City("a",0,0);
    City*b=new City("b",0,100);
    City*c=new City("c",100,300);
    testMap.addCity(a);
    testMap.addCity(b);
    testMap.addCity(c);

    Street*s1=new Street(a,b);
    Street*s2=new Street(b,c);
    Street*s3=new Street(a,c);
    testMap.addStreet(s1);
    testMap.addStreet(s2);
    testMap.addStreet(s3);

    testMap.draw(scene);
    QVector<Street*>kuerzesterWeg=Dijkstra::search(testMap,a->getName(),c->getName());

    for(auto it=kuerzesterWeg.begin();it!=kuerzesterWeg.end();it++)
    {
        (*it)->drawRed(scene);
    }
}


void MainWindow::on_addStateRoad_clicked()
{
    City*newCity1=new City("CoolCity1",10,20);
    City*newCity2=new City("CoolCity",80,10);
    Motorway*way1=new Motorway(newCity1,newCity2);
    newCity1->draw(scene);
    newCity2->draw(scene);
    way1->draw(scene);
}

