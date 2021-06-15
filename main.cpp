#include "mainwindow.h"
#include "loginform.h"

#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <QDebug>

//void kueri(QSqlDatabase& db) {
//    QSqlQuery query(db);
//    QString username, pass;
//    username = "admin";
//    pass = "admin";
//    // QString sql = "select role from users where username = '" + username + "' and password = '" + pass + "';";

//    query.exec("select * from users;");
//}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // MainWindow w;


    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:/SourceCode/QtApp/POS-Software/users.db");
    if(db.open())
        qDebug() << "Connection OK!";
    else
        qDebug() << "Connection FAIL!";

    LoginForm login(nullptr, &db);


//    kueri(db);


    login.show();
    return a.exec();
}
