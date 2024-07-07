#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "map.h"
#include "dialog.h"
#include "mapio.h"
#include "mapionrw.h"
#include "dijkstra.h"


#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_test_clicked();

    void on_actionExit_triggered();

    void on_actionClear_Scene_triggered();

    void on_actionAbout_triggered();

    void on_testDrawCityButton_clicked();

    void on_checkBoxTest_clicked();

    void on_AddCity_clicked();

    void on_fillMap_clicked();

    void on_AddStreet_clicked();

    void on_testAbstractMap_clicked();


    void on_testDrawStreetButton_clicked();

    void on_tesDrawtMapButton_clicked();

    void on_addMotorWay_clicked();

    void on_testDijkstra_clicked();

    void on_addStateRoad_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene scene;
    QMessageBox msgBox;
    Map map;
    MapIo*mapio;
};
#endif // MAINWINDOW_H
