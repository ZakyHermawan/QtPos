#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H
#include <QSqlDatabase>
#include <QString>

#include <QDebug>

namespace auth {
    int login(QSqlDatabase*, QString&, QString&);
} // end namespace auth


#endif // AUTHENTICATION_H
