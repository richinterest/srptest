#include <QApplication>
#include"clientwindow.h""
#include"serverwindow.h"
#include"server.h"
#include"client.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Create an instance of the Server class
    Server server;

    // Create an instance of the ServerWindow class and associate it with the server
    ServerWindow ServerWindow(&server);
    ServerWindow.show();

    // Create an instance of the Client class
    Client client;

    // Create an instance of the ClientWindow class and associate it with the client
    ClientWindow ClientWindow(&client);
    ClientWindow.show();

    return a.exec();
}
