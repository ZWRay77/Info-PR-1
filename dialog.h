#ifndef DIALOG_H
#define DIALOG_H

#include "city.h"
#include "street.h"

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    City* newCity();
    QString getCity1Name();
    QString getCity2Name();

private:
    Ui::Dialog *ui;
    QString gorad;
    QString street;
    QString nameCity1;
    QString nameCity2;
    int x;
    int y;
};

#endif // DIALOG_H
