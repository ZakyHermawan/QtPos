#include "authentication.h"

#include "loginform.h"
#include "ui_loginform.h"

#include <QString>
#include <QSqlDatabase>
#include <QByteArray>
#include <QCryptographicHash>
#include <QTextCodec>

LoginForm::LoginForm(QWidget* parent, QSqlDatabase* db) :
    QWidget(parent),
    ui(new Ui::LoginForm),
    m_db(db)
{
    ui->setupUi(this);
}

LoginForm::~LoginForm()
{
    delete ui;
}

void LoginForm::on_pushButton_clicked()
{
    QString username, password;
    username = ui->username->text();
    password = ui->password->text();
    QByteArray hashed_pass = QCryptographicHash::hash(password.toLocal8Bit(), QCryptographicHash::Md5);

    QString str = hashed_pass.toHex();

    bool valid = auth::login(m_db, username, str);
    if(valid) {
        qDebug() << "valid";
    }
    else {
        qDebug() << "not valid";
    }
}
