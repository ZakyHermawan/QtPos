#ifndef CLIENT_H
#define CLIENT_H

#include "buydialog.h"

#include <QWidget>
#include <QCloseEvent>
#include <QPointer>
#include <QDebug>

namespace Ui {
class Client;
}

class Client : public QWidget
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = nullptr);
    virtual ~Client();

private slots:
    void show_client();
    void delete_current_goods();
    void change_amount(int row, int amount);

    void on_quitButton_clicked();

    void on_buyButton_clicked();

signals:
    void closeSignal();
    void openConfirmation();

private:
    Ui::Client *ui;
    QPointer<BuyDialog> m_buy_confirmation;
    void closeEvent(QCloseEvent* event);
};

#endif // CLIENT_H
