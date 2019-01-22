#ifndef LINEEDITTAG_H
#define LINEEDITTAG_H

#include <QLineEdit>

/**
 * @author thibdev
 * @brief The LineEditTag class
 */
class LineEditTag : public QLineEdit
{
    Q_OBJECT

    Q_PROPERTY(QString tags READ getTagsStr WRITE setTags)

public:
    explicit LineEditTag(QWidget *parent = nullptr);
    ~LineEditTag() override;
    QStringList getTags() const;
    QString getTagsStr() const;
    void setTags(const QString& tags);
    void setTags(const QStringList& tags);

private slots:
    void addTag();

protected:
    void leaveEvent(QEvent *evt) override;
    void keyPressEvent(QKeyEvent *evt) override;
    void mousePressEvent(QMouseEvent *evt) override;
    void mouseMoveEvent(QMouseEvent *evt) override;
    void paintEvent(QPaintEvent *evt) override;

private:
    QStringList tags;
    QPoint cursorPos, clickedPos;

};

#endif // LINEEDITTAG_H
