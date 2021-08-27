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
    explicit BuyDialog(QWidget *parent = nullptr);
    explicit BuyDialog(QWidget *parent, int id, int row);

    void setId(int id);
    void setRow(int row);

    int getId();
    int getRow();

    virtual ~BuyDialog();

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
    int m_goodsId;
    int m_currentRow;
};

#endif // BUYDIALOG_H
