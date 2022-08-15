#include "MainWindow.h"
#include "ui_chatwidget.h"
#include <QDebug>
#include "login.h"
#include "modify.h"
#include "chatwindow.h"

ChatWidget::ChatWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChatWidget)
{
    ui->setupUi(this);
    connect(ui->OptionBtn,&QToolButton::clicked,this,[=]()
    {
        Modify *w=new Modify();
        w->show();
    });
    connect(ui->p1,QToolButton::clicked,this,[=]()
    {
       chatwindow * w = new chatwindow();
       w->show();
    });
}

ChatWidget::~ChatWidget()
{
    delete ui;

}
