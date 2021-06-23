#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QWidget>
#include <QKeyEvent>

#include <QDebug>

namespace Ui {
    class LoginForm;
}

class LoginForm : public QWidget
{
    Q_OBJECT

public:
    explicit LoginForm(QWidget* parent = nullptr);
    ~LoginForm();

private slots:
    void show_login();
    void login_destroy();

    void keyPressEvent(QKeyEvent* event);

    void on_submitButton_clicked();

signals:
    void admin_login();
    void client_login();


private:
    Ui::LoginForm* ui;
};

#endif // LOGINFORM_H
