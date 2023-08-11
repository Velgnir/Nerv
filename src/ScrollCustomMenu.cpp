#include "includes/ScrollCustomMenu.h"
#include <QMenu>
#include <QContextMenuEvent>
#include <QAction>

CustomScrollArea::CustomScrollArea(FileController *set_file_operator,QWidget* parent)
    : QScrollArea(parent) {
    file_operator = set_file_operator;
    // Initialize your scroll area as needed
}

void CustomScrollArea::contextMenuEvent(QContextMenuEvent* event) {
    QMenu contextMenu(this);

    QAction* action1 = contextMenu.addAction("Paste");
    // Add more actions as needed...

    connect(action1, &QAction::triggered, this, &CustomScrollArea::onAction1Triggered);
   // connect(action2, &QAction::triggered, this, &CustomScrollArea::onAction2Triggered);
    // Connect other actions to respective slots...

    contextMenu.exec(event->globalPos());
}

void CustomScrollArea::showContextMenu(const QPoint& pos) {
    // Your code to show the context menu and handle actions...
}

void CustomScrollArea::onAction1Triggered() {
    // Code for Action 1
    file_operator->paste(file_operator->ShowPath());
}

