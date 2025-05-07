#ifndef UDPWORKER_H
#define UDPWORKER_H

#include <QUdpSocket>
#include <QNetworkDatagram>
#include <QDateTime>


#define BIND_PORT 12345

class UDPworker : public QObject
{
    Q_OBJECT
public:
    explicit UDPworker(QObject *parent = nullptr);
    void InitSocket(void);
    void ReadDatagram(QNetworkDatagram datagram);
    void ReadUsersDatagram(QNetworkDatagram datagram);
    void SendDatagram(QByteArray data);
    void SendUsersDatagram(QByteArray data);

private slots:
    void readPendingDatagrams(void);
    void readUsersDatagrams(void);
private:
    QUdpSocket* serviceUdpSocket;
    QUdpSocket* usersDatagram;
signals:
    void sig_sendTimeToGUI(QDateTime data);
    void sig_sendSizeAndUserAddressToGUI(int size, QString userAddress);
};

#endif // UDPWORKER_H
