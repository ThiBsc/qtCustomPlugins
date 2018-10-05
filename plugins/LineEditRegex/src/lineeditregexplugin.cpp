#include "lineeditregex.h"
#include "lineeditregexplugin.h"

#include <QtPlugin>

LineEditRegexPlugin::LineEditRegexPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void LineEditRegexPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool LineEditRegexPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *LineEditRegexPlugin::createWidget(QWidget *parent)
{
    return new LineEditRegex(parent);
}

QString LineEditRegexPlugin::name() const
{
    return QLatin1String("LineEditRegex");
}

QString LineEditRegexPlugin::group() const
{
    return QLatin1String("My Custom Plugins");
}

QIcon LineEditRegexPlugin::icon() const
{
    return QIcon(QLatin1String("://icons/text.png"));
}

QString LineEditRegexPlugin::toolTip() const
{
    return QLatin1String("Line edit controled by regular expression");
}

QString LineEditRegexPlugin::whatsThis() const
{
    return QLatin1String("Line edit controled by regular expression.");
}

bool LineEditRegexPlugin::isContainer() const
{
    return false;
}

QString LineEditRegexPlugin::domXml() const
{
    return QLatin1String("<widget class=\"LineEditRegex\" name=\"lineEditRegex\">\n</widget>\n");
}

QString LineEditRegexPlugin::includeFile() const
{
    return QLatin1String("lineeditregex.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(LineEditRegexPlugin, LineEditRegexPlugin)
#endif // QT_VERSION < 0x050000
