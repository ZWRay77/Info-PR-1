#include "dialog.h"
#include "ui_dialog.h"

#include <QDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

City* Dialog::newCity()
{
    gorad = ui->nameStadt->text();
    qDebug() << gorad;
    bool ok;

    x = ui->xAchse->text().toInt(&ok);

    if (ok == false)
    {
        qDebug() << "Bitte geben Sie eine Zahl ein!";
    }
    else
    {
        qDebug() << y;
    }

    y = ui->yAchse->text().toInt(&ok);
    if (ok == false)
    {
        qDebug() << "Bitte geben Sie eine Zahl ein!";
    }
    else
    {
        qDebug() << y;
    }

    return  new City(gorad, x, y);
}

QString Dialog::getCity1Name()
{
    nameCity1 = ui->nameStadt1->text();
    return nameCity1;
}

QString Dialog::getCity2Name()
{
    nameCity2 = ui->nameStadt2->text();
    return nameCity2;
}
