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

void Client::closeEvent(QCloseEvent* event)
{
    // show login form
    emit this->closeSignal();
    event->accept();
}

void Client::client_destroy()
{
    delete this;
}

void Client::on_quitButton_clicked()
{
    // close app and show login form
    this->close();
}
