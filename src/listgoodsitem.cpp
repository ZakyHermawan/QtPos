#include "listgoodsitem.h"

ListGoodsItem::ListGoodsItem(int id, const QListWidgetItem &other)
    : QListWidgetItem(other), m_id(id)
{

}

ListGoodsItem::ListGoodsItem(int id, const QIcon &icon, const QString &text, QListWidget *parent, int type)
    : QListWidgetItem(icon, text, parent, type),
      m_id(id)
{

}

ListGoodsItem::ListGoodsItem(int id, const QString &text, QListWidget *parent, int type)
    : QListWidgetItem(text, parent, type),
      m_id(id)
{

}

ListGoodsItem::ListGoodsItem(int id, QListWidget *parent, int type)
    : QListWidgetItem(parent, type),
      m_id(id)
{

}


int ListGoodsItem::getId()
{
    return m_id;
}
