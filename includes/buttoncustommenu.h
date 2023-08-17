#ifndef BUTTONCUSTOMMENU_H
#define BUTTONCUSTOMMENU_H

#include <QPushButton>
#include <QMenu>
#include <QAction>
#include <QLabel>
#include <QContextMenuEvent>
#include <QDebug>
#include <filesystem>
#include "filecontroller.h"

class MainWindow;

class BUTTONCUSTOMMENU : public QPushButton {
public:
    BUTTONCUSTOMMENU(QWidget* parent = nullptr);
    BUTTONCUSTOMMENU( MainWindow *mainwindow,const QString& text, FileController* ref,QWidget* parent  = nullptr);
    QLabel* File_name;
    QLabel* File_Location;
    QLabel* File_weight;
    QLabel* File_type;
    //void initializeContextMenu();
private:
    MainWindow *mainwindowref;
    FileController* file_operator;
    std::string formatFileSize(uintmax_t size);
    uintmax_t getTotalDirectorySize(const std::filesystem::path& directoryPath);
protected:
    void contextMenuEvent(QContextMenuEvent* event) override;
private slots:
    void onAction1Triggered();
};

#endif // BUTTONCUSTOMMENU_H
