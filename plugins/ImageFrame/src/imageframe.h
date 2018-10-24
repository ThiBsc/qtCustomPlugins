#ifndef IMAGE_H
#define IMAGE_H

#include <QFrame>
#include <QPixmap>

/**
 * @author thibdev
 * @brief The Image class
 */
class ImageFrame : public QFrame
{
	Q_OBJECT

	Q_PROPERTY(QPixmap pixmap READ getPixmap WRITE setPixmap)
	Q_PROPERTY(Qt::AspectRatioMode ratiomode READ getAspectRatioMode WRITE setAspectRatioMode)

public:
	ImageFrame(QWidget *parent = Q_NULLPTR);
	ImageFrame(const QPixmap pixmap, QWidget *parent = Q_NULLPTR);
	~ImageFrame();
	QPixmap getPixmap() const;
	void setPixmap(QPixmap pixmap);
	Qt::AspectRatioMode getAspectRatioMode() const;
	void setAspectRatioMode(Qt::AspectRatioMode ratiomode);

protected:
	void paintEvent(QPaintEvent *event) override;

private:
	QPixmap m_pixmap, m_nopixmap;
	Qt::AspectRatioMode m_aspectRatioMode;
	bool hasPixmap;
	
};

#endif // LINEEDITICON_H
