#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <QWidget>

#include <QDebug>

namespace Ui {
class administrator;
}

class administrator : public QWidget
{
    Q_OBJECT

public:
    explicit administrator(QWidget *parent = nullptr);
    ~administrator();

private:
    Ui::administrator *ui;
};

#endif // ADMINISTRATOR_H
