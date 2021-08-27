#ifndef GOODSMODEL_H
#define GOODSMODEL_H

#include <QIcon>
#include <QSqlTableModel>

#include <QDebug>

class GoodsModel : public QSqlTableModel
{
    Q_OBJECT

private:
    const int m_imageColumn = 4;

public:
    GoodsModel(QObject* parent = nullptr, QSqlDatabase db = QSqlDatabase());
    virtual ~GoodsModel();

    int columnCount(const QModelIndex& parent) const;
    bool setHeaderData(int section, Qt::Orientation orientation, const QVariant& value, int role = Qt::EditRole);
    QVariant headerData(int section, Qt::Orientation orentation, int role=Qt::DisplayRole) const;
    QVariant data(const QModelIndex& index, int role) const;

};

#endif // GOODSMODEL_H
