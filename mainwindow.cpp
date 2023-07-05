#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "filecontroller.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Nerv = *new FileController;
    ui->lineEdit->setText( QString::fromStdString("C:\\"));
    Update();
    QString Qpath = QString::fromStdString(Nerv.ShowPath());
    ui->lineEdit->setText(Qpath);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Folders() {
    QLayoutItem* item;
    while ((item = ui->gridLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }
    int x=0,y=0;
    for (const auto& file : Nerv.ShowFilesList()) {
        QPushButton* button1 = new QPushButton(QString::fromStdString(file));
        button1->setMaximumWidth(75);
        button1->setMaximumHeight(75);
        button1->setMinimumHeight(75);
        connect(button1, &QPushButton::clicked, this, &MainWindow::handleButtonClick);
        ui->gridLayout->addWidget(button1, y, x);
        ++x;
        if(x==5){
            x=0;
            ++y;
        }
    }

}
void MainWindow::Update() {
    Nerv.SetPath(ui->lineEdit->text().toStdString());
    if(Nerv.UpdateFiles()){
        std::string FileListBrowser = "";
        for (const auto& file : Nerv.ShowFilesList()) {
            FileListBrowser += file + "\n";
        }
        QString qstr = QString::fromStdString(FileListBrowser);
        ui->textBrowser->setText(qstr);
        Folders();
        ui->gridLayout->update();

    }

}

void MainWindow::on_lineEdit_returnPressed()
{
    Update();
    //TODO: rewrite it to its own function
    QString Qdir = QString::fromStdString(Nerv.ShowPath());
    QFileInfo fileInfo(Qdir);
    if (fileInfo.isDir()) {
        Nerv.current_history_moment=Nerv.History.size();
        Nerv.History.push_back(Nerv.ShowPath());

    }
}

void MainWindow::handleButtonClick() {
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
    /*
    if (clickedButton) {
        QString buttonName = clickedButton->text();
        qDebug() << "Button clicked: " << buttonName;
    }
*/
    if (clickedButton) {
        QString qstr = QString::fromStdString(Nerv.ShowPath()+"\\");
        ui->lineEdit->setText(qstr+clickedButton->text());
        Update();
        //TODO: rewrite it to its own function
        QString Qdir = QString::fromStdString(Nerv.ShowPath());
        QFileInfo fileInfo(Qdir);
        if (fileInfo.isDir()) {
            Nerv.current_history_moment=Nerv.History.size();
            Nerv.History.push_back(Nerv.ShowPath());

        }
    }
}

void MainWindow::on_pushButton_Prev_clicked()
{

    if(Nerv.current_history_moment>0){

        QString qstr = QString::fromStdString(Nerv.History[Nerv.current_history_moment-1]);
        ui->lineEdit->setText(qstr);
        Nerv.current_history_moment--;
        //Nerv.History.push_back(Nerv.ShowPath());
        Update();
    }

}


void MainWindow::on_pushButton_Next_clicked()
{
    if(Nerv.current_history_moment<Nerv.History.size()-1){
        QString qstr = QString::fromStdString(Nerv.History[Nerv.current_history_moment+1]);
        ui->lineEdit->setText(qstr);
        Nerv.current_history_moment++;
        //Nerv.History.push_back(Nerv.ShowPath());
        Update();
    }
}

