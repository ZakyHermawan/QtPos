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

    QSqlDatabase users_db, goods_db, histories_db;
    users_db = QSqlDatabase::addDatabase("QSQLITE", "users_connection");
    users_db.setDatabaseName("D:/SourceCode/QtApp/something/databases/users.db");

    goods_db = QSqlDatabase::addDatabase("QSQLITE", "goods_connection");
    goods_db.setDatabaseName("D:/SourceCode/QtApp/something/databases/goods.db");

    histories_db = QSqlDatabase::addDatabase("QSQLITE", "histories_connection");
    histories_db.setDatabaseName("D:/SourceCode/QtApp/something/databases/histories.db");

    if(users_db.open() && goods_db.open())
        qDebug() << "Connection OK!";
    else
        qDebug() << "Connection FAIL!";

    QPointer<LoginForm> login = new LoginForm;
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
