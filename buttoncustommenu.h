#ifndef BUTTONCUSTOMMENU_H
#define BUTTONCUSTOMMENU_H

#include <QPushButton>
#include <QMenu>
#include <QAction>
#include <QContextMenuEvent>
#include <QDebug>
#include "filecontroller.h"

class BUTTONCUSTOMMENU : public QPushButton {
public:
    BUTTONCUSTOMMENU(QWidget* parent = nullptr);
    BUTTONCUSTOMMENU(const QString& text, FileController* ref,QWidget* parent  = nullptr);

    //void initializeContextMenu();
private:
    FileController* file_operator;
protected:
    void contextMenuEvent(QContextMenuEvent* event) override {
        QMenu menu(this);

        QAction* copyAction = menu.addAction("Copy");
        QAction* cutAction = menu.addAction("Cut");
        QAction* pasteAction = menu.addAction("Paste");
        QAction* deleteAction = menu.addAction("Delete");

        // Show the context menu at the mouse position
        QAction* selectedItem = menu.exec(event->globalPos());
        QString tooltip = toolTip();
        // Handle the selected action (if any)
        if (selectedItem == copyAction) {
            // Accessing the tooltip of the button
           // QString tooltip = toolTip();
            if (!tooltip.isEmpty()) {
                file_operator->copy(tooltip.toStdString());
            }
            qDebug("copy");
            qDebug() << tooltip.toStdString();
        } else if (selectedItem == cutAction) {

            if (!tooltip.isEmpty()) {
                file_operator->cut(tooltip.toStdString());
            }
            qDebug("cut");
            qDebug() << tooltip.toStdString();
        } else if (selectedItem == pasteAction) {
            std::filesystem::path pathObj(tooltip.toStdString());
            qDebug("Paste");
            qDebug() << tooltip.toStdString();

            if (std::filesystem::is_directory(pathObj)) {
                file_operator->paste(tooltip.toStdString());
                 qDebug("Done");

            }
        }else if (selectedItem == deleteAction) {

            if (!tooltip.isEmpty()) {
                file_operator->remove(tooltip.toStdString());
            }
            qDebug("Deleted");
            qDebug() << tooltip.toStdString();
        }
    }

};

#endif // BUTTONCUSTOMMENU_H
