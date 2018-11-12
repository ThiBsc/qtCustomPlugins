#ifndef CIRCULARPROGRESS_H
#define CIRCULARPROGRESS_H

#include <QWidget>
#include <QPropertyAnimation>

/**
 * @author thibdev
 * @brief The CircularProgress class
 */

class CircularProgress : public QWidget
{
    Q_OBJECT

    Q_PROPERTY(int min READ getMin WRITE setMin NOTIFY minChanged)
    Q_PROPERTY(int max READ getMax WRITE setMax NOTIFY maxChanged)
    Q_PROPERTY(int value READ getValue WRITE setValue NOTIFY valueChanged)
    Q_PROPERTY(QColor bgColor READ getBgColor WRITE setBgColor)
    Q_PROPERTY(QColor valueColor READ getValueColor WRITE setValueColor)
    Q_PROPERTY(int barWidth READ getBarWidth WRITE setBarWidth)
    Q_PROPERTY(bool showtext READ isShowingText WRITE setTextVisible)
    Q_PROPERTY(bool infinity READ infinityMode WRITE setInfinityMode)
    Q_PROPERTY(int startAngle READ getStartAngle WRITE setStartAngle)

public:
    enum ProgressType { Filled=0, Ellipse };
    explicit CircularProgress(QWidget *parent = nullptr);
    void setProgressType(ProgressType progressType);
    int getValue() const;
    int getMin() const;
    int getMax() const;
    QColor getBgColor() const;
    QColor getValueColor() const;
    int getBarWidth() const;
    bool isShowingText() const;
    bool infinityMode() const;
    int getStartAngle() const;

signals:
    void valueChanged(int nval);
    void minChanged(int nmin);
    void maxChanged(int nmax);

public slots:
    void setValue(int value);
    void setMin(int min);
    void setMax(int max);
    void setRange(int min, int max);
    void setBgColor(QColor bgcolor);
    void setValueColor(QColor valuecolor);
    void setBarWidth(int bwidth);
    void setTextVisible(bool visible = true);
    void setInfinityMode(bool infinite);
    void setStartAngle(int s_angle);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QPropertyAnimation *m_animation;
    ProgressType m_progressType;
    QColor m_bgColor, m_valueColor;
    int m_min, m_max, m_value;
    int m_startAngle, m_barWidth;
    bool m_showTextPercent, m_infinityMode;

};

#endif // CIRCULARPROGRESS_H
