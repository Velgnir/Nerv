/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionEnter;
    QWidget *centralwidget;
    QLineEdit *lineEdit;
    QPushButton *pushButton_Next;
    QPushButton *pushButton_Prev;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1308, 648);
        actionEnter = new QAction(MainWindow);
        actionEnter->setObjectName(QString::fromUtf8("actionEnter"));
        actionEnter->setCheckable(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(120, 10, 1181, 24));
        pushButton_Next = new QPushButton(centralwidget);
        pushButton_Next->setObjectName(QString::fromUtf8("pushButton_Next"));
        pushButton_Next->setGeometry(QRect(60, 10, 41, 24));
        pushButton_Prev = new QPushButton(centralwidget);
        pushButton_Prev->setObjectName(QString::fromUtf8("pushButton_Prev"));
        pushButton_Prev->setGeometry(QRect(10, 10, 41, 24));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(490, 40, 801, 551));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 799, 549));
        gridLayoutWidget = new QWidget(scrollAreaWidgetContents);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 801, 551));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea->setWidget(scrollAreaWidgetContents);
        scrollArea_2 = new QScrollArea(centralwidget);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setGeometry(QRect(0, 40, 471, 551));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 469, 549));
        formLayoutWidget = new QWidget(scrollAreaWidgetContents_2);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(0, 0, 471, 551));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea_2->setWidget(scrollAreaWidgetContents_2);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1308, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Nerv", nullptr));
        actionEnter->setText(QCoreApplication::translate("MainWindow", "Enter", nullptr));
#if QT_CONFIG(shortcut)
        actionEnter->setShortcut(QCoreApplication::translate("MainWindow", "Return", nullptr));
#endif // QT_CONFIG(shortcut)
        pushButton_Next->setText(QCoreApplication::translate("MainWindow", "Next", nullptr));
        pushButton_Prev->setText(QCoreApplication::translate("MainWindow", "Prev", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H