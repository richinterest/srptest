#include <QApplication>
#include"clientwindow.h""
#include"serverwindow.h"
#include"server.h"
#include"client.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Server server;
    server.startServer();
    // Create an instance of the ServerWindow class and associate it with the server
    ServerWindow serverWindow(&server);
    serverWindow.show();
    // Create an instance of the Client class
    Client client;
    client.connectToServer();

    // Create an instance of the ClientWindow class and associate it with the client
    ClientWindow clientWindow(&client);
    clientWindow.show();

    return a.exec();
}
