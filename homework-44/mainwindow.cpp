#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lb_statusConnect->setStyleSheet("color:red");
    ui->pb_request->setEnabled(false);
    dataDb = new DbData(this);
    dataBase = new DataBase(this);
    msg = new QMessageBox(this);
    dataForConnect.resize(NUM_DATA_FOR_CONNECT_TO_DB);
    dataBase->AddDataBase(POSTGRE_DRIVER, DB_NAME);
    ui->verticalLayout->insertWidget(3, dataBase->getView());
    connect(dataDb, &DbData::sig_sendData, this, [&](QVector<QString> receivData){
        dataForConnect = receivData;
    });
    connect(dataBase, &DataBase::sig_SendStatusConnection,
            this, &MainWindow::ReceiveStatusConnectionToDB);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete dataDb;
    delete dataBase;
    delete msg;
}

void MainWindow::on_act_addData_triggered()
{
    dataDb->show();
}

void MainWindow::on_act_connect_triggered()
{
    if(ui->lb_statusConnect->text() == "Отключено") {
        ui->lb_statusConnect->setText("Подключение...");
        ui->lb_statusConnect->setStyleSheet("color:black");

        QtConcurrent::run([this](){
            dataBase->ConnectToDataBase(dataForConnect);
        });
    }
    else {
        dataBase->DisconnectFromDataBase(DB_NAME);
        ui->lb_statusConnect->setText("Отключено");
        ui->lb_statusConnect->setStyleSheet("color:red");
        ui->pb_request->setEnabled(false);
    }
}

void MainWindow::on_pb_request_clicked()
{
    int requestType = ui->cb_category->currentIndex() + 1;
    dataBase->RequestToDB(requestType);
}

void MainWindow::on_pb_clear_clicked()
{
    dataBase->getView()->setModel(nullptr);
}

void MainWindow::ReceiveStatusConnectionToDB(bool status)
{
    if(status) {
        ui->act_connect->setText("Отключиться");
        ui->lb_statusConnect->setText("Подключено");
        ui->lb_statusConnect->setStyleSheet("color:green");
        ui->pb_request->setEnabled(true);
    }
    else {
        msg->setIcon(QMessageBox::Critical);
        msg->setText(dataBase->GetLastError().text());
        ui->lb_statusConnect->setText("Ошибка подключения!");
        ui->lb_statusConnect->setStyleSheet("color:red");
        msg->exec();
    }
}
