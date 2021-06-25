#include "include/administrator.h"
#include "ui_administrator.h"

Administrator::Administrator(QWidget *parent) :
    QStackedWidget(parent),
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

void Administrator::destroy()
{
    delete this;
}

void Administrator::on_quitButton_clicked()
{
    emit this->close();
}

void Administrator::on_userButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(AdminWindow::USERS);
}

void Administrator::on_goodsButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(AdminWindow::GOODS);
}

void Administrator::on_historyButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(AdminWindow::HISTORY);
}
