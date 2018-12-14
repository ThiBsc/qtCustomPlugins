#ifndef ABSTRACTLISTMODELCHECKABLECBX_H
#define ABSTRACTLISTMODELCHECKABLECBX_H

#include <QAbstractListModel>

/**
 * @author thibdev
 * @brief The AbstractListModelCheckableCbx class
 */
class AbstractListModelCheckableCbx : public QAbstractListModel
{
	Q_OBJECT

public:
	AbstractListModelCheckableCbx(QObject *parent = Q_NULLPTR);
	~AbstractListModelCheckableCbx();
	virtual int columnCount(const QModelIndex &parent = QModelIndex()) const;
	virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
	virtual int rowCount(const QModelIndex &parent = QModelIndex()) const;
	virtual Qt::ItemFlags flags(const QModelIndex &index) const;
	virtual bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
	void addItem(const QString& item);
	void clearItems();
	QList<QString> getItems() const;

signals:
    void selectionChanged();

private:
	QMap<QString, bool> *_data;
    QStringList selectionText;
	
};

#endif // ABSTRACTLISTMODELCHECKABLECBX_H
