#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <QWidget>
#include <QCloseEvent>

#include <QDebug>

enum AdminWindow {
    NAVIGASI,
    USERS,
    GOODS,
    HISTORY
};

namespace Ui {
class Administrator;
}

class Administrator : public QWidget
{
    Q_OBJECT

public:
    explicit Administrator(QWidget *parent = nullptr);
    ~Administrator();

private slots:
    void show_admin();
    void admin_destroy();

    void on_quitButton_clicked();

    void on_userButton_clicked();

    void on_goodsButton_clicked();

    void on_historyButton_clicked();

    void on_userBack_clicked();

    void on_goodsBack_clicked();

    void on_historyBack_clicked();

    void on_deleteItem_clicked();

    void on_deleteUser_clicked();

signals:
    void closeSignal();

private:
    Ui::Administrator *ui;

    void closeEvent(QCloseEvent* event);
};

#endif // ADMINISTRATOR_H
