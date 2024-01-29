// Client.h
#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>

class Client : public QObject
{
    Q_OBJECT

public:
    Client(QObject *parent = nullptr);
    ~Client();

public slots:
    void connectToServer();
    void sendData(const QString &data);

private slots:
    void readResponse();

private:
    QTcpSocket *tcpSocket;
};

#endif // CLIENT_H
