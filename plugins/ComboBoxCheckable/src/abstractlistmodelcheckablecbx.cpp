#include "abstractlistmodelcheckablecbx.h"

AbstractListModelCheckableCbx::AbstractListModelCheckableCbx(QObject *parent)
	: QAbstractListModel(parent)
{
    _data = new QMap<QString, bool>();
}

AbstractListModelCheckableCbx::~AbstractListModelCheckableCbx()
{
	delete _data;
}

int AbstractListModelCheckableCbx::columnCount(const QModelIndex & parent) const
{
	Q_UNUSED(parent);
	return 1;
}

QVariant AbstractListModelCheckableCbx::data(const QModelIndex & index, int role) const
{
	QVariant ret = QVariant();
	if (index.isValid()) {
		switch (role) {
		case Qt::DisplayRole:
            ret = (index.row()==0 ? selectionText.join(',') : _data->keys().at(index.row()-1));
			break;
        case Qt::ToolTipRole:
            ret = (index.row()==0 ? selectionText.join('\n') : _data->keys().at(index.row()-1));
            break;
		case Qt::CheckStateRole:
            ret = index.row()==0 ? QVariant() : (_data->value(data(index, Qt::DisplayRole).toString()) ? Qt::Checked : Qt::Unchecked);
            break;
		default:
			break;
		}
	}
	return ret;
}

int AbstractListModelCheckableCbx::rowCount(const QModelIndex & parent) const
{
	Q_UNUSED(parent);
    return _data->size()+1;
}

Qt::ItemFlags AbstractListModelCheckableCbx::flags(const QModelIndex & index) const
{
    Qt::ItemFlags flags = Qt::ItemIsEnabled;
    if (index.row() > 0){
        flags |= Qt::ItemIsUserCheckable;
    }
    return flags;
}

bool AbstractListModelCheckableCbx::setData(const QModelIndex & index, const QVariant & value, int role)
{
	switch (role) {
		case Qt::CheckStateRole:
			_data->insert(data(index, Qt::DisplayRole).toString(), !data(index, Qt::CheckStateRole).toBool());
            if (data(index, Qt::CheckStateRole).toBool()){
                selectionText.append(data(index, Qt::DisplayRole).toString());
            } else {
                selectionText.removeOne(data(index, Qt::DisplayRole).toString());
            }
            emit dataChanged(AbstractListModelCheckableCbx::index(0), AbstractListModelCheckableCbx::index(0));
            emit selectionChanged();
			return true;
		default:
			return QAbstractListModel::setData(index, value, role);
	}
}

void AbstractListModelCheckableCbx::addItem(const QString& item)
{
	beginInsertRows(index(rowCount()), rowCount(), rowCount());
    _data->insert(item, false);
    endInsertRows();
}

void AbstractListModelCheckableCbx::clearItems()
{
	_data->clear();
	selectionText.clear();
	emit dataChanged(index(0), index(0));
    emit selectionChanged();
}

QList<QString> AbstractListModelCheckableCbx::getItems() const
{
	return _data->keys();
}
