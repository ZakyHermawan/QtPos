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
    qDebug() << "Administrator deleted";
    delete ui;
}

void Administrator::halo()
{
    qDebug() << "Berhasil masuk admin!";
    this->show();
}

void Administrator::destroy() {
    delete this;
}

void Administrator::on_quitButton_clicked()
{
    emit this->close();
}
