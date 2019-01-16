#ifndef LINEEDITTAGPLUGIN_H
#define LINEEDITTAGPLUGIN_H

#include <QDesignerCustomWidgetInterface>

/**
 * @brief The LineEditTagPlugin class
 * http://doc.qt.io/archives/qt-4.8/designer-creating-custom-widgets.html
 */
class LineEditTagPlugin : public QObject, public QDesignerCustomWidgetInterface
{
    Q_OBJECT
    Q_INTERFACES(QDesignerCustomWidgetInterface)
#if QT_VERSION >= 0x050000
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QDesignerCustomWidgetInterface")
#endif // QT_VERSION >= 0x050000

public:
    LineEditTagPlugin(QObject *parent = Q_NULLPTR);

    bool isContainer() const;
    bool isInitialized() const;
    QIcon icon() const;
    QString domXml() const;
    QString group() const;
    QString includeFile() const;
    QString name() const;
    QString toolTip() const;
    QString whatsThis() const;
    QWidget *createWidget(QWidget *parent);
    void initialize(QDesignerFormEditorInterface *core);

private:
    bool m_initialized;
};

#endif // LINEEDITTAGPLUGIN_H
