#include "query_command.h"

#include <QVariant>

void add_history(QString operasi, QString nama_barang, int jumlah) {
    QSqlQuery history_query(QSqlDatabase::database("histories_connection"));

    history_query.exec("SELECT MAX(id) from history");
    history_query.next();

    int last_id;
    QString current_date, current_time;

    last_id = history_query.value(0).toInt();
    current_date = QDate::currentDate().toString("dd-MM-yyyy");
    current_time = QTime::currentTime().toString();

    history_query.prepare("INSERT INTO history ( id, operasi, nama_barang, jumlah, tanggal, waktu ) "
                          "VALUES ( :id , :operasi , :nama_barang , :jumlah , :tanggal , :waktu )");
    history_query.bindValue(":id", last_id+1);
    history_query.bindValue(":operasi", operasi);
    history_query.bindValue(":nama_barang", nama_barang);
    history_query.bindValue(":jumlah", jumlah);
    history_query.bindValue(":tanggal", current_date);
    history_query.bindValue(":waktu", current_time);

    history_query.exec();
}

void delete_with_id(QString connectionName, QString tableName, int id) {
    QSqlQuery query(QSqlDatabase::database(connectionName));
    query.prepare(QString("DELETE FROM %1 WHERE id = :id").arg(tableName));
    query.bindValue(":id", id);
    query.exec();
}
