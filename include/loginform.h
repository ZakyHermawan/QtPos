#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QWidget>
#include <QSqlDatabase>
#include <QKeyEvent>

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
    void show_login();
    void destroy();

    void keyPressEvent(QKeyEvent* event);

    void on_submitButton_clicked();

signals:
    void admin_login();


private:
    Ui::LoginForm* ui;
    QSqlDatabase* m_db;
};

#endif // LOGINFORM_H
