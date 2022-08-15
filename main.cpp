#include "login.h"
#include "database.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());
    QApplication a(argc, argv);


    Login w;
    w.show();

    return a.exec();
}
