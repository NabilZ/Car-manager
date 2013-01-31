/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri 14. Oct 22:29:45 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton_client;
    QPushButton *pushButton_auto;
    QPushButton *pushButton_hire;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(300, 300);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(300, 300));
        MainWindow->setMaximumSize(QSize(300, 300));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton_client = new QPushButton(centralWidget);
        pushButton_client->setObjectName(QString::fromUtf8("pushButton_client"));
        pushButton_client->setGeometry(QRect(110, 50, 83, 22));
        pushButton_auto = new QPushButton(centralWidget);
        pushButton_auto->setObjectName(QString::fromUtf8("pushButton_auto"));
        pushButton_auto->setGeometry(QRect(110, 100, 85, 23));
        pushButton_hire = new QPushButton(centralWidget);
        pushButton_hire->setObjectName(QString::fromUtf8("pushButton_hire"));
        pushButton_hire->setGeometry(QRect(110, 150, 85, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 300, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\237\321\200\320\276\320\272\320\260\321\202 \320\260\320\262\321\202\320\276\320\274\320\276\320\261\320\270\320\273\320\265\320\271", 0, QApplication::UnicodeUTF8));
        pushButton_client->setText(QApplication::translate("MainWindow", "Client", 0, QApplication::UnicodeUTF8));
        pushButton_auto->setText(QApplication::translate("MainWindow", "Car", 0, QApplication::UnicodeUTF8));
        pushButton_hire->setText(QApplication::translate("MainWindow", "Hire", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
