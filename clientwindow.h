#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H
#include <ui_clientwindow.h>
#include <QMainWindow>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>

class ClientWindow: public QWidget{
    Q_OBJECT;
public:
   ClientWindow(QWidget *parent=nullptr);
    ~ClientWindow();

private slots:
    void onSendMessage();

private:
    Ui::clientwindow *ui;
};

#endif // CLIENTWINDOW_H
