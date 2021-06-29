#include "include/administrator.h"
#include "ui_administrator.h"

#include <QSqlQuery>

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

void Administrator::closeEvent(QCloseEvent* event)
{
    ui->stackedWidget->setCurrentIndex(AdminWindow::NAVIGASI);

    // loginform kembali ditampilkan
    emit this->closeSignal();
    event->accept();
}

void Administrator::show_admin()
{
    qDebug() << "Admin berhasil masuk!";
    this->show();
}

void Administrator::admin_destroy()
{
    delete this;
}

void Administrator::on_quitButton_clicked()
{
    // close app and show login form
    this->close();
}


/* navigate user */
void Administrator::on_userButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(AdminWindow::USERS);

    QSqlQuery query(QSqlDatabase::database("users_connection"));
    query.exec("select * from users");
    int index = 1;

    while(query.next()) {
        QString username = query.value(1).toString();
        QString role = query.value(3).toString();
        QListWidgetItem *item = new QListWidgetItem(QString(index) + " "+ username + " " + role);
        ui->listWidget->addItem(item);
        ++index;
    }
}

void Administrator::on_goodsButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(AdminWindow::GOODS);
    qDebug() << "goods";
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
        QListWidgetItem *item = new QListWidgetItem(QIcon(":/" + image_path), nama_barang);
        ui->listWidget_2->addItem(item);
        ++index;
    }
}

void Administrator::on_historyButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(AdminWindow::HISTORY);
}

/* back to navigate page */
void Administrator::on_userBack_clicked()
{
    ui->listWidget->clear();
    ui->stackedWidget->setCurrentIndex(AdminWindow::NAVIGASI);
}


void Administrator::on_goodsBack_clicked()
{
    ui->listWidget_2->clear();
    ui->stackedWidget->setCurrentIndex(AdminWindow::NAVIGASI);
}


void Administrator::on_historyBack_clicked()
{
    ui->stackedWidget->setCurrentIndex(AdminWindow::NAVIGASI);
}
