// server.cpp
#include "server.h"

Server::Server(QObject *parent)
    : QObject(parent), tcpServer(new QTcpServer(this))
{
    connect(tcpServer, &QTcpServer::newConnection, this, &Server::handleConnection);
}

Server::~Server()
{
    for (QTcpSocket* client : clients) {
        client->close();
        client->deleteLater();
    }

    tcpServer->close();
    delete tcpServer;
}

void Server::startServer()
{
    if (!tcpServer->listen(QHostAddress::Any, 12345)) {
        qDebug() << "Server could not start!";
    } else {
        qDebug() << "Server started!";
    }
}

void Server::handleConnection()
{
    QTcpSocket *newClient = tcpServer->nextPendingConnection();
    qDebug() << "New client connected: " << newClient->peerAddress().toString();

    clients.append(newClient);

    connect(newClient, &QTcpSocket::readyRead, this, &Server::readData);
}

void Server::readData()
{
    for (QTcpSocket* client : clients) {
        if (client->bytesAvailable() > 0) {
            QByteArray data = client->readAll();
            qDebug() << "Client data received: " << data;

            // Broadcast the message to all clients
            for (QTcpSocket* otherClient : clients) {
                if (otherClient != client) {
                    otherClient->write(data);
                }
            }
        }
    }
}
