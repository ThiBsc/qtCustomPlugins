#include "comboboxcheckable.h"
#include "abstractlistmodelcheckablecbx.h"
#include <QStyleFactory>

ComboBoxCheckable::ComboBoxCheckable(QWidget *parent)
	: QComboBox(parent)
{
	listModel = new AbstractListModelCheckableCbx();
	setModel(listModel);
#ifdef __GNUC__
	// Force Windows style because Fusions doesn't show CheckBox in model
	setStyle(QStyleFactory::create("Windows"));
#endif

    connect(listModel, SIGNAL(selectionChanged()), this, SLOT(checkItem()));
}

ComboBoxCheckable::~ComboBoxCheckable()
{
	delete listModel;
}

void ComboBoxCheckable::addItem(const QString& item)
{
    listModel->addItem(item);
}

void ComboBoxCheckable::addItems(const QStringList& items)
{
	for (const QString& item : items){
    	listModel->addItem(item);
	}
}

QList<QString> ComboBoxCheckable::getItems() const
{
	return listModel->getItems();
}

void ComboBoxCheckable::checkItem()
{
    QModelIndex index = listModel->index(0);
    setCurrentText(index.data(Qt::DisplayRole).toString());
    setToolTip(index.data(Qt::ToolTipRole).toString());
}

