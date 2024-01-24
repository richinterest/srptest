// server.h
#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QList>

class Server : public QObject
{
    Q_OBJECT

public:
    Server(QObject *parent = nullptr);
    ~Server();

public slots:
    void startServer();

private slots:
    void handleConnection();
    void readData();

private:
    QTcpServer *tcpServer;
    QList<QTcpSocket*> clients;
};

#endif // SERVER_H
