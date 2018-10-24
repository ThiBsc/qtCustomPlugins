#include "imageframe.h"
#include "imageframeplugin.h"

#include <QtPlugin>

ImageFramePlugin::ImageFramePlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void ImageFramePlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool ImageFramePlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *ImageFramePlugin::createWidget(QWidget *parent)
{
    return new ImageFrame(parent);
}

QString ImageFramePlugin::name() const
{
    return QLatin1String("ImageFrame");
}

QString ImageFramePlugin::group() const
{
    return QLatin1String("My Custom Plugins");
}

QIcon ImageFramePlugin::icon() const
{
    return QIcon(QLatin1String("://icons/photo.png"));
}

QString ImageFramePlugin::toolTip() const
{
    return QLatin1String("An image");
}

QString ImageFramePlugin::whatsThis() const
{
    return QLatin1String("The possibility to put an image in a frame.");
}

bool ImageFramePlugin::isContainer() const
{
    return false;
}

QString ImageFramePlugin::domXml() const
{
    return QLatin1String("<widget class=\"ImageFrame\" name=\"imageFrame\">\n</widget>\n");
}

QString ImageFramePlugin::includeFile() const
{
    return QLatin1String("imageframe.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(ImageFramePlugin, ImageFramePlugin)
#endif // QT_VERSION < 0x050000
