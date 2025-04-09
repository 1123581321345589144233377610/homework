#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Dima's Music");
    ui->upVolume->setText("Boost the sound by 10%");
    ui->upVolume->setCheckable(true);
    ui->musicList->addItem(QString("Downfall"));
    ui->musicList->addItem(QString("Let it Snow"));
    ui->musicList->addItem(QString("Nervous"));
    ui->volume->setMinimum(0);
    ui->volume->setMaximum(10);
    ui->volume->setValue(0);
    ui->activateAudioBoost->setText("Activate audio boost");
    ui->deactivateAudioBoost->setText("Deactivate audio boost");
    ui->activateAudioBoost->setCheckable(true);
    ui->deactivateAudioBoost->setCheckable(true);
    ui->activateAudioBoost->setChecked(true);
    connect(ui->upVolume, SIGNAL(clicked()), this, SLOT(onUpVolumeClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onUpVolumeClicked(){
    if(ui->activateAudioBoost->isChecked()){
        if(ui->volume->value() < 10){
            ui->volume->setValue(ui->volume->value() + 1);
        }else{
            ui->volume->setValue(0);
        }
    }
}
