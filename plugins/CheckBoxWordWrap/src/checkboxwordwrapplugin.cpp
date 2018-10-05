#include "checkboxwordwrap.h"
#include "checkboxwordwrapplugin.h"

#include <QtPlugin>

CheckBoxWordWrapPlugin::CheckBoxWordWrapPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void CheckBoxWordWrapPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool CheckBoxWordWrapPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *CheckBoxWordWrapPlugin::createWidget(QWidget *parent)
{
    return new CheckBoxWordWrap(parent);
}

QString CheckBoxWordWrapPlugin::name() const
{
    return QLatin1String("CheckBoxWordWrap");
}

QString CheckBoxWordWrapPlugin::group() const
{
    return QLatin1String("My Custom Plugins");
}

QIcon CheckBoxWordWrapPlugin::icon() const
{
    return QIcon(QLatin1String("://icons/check_icon.png"));
}

QString CheckBoxWordWrapPlugin::toolTip() const
{
    return QLatin1String("CheckBox with word-wrap");
}

QString CheckBoxWordWrapPlugin::whatsThis() const
{
    return QLatin1String("A Checkbox with auto word-wrap");
}

bool CheckBoxWordWrapPlugin::isContainer() const
{
    return false;
}

QString CheckBoxWordWrapPlugin::domXml() const
{
    return QLatin1String("<widget class=\"CheckBoxWordWrap\" name=\"checkBoxWordWrap\">\n</widget>\n");
}

QString CheckBoxWordWrapPlugin::includeFile() const
{
    return QLatin1String("checkboxwordwrap.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(checkboxwordwrapplugin, CheckBoxWordWrapPlugin)
#endif // QT_VERSION < 0x050000
