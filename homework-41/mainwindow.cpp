#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "stopwatch.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("STOPWATCH");
    ui->lapButton->setEnabled(false);
    connect(&stopwatch, &Stopwatch::timeUpdated, this, &MainWindow::updateDisplay);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startStopButton_clicked()
{
    stopwatch.startStop();
    ui->startStopButton->setText(stopwatch.isRunning() ? "STOP" : "START");
    ui->lapButton->setEnabled(stopwatch.isRunning());
}

void MainWindow::on_resetButton_clicked()
{
    stopwatch.reset();
    ui->finalTime->setText("0 SEC.");
    ui->lapBrowser->clear();
    ui->lapButton->setEnabled(false);
    ui->startStopButton->setText("START");
}

void MainWindow::on_lapButton_clicked()
{
    stopwatch.lap();
}

void MainWindow::updateDisplay()
{
    ui->finalTime->setText(stopwatch.getTime());
    ui->lapBrowser->setPlainText(stopwatch.getLaps().join("\n"));
}
