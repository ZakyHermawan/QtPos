#include "include/client.h"
#include "ui_client.h"

Client::Client(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);
}

Client::~Client()
{
    qDebug() << "Client deleted";
    delete ui;
}

void Client::show_client()
{
    qDebug() << "Client berhasil login";
    this->show();
}

void Client::client_destroy()
{
    delete this;
}
