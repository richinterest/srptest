// Client.cpp
#include "Client.h"

Client::Client(QObject *parent)
    : QObject(parent), tcpSocket(new QTcpSocket(this))
{
    connect(tcpSocket, &QTcpSocket::connected, this, &Client::sendData);
    connect(tcpSocket, &QTcpSocket::readyRead, this, &Client::readResponse);
}

Client::~Client()
{
    delete tcpSocket;
}

void Client::connectToServer()
{
    tcpSocket->connectToHost(QHostAddress::LocalHost, 12345);

    if (tcpSocket->waitForConnected()) {
        qDebug() << "Connected to server!";
    } else {
        qDebug() << "Connection failed!";
    }
}

void Client::sendData()
{
    // 发送数据给服务器
    QString dataToSend = "Hello from client!";
    tcpSocket->write(dataToSend.toUtf8());
}

void Client::readResponse()
{
    if (tcpSocket->bytesAvailable() > 0)
    {
        QByteArray responseData = tcpSocket->readAll();
        qDebug() << "Client received response:" << responseData;
    }
}
