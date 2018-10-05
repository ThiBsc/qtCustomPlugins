#ifndef LINEEDITREGEX_H
#define LINEEDITREGEX_H

#include "lineediticon.h"

class QRegularExpression;
class QRegularExpressionValidator;

/**
 * @brief The LineEditRegex class
 * Allow text by regular expression
 */
class LineEditRegex : public LineEditIcon
{
    Q_OBJECT

    Q_PROPERTY(QString pattern READ getPattern WRITE setPattern)

public:
    LineEditRegex(QWidget *parent = Q_NULLPTR);
    LineEditRegex(const QString pattern, QWidget *parent = Q_NULLPTR);
    ~LineEditRegex();
    QString getPattern() const;
    void setPattern(const QString pattern);
    QVariant getValue(const QString regexGroup) const;
    QVariant getValue(int group) const;
    bool isValid() const;

private:
    QRegularExpression          *regex;
    QRegularExpressionValidator *validator;

};

#endif // LINEEDITREGEX_H
