#ifndef ADMINLOGIN_H
#define ADMINLOGIN_H

#include <QDialog>

namespace Ui {
class adminlogin;
}

class adminlogin : public QDialog
{
    Q_OBJECT

public:
    explicit adminlogin(QWidget *parent = 0);
    ~adminlogin();

private:
    Ui::adminlogin *ui;
};

#endif // ADMINLOGIN_H
