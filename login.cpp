#include "login.h"
#include "ui_login.h"
#include <Qdebug>
#include <QMessageBox>
#include "chat.h"
#include "register.h"
#include "database.h"
#include "MainWindow.h"

QString globaldata;
QString user;
QString pass;


Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{//获取用户在文本框中的数据
    QString id = ui->lineEdit->text();
    QString mima = ui->lineEdit_2->text();
    //调试打印账号和密码
    DataBase d;
    d.createConnection();  //创建连接
    if(d.queryAll(id,mima))
    {
        //创建并显示主窗口
        globaldata=ui->lineEdit->text();
        user=d.queryAll2(id,mima);
        pass=mima;
        qDebug() << user;
        this->close();
        ChatWidget * W = new ChatWidget();
        W->show();
    }else{
        qDebug() << "登录失败，请重新输入";
        QMessageBox::warning(this,"友情提示","账号或密码有误");

    }



}
//重置按钮的处理函数
void Login::on_pushButton_2_clicked()
{
    this->close();
    Register*w = new Register();
    w->show();
}
