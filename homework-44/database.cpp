#include "database.h"
#include <QDebug>

DataBase::DataBase(QObject *parent) : QObject(parent)
{
    dataBase = new QSqlDatabase(QSqlDatabase::addDatabase(POSTGRE_DRIVER));
    view = new QTableView();
    tableModel = nullptr;
    queryModel = nullptr;
}

DataBase::~DataBase()
{
    delete dataBase;
    delete view;
    delete tableModel;
    delete queryModel;
}

void DataBase::AddDataBase(QString driver, QString nameDB)
{
    *dataBase = QSqlDatabase::addDatabase(driver, nameDB);
}

void DataBase::ConnectToDataBase(QVector<QString> data)
{
    dataBase->setHostName(data[hostName]);
    dataBase->setDatabaseName(data[dbName]);
    dataBase->setUserName(data[login]);
    dataBase->setPassword(data[pass]);
    dataBase->setPort(data[port].toInt());

    bool status = dataBase->open();
    if(status) {
        tableModel = new QSqlTableModel(this, *dataBase);
        tableModel->setTable("film");
        tableModel->select();
    }
    emit sig_SendStatusConnection(status);
}

void DataBase::DisconnectFromDataBase(QString nameDb)
{
    *dataBase = QSqlDatabase::database(nameDb);
    dataBase->close();
}

void DataBase::RequestToDB(int requestType)
{
    if (!dataBase->isOpen()) {
        qDebug() << "Database not open!";
        return;
    }

    switch(requestType) {
    case requestAllFilms: {
        tableModel->setHeaderData(1, Qt::Horizontal, "Название фильма");
        tableModel->setHeaderData(2, Qt::Horizontal, "Описание фильма");
        view->setModel(tableModel);
        for (int col = 0; col < tableModel->columnCount(); ++col) {
            if (col != 1 && col != 2) {
                view->hideColumn(col);
            }
        }
        break;
    }
    case requestComedy:
    case requestHorrors: {
        QString category = (requestType == requestComedy) ? "Comedy" : "Horror";
        QString query = QString(
                            "SELECT f.title AS \"Название фильма\", f.description AS \"Описание фильма\" "
                            "FROM film f "
                            "JOIN film_category fc ON f.film_id = fc.film_id "
                            "JOIN category c ON c.category_id = fc.category_id "
                            "WHERE c.name = '%1'").arg(category);

        if(queryModel) delete queryModel;
        queryModel = new QSqlQueryModel(this);
        queryModel->setQuery(query, *dataBase);

        view->setModel(queryModel);
        break;
    }
    }
}

QSqlError DataBase::GetLastError()
{
    return dataBase->lastError();
}

QTableView* DataBase::getView() const
{
    return view;
}
