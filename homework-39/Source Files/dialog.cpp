#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setWindowTitle("CONNECT TO DATABASE");
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(onPushButtonClicked()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::onPushButtonClicked()
{
    database = QSqlDatabase::addDatabase("MYSQL");
    QString host = ui->host->text();
    QString databaseName = ui->database->text();
    QString login = ui->login->text();
    QString password = ui->password->text();
    unsigned int port = ui->port->text().toUInt();
    database.setHostName(host);
    database.setPort(port);
    database.setDatabaseName(databaseName);
    database.setUserName(login);
    database.setPassword(password);
    if(!database.open()){
        ui->result->setText("<font color='red' size='12' face='Bahnschrift'>NO CONNECTION!</font>");
    }else{
        ui->result->setText("<font color='green' size='12' face='Bahnschrift'>THERE'S A CONNECTION!</font>");
    }
}
