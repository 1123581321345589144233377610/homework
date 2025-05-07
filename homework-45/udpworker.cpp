#include "udpworker.h"

UDPworker::UDPworker(QObject *parent) : QObject(parent) {}

/*!
 * @brief Метод инициализирует UDP сервер
 */
void UDPworker::InitSocket()
{
    serviceUdpSocket = new QUdpSocket(this);
    usersDatagram = new QUdpSocket(this);
    /*
     * Соединяем присваиваем адрес и порт серверу и соединяем функцию
     * обраотчик принятых пакетов с сокетом
     */
    serviceUdpSocket->bind(QHostAddress::LocalHost, BIND_PORT);
    usersDatagram->bind(QHostAddress::LocalHost, BIND_PORT + 1);
    connect(serviceUdpSocket, &QUdpSocket::readyRead, this, &UDPworker::readPendingDatagrams);
    connect(usersDatagram, &QUdpSocket::readyRead, this, &UDPworker::readUsersDatagrams);
}

/*!
 * @brief Метод осуществляет обработку принятой датаграммы
 */
void UDPworker::ReadDatagram(QNetworkDatagram datagram)
{
    QByteArray data;
    data = datagram.data();
    QDataStream inStr(&data, QIODevice::ReadOnly);
    QDateTime dateTime;
    inStr >> dateTime;
    emit sig_sendTimeToGUI(dateTime);
}
/*!
 * @brief Метод осуществляет опередачу датаграммы
 */

void UDPworker::ReadUsersDatagram(QNetworkDatagram datagram){
    int size = datagram.data().size();
    QString userAddress = datagram.senderAddress().toString();
    emit sig_sendSizeAndUserAddressToGUI(size, userAddress);
}

void UDPworker::SendDatagram(QByteArray data)
{
    /*
     *  Отправляем данные на localhost и задефайненный порт
     */
    serviceUdpSocket->writeDatagram(data, QHostAddress::LocalHost, BIND_PORT);
}

void UDPworker::SendUsersDatagram(QByteArray data)
{
    usersDatagram->writeDatagram(data, QHostAddress::LocalHost, BIND_PORT + 1);
}

/*!
 * @brief Метод осуществляет чтение датаграм из сокета
 */
void UDPworker::readPendingDatagrams(void)
{
    /*
     *  Производим чтение принятых датаграмм
     */
    while(serviceUdpSocket->hasPendingDatagrams()){
            QNetworkDatagram datagram = serviceUdpSocket->receiveDatagram();
            ReadDatagram(datagram);
    }
}

void UDPworker::readUsersDatagrams(void){
    while(usersDatagram->hasPendingDatagrams()){
        QNetworkDatagram datagram = usersDatagram->receiveDatagram();
        ReadUsersDatagram(datagram);
    }
}
