#include "everywhere.h"
#include <QWebFrame>

everywhere::everywhere(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	QObject::connect(ui.lineEdit_device,SIGNAL(returnPressed()),this,SLOT(display_marker_on_map(void)));
}

everywhere::~everywhere()
{

}
void everywhere::display_marker_on_map(void)
{
	QString location;
	location = "add_marker(\"" + ui.lineEdit_device->text() + "\")";
	ui.webView->page()->mainFrame()->evaluateJavaScript(location);
}
