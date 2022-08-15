#ifndef MODIFY_H
#define MODIFY_H
#include <MainWindow.h>
#include <QWidget>

namespace Ui {
class Modify;
}

class Modify : public QWidget
{
    Q_OBJECT

public:
    explicit Modify(QWidget *parent = 0);
    ~Modify();

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Modify *ui;
};

#endif // MODIFY_H
