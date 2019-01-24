#include "lineedittag.h"

#include <QKeyEvent>
#include <QPainter>
#include <QDebug>

LineEditTag::LineEditTag(QWidget *parent)
    : QLineEdit (parent)
{
    setMinimumHeight(24);
}

LineEditTag::~LineEditTag()
{

}

QStringList LineEditTag::getTags() const
{
    return tags;
}

QString LineEditTag::getTagsStr() const
{
    return tags.join(' ');
}

void LineEditTag::setTags(const QString& tags)
{
    if (!tags.isEmpty()){
        this->tags = tags.split(' ');
        clear();
        update();
    }
}

void LineEditTag::setTags(const QStringList& tags)
{
    if (!tags.isEmpty()){
        this->tags = tags;
        clear();
        update();
    }
}

void LineEditTag::addTag()
{
    if (!text().isEmpty()){
        tags.append(text());
        clear();
        update();
    }
}

void LineEditTag::leaveEvent(QEvent *evt)
{
    QLineEdit::leaveEvent(evt);
    cursorPos = clickedPos = QPoint();
}

void LineEditTag::keyPressEvent(QKeyEvent *evt)
{
    if (evt->key() == Qt::Key_Return || evt->key() == Qt::Key_Enter || evt->key() == Qt::Key_Space){
        evt->accept();
        addTag();
    } else {
        QLineEdit::keyPressEvent(evt);
    }
}

void LineEditTag::mousePressEvent(QMouseEvent *evt)
{
    clickedPos = evt->pos();
    QLineEdit::mousePressEvent(evt);
}

void LineEditTag::mouseMoveEvent(QMouseEvent *evt)
{
    QLineEdit::mouseMoveEvent(evt);
    cursorPos = evt->pos();
}

void LineEditTag::paintEvent(QPaintEvent *evt)
{
    QLineEdit::paintEvent(evt);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QFontMetrics fm = fontMetrics();
    QRectF r = rect();
    double space = double(r.height()-fm.height())/2;
    int padding = 4;
    int cross_size = int(r.height()-space*2);
    r.setX(padding);
    r.setY(double(r.height()-fm.height())/4);
    QPen pen = painter.pen();
    QBrush brush = painter.brush();
    // Stackoverflow tag like
    QColor tag_bg(225, 236, 244);
    QColor tag_txt(44, 87, 119);
    int x_offset = padding;
    int idx = 0;
    for (const QString& tag : tags){
        QRect tag_rect = fm.boundingRect(tag);
        r.setWidth(tag_rect.width()+(padding*2)+(padding+cross_size));
        r.setHeight(tag_rect.height()+space);
        QRectF cross_rect = QRectF(r.x()+r.width()-cross_size-padding, space, cross_size, cross_size);
        if (cross_rect.contains(clickedPos)){
            clickedPos = QPoint();
            tags.removeAt(idx);
        } else {
            QPainterPath tag_path;
            tag_path.addRoundedRect(r, 2, 2);
            // Draw tag background and text
            painter.fillPath(tag_path, QBrush(tag_bg));
            painter.setPen(tag_txt);
            painter.drawText(QRectF(r.x()+padding, 0, tag_rect.width(), height()), Qt::AlignVCenter, tag);
            // Draw the cross to remove tag
            bool isHovered = r.contains(cursorPos);
            if (isHovered){
                // Manage the hovered
                QPainterPath cross_path;
                cross_path.addRoundedRect(cross_rect, 2, 2);
                painter.fillPath(cross_path, QBrush(tag_txt));
                // Manage the remove tag mouse cursor
                if (cross_rect.contains(cursorPos)){
                    setCursor(Qt::PointingHandCursor);
                } else {
                    setCursor(Qt::ArrowCursor);
                }
            }
            pen.setWidth(2);
            pen.setColor( (isHovered ? tag_bg : tag_txt) );
            painter.setPen(pen);
            QPointF topL = cross_rect.topLeft(), topR = cross_rect.topRight(), botL = cross_rect.bottomLeft(), botR = cross_rect.bottomRight();
            topL.setX(topL.x()+3);
            topL.setY(topL.y()+3);
            topR.setX(topR.x()-3);
            topR.setY(topR.y()+3);
            botL.setX(botL.x()+3);
            botL.setY(botL.y()-3);
            botR.setX(botR.x()-3);
            botR.setY(botR.y()-3);
            painter.drawLine(topL, botR);
            painter.drawLine(topR, botL);

            x_offset += r.width()+(padding);
            r.setX(x_offset);
            idx++;
        }
    }
    if (textMargins().left() != (x_offset)){
        if (tags.isEmpty()){
            setTextMargins(0, 0, 0, 0);
        } else {
            setTextMargins(x_offset-padding, 0, 0, 0);
        }
    }
}
