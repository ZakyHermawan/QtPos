#include "authentication.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <QVariant>
#include <QDebug>


bool auth::login(QSqlDatabase* db, QString& username, QString& password) {
    QSqlQuery query(*db);
    QString statement = "select role from users where username='" + username + "' and password='"+password+"';";
    query.exec(statement);

    while(query.next()) {
        QString role = query.value(0).toString();
        if(role == "admin") {
            return true;
        }
    }
    return false;
}
