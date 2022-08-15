#include "register.h"
#include "ui_register.h"
#include "login.h"
#include "database.h"
#include <QMessageBox>

Register::Register(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
}

Register::~Register()
{
    delete ui;
}

void Register::on_pushButton_clicked()
{

    QString id=ui->lineEdit->text();
    QString username=ui->lineEdit_2->text();
    QString mima=ui->lineEdit_3->text();


    DataBase d;
    d.createConnection();  //创建连接
    d.createTable();
    d.insert( id, username,mima);
    if(d.queryAll(id,mima)){
        QMessageBox::warning(this,"友情提示","注册成功 返回登录界面");
        this->close();
        Login*w=new Login();
        w->show();
    }
    else{
        QMessageBox::warning(this,"友情提示","注册失败");
    }
}

void Register::on_pushButton_2_clicked()
{
    this->close();
    Login*w=new Login();
    w->show();
}
