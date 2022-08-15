#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QWidget>

namespace Ui {
class chatwindow;
}

class chatwindow : public QWidget
{
    Q_OBJECT

public:
    explicit chatwindow(QWidget *parent = nullptr);
    ~chatwindow();

private:
    Ui::chatwindow *ui;
};

#endif // CHATWINDOW_H
