#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H
#include <QSqlDatabase>
#include <QString>

#include <QDebug>

namespace auth {
    bool login(QSqlDatabase*, QString&, QString&);
} // end namespace auth


#endif // AUTHENTICATION_H
