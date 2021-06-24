#include "include/loginform.h"
#include "include/administrator.h"
#include "include/client.h"

#include <QApplication>
#include <QSqlDatabase>
#include <QPointer>

#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:/SourceCode/QtApp/POS-Software/databases/users.db");
    if(db.open())
        qDebug() << "Connection OK!";
    else
        qDebug() << "Connection FAIL!";

    QPointer<LoginForm> login = new LoginForm(nullptr, &db);
    QPointer<Administrator> admin = new Administrator;
    QPointer<Client> client = new Client;

    QObject::connect(login, SIGNAL(admin_login()), admin, SLOT(show_admin()));
    QObject::connect(login, SIGNAL(client_login()), client, SLOT(show_client()));

    QObject::connect(&a, SIGNAL(aboutToQuit()), login, SLOT(login_destroy()));
    QObject::connect(&a, SIGNAL(aboutToQuit()), admin, SLOT(admin_destroy()));
    QObject::connect(&a, SIGNAL(aboutToQuit()), client, SLOT(client_destroy()));

    QObject::connect(admin, SIGNAL(closeSignal()), login, SLOT(show_login()));
    QObject::connect(client, SIGNAL(closeSignal()), login, SLOT(show_login()));

    login->show();

    return a.exec();
}
