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
#include <QCheckBox>
#include <QLabel>
#include <filesystem>
//#include <QDragEnterEvent>
//#include <QDropEvent>
//#include <QMimeData>
//#include <QUrl>
//#include <QDebug>
#include "buttoncustommenu.h"
#include "ScrollCustomMenu.h"
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

    /*
protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;*/
private slots:
    void handleButtonClick(FileInList* file);
    void BrowserButtonClick(FileInList* file);
    void on_lineEdit_returnPressed();

    void on_pushButton_Prev_clicked();

    void on_pushButton_Next_clicked();

    void on_checkBox_stateChanged(int arg1);

    //void showContextMenu(const QPoint& pos);
private:
    void Folders();
    void Update();
    void Update_browser();
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
