#include "tcpclient.h"

TCPclient::TCPclient(QObject *parent) : QObject(parent)
{
    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::connected, this, [&](){
        emit sig_connectStatus(STATUS_SUCCES);
    });
    connect(socket, &QTcpSocket::errorOccurred, this, [&](){
        emit sig_connectStatus(ERR_CONNECT_TO_HOST);});
    connect(socket, &QTcpSocket::disconnected, this, &TCPclient::sig_Disconnected);
    connect(socket, &QTcpSocket::readyRead, this, &TCPclient::ReadyRead);
}

QDataStream &operator >>(QDataStream &out, ServiceHeader &data)
{
    out >> data.id;
    out >> data.idData;
    out >> data.status;
    out >> data.len;

    return out;
};

QDataStream &operator <<(QDataStream &in, ServiceHeader &data){

    in << data.id;
    in << data.idData;
    in << data.status;
    in << data.len;

    return in;
};

QDataStream &operator >>(QDataStream &out, StatServer &data){

    out >> data.incBytes;
    out >> data.sendBytes;
    out >> data.revPck;
    out >> data.sendPck;
    out >> data.workTime;
    out >> data.clients;
    return out;
};

QDataStream &operator <<(QDataStream &in, StatServer &data){

    in << data.incBytes;
    in << data.sendBytes;
    in << data.revPck;
    in << data.sendPck;
    in << data.workTime;
    in << data.clients;

    return in;
};

void TCPclient::SendRequest(ServiceHeader head)
{
    QByteArray sendHdr;
    QDataStream outStr(&sendHdr, QIODevice::WriteOnly);
    outStr << head;
    socket->write(sendHdr);
}

void TCPclient::SendData(ServiceHeader head, QString str)
{
    QByteArray sendHdr;
    QDataStream outStr(&sendHdr, QIODevice::WriteOnly);
    outStr << head;
    outStr << str;
    socket->write(sendHdr);
}

void TCPclient::ConnectToHost(QHostAddress host, uint16_t port)
{
    socket->connectToHost(host, port);
}

void TCPclient::DisconnectFromHost()
{
    socket->disconnectFromHost();
}

void TCPclient::ReadyRead()
{

    QDataStream incStream(socket);

    if(incStream.status() != QDataStream::Ok){
        QMessageBox msg;
        msg.setIcon(QMessageBox::Warning);
        msg.setText("Ошибка открытия входящего потока для чтения данных!");
        msg.exec();
    }
    while(incStream.atEnd() == false){
        if(servHeader.idData == 0){
            if(socket->bytesAvailable() < sizeof(ServiceHeader)){
                return;
            }else{
                incStream >> servHeader;
                if(servHeader.id != ID){
                    uint16_t hdr = 0;
                    while(incStream.atEnd()){
                        incStream >> hdr;
                        if(hdr == ID){
                            incStream >> servHeader.idData;
                            incStream >> servHeader.status;
                            incStream >> servHeader.len;
                            break;
                        }
                    }
                }
            }
        }
        if(socket->bytesAvailable() < servHeader.len){
            return;
        }else{
            ProcessingData(servHeader, incStream);
            servHeader.idData = 0;
            servHeader.status = 0;
            servHeader.len = 0;
        }
    }
}

void TCPclient::ProcessingData(ServiceHeader header, QDataStream &stream)
{
    switch (header.idData){
    case GET_TIME: {
        QDateTime time;
        stream >> time;
        emit sig_sendTime(time);
        break;
    }
    case GET_SIZE: {
        uint32_t len;
        stream >> len;
        emit sig_sendFreeSize(len);
        break;
    }
    case GET_STAT: {
        StatServer status;
        stream >> status;
        emit sig_sendStat(status);
        break;
    }

    case SET_DATA: {
        QString message;
        stream >> message;
        if (header.status == ERR_NO_FREE_SPACE)
        {
            message = "ERR_NO_FREE_SPACE";
        }
        emit sig_SendReplyForSetData(message);
        break;
    }
    case CLEAR_DATA: {
        QString message = "данные на сервере очищены";
        emit sig_SendReplyForSetData(message);
        break;
    }
    default:
        return;

    }
}
