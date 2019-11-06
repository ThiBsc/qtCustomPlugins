#ifndef LINEEDITICON_H
#define LINEEDITICON_H

#include <QLineEdit>
#include <QIcon>

/**
 * @author thibsc
 * @brief The LineEditIcon class
 * Allow to add an icon before the text
 */
class LineEditIcon : public QLineEdit
{
	Q_OBJECT

	Q_PROPERTY(QIcon icon READ getIcon WRITE setIcon)

public:
	LineEditIcon(QWidget *parent = Q_NULLPTR);
	LineEditIcon(const QIcon icon, QWidget *parent = Q_NULLPTR);
	~LineEditIcon();
	QIcon getIcon() const;
	void setIcon(QIcon icon);

protected:
	void paintEvent(QPaintEvent *event) override;

private:
	QIcon m_icon;
	
};

#endif // LINEEDITICON_H
