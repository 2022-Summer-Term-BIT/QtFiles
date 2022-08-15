#include "chatwindow.h"
#include "ui_chatwindow.h"

chatwindow::chatwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chatwindow)
{
    ui->setupUi(this);
}

chatwindow::~chatwindow()
{
    delete ui;
}
