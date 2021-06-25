#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <QWidget>

#include <QDebug>

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
    void halo();
    void destroy();

    void on_quitButton_clicked();

private:
    Ui::Administrator *ui;
};

#endif // ADMINISTRATOR_H
