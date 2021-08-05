#include "tfecircularprogress.h"
#include <QPainter>
#include <QMouseEvent>

TFeCircularProgress::TFeCircularProgress(QWidget *parent)
    : QWidget(parent)
    , m_animation(new QPropertyAnimation(this, "startAngle"))
    , m_progressType(TFeCircularProgress::Ellipse)
    , m_bgColor(QColor("dimgrey"))
    , m_valueColor(QColor("cornflowerblue"))
    , m_min(0)
    , m_max(100)
    , m_value(5)
    , m_startAngle(90 * 16) // All angle must be specified in 1/16th of a degree
    , m_barWidth(16)
    , m_showTextPercent(true)
    , m_infinityMode(false)
{
    //setMouseTracking(true);
    connect(this, SIGNAL(minChanged(int)), this, SLOT(update()));
    connect(this, SIGNAL(maxChanged(int)), this, SLOT(update()));
    connect(this, SIGNAL(valueChanged(int)), this, SLOT(update()));
}

void TFeCircularProgress::setProgressType(TFeCircularProgress::ProgressType progressType)
{
    m_progressType = progressType;
}

int TFeCircularProgress::getValue() const
{
    return m_value;
}

void TFeCircularProgress::setValue(int value)
{
    m_value = value;
    emit valueChanged(value);
}

int TFeCircularProgress::getMin() const
{
    return m_min;
}

void TFeCircularProgress::setMin(int min)
{
    m_min = min;
    emit minChanged(min);
}

int TFeCircularProgress::getMax() const
{
    return m_max;
}

void TFeCircularProgress::setMax(int max)
{
    m_max = max;
    emit maxChanged(max);
}

void TFeCircularProgress::setRange(int min, int max)
{
    blockSignals(true);
    setMin(min);
    blockSignals(false);
    setMax(max);
}

QColor TFeCircularProgress::getBgColor() const
{
    return m_bgColor;
}

void TFeCircularProgress::setBgColor(QColor bgcolor)
{
    m_bgColor = bgcolor;
    update();
}

QColor TFeCircularProgress::getValueColor() const
{
    return m_valueColor;
}

void TFeCircularProgress::setValueColor(QColor valuecolor)
{
    m_valueColor = valuecolor;
    update();
}

int TFeCircularProgress::getBarWidth() const
{
    return m_barWidth;
}

void TFeCircularProgress::setBarWidth(int bwidth)
{
    m_barWidth = bwidth;
    update();
}

bool TFeCircularProgress::isShowingText() const
{
    return m_showTextPercent;
}

void TFeCircularProgress::setTextVisible(bool visible)
{
    m_showTextPercent = visible;
    update();
}

bool TFeCircularProgress::infinityMode() const
{
    return m_infinityMode;
}

void TFeCircularProgress::setInfinityMode(bool infinite)
{
    m_infinityMode = infinite;
    if (m_infinityMode){
        // Playing with 20% of the circle
        m_min = 0;
        m_value = 20;
        m_max = 100;
        // -1 to make an infinite animation
        m_animation->setLoopCount(-1);
        m_animation->setDuration(2500);
        // The start position to the end (complete loop)
        m_animation->setStartValue(90*16);
        m_animation->setEndValue(-270*16);
        m_animation->start();
    } else {
        m_animation->stop();
        m_startAngle = 90 * 16;
    }
}

int TFeCircularProgress::getStartAngle() const
{
    return m_startAngle;
}

void TFeCircularProgress::setStartAngle(int s_angle)
{
    m_startAngle = s_angle;
    update();
}

void TFeCircularProgress::paintEvent(QPaintEvent *event)
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

    int angle = int(((double(m_value-m_min)/double(m_max-m_min))*16) * 360);
    // All angle must be specified in 1/16th of a degree
    pen.setColor(m_bgColor);
    painter.setPen(pen);
    painter.drawArc(rectArea, m_startAngle, (16 * 360));
    // draw value text
    if (m_showTextPercent){
        font.setPointSize(rectArea.width()/4);
        painter.setFont(font);
        painter.drawText(rect(), Qt::AlignCenter, (m_infinityMode ? "∞" : QString::number(int((double(m_value-m_min)/double(m_max-m_min))*100))+"%"));
    }
    // draw value arc
    pen.setColor(m_valueColor);
    pen.setWidth(m_barWidth-m_barWidth/3);
    painter.setPen(pen);
    painter.drawArc(rectArea, m_startAngle, -angle);
}
