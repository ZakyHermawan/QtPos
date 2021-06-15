#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H
#include <QSqlDatabase>
#include <QString>

namespace auth {
    bool login(QSqlDatabase*, QString&, QString&);
} // end namespace auth


#endif // AUTHENTICATION_H
