#include "include/client.h"
#include "ui_client.h"

#include "include/listgoodsitem.h"
#include "include/listusersitem.h"

#include <QIcon>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QStringList>
#include <QListWidgetItem>


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

    delete m_buy_confirmation;
    delete ui;
}

void Client::delete_current_goods()
{
    int current_row = ui->listWidget->currentRow();

    // item on ui will be deleted too
    ListGoodsItem* del = dynamic_cast<ListGoodsItem* >(ui->listWidget->takeItem(current_row));
    delete del;
}

void Client::show_client()
{
    qDebug() << "Client berhasil login";

    QSqlQuery query(QSqlDatabase::database("goods_connection"));
    query.exec("SELECT * FROM goods");

    int index = 1;
    while(query.next()) {
        int id = query.value(0).toInt();
        QString nama_barang = query.value(1).toString();
        int jumlah = query.value(2).toInt();
        QString image_path = query.value(4).toString();
        ListGoodsItem *item = new ListGoodsItem(id, QIcon(":/" + image_path), nama_barang + " " + QString::number(jumlah));
        ui->listWidget->addItem(item);
        ++index;
    }
    this->show();
}

void Client::change_amount(int row, int amount)
{
    ListGoodsItem *item = dynamic_cast<ListGoodsItem*>(ui->listWidget->item(row));
    QString text = item->text();
    QStringList list = text.split(" ");
    qDebug() << "baris: " << row << "amount: " << amount;
    list[1] = QString::number(amount);
    text = list[0] + " " + list[1];
    item->setText(text);

}

void Client::closeEvent(QCloseEvent* event)
{
    if(m_buy_confirmation != nullptr) {
        delete m_buy_confirmation;
        m_buy_confirmation = nullptr;
    }

    ui->listWidget->clear();

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

void Client::on_buyButton_clicked()
{
    int current_row = ui->listWidget->currentRow();
    int selected_items = ui->listWidget->selectedItems().count();

    if(selected_items == 0) {
        return;
    }

    ListGoodsItem* goods = dynamic_cast<ListGoodsItem*> (ui->listWidget->currentItem());
    int id = goods->getId();


    m_buy_confirmation = new BuyDialog(this, id, current_row);
    m_buy_confirmation->setAttribute(Qt::WA_DeleteOnClose);

    QObject::connect(this, SIGNAL(openConfirmation()), m_buy_confirmation, SLOT(show_dialog()));
    QObject::connect(m_buy_confirmation, SIGNAL(soldOut()), this, SLOT(delete_current_goods()));
    QObject::connect(m_buy_confirmation, SIGNAL(buyFew(int, int)), this, SLOT(change_amount(int, int)));

    emit this->openConfirmation();

}
