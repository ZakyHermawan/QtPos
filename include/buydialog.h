#ifndef BUYDIALOG_H
#define BUYDIALOG_H

#include <QDialog>
#include <QObject>
#include <QEvent>

#include <QDebug>

namespace Ui {
class BuyDialog;
}

class BuyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BuyDialog(QWidget *parent = nullptr, int id=0, int row=0);
    ~BuyDialog();

private slots:
    bool eventFilter(QObject* obj=nullptr, QEvent* event=nullptr);

    void show_dialog();

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();


signals:
    void soldOut();
    void buyFew(int row, int amount);

private:
    Ui::BuyDialog *ui;
    int m_goods_id;
    int m_current_row;
};

#endif // BUYDIALOG_H
