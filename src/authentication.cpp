#include "include/authentication.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>

int auth::login(QString& username, QString& hashed_password) {
    QSqlQuery query(QSqlDatabase::database("users_connection"));

    query.prepare("SELECT role FROM users WHERE username=:username AND password=:password");

    query.bindValue(":username", username);
    query.bindValue(":password", hashed_password);

    query.exec();

    while(query.next()) {
        QString role = query.value(0).toString();
        if(role == "admin") {
            return 1;
        }
        else if(role ==  "user") {
            return 2;
        }
    }
    return 0;
}
