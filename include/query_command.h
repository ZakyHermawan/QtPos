#ifndef QUERY_COMMAND_H
#define QUERY_COMMAND_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <QTime>
#include <QDate>

#include <QDebug>

void add_history(QString operasi, QString nama_barang, int jumlah);
void delete_with_id(QString connectionName, QString tableName, int id);

#endif // QUERY_COMMAND_H
