#include "administrator.h"
#include "ui_administrator.h"

#include <QString>

administrator::administrator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::administrator)
{

}

administrator::~administrator()
{
    delete ui;
}
