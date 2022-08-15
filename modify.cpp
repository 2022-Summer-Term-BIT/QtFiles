#include "modify.h"
#include "ui_modify.h"
#include "login.h"
#include "chat.h"
#include "database.h"
#include <QMessageBox>

extern QString globaldata;
extern QString user;
extern QString pass;


Modify::Modify(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Modify)
{
    ui->setupUi(this);
    ui->label_4->setText(globaldata);
    //ui->lineEdit->setText(user);
    //ui->lineEdit_2->setText(pass);
}

Modify::~Modify()
{
    delete ui;
}

void Modify::on_pushButton_clicked()
{
    this->close();
}

void Modify::on_pushButton_2_clicked()
{
    QString username=ui->lineEdit->text();
    QString mima=ui->lineEdit_2->text();
    DataBase d;
    d.createConnection();  //创建连接
    d.updateById(globaldata,username,mima);
    if(d.queryAll(globaldata,mima)){
        QMessageBox::warning(this,"友情提示","修改成功,请返回登录界面，重新登录");
        this->close();
        //W->close();
        Login*w = new Login();
        w->show();
    }
    else{
        QMessageBox::warning(this,"友情提示","修改失败");
    }
}
