#include "clientwindow.h"
#include"ui_clientwindow.h"

ClientWindow::ClientWindow(QWidget *parent)
    : QWidget(parent),
    ui(new Ui::clientwindow) // 使用 Ui::ServerWindow
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

    // 将消息追加到聊天框中
    ui->lineEdit->setText("You: " + message);

    // 清空消息输入框
    ui->textEdit->clear();
}
