#include "circularprogress.h"
#include <QPainter>
#include <QMouseEvent>

CircularProgress::CircularProgress(QWidget *parent)
    : QWidget(parent)
    , m_progressType(CircularProgress::Ellipse)
    , m_bgColor(QColor("dimgrey"))
    , m_valueColor(QColor("cornflowerblue"))
    , m_min(0)
    , m_max(100)
    , m_value(0)
    , m_barWidth(16)
	, m_showTextPercent(true)
{
    //setMouseTracking(true);
    connect(this, SIGNAL(minChanged(qreal)), this, SLOT(update()));
    connect(this, SIGNAL(maxChanged(qreal)), this, SLOT(update()));
    connect(this, SIGNAL(valueChanged(qreal)), this, SLOT(update()));
}

void CircularProgress::setProgressType(CircularProgress::ProgressType progressType)
{
    m_progressType = progressType;
}

qreal CircularProgress::getValue() const
{
    return m_value;
}

void CircularProgress::setValue(qreal value)
{
    m_value = value;
    emit valueChanged(value);
}

qreal CircularProgress::getMin() const
{
    return m_min;
}

void CircularProgress::setMin(qreal min)
{
    m_min = min;
    emit minChanged(min);
}

qreal CircularProgress::getMax() const
{
    return m_max;
}

void CircularProgress::setMax(qreal max)
{
    m_max = max;
    emit maxChanged(max);
}

void CircularProgress::setRange(qreal min, qreal max)
{
    blockSignals(true);
    setMin(min);
    blockSignals(false);
    setMax(max);
}

QColor CircularProgress::getBgColor() const
{
	return m_bgColor;
}

void CircularProgress::setBgColor(QColor bgcolor)
{
	m_bgColor = bgcolor;
	update();
}

QColor CircularProgress::getValueColor() const
{
	return m_valueColor;
}

void CircularProgress::setValueColor(QColor valuecolor)
{
	m_valueColor = valuecolor;
	update();
}

int CircularProgress::getBarWidth() const
{
	return m_barWidth;
}

void CircularProgress::setBarWidth(int bwidth)
{
	m_barWidth = bwidth;
	update();
}

bool CircularProgress::isShowingText() const
{
	return m_showTextPercent;
}

void CircularProgress::setTextVisible(bool visible)
{
	m_showTextPercent = visible;
	update();
}

void CircularProgress::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    QPainter painter(this);
    //painter.fillRect(rect(), QColor(Qt::white));

    QPen pen = painter.pen();
    QBrush brush = painter.brush();
    QFont font = painter.font();
    //int w = width(), h = height();

    pen.setWidth(m_barWidth);
    pen.setCapStyle(Qt::FlatCap);
    int offset = pen.width()/2;
    QRect rectArea(rect().adjusted(offset, offset, -offset, -offset));
    painter.setRenderHint(QPainter::Antialiasing);

    int startAngle = 90 * 16;
    int angle = int((((m_value-m_min)/(m_max-m_min))*16) * 360);
    // All angle must be specified in 1/16th of a degree
    pen.setColor(m_bgColor);
    painter.setPen(pen);
    painter.drawArc(rectArea, startAngle, (16 * 360));
    // draw value text
	if (m_showTextPercent){
		font.setPointSize(rectArea.width()/4);
		painter.setFont(font);
		painter.drawText(rect(), Qt::AlignCenter, QString::number(int(((m_value-m_min)/(m_max-m_min))*100))+"%");
	}
    // draw value arc
    pen.setColor(m_valueColor);
    pen.setWidth(m_barWidth-m_barWidth/3);
    painter.setPen(pen);
    painter.drawArc(rectArea, startAngle, -angle);
}
