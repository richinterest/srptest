#include "clientwindow.h"
#include"ui_clientwindow.h"

ClientWindow::ClientWindow(Client *client,QWidget *parent)
    : QWidget(parent),
    ui(new Ui::clientwindow),client(client) // 使用 Ui::ServerWindow
{
    ui->setupUi(this);  // 初始化 UI 元素

    // 连接发送按钮的点击事件到槽函数
    connect(ui->pushButton, &QPushButton::clicked, this, &ClientWindow::onSendMessage);
}

ClientWindow::~ClientWindow()
{
    delete ui;  // 在析构函数中释放 Ui::ServerWindow 对象
}

void ClientWindow::onSendMessage()
{
    // 获取用户输入的消息
    QString message = ui->textEdit->toPlainText();
    client->sendData(message);
    // 将消息追加到聊天框中
    ui->history->setText("You: " + message);

    // 清空消息输入框
    ui->textEdit->clear();
}
