// serverwindow.cpp
#include "ui_serverwindow.h"
#include "serverwindow.h"

ServerWindow::ServerWindow(Server *server,QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::serverwindow),
    server(server)
{
    ui->setupUi(this);  // 初始化 UI 元素

    // 连接发送按钮的点击事件到槽函数
    connect(ui->sendButton, &QPushButton::clicked, this, &ServerWindow::onSendMessage);
    connect(server, &Server::messageReceived, this, &ServerWindow::appendMessage);
}

ServerWindow::~ServerWindow()
{
    delete ui;  // 在析构函数中释放 Ui::ServerWindow 对象
}

void ServerWindow::onSendMessage()
{
    // 获取用户输入的消息
    QString message = ui->messageInput->toPlainText();

    // 将消息追加到聊天框中
    ui->chatBox->setText("You: " + message);

    // 清空消息输入框
    ui->messageInput->clear();

    // 通过 Server 对象处理消息，例如发送给其他客户端

}
void ServerWindow::appendMessage(const QString& message){
    ui->chatBox->setText(message);
}
