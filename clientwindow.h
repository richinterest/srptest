#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H
#include <ui_clientwindow.h>
#include <QWidget>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include"client.h"

class ClientWindow: public QWidget{
    Q_OBJECT;
public:
   ClientWindow(Client *client,QWidget *parent=nullptr);
    ~ClientWindow();
signals:
    void messageSent(const QString &message);
private slots:
    void onSendMessage();

private:
    Ui::clientwindow *ui;
    Client *client;
};

#endif // CLIENTWINDOW_H
