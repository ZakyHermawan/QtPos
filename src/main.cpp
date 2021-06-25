#include "include/loginform.h"
#include "include/administrator.h"


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

    login->show();

    QObject::connect(login, SIGNAL(admin_login()), admin, SLOT(halo()));

    QObject::connect(&a, SIGNAL(aboutToQuit()), login, SLOT(destroy()));
    QObject::connect(&a, SIGNAL(aboutToQuit()), admin, SLOT(destroy()));

    return a.exec();
}
