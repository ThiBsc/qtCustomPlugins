#ifndef CIRCULARPROGRESS_H
#define CIRCULARPROGRESS_H

#include <QWidget>

/**
 * @author thibdev
 * @brief The Image class
 */

class CircularProgress : public QWidget
{
    Q_OBJECT

    Q_PROPERTY(qreal min READ getMin WRITE setMin NOTIFY minChanged)
    Q_PROPERTY(qreal max READ getMax WRITE setMax NOTIFY maxChanged)
    Q_PROPERTY(qreal value READ getValue WRITE setValue NOTIFY valueChanged)
	Q_PROPERTY(QColor bgColor READ getBgColor WRITE setBgColor)
	Q_PROPERTY(QColor valueColor READ getValueColor WRITE setValueColor)
	Q_PROPERTY(int barWidth READ getBarWidth WRITE setBarWidth)
	Q_PROPERTY(bool showtext READ isShowingText WRITE setTextVisible)

public:
    enum ProgressType { Filled=0, Ellipse };
    explicit CircularProgress(QWidget *parent = nullptr);
    void setProgressType(ProgressType progressType);
    qreal getValue() const;
    void setValue(qreal value);
    qreal getMin() const;
    void setMin(qreal min);
    qreal getMax() const;
    void setMax(qreal max);
    void setRange(qreal min, qreal max);
	QColor getBgColor() const;
	void setBgColor(QColor bgcolor);
	QColor getValueColor() const;
	void setValueColor(QColor valuecolor);
	int getBarWidth() const;
	void setBarWidth(int bwidth);
	bool isShowingText() const;
	void setTextVisible(bool visible = true);

signals:
    void valueChanged(qreal nval);
    void minChanged(qreal nmin);
    void maxChanged(qreal nmax);

public slots:

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    ProgressType m_progressType;
    QColor m_bgColor, m_valueColor;
    qreal m_min, m_max, m_value;
    int m_barWidth;
	bool m_showTextPercent;

};

#endif // CIRCULARPROGRESS_H
