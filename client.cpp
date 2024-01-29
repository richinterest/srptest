// Client.cpp
#include "Client.h"
#include"clientwindow.h"
Client::Client(QObject *parent)
    : QObject(parent), tcpSocket(new QTcpSocket(this))
{
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

void Client::sendData(const QString &data) // 修改 sendDate 接收一个 QString 参数
{
    QString dataToSend = data;
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
