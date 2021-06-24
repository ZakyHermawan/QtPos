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

void Administrator::closeEvent(QCloseEvent* event)
{
    // loginform kembali ditampilkan
    emit closeSignal();
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
    emit this->close();
}


/* navigate user */
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

/* back to navigate page */
void Administrator::on_userBack_clicked()
{
    ui->stackedWidget->setCurrentIndex(AdminWindow::NAVIGASI);
}


void Administrator::on_goodsBack_clicked()
{
    ui->stackedWidget->setCurrentIndex(AdminWindow::NAVIGASI);
}


void Administrator::on_historyBack_clicked()
{
    ui->stackedWidget->setCurrentIndex(AdminWindow::NAVIGASI);
}
