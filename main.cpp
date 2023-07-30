#include <QApplication>
#include "mainwindow.h" // Your main window header file

int main(int argc, char *argv[])
{
    QApplication app(argc, argv); // Initialize the QApplication object

    // Now you can create your main window or other GUI components
    MainWindow mainWindow; // Assuming you have a class named MainWindow
    mainWindow.show();

    // Start the event loop by calling exec()
    return app.exec();
}
