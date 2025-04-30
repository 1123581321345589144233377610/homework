#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlTableModel>
#include <QSqlQueryModel>
#include <QDebug>

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

    dataBase->AddDataBase(POSTGRE_DRIVER, DB_NAME);

    connect(dataDb, &DbData::sig_sendData, this, [&](QVector<QString> receivData){
        dataBase->ConnectToDataBase(receivData);
    });

    connect(dataBase, &DataBase::sig_SendStatusConnection, this, &MainWindow::ReceiveStatusConnectionToDB);
    connect(ui->pb_clear, &QPushButton::clicked, this, &MainWindow::on_pb_clear_clicked);
}

void MainWindow::on_pb_request_clicked()
{
    QString category = ui->cb_category->currentText();
    QSqlQueryModel *model = new QSqlQueryModel(this);
    QString query;

    if(category == "Все") {
        query =
            "SELECT "
            "   title AS \"Название фильма\", "
            "   description AS \"Описание фильма\" "
            "FROM film";
    } else {
        QString categoryFilter = (category == "Комедия") ? "Comedy" : "Horror";
        query =
            "SELECT "
            "   f.title AS \"Название фильма\", "
            "   f.description AS \"Описание фильма\" "
            "FROM film f "
            "JOIN film_category fc ON f.film_id = fc.film_id "
            "JOIN category c ON c.category_id = fc.category_id "
            "WHERE c.name = '" + categoryFilter + "'";
    }

    model->setQuery(query, dataBase->getDatabase());

    if(model->lastError().isValid()) {
        qDebug() << "Ошибка запроса:" << model->lastError().text();
        return;
    }

    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
}

void MainWindow::on_pb_clear_clicked()
{
    ui->tableView->setModel(nullptr);
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
    if(ui->lb_statusConnect->text() == "Отключено"){
       ui->lb_statusConnect->setText("Подключение");
       ui->lb_statusConnect->setStyleSheet("color : black");
       auto conn = [&]{dataBase->ConnectToDataBase(dataForConnect);};
       QFuture<void> future = QtConcurrent::run(conn);
    }else{
        dataBase->DisconnectFromDataBase(DB_NAME);
        ui->lb_statusConnect->setText("Отключено");
        ui->act_connect->setText("Подключиться");
        ui->lb_statusConnect->setStyleSheet("color:red");
        ui->pb_request->setEnabled(false);
    }
}

void MainWindow::ScreenDataFromDB(const QTableWidget *widget, int typeRequest){}

void MainWindow::ReceiveStatusConnectionToDB(bool status)
{
    if(status){
        ui->act_connect->setText("Отключиться");
        ui->lb_statusConnect->setText("Подключено к БД");
        ui->lb_statusConnect->setStyleSheet("color:green");
        ui->pb_request->setEnabled(true);
    }
    else{
        dataBase->DisconnectFromDataBase(DB_NAME);
        msg->setIcon(QMessageBox::Critical);
        msg->setText(dataBase->GetLastError().text());
        ui->lb_statusConnect->setText("Отключено");
        ui->lb_statusConnect->setStyleSheet("color:red");
        msg->exec();
    }
}
