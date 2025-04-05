#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("CONNECT TO DATABASE");
    dialog = new Dialog(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(onPushButtonClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onPushButtonClicked()
{
    dialog->show();
}
