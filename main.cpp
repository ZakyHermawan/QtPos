#include "mainwindow.h"
#include "loginform.h"

#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:/SourceCode/QtApp/POS-Software/users.db");
    if(db.open())
        qDebug() << "Connection OK!";
    else
        qDebug() << "Connection FAIL!";

    LoginForm login(nullptr, &db);


    login.show();
    return a.exec();
}
