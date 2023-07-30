#include "filecontroller.h"
#ifndef CUSTOMSCROLLAREA_H
#define CUSTOMSCROLLAREA_H

#include <QScrollArea>

class CustomScrollArea : public QScrollArea {
    Q_OBJECT

public:
    explicit CustomScrollArea(FileController *set_file_operator,QWidget* parent = nullptr);
    FileController* file_operator;

protected:
    void contextMenuEvent(QContextMenuEvent* event) override;

private slots:
    void showContextMenu(const QPoint& pos);
    void onAction1Triggered();
    // Add more slots for other actions...

private:
         // Define your context menu and actions here
};

#endif
