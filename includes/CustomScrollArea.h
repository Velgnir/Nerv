#include <QScrollArea>
#include <QMenu>
#include <QWidget>
#include <QContextMenuEvent>
#include <QAction>
#include "filecontroller.h"
//#include "mainwindow.h"
#ifndef CUSTOMSCROLLAREA_H
#define CUSTOMSCROLLAREA_H

#include <QScrollArea>
class MainWindow;
class CustomScrollArea : public QScrollArea {
public:
    explicit CustomScrollArea(MainWindow *mainWindow,FileController *set_file_operator,QWidget* parent = nullptr);
    FileController* file_operator;

protected:
    void contextMenuEvent(QContextMenuEvent* event) override;

private slots:
    void showContextMenu(const QPoint& /*pos*/);
    void onAction1Triggered();
    // Add more slots for other actions...

private:
    MainWindow *mainWindowRef;
         // Define your context menu and actions here
};

#endif