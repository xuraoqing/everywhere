/********************************************************************************
** Form generated from reading UI file 'everywhere.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVERYWHERE_H
#define UI_EVERYWHERE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_everywhereClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *everywhereClass)
    {
        if (everywhereClass->objectName().isEmpty())
            everywhereClass->setObjectName(QString::fromUtf8("everywhereClass"));
        everywhereClass->resize(600, 400);
        menuBar = new QMenuBar(everywhereClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        everywhereClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(everywhereClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        everywhereClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(everywhereClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        everywhereClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(everywhereClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        everywhereClass->setStatusBar(statusBar);

        retranslateUi(everywhereClass);

        QMetaObject::connectSlotsByName(everywhereClass);
    } // setupUi

    void retranslateUi(QMainWindow *everywhereClass)
    {
        everywhereClass->setWindowTitle(QApplication::translate("everywhereClass", "everywhere", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class everywhereClass: public Ui_everywhereClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVERYWHERE_H
