#include "mainwindow.h"
#include "loginform.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // MainWindow w;
    LoginForm login;
    login.show();
    return a.exec();
}
