#ifndef DATABASE_H
#define DATABASE_H

#include <QTextCodec>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QtDebug>
#include <QSqlRecord>
#include <QMessageBox>

class DataBase
{
public:
    bool createConnection();  //创建一个连接
    bool createTable();       //创建数据库表
    bool insert(QString id, QString username, QString mima);            //出入数据
    bool queryAll(QString id, QString mima);
    QString queryAll2(QString id, QString mima);
    bool updateById(QString id, QString username, QString mima);  //更新
};

#endif // DATABASE_H
