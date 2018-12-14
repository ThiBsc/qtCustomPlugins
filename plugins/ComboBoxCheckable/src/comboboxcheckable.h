#ifndef COMBOBOXCHECKABLE_H
#define COMBOBOXCHECKABLE_H

#include <QComboBox>

class AbstractListModelCheckableCbx;

/**
 * @author thibdev
 * @brief The ComboBoxCheckable class
 */
class ComboBoxCheckable : public QComboBox
{
	Q_OBJECT

public:
	ComboBoxCheckable(QWidget *parent = Q_NULLPTR);
	~ComboBoxCheckable();
	void addItem(const QString& item);
	void addItems(const QStringList& items);
	QList<QString> getItems() const;

private slots:
    void checkItem();

private:
    AbstractListModelCheckableCbx *listModel;
	
};

#endif // COMBOBOXCHECKABLE_H
