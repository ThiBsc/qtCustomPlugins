#include "tfecircularprogress.h"
#include "tfecircularprogressplugin.h"

#include <QtPlugin>

TFeCircularProgressPlugin::TFeCircularProgressPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void TFeCircularProgressPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool TFeCircularProgressPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *TFeCircularProgressPlugin::createWidget(QWidget *parent)
{
    return new TFeCircularProgress(parent);
}

QString TFeCircularProgressPlugin::name() const
{
    return QLatin1String("TFeCircularProgress");
}

QString TFeCircularProgressPlugin::group() const
{
    return QLatin1String("My Custom Plugins");
}

QIcon TFeCircularProgressPlugin::icon() const
{
    return QIcon(QLatin1String("://icons/pie-chart.png"));
}

QString TFeCircularProgressPlugin::toolTip() const
{
    return QLatin1String("A circular progress bar");
}

QString TFeCircularProgressPlugin::whatsThis() const
{
    return QLatin1String("A circular progress bar.");
}

bool TFeCircularProgressPlugin::isContainer() const
{
    return false;
}

QString TFeCircularProgressPlugin::domXml() const
{
    return QLatin1String("<widget class=\"TFeCircularProgress\" name=\"tfecircularProgress\">\n</widget>\n");
}

QString TFeCircularProgressPlugin::includeFile() const
{
    return QLatin1String("tfecircularprogress.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(TFeCircularProgressPlugin, TFeCircularProgressPlugin)
#endif // QT_VERSION < 0x050000
