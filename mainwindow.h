#include "filecontroller.h"
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QDir>
#include <QFileInfo>
#include <QWidget>
#include "ui_mainwindow.h"
#include "filecontroller.h"
#include "fileinlist.h"
#include <QCheckBox>
#include <QLabel>


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
    std::vector<FileInList> Update_File_Tree(std::vector<FileInList> tree);




private slots:
    void handleButtonClick();
    void BrowserButtonClick();
    void on_lineEdit_returnPressed();

    void on_pushButton_Prev_clicked();

    void on_pushButton_Next_clicked();

    void on_checkBox_stateChanged(int arg1);

private:
    void Folders();
    void Update();
    void Update_browser();
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
