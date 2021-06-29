#include "include/administrator.h"
#include "ui_administrator.h"

#include "include/listgoodsitem.h"
#include "include/listusersitem.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QPointer>

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
    query.exec("SELECT * FROM users");
    int index = 1;

    while(query.next()) {
        int id = query.value(0).toInt();
        QString username = query.value(1).toString();
        QString role = query.value(3).toString();
        ListUsersItem *item = new ListUsersItem(id, QString(index) + " "+ username + " " + role);
        ui->listWidget->addItem(item);
        ++index;
    }
}

void Administrator::on_goodsButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(AdminWindow::GOODS);
    qDebug() << "goods";
    QSqlQuery query(QSqlDatabase::database("goods_connection"));
    query.exec("SELECT * FROM goods");

    int index = 1;
    while(query.next()) {
        int id = query.value(0).toInt();
        QString nama_barang = query.value(1).toString();
        QString image_path = query.value(4).toString();
        ListGoodsItem *item = new ListGoodsItem(id, QIcon(":/" + image_path), nama_barang);
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

void Administrator::on_deleteItem_clicked()
{

    int current_row = ui->listWidget_2->currentRow();

    // make sure there is a row that being focused
    if(current_row == -1) {
        return;
    }

    ListGoodsItem* current_item = dynamic_cast<ListGoodsItem* >(ui->listWidget_2->takeItem(current_row));
    int id = current_item->getId();

    QSqlQuery query(QSqlDatabase::database("goods_connection"));
    query.prepare("DELETE FROM goods WHERE id = :id");
    query.bindValue(":id", id);

    query.exec();

    delete current_item;
}

void Administrator::on_deleteUser_clicked()
{
    int current_row = ui->listWidget->currentRow();

    // make sure there is a row that being focused
    if(current_row == -1) {
        return;
    }

    ListUsersItem* current_user = dynamic_cast<ListUsersItem* >(ui->listWidget->takeItem(current_row));

    int id = current_user->getId();

    QSqlQuery query(QSqlDatabase::database("users_connection"));

    query.prepare("DELETE FROM users WHERE id = :id");
    query.bindValue(":id", id);

    query.exec();

    delete current_user;
}
