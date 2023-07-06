#include "filecontroller.h"
#include "qscrollarea.h"
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QDir>
#include <QFileInfo>
#include <QWidget>

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    FileController Nerv;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();




private slots:
    void handleButtonClick();
    void on_lineEdit_returnPressed();

    void on_pushButton_Prev_clicked();

    void on_pushButton_Next_clicked();

private:
    void Folders();
    void Update();
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
