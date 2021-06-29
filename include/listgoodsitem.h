#ifndef LISTGOODSITEM_H
#define LISTGOODSITEM_H

#include <QListWidgetItem>

#include <QDebug>

class ListGoodsItem: public QListWidgetItem
{

private:
    int m_id;

public:

    ListGoodsItem(int id, const QListWidgetItem &other);
    ListGoodsItem(int id, const QIcon &icon, const QString &text, QListWidget *parent = nullptr, int type = Type);
    ListGoodsItem(int id, const QString &text, QListWidget *parent = nullptr, int type = Type);
    ListGoodsItem(int id, QListWidget *parent = nullptr, int type = Type);

    ~ListGoodsItem();

    int getId();

};

#endif // LISTGOODSITEM_H
