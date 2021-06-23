#include "include/authentication.h"
#include "include/loginform.h"

#include "ui_loginform.h"

#include <QString>
#include <QSqlDatabase>
#include <QByteArray>
#include <QCryptographicHash>

LoginForm::LoginForm(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::LoginForm)
{
    ui->setupUi(this);
}

LoginForm::~LoginForm()
{
    qDebug() << "Login form deleted";
    delete ui;
}

void LoginForm::show_login()
{
    this->show();
}

void LoginForm::login_destroy()
{
    delete this;
}

void LoginForm::on_submitButton_clicked()
{
    QString username, password;
    username = ui->username->text();
    password = ui->password->text();
    QByteArray hashed_pass = QCryptographicHash::hash(password.toLocal8Bit(), QCryptographicHash::Md5);

    QString hashed_str = hashed_pass.toHex();

    int code = auth::login(username, hashed_str);
    qDebug() << "hashed pass: " << hashed_str;



    qDebug() << "Code:" << code;

    if(code == 1) {
        this->hide();
        emit this->admin_login();
    }
    else if (code == 2){
        this->hide();
        emit this->client_login();
    }
}

void LoginForm::keyPressEvent(QKeyEvent* event)
{
    if(event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter) {
        emit this->on_submitButton_clicked();
    }
}

