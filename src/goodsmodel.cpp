#include "goodsmodel.h"

GoodsModel::GoodsModel(QObject* parent, QSqlDatabase db) : QSqlTableModel(parent, db)
{
    this->setHeaderData(4, Qt::Horizontal, "image");
}

GoodsModel::~GoodsModel()
{
    qDebug() << "Goods model destructed";
}

bool GoodsModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    return QSqlTableModel::setHeaderData(section, orientation, value, role);
}

QVariant GoodsModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(orientation == Qt::Horizontal && role == Qt::DisplayRole && section == m_imageColumn) {
        return QVariant("Image");
    }
    return QSqlTableModel::headerData(section, orientation, role);
}

QVariant GoodsModel::data(const QModelIndex& index, int role) const
{
    if(index.column() == m_imageColumn) {
        if(role == Qt::DisplayRole) {
            return QString();
        }

        QString imageFile = ":/" + QSqlTableModel::data(index, Qt::DisplayRole).toString();
        QPixmap pixmap(imageFile);
        pixmap = pixmap.scaled(QSize(80, 80), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        if(role == Qt::DecorationRole)
            return pixmap;

        if(role == Qt::SizeHintRole)
            return pixmap.size();
    }

    return QSqlTableModel::data(index, role);
}

int GoodsModel::columnCount(const QModelIndex& parent) const
{
    return QSqlQueryModel::columnCount(parent);
}
