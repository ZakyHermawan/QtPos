#ifndef CLIENT_H
#define CLIENT_H

#include <QWidget>
#include <QCloseEvent>
#include <QSqlDatabase>

#include <QDebug>

namespace Ui {
class Client;
}

class Client : public QWidget
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = nullptr, QSqlDatabase* db = nullptr);
    ~Client();

private slots:
    void show_client();
    void client_destroy();

    void on_quitButton_clicked();

signals:
    void closeSignal();

private:
    Ui::Client *ui;
    QSqlDatabase* m_db;

    void closeEvent(QCloseEvent* event);
};

#endif // CLIENT_H
