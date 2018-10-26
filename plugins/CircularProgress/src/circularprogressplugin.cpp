#include "circularprogress.h"
#include "circularprogressplugin.h"

#include <QtPlugin>

CircularProgressPlugin::CircularProgressPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void CircularProgressPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool CircularProgressPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *CircularProgressPlugin::createWidget(QWidget *parent)
{
    return new CircularProgress(parent);
}

QString CircularProgressPlugin::name() const
{
    return QLatin1String("CircularProgress");
}

QString CircularProgressPlugin::group() const
{
    return QLatin1String("My Custom Plugins");
}

QIcon CircularProgressPlugin::icon() const
{
    return QIcon(QLatin1String("://icons/pie-chart.png"));
}

QString CircularProgressPlugin::toolTip() const
{
    return QLatin1String("A circular progress bar");
}

QString CircularProgressPlugin::whatsThis() const
{
    return QLatin1String("A circular progress bar.");
}

bool CircularProgressPlugin::isContainer() const
{
    return false;
}

QString CircularProgressPlugin::domXml() const
{
    return QLatin1String("<widget class=\"CircularProgress\" name=\"circularProgress\">\n</widget>\n");
}

QString CircularProgressPlugin::includeFile() const
{
    return QLatin1String("circularprogress.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(CircularProgressPlugin, CircularProgressPlugin)
#endif // QT_VERSION < 0x050000
