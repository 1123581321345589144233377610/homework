#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlError>
#include <QTableView>

#define POSTGRE_DRIVER "QPSQL"
#define DB_NAME "MyDB"
#define NUM_DATA_FOR_CONNECT_TO_DB 5

enum fieldsForConnect {
    hostName = 0,
    dbName = 1,
    login = 2,
    pass = 3,
    port = 4
};

enum requestType {
    requestAllFilms = 1,
    requestComedy   = 2,
    requestHorrors  = 3
};

class DataBase : public QObject
{
    Q_OBJECT
public:
    explicit DataBase(QObject *parent = nullptr);
    ~DataBase();

    void AddDataBase(QString driver, QString nameDB = "");
    void DisconnectFromDataBase(QString nameDb = "");
    void RequestToDB(int requestType);
    QSqlError GetLastError();
    void ConnectToDataBase(QVector<QString> dataForConnect);
    QTableView* getView() const;

signals:
    void sig_SendStatusConnection(bool);

private:
    QSqlDatabase* dataBase;
    QSqlTableModel* tableModel;
    QSqlQueryModel* queryModel;
    QTableView* view;
};

#endif // DATABASE_H
