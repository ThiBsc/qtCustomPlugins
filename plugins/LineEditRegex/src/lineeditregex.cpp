#include "lineeditregex.h"
#include <QRegularExpression>
#include <QRegularExpressionValidator>

LineEditRegex::LineEditRegex(QWidget *parent)
    : LineEditIcon(QIcon(), parent)
    , regex(new QRegularExpression())
{
    validator = new QRegularExpressionValidator(*regex, this);
    setValidator(validator);
}

LineEditRegex::LineEditRegex(const QString pattern, QWidget *parent)
    : LineEditIcon(QIcon(), parent)
    , regex(new QRegularExpression(pattern, QRegularExpression::NoPatternOption))
{
    validator = new QRegularExpressionValidator(*regex, this);
    setValidator(validator);
}

LineEditRegex::~LineEditRegex()
{
    delete regex;
    delete validator;
}

QString LineEditRegex::getPattern() const
{
    return regex->pattern();
}

void LineEditRegex::setPattern(const QString pattern)
{
    if (!pattern.isEmpty()){
        regex->setPattern(pattern);
        validator->setRegularExpression(QRegularExpression(pattern));
    }
}

QVariant LineEditRegex::getValue(const QString regexGroup) const
{
    QRegularExpressionMatch rem = regex->match(text());
    return rem.captured(regexGroup);
}

QVariant LineEditRegex::getValue(int group) const
{
    QRegularExpressionMatch rem = regex->match(text());
    return rem.captured(group);
}

bool LineEditRegex::isValid() const
{
    int pos = 0;
    QString input = text();
    QValidator::State state = validator->validate(input, pos);
    return state == QValidator::Acceptable;
}
