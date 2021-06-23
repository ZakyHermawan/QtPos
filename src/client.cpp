#include "include/client.h"
#include "ui_client.h"

#include <QSqlQuery>
#include <QSqlDatabase>

Client::Client(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Client)
{
    QSqlQuery query(QSqlDatabase::database("goods_connection"));
    query.exec("select * from goods");

    int index = 1;
    while(query.next()) {
        QString nama_barang = query.value(1).toString();
        int jumlah = query.value(2).toInt();
        unsigned long long int harga = query.value(3).toLongLong();
        QString image_path = query.value(4).toString();
        qDebug() << "id:" << index << "Nama barang:" << nama_barang << "Jumlah:" << jumlah
                 << "Harga:" << harga << "Image path:" << image_path;
        ++index;
    }

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
