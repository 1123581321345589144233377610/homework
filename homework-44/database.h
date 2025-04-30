#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QTableWidget>

#define POSTGRE_DRIVER "QPSQL"
#define DB_NAME "MyDB"
#define NUM_DATA_FOR_CONNECT_TO_DB 5

enum fieldsForConnect{
    hostName = 0,
    dbName = 1,
    login = 2,
    pass = 3,
    port = 4
};

class DataBase : public QObject
{
    Q_OBJECT
public:
    explicit DataBase(QObject *parent = nullptr);
    ~DataBase();
    void AddDataBase(QString driver, QString nameDB = "");
    void DisconnectFromDataBase(QString nameDb = "");
    QSqlError GetLastError();
    QSqlDatabase getDatabase() const;
    void ConnectToDataBase(QVector<QString> dataForConnect);
signals:
    void sig_SendStatusConnection(bool);
private:
    QSqlDatabase *dataBase;
};

#endif // DATABASE_H
