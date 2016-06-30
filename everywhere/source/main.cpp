#include "everywhere.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	everywhere w;
	w.show();
	return a.exec();
}
