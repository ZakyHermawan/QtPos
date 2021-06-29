#include "include/listusersitem.h"

ListUsersItem::ListUsersItem(int id, const QListWidgetItem &other)
    : QListWidgetItem(other), m_id(id)
{

}

ListUsersItem::ListUsersItem(int id, const QIcon &icon, const QString &text, QListWidget *parent, int type)
    : QListWidgetItem(icon, text, parent, type),
      m_id(id)
{

}

ListUsersItem::ListUsersItem(int id, const QString &text, QListWidget *parent, int type)
    : QListWidgetItem(text, parent, type),
      m_id(id)
{

}

ListUsersItem::ListUsersItem(int id, QListWidget *parent, int type)
    : QListWidgetItem(parent, type),
      m_id(id)
{

}

ListUsersItem::~ListUsersItem()
{

}

int ListUsersItem::getId()
{
    return m_id;
}
