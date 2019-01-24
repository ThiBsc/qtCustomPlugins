#include "lineediticon.h"
#include <QPainter>

LineEditIcon::LineEditIcon(QWidget *parent)
	: QLineEdit(parent)
{
	setIcon(QIcon());
}

LineEditIcon::LineEditIcon(const QIcon icon, QWidget *parent)
	: QLineEdit(parent)
{
	setIcon(icon);
}

LineEditIcon::~LineEditIcon()
{

}

QIcon LineEditIcon::getIcon() const
{
	return m_icon;
}

void LineEditIcon::setIcon(QIcon icon)
{
	m_icon = icon;
	if (m_icon.isNull()){
		setTextMargins(0, 0, 0, 0);
	} else {
		setTextMargins(height(), 0, 0, 0);
	}
}

void LineEditIcon::paintEvent(QPaintEvent * event)
{
	QLineEdit::paintEvent(event);
	if (!m_icon.isNull()) {
		QPainter painter(this);
		QPixmap pxm = m_icon.pixmap(height() - 6, height() - 6);
		int x = 2, cx = pxm.width();

		painter.drawPixmap(2, 3, pxm);
		painter.setPen(QColor("lightgrey"));
		painter.drawLine(cx + 2, 3, cx + 2, height() - 4);
	}
}
