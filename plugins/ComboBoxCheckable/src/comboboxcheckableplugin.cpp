#include "comboboxcheckable.h"
#include "comboboxcheckableplugin.h"

#include <QtPlugin>

ComboBoxCheckablePlugin::ComboBoxCheckablePlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void ComboBoxCheckablePlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool ComboBoxCheckablePlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *ComboBoxCheckablePlugin::createWidget(QWidget *parent)
{
    return new ComboBoxCheckable(parent);
}

QString ComboBoxCheckablePlugin::name() const
{
    return QLatin1String("ComboBoxCheckable");
}

QString ComboBoxCheckablePlugin::group() const
{
    return QLatin1String("My Custom Plugins");
}

QIcon ComboBoxCheckablePlugin::icon() const
{
    return QIcon(QLatin1String("://icons/checklist.png"));
}

QString ComboBoxCheckablePlugin::toolTip() const
{
    return QLatin1String("ComboBox with multiple selection");
}

QString ComboBoxCheckablePlugin::whatsThis() const
{
    return QLatin1String("ComboBox with multiple selection.");
}

bool ComboBoxCheckablePlugin::isContainer() const
{
    return false;
}

QString ComboBoxCheckablePlugin::domXml() const
{
    return QLatin1String("<widget class=\"ComboBoxCheckable\" name=\"ComboBoxCheckable\">\n</widget>\n");
}

QString ComboBoxCheckablePlugin::includeFile() const
{
    return QLatin1String("comboboxcheckable.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(ComboBoxCheckablePlugin, ComboBoxCheckablePlugin)
#endif // QT_VERSION < 0x050000
