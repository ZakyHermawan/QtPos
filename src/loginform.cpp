#include "include/authentication.h"
#include "include/loginform.h"

#include "ui_loginform.h"

#include <QString>
#include <QSqlDatabase>
#include <QByteArray>
#include <QCryptographicHash>

LoginForm::LoginForm(QWidget* parent, QSqlDatabase* db) :
    QWidget(parent),
    ui(new Ui::LoginForm),
    m_db(db)
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

void LoginForm::destroy()
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

    bool valid = auth::login(m_db, username, hashed_str);
    qDebug() << "hashed pass: " << hashed_str;
    if(valid) {
        qDebug() << "valid";
        this->hide();
        emit this->admin_login();
    }
    else {
        qDebug() << "not valid";
    }
}

void LoginForm::keyPressEvent(QKeyEvent* event)
{
    if(event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter) {
        emit this->on_submitButton_clicked();
    }
}

