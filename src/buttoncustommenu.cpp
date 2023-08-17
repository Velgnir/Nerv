#include "buttoncustommenu.h"
#include "mainwindow.h"
BUTTONCUSTOMMENU::BUTTONCUSTOMMENU(QWidget* parent)
    : QPushButton(parent)
{
    //initializeContextMenu();
}

BUTTONCUSTOMMENU::BUTTONCUSTOMMENU(MainWindow *mainwindow,const QString& text, FileController* ref,QWidget* parent)
    : QPushButton(text, parent),mainwindowref(mainwindow)
{
    file_operator= ref;
    //initializeContextMenu();
}
/*




  */
std::string BUTTONCUSTOMMENU::formatFileSize(uintmax_t size) {
    static const char* sizeSuffixes[] = { "B", "KB", "MB", "GB", "TB" };
    int i = 0;

    double fileSize = static_cast<double>(size);
    while (fileSize >= 1024 && i < 4) {
        fileSize /= 1024;
        ++i;
    }

    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << fileSize << " " << sizeSuffixes[i];
    return oss.str();
}
uintmax_t BUTTONCUSTOMMENU::getTotalDirectorySize(const std::filesystem::path& directoryPath) {
uintmax_t totalSize = 0;

for (const auto& entry : std::filesystem::recursive_directory_iterator(directoryPath)) {
if (std::filesystem::is_regular_file(entry)) {
totalSize += std::filesystem::file_size(entry);
}
}

return totalSize;
}


void BUTTONCUSTOMMENU::contextMenuEvent(QContextMenuEvent* event)  {
QMenu menu(this);

QAction* copyAction = menu.addAction("Copy");
QAction* cutAction = menu.addAction("Cut");
QAction* pasteAction = menu.addAction("Paste");
QAction* deleteAction = menu.addAction("Delete");
QAction* infoAction = menu.addAction("Properties");

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
//  qDebug("copy");
//   qDebug() << tooltip.toStdString();
} else if (selectedItem == cutAction) {

if (!tooltip.isEmpty()) {
file_operator->cut(tooltip.toStdString());
}
//  qDebug("cut");
//  qDebug() << tooltip.toStdString();
} else if (selectedItem == pasteAction) {
std::filesystem::path pathObj(tooltip.toStdString());

// qDebug("Paste");
// qDebug() << tooltip.toStdString();

if (std::filesystem::is_directory(pathObj)) {
file_operator->paste(tooltip.toStdString());
    //mainwindowref->Update();

//  qDebug("Done");

}
}else if (selectedItem == deleteAction) {

if (!tooltip.isEmpty()) {
file_operator->remove(tooltip.toStdString());
    //mainwindowref->Update();
}
// qDebug("Deleted");
// qDebug() << tooltip.toStdString();
}else if (selectedItem == infoAction) {
File_name->setText(text());
File_Location->setText(tooltip);
if (std::filesystem::is_directory(tooltip.toStdString()) ) {
File_type->setText("Directory");
File_weight->setText(QString::fromStdString(formatFileSize(getTotalDirectorySize(tooltip.toStdString()))));
} else if (std::filesystem::is_regular_file(tooltip.toStdString())) {
File_type->setText("Regular file");
File_weight->setText(QString::fromStdString(formatFileSize(std::filesystem::file_size(tooltip.toStdString()))));
} else if (std::filesystem::is_block_file(tooltip.toStdString())) {
File_type->setText("Block file");
File_weight->setText(QString::fromStdString(formatFileSize(std::filesystem::file_size(tooltip.toStdString()))));
} else if (std::filesystem::is_character_file(tooltip.toStdString())) {
File_type->setText("Character file");
File_weight->setText(QString::fromStdString(formatFileSize(std::filesystem::file_size(tooltip.toStdString()))));
} else if (std::filesystem::is_fifo(tooltip.toStdString())) {
File_type->setText("Fifo file");
File_weight->setText(QString::fromStdString(formatFileSize(std::filesystem::file_size(tooltip.toStdString()))));
} else if (std::filesystem::is_socket(tooltip.toStdString())) {
File_type->setText("Socket file");
File_weight->setText(QString::fromStdString(formatFileSize(std::filesystem::file_size(tooltip.toStdString()))));
} else if (std::filesystem::is_symlink(tooltip.toStdString())) {
File_type->setText("Symlink file");
File_weight->setText(QString::fromStdString(formatFileSize(std::filesystem::file_size(tooltip.toStdString()))));
} else {
File_type->setText("Other file");
File_weight->setText(QString::fromStdString(formatFileSize(std::filesystem::file_size(tooltip.toStdString()))));
}

// qDebug("Deleted");
// qDebug() << tooltip.toStdString();
}

}
