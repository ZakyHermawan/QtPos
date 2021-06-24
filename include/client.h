#ifndef CLIENT_H
#define CLIENT_H

#include <QWidget>

#include <QDebug>

namespace Ui {
class Client;
}

class Client : public QWidget
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = nullptr);
    ~Client();

private slots:
    void show_client();
    void client_destroy();

private:
    Ui::Client *ui;
};

#endif // CLIENT_H
