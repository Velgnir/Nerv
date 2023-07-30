#include "buttoncustommenu.h"

BUTTONCUSTOMMENU::BUTTONCUSTOMMENU(QWidget* parent)
    : QPushButton(parent)
{
    //initializeContextMenu();
}

BUTTONCUSTOMMENU::BUTTONCUSTOMMENU(const QString& text, FileController* ref,QWidget* parent)
    : QPushButton(text, parent)
{
    file_operator= ref;
    //initializeContextMenu();
}





