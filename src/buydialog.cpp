#include "buydialog.h"
#include "ui_buydialog.h"

#include "include/query_command.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDate>
#include <QTime>

BuyDialog::BuyDialog(QWidget *parent, int id, int row) :
    QDialog(parent),
    ui(new Ui::BuyDialog),
    m_goods_id(id),
    m_current_row(row)
{
    qDebug() << "buy dialog constructed";
    ui->setupUi(this);
}

BuyDialog::~BuyDialog()
{
    qDebug() << "Buy dialog destroyed";
    delete ui;
}

bool BuyDialog::eventFilter(QObject* obj, QEvent* event)
{
    Q_UNUSED(obj);
    if(event->type() == QEvent::FocusAboutToChange) {
        qDebug() << "ganti focus";
        return true;
    }
    return false;
}

void BuyDialog::show_dialog()
{
    this->show();
}

void BuyDialog::on_buttonBox_accepted()
{
    QSqlQuery query(QSqlDatabase::database("goods_connection"));

    query.prepare("SELECT * FROM goods WHERE id = :id");
    query.bindValue(":id", m_goods_id);
    query.exec();

    int spinbox_val = ui->spinBox->value();

    QString operasi, nama_barang;

    if(query.next()) {
        nama_barang = query.value(1).toString();
        int jumlah = query.value(2).toInt();

        if(spinbox_val == 0) {
            ui->errorMessage->setText(" ");
            return;
        }

        if(spinbox_val > jumlah) {
            ui->errorMessage->setStyleSheet("QLabel#errorMessage {color: red}");
            ui->errorMessage->setText("Jumlah barang kurang");
        }

        else {
            ui->errorMessage->setText(" ");
            int sisa = jumlah - spinbox_val;

            if(sisa == 0) {
                delete_with_id("goods_connection", "goods", m_goods_id);
                emit this->soldOut();
                add_history("BUY", nama_barang, spinbox_val);
                this->close();
            }

            else {
                query.prepare(QString("UPDATE goods SET jumlah = %1 WHERE id = :id").arg(sisa));
                query.bindValue(":id", m_goods_id);
                query.exec();

                add_history("BUY", nama_barang, spinbox_val);
                emit this->buyFew(m_current_row, sisa);
            }
        }
    }
}

void BuyDialog::on_buttonBox_rejected()
{
    this->close();
}
