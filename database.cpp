#include "database.h"



//建立一个数据库连接
bool DataBase::createConnection()
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");   //数据库驱动类型为SQL Server
    qDebug()<<"ODBC driver?"<<db.isValid();
    QString dsn = QString::fromLocal8Bit("user_info_db");   //数据源名称
    db.setHostName("localhost");                            //选择本地主机
    db.setDatabaseName(dsn);                                //设置数据源名称
    db.setUserName("user_b");                               //登录用户
    db.setPassword("sjw26366367");                          //密码
    if(!db.open())                                          //打开数据库
    {
        qDebug()<<db.lastError().text();
        QMessageBox::critical(0, QObject::tr("Database error"), db.lastError().text());
        return false;                                   //打开失败
    }
    else
    {
        qDebug() <<  "数据库连接成功！";
    }
    return true;
}

//创建数据库表
bool DataBase::createTable()
{
    QSqlDatabase db = QSqlDatabase::database();   //数据库驱动类型为SQL Server
    QSqlQuery query(db);
    bool success = query.exec("create table ClientInformation(id varchar(20),username varchar(20),mima varchar(20))");
    if(success)
    {
        qDebug() << QObject::tr("数据库表创建成功！\n");
        return true;
    }
    else
    {
        qDebug() << QObject::tr("数据库表创建失败！\n");
        return false;
    }
}

//向数据库中插入记录
bool DataBase::insert(QString id,QString username,QString mima)
{
    QSqlDatabase db = QSqlDatabase::database(); //建立数据库连接
    QSqlQuery query(db);
    query.prepare("insert into ClientInformation values(?, ?, ?)");
    query.bindValue(0, id);
    query.bindValue(1, username);
    query.bindValue(2, mima);

    bool success=query.exec();
    if(!success)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << QString(QObject::tr("插入失败"));
        return false;
    }
    return true;
}

//查询信息
bool DataBase::queryAll(QString id,QString mima)
{
    QSqlDatabase db = QSqlDatabase::database(); //建立数据库连接
    QSqlQuery query(db);
    query.exec(QString("select * from ClientInformation where id = '%1' and mima = '%2'").arg(id).arg(mima));
    QSqlRecord rec = query.record();
    qDebug() << QObject::tr("ClientInformation 列数：" ) << rec.count();

    if(query.next())
    {

        return true;
    }
    else
    {
        return false;
    }
}

QString DataBase::queryAll2(QString id,QString mima)
{
    QSqlDatabase db = QSqlDatabase::database(); //建立数据库连接
    QSqlQuery query(db);
    query.exec(QString("select username from ClientInformation where id= '%1' and mima = '%2'").arg(id).arg(mima));

    if(query.next())
    {
        return query.value(0).toString();
    }
}


//根据ID更新记录
bool DataBase::updateById(QString id, QString username, QString mima)
{
    QSqlDatabase db = QSqlDatabase::database(); //建立数据库连接
    QSqlQuery query(db);
    query.prepare(QString("update ClientInformation set username='%1',mima='%2' where id='%3'").arg(username).arg(mima).arg(id));
     bool success=query.exec();
     if(!success)
     {
          QSqlError lastError = query.lastError();
          qDebug() << lastError.driverText() << QString(QObject::tr("更新失败"));
     }
    return true;
}


