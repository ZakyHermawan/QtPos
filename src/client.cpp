#include "include/client.h"
#include "ui_client.h"

#include <QSqlQuery>
#include <QSqlDatabase>
#include <QListWidgetItem>
#include <QIcon>

Client::Client(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);
}

Client::~Client()
{
    qDebug() << "Client deleted";
    ui->listWidget->clear();
    delete ui;
}

void Client::show_client()
{
    qDebug() << "Client berhasil login";

    QSqlQuery query(QSqlDatabase::database("goods_connection"));
    query.exec("SELECT * FROM goods");

    int index = 1;
    while(query.next()) {
        QString nama_barang = query.value(1).toString();
        QString image_path = query.value(4).toString();
        QListWidgetItem *item = new QListWidgetItem(QIcon(":/" + image_path), nama_barang);
        ui->listWidget->addItem(item);
        ++index;
    }
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
    ui->listWidget->clear();
    delete this;
}

void Client::on_quitButton_clicked()
{
    // close app and show login form
    this->close();
}
