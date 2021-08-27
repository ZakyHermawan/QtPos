#include "ui_administrator.h"

#include "administrator.h"
#include "listgoodsitem.h"
#include "listusersitem.h"
#include "query_command.h"

#include <QSqlDatabase>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QModelIndexList>
#include <QStandardItem>
#include <QList>
#include <QSqlRecord>

Administrator::Administrator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Administrator),
    m_userModel(new QSqlTableModel(this , QSqlDatabase::database("users_connection"))),
    m_goodsModel(new GoodsModel(this, QSqlDatabase::database("goods_connection"))),
    m_historyModel(new QSqlTableModel(this, QSqlDatabase::database("histories_connection")))
{
    ui->setupUi(this);
    m_userModel->setTable("users");
    m_userModel->setEditStrategy(QSqlTableModel::OnFieldChange);
    m_userModel->select();

    m_historyModel->setTable("history");
    m_historyModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    m_historyModel->select();

    m_goodsModel->setTable("goods");

    m_goodsModel->setEditStrategy(QSqlTableModel::OnFieldChange);
    m_goodsModel->select();
    m_goodsModel->setHeaderData(0, Qt::Horizontal, tr("image"));

    ui->usersTableView->setModel(m_userModel);
    ui->usersTableView->horizontalHeader()->setStretchLastSection(true);
    ui->usersTableView->hideColumn(0);
    ui->usersTableView->hideColumn(2);

    ui->historiesTableView->setModel(m_historyModel);
    ui->historiesTableView->horizontalHeader()->setStretchLastSection(true);
    ui->historiesTableView->hideColumn(0);

    ui->goodsTableView->setModel(m_goodsModel);
    ui->goodsTableView->horizontalHeader()->setStretchLastSection(true);
    ui->goodsTableView->hideColumn(0);

    ui->goodsTableView->resizeColumnToContents(4);
    ui->goodsTableView->resizeRowsToContents();
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

void Administrator::on_quitButton_clicked()
{
    // close app and show login form
    this->close();
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
    ui->usersTableView->clearSpans();
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

// TODO write to history
void Administrator::on_deleteItem_clicked()
{

}

void Administrator::on_deleteUser_clicked()
{
    QModelIndexList lst = ui->usersTableView->selectionModel()->selectedIndexes();

    if(!lst.isEmpty()) {
        int row = lst.first().row();
        m_userModel->removeRow(row);
        m_userModel->select();
    }
    else{
        qDebug() << "tidak ada item yang dipilih";
    }
    ui->usersTableView->clearSelection();
}

void Administrator::on_deleteHistory_clicked()
{
    QModelIndexList lst = ui->historiesTableView->selectionModel()->selectedIndexes();
    int size = lst.size();

    if(!lst.isEmpty()) {
        m_historyModel->removeRows(lst.first().row(), size);
        m_historyModel->submitAll();
    }

    ui->usersTableView->clearSelection();
}

//TODO, show dialogbox to register a user
void Administrator::on_addUser_clicked()
{
    return;
}
