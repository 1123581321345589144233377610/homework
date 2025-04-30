#include "dbdata.h"
#include "database.h"
#include "ui_dbdata.h"

DbData::DbData(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DbData)
{
    ui->setupUi(this);
    ui->le_host->setText("981757-ca08998.tmweb.ru");
    ui->le_dbName->setText("netology_cpp");
    ui->le_login->setText("netology_usr_cpp");
    ui->le_pass->setText("CppNeto3");
    ui->spB_port->setValue(5432);
    data.resize(NUM_DATA_FOR_CONNECT_TO_DB);

}

DbData::~DbData()
{
    delete ui;
}

void DbData::on_buttonBox_accepted()
{
    data[hostName] = ui->le_host->text();
    data[dbName] = ui->le_dbName->text();
    data[login] = ui->le_login->text();
    data[pass] = ui->le_pass->text();
    data[port] = ui->spB_port->text();
    emit sig_sendData(data);
}
