#ifndef LISTUSERSITEM_H
#define LISTUSERSITEM_H

#include <QListWidgetItem>

#include <QDebug>

class ListUsersItem: public QListWidgetItem
{

private:
    int m_id;

public:

    ListUsersItem(int id, const QListWidgetItem &other);
    ListUsersItem(int id, const QIcon &icon, const QString &text, QListWidget *parent = nullptr, int type = Type);
    ListUsersItem(int id, const QString &text, QListWidget *parent = nullptr, int type = Type);
    ListUsersItem(int id, QListWidget *parent = nullptr, int type = Type);

    ~ListUsersItem();

    int getId();

};
#endif // LISTUSERSITEM_H
