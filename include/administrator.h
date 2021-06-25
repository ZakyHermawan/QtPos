#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <QStackedWidget>
#include <QWidget>
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

class Administrator : public QStackedWidget
{
    Q_OBJECT

public:
    explicit Administrator(QWidget *parent = nullptr);
    ~Administrator();

private slots:
    void halo();
    void destroy();

    void on_quitButton_clicked();

    void on_userButton_clicked();

    void on_goodsButton_clicked();

    void on_historyButton_clicked();

private:
    Ui::Administrator *ui;
};

#endif // ADMINISTRATOR_H
