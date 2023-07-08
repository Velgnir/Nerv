#include "mainwindow.h"

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


    //setCentralWidget(ui->scrollArea);

    DWORD drivesMask = GetLogicalDrives();

    std::vector<std::string> drives;

    for (char letter = 'A'; letter <= 'Z'; ++letter) {
        if (drivesMask & 1) {
            std::string drivePath = std::string(1, letter);
            FileInList* new_one = new FileInList(drivePath+":\\" ,drivePath+":\\"  ,0);
            Nerv.Files_browser.push_back(*new_one);
        }
        drivesMask >>= 1;
    }
    Update_browser();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void File_Search(std::vector<FileInList>& tree,int i, std::string path,std::vector<FileInList>& new_tree){
    if(i<tree.size()-1){
        //FileInList* new_one = new FileInList(tree[i].path,tree[i].name,tree[i].level);
        new_tree.push_back(tree[i]);

        if(tree[i].status && tree[i+1].level>tree[i].level){
            File_Search(tree,i+1,tree[i+1].path,new_tree);
        }else if(tree[i].status && tree[i+1].level<=tree[i].level){
//gotta create new
            for(const std::string& el : tree[i].FilesAt()){
                FileInList* new_one = new FileInList(path+"\\"+el,el,tree[i].level+1);
                new_tree.push_back(*new_one);
            }
            File_Search(tree,i+1,tree[i+1].path,new_tree);
        }else if(!tree[i].status){
            for(int j=i+1; j<tree.size(); ++j){
                if(tree[j].level<=tree[i].level){
                    File_Search(tree,j,tree[j].path,new_tree);
                    break;
                }
            }
        }
    }else if(i<=tree.size()-1){
        new_tree.push_back(tree[i]);
        if( tree[i].status){
                //gotta create new
                for(const std::string& el : tree[i].FilesAt()){
                    FileInList* new_one = new FileInList(path+"\\"+el,el,tree[i].level+1);
                    new_tree.push_back(*new_one);
                }

        }
    }
}
std::vector<FileInList> Update_File_Tree(std::vector<FileInList> tree){

    std::vector<FileInList> new_one;
    File_Search(tree,0,tree[0].path,new_one);

    return new_one;
}
void MainWindow::Folders() {
    QScrollArea* scrollArea = ui->scrollArea;
    QWidget* scrollContent = new QWidget;

    QVBoxLayout* scrollLayout = new QVBoxLayout(scrollContent);
    ui->gridLayout = new QGridLayout;

    scrollLayout->addLayout(ui->gridLayout);
    scrollLayout->addLayout(ui->gridLayout);
    scrollContent->setLayout(scrollLayout);
    scrollArea->setWidget(scrollContent);
    scrollContent->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

    int row = 0;
    int column = 0;
    for (const auto& file : Nerv.ShowFilesList()) {
        QPushButton* button1 = new QPushButton(QString::fromStdString(file));
        // Set button properties if needed
        button1->setMaximumWidth(100);
        button1->setMinimumHeight(100);
        connect(button1, &QPushButton::clicked, this, &MainWindow::handleButtonClick);
        ui->gridLayout->addWidget(button1,row, column);
        column++;
        if (column >=5) {
            column = 0;
            row++;
        }
    }



    //setCentralWidget(ui->scrollArea);
    //setCentralWidget(scrollArea);
}
void MainWindow::Update_browser(){

    QScrollArea* scrollArea = ui->scrollArea_2;
    QWidget* scrollContent = new QWidget;

    QVBoxLayout* scrollLayout = new QVBoxLayout(scrollContent);
    scrollLayout->setAlignment(Qt::AlignTop);  // Align the content to the top

    ui->formLayout = new QFormLayout;

    scrollLayout->addLayout(ui->formLayout);
    scrollContent->setLayout(scrollLayout);
    scrollArea->setWidget(scrollContent);
    scrollContent->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

    int WidthMultiplier = 50;

    for(int i = 0; i < Nerv.Files_browser.size(); ++i) {
        QHBoxLayout* rowLayout = new QHBoxLayout;  // Create a layout for each row

        QPushButton* button1 = new QPushButton(QString::fromStdString(Nerv.Files_browser[i].name));
        button1 ->setToolTip(QString::fromStdString(Nerv.Files_browser[i].path));
        connect(button1, &QPushButton::clicked, this, &MainWindow::BrowserButtonClick);
        QCheckBox* checkBox = new QCheckBox();
        checkBox->setMinimumWidth(Nerv.Files_browser[i].level * WidthMultiplier+20);
        checkBox->setMaximumWidth(Nerv.Files_browser[i].level * WidthMultiplier+30);
        checkBox->setChecked(Nerv.Files_browser[i].status);
        checkBox->setObjectName(QString::fromStdString(std::to_string(i)));

        connect(checkBox, SIGNAL(stateChanged(int)), this, SLOT(on_checkBox_stateChanged(int)));

        rowLayout->addWidget(checkBox);
        rowLayout->addWidget(button1);

        ui->formLayout->addRow(rowLayout);
    }


    /*    QScrollArea* scrollArea = ui->scrollArea;
    QWidget* scrollContent = new QWidget;

    QVBoxLayout* scrollLayout = new QVBoxLayout(scrollContent);
    ui->gridLayout = new QGridLayout;

    scrollLayout->addLayout(ui->gridLayout);
    scrollLayout->addLayout(ui->gridLayout);
    scrollContent->setLayout(scrollLayout);
    scrollArea->setWidget(scrollContent);
    scrollContent->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

    int row = 0;
    int column = 0;
    for (const auto& file : Nerv.ShowFilesList()) {
        QPushButton* button1 = new QPushButton(QString::fromStdString(file));
        // Set button properties if needed
        button1->setMaximumWidth(100);
        button1->setMinimumHeight(100);
        connect(button1, &QPushButton::clicked, this, &MainWindow::handleButtonClick);
        ui->gridLayout->addWidget(button1,row, column);
        column++;
        if (column >=5) {
            column = 0;
            row++;
        }
    }*/

   // QLayout* layout = ui->gridLayout_2
    //int newWidth = 5;

    //QSpacerItem* existingSpacer = ui->horizontalSpacer;

    //layout->removeItem(existingSpacer);

    //QSpacerItem* newSpacer = new QSpacerItem(newWidth, 0, QSizePolicy::Fixed, QSizePolicy::Minimum);


    //layout->addItem(newSpacer);

    //existingSpacer = newSpacer;
    //ui->gridLayout->update();

}
void MainWindow::Update() {
    Nerv.SetPath(ui->lineEdit->text().toStdString());
    if(Nerv.UpdateFiles()){


        Folders();
        //ui->gridLayout->update();

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
void MainWindow::BrowserButtonClick() {
    //TODO
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
    ui->lineEdit->setText(clickedButton->toolTip());
    Update();
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


void MainWindow::on_checkBox_stateChanged(int arg1)
{
    QCheckBox* checkbox = qobject_cast<QCheckBox*>(sender());
    Nerv.Files_browser[std::stoi(checkbox->objectName().toStdString())].status = checkbox->isChecked();
    Nerv.Files_browser=::Update_File_Tree(Nerv.Files_browser);
    Update_browser();
}
