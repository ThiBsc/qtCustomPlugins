#include "imageframe.h"
#include <QPainter>

ImageFrame::ImageFrame(QWidget *parent)
	: QFrame(parent)
	, m_aspectRatioMode(Qt::KeepAspectRatio)
{
	setPixmap(QPixmap());
	m_nopixmap.load("://icons/photo.png", nullptr, Qt::AutoColor);
}

ImageFrame::ImageFrame(const QPixmap pixmap, QWidget *parent)
	: QFrame(parent)
	, m_aspectRatioMode(Qt::KeepAspectRatio)
{
	setPixmap(pixmap);
	m_nopixmap.load("://icons/photo.png", nullptr, Qt::AutoColor);
}

ImageFrame::~ImageFrame()
{

}

QPixmap ImageFrame::getPixmap() const
{
	return m_pixmap;
}

void ImageFrame::setPixmap(QPixmap pixmap)
{
	m_pixmap = pixmap;
	update();
}

Qt::AspectRatioMode ImageFrame::getAspectRatioMode() const
{
	return m_aspectRatioMode;
}

void ImageFrame::setAspectRatioMode(Qt::AspectRatioMode ratiomode)
{
	m_aspectRatioMode = ratiomode;
	update();
}

void ImageFrame::paintEvent(QPaintEvent * event)
{
	QFrame::paintEvent(event);
	QPainter painter(this);
	QPen pen = painter.pen();
	int w = width(), h = height();
	QPixmap pix;
	if (m_pixmap.isNull()) {
		pen.setStyle(Qt::DashLine);
		pen.setColor(QColor(Qt::lightGray));
		pen.setWidth(2);
		painter.setPen(pen);
		QRect frame(1, 1, w-pen.width(), h-pen.width());
		painter.drawRect(frame);
		pix = m_nopixmap.scaled(QSize(w/2, h/2), Qt::KeepAspectRatio);
		painter.drawPixmap(w/2-pix.width()/2, h/2-pix.height()/2, pix);
	} else {
		pix = m_pixmap.scaled(w, h, m_aspectRatioMode);
		if (pix.width() < w || pix.height() < h){
			// Center
			painter.drawPixmap(w/2-pix.width()/2, h/2-pix.height()/2, pix);
		} else {
			painter.drawPixmap(0, 0, pix);
		}
	}
}
