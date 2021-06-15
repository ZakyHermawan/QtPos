#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QWidget>
#include <QSqlDatabase>

#include <QDebug>

namespace Ui {
class LoginForm;
}

class LoginForm : public QWidget
{
    Q_OBJECT

public:
    explicit LoginForm(QWidget* parent = nullptr, QSqlDatabase* db=nullptr);
    ~LoginForm();

private slots:
    void on_pushButton_clicked();

    void on_username_returnPressed();

    void on_password_returnPressed();

private:
    Ui::LoginForm* ui;
    QSqlDatabase* m_db;
};

#endif // LOGINFORM_H
