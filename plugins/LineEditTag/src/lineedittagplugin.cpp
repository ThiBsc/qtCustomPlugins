#include "lineedittag.h"
#include "lineedittagplugin.h"

#include <QtPlugin>

LineEditTagPlugin::LineEditTagPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void LineEditTagPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool LineEditTagPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *LineEditTagPlugin::createWidget(QWidget *parent)
{
    return new LineEditTag(parent);
}

QString LineEditTagPlugin::name() const
{
    return QLatin1String("LineEditTag");
}

QString LineEditTagPlugin::group() const
{
    return QLatin1String("My Custom Plugins");
}

QIcon LineEditTagPlugin::icon() const
{
    return QIcon(QLatin1String("://icons/tag.png"));
}

QString LineEditTagPlugin::toolTip() const
{
    return QLatin1String("Line edit with tags");
}

QString LineEditTagPlugin::whatsThis() const
{
    return QLatin1String("Line edit with tags like the Stackoverflow tag system.");
}

bool LineEditTagPlugin::isContainer() const
{
    return false;
}

QString LineEditTagPlugin::domXml() const
{
    return QLatin1String("<widget class=\"LineEditTag\" name=\"lineEditTag\">\n</widget>\n");
}

QString LineEditTagPlugin::includeFile() const
{
    return QLatin1String("lineedittag.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(LineEditTagPlugin, LineEditTagPlugin)
#endif // QT_VERSION < 0x050000
