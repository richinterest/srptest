// serverwindow.h
#ifndef SERVERWINDOW_H
#define SERVERWINDOW_H
#include "ui_serverwindow.h"
#include <QMainWindow>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include"server.h"
class ServerWindow : public QMainWindow
{
    Q_OBJECT

public:
    ServerWindow(Server* server, QWidget *parent = nullptr);
    ~ServerWindow();

private slots:
    void onSendMessage();
    void appendMessage(const QString &message);

private:
    Ui::serverwindow *ui;
    Server *server;
};

#endif // SERVERWINDOW_H
