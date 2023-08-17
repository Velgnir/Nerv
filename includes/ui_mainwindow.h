/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
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
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *file_location;
    QLabel *file_name;
    QLabel *file_weight;
    QLabel *file_type;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1492, 642);
        actionEnter = new QAction(MainWindow);
        actionEnter->setObjectName("actionEnter");
        actionEnter->setCheckable(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(120, 10, 1361, 24));
        pushButton_Next = new QPushButton(centralwidget);
        pushButton_Next->setObjectName("pushButton_Next");
        pushButton_Next->setGeometry(QRect(60, 10, 41, 24));
        pushButton_Prev = new QPushButton(centralwidget);
        pushButton_Prev->setObjectName("pushButton_Prev");
        pushButton_Prev->setGeometry(QRect(10, 10, 41, 24));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(490, 40, 711, 551));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 709, 549));
        gridLayoutWidget = new QWidget(scrollAreaWidgetContents);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(0, 0, 711, 551));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea->setWidget(scrollAreaWidgetContents);
        scrollArea_2 = new QScrollArea(centralwidget);
        scrollArea_2->setObjectName("scrollArea_2");
        scrollArea_2->setGeometry(QRect(0, 40, 471, 551));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 469, 549));
        formLayoutWidget = new QWidget(scrollAreaWidgetContents_2);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(0, 0, 471, 551));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea_2->setWidget(scrollAreaWidgetContents_2);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(1220, 60, 81, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(1220, 180, 81, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(1220, 330, 71, 16));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(1220, 390, 61, 16));
        file_location = new QLabel(centralwidget);
        file_location->setObjectName("file_location");
        file_location->setGeometry(QRect(1350, 180, 131, 121));
        file_location->setStyleSheet(QString::fromUtf8(""));
        file_name = new QLabel(centralwidget);
        file_name->setObjectName("file_name");
        file_name->setGeometry(QRect(1350, 60, 121, 81));
        file_name->setStyleSheet(QString::fromUtf8(""));
        file_weight = new QLabel(centralwidget);
        file_weight->setObjectName("file_weight");
        file_weight->setGeometry(QRect(1350, 390, 121, 31));
        file_type = new QLabel(centralwidget);
        file_type->setObjectName("file_type");
        file_type->setGeometry(QRect(1350, 330, 121, 21));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1492, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
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
        label->setText(QCoreApplication::translate("MainWindow", "File name:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "File location:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "File type:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "File weight:", nullptr));
        file_location->setText(QString());
        file_name->setText(QString());
        file_weight->setText(QString());
        file_type->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
