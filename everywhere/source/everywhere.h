#ifndef EVERYWHERE_H
#define EVERYWHERE_H

#include <QtGui/QMainWindow>
#include "ui_everywhere.h"

class everywhere : public QMainWindow
{
	Q_OBJECT

public:
	everywhere(QWidget *parent = 0, Qt::WFlags flags = 0);
	~everywhere();
public slots:
	void display_marker_on_map(void);

private:
	Ui::everywhereClass ui;
};

#endif // EVERYWHERE_H
