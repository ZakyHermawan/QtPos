#include "include/mainwindow.h"
#include "include/loginform.h"
#include "include/administrator.h"


#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <QPointer>
#include <QStackedWidget>
#include <QSize>

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


    // LoginForm login(nullptr, &db);

    QPointer<MainWindow> stackedWidget = new MainWindow;
    LoginForm* login = new LoginForm(stackedWidget, &db);

    Administrator* tmp = new Administrator(stackedWidget);

    QSize login_size = login->size();

    stackedWidget->addWidget(login);
    stackedWidget->addWidget(tmp);

    stackedWidget->setCurrentWidget(login);
    stackedWidget->setFixedSize(login_size);

    stackedWidget->show();

    QObject::connect(login, SIGNAL(admin_login()), stackedWidget, SLOT(admin_logged()));

    return a.exec();
}
