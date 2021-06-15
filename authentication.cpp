#include "authentication.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <QVariant>

bool auth::login(QSqlDatabase* db, QString& username, QString& hashed_password) {
    QSqlQuery query(*db);

    query.prepare("select role from users where username=:username and password=:password");

    query.bindValue(":username", username);
    query.bindValue(":password", hashed_password);




    query.exec();

    while(query.next()) {
        QString role = query.value(0).toString();
        qDebug() << role;
        if(role == "admin") {
            return true;
        }
    }
    return false;
}
