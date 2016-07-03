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
#include <QtGui/QCheckBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <QtWebKit/QWebView>

QT_BEGIN_NAMESPACE

class Ui_everywhereClass
{
public:
    QAction *action;
    QAction *action_2;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit_device;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QCheckBox *checkBox;
    QFrame *line;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QWebView *webView;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *everywhereClass)
    {
        if (everywhereClass->objectName().isEmpty())
            everywhereClass->setObjectName(QString::fromUtf8("everywhereClass"));
        everywhereClass->resize(1090, 677);
        action = new QAction(everywhereClass);
        action->setObjectName(QString::fromUtf8("action"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(14);
        action->setFont(font);
        action_2 = new QAction(everywhereClass);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        action_2->setFont(font);
        centralWidget = new QWidget(everywhereClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(400, 0));
        groupBox->setMaximumSize(QSize(400, 16777215));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(3);
        verticalLayout->setContentsMargins(3, 3, 3, 3);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 2, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 0, 3, 1, 1);

        lineEdit_device = new QLineEdit(groupBox);
        lineEdit_device->setObjectName(QString::fromUtf8("lineEdit_device"));
        lineEdit_device->setMinimumSize(QSize(200, 0));
        lineEdit_device->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(lineEdit_device, 1, 0, 1, 1);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 1, 1, 1, 1);

        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 1, 2, 1, 1);

        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setCheckable(true);
        checkBox->setChecked(true);
        checkBox->setTristate(false);

        gridLayout->addWidget(checkBox, 1, 3, 1, 1);


        verticalLayout->addLayout(gridLayout);

        line = new QFrame(groupBox);
        line->setObjectName(QString::fromUtf8("line"));
        line->setLineWidth(0);
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(3);
        verticalLayout_2->setContentsMargins(3, 3, 3, 3);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        webView = new QWebView(groupBox_2);
        webView->setObjectName(QString::fromUtf8("webView"));
        webView->setAcceptDrops(true);
        webView->setUrl(QUrl(QString::fromUtf8("file:///E:/vcprj/everywhere/everywhere/source/map.html")));

        verticalLayout_2->addWidget(webView);


        horizontalLayout->addWidget(groupBox_2);

        everywhereClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(everywhereClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1090, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        everywhereClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(everywhereClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        everywhereClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        everywhereClass->insertToolBarBreak(mainToolBar);
        statusBar = new QStatusBar(everywhereClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        everywhereClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(action);
        menu_2->addAction(action_2);

        retranslateUi(everywhereClass);

        QMetaObject::connectSlotsByName(everywhereClass);
    } // setupUi

    void retranslateUi(QMainWindow *everywhereClass)
    {
        everywhereClass->setWindowTitle(QApplication::translate("everywhereClass", "everywhere", 0, QApplication::UnicodeUTF8));
        action->setText(QApplication::translate("everywhereClass", "\347\263\273\347\273\237\351\205\215\347\275\256", 0, QApplication::UnicodeUTF8));
        action_2->setText(QApplication::translate("everywhereClass", "\345\205\263\344\272\216\350\275\257\344\273\266", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("everywhereClass", "\350\256\276\345\244\207\345\210\227\350\241\250", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("everywhereClass", "\345\234\260\345\235\200", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("everywhereClass", "\344\274\240\346\204\237\345\231\250\345\220\215\347\247\260", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("everywhereClass", "\345\200\274", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("everywhereClass", "\350\256\276\345\244\207\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        lineEdit_device->setText(QApplication::translate("everywhereClass", "\346\265\231\346\261\237\347\234\201\346\235\255\345\267\236\345\270\202\350\245\277\346\271\226\345\214\272\346\226\255\346\241\245", 0, QApplication::UnicodeUTF8));
        lineEdit->setText(QApplication::translate("everywhereClass", "1\345\217\267\346\266\262\344\275\215", 0, QApplication::UnicodeUTF8));
        lineEdit_2->setText(QApplication::translate("everywhereClass", "2.4\347\261\263", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("everywhereClass", "\345\234\250\347\272\277", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("everywhereClass", "\345\234\260\345\233\276", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("everywhereClass", "\351\205\215\347\275\256", 0, QApplication::UnicodeUTF8));
        menu_2->setTitle(QApplication::translate("everywhereClass", "\345\205\263\344\272\216", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class everywhereClass: public Ui_everywhereClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVERYWHERE_H
