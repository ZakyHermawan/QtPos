#include "include/administrator.h"
#include "ui_administrator.h"

Administrator::Administrator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Administrator)
{
    ui->setupUi(this);
}

Administrator::~Administrator()
{
    delete ui;
}

void Administrator::halo()
{
    qDebug() << "Halo!";
}
