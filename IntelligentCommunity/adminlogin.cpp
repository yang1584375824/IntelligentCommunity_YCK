#include "adminlogin.h"
#include "ui_adminlogin.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QLineEdit>

adminlogin::adminlogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminlogin)
{
    ui->setupUi(this);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    ui->lineEdit->setPlaceholderText("账号/手机号/身份证号码等");
    ui->lineEdit_2->setPlaceholderText("密码");
}

adminlogin::~adminlogin()
{
    delete ui;
}

void adminlogin::on_pushButton_clicked()
{
    QSqlQuery query;
    if(query.exec("select * from admin"))
           {

               while(query.next())//遍历数据表格

               {

                    QString id= query.value(0).toString().trimmed();//trimmed函数表示去除QString两边的空格
                    QString tel= query.value(1).toString().trimmed();
                    QString IDcard =query.value(2).toString().trimmed();
                    QString password=query.value(3).toString().trimmed();

                    if((ui->lineEdit->text() == id)&&(ui->lineEdit_2->text() == password)||(ui->lineEdit->text() == tel)&&(ui->lineEdit_2->text() == password)||(ui->lineEdit->text() == IDcard)&&(ui->lineEdit_2->text() == password)){

                        QMessageBox::information(this,tr("提示"),tr("登录成功！"),QMessageBox::Ok);
                        this->close();
                        return;

               }

           }
                   QMessageBox::warning(this, tr("登录失败"),
                                        tr("请输入正确的账号或密码！"), QMessageBox::Ok);
                   ui->lineEdit->clear();
                   ui->lineEdit_2->clear();
                   ui->lineEdit->setFocus();
}
}

void adminlogin::on_pushButton_2_clicked()
{

}

void adminlogin::on_commandLinkButton_clicked()
{
    MainWindow *w = new MainWindow;
    w->show();
    this->close();
}
