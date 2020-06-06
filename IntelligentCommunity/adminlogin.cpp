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
}

adminlogin::~adminlogin()
{
    delete ui;
}

void adminlogin::on_pushButton_clicked()
{
    QSqlQuery query;
        query.prepare("select * from admin where id=?");
        query.addBindValue(ui->lineEdit->text());
        query.exec();
        if(query.next())
        {
           if (query.value(1).toString() == ui->lineEdit_2->text())
            {
               //创建管理员管理窗口
               QMessageBox::information(this,tr("提示"),tr("登录成功！"),QMessageBox::Ok);
               this->close();
               return;
            }
            else
            {
                QMessageBox::warning(this, tr("密码错误"),
                                     tr("请输入正确的密码再登录！"), QMessageBox::Ok);
                ui->lineEdit->clear();
                ui->lineEdit_2->clear();
                ui->lineEdit->setFocus();
            }
        }
        else{
            QMessageBox::information(this,tr("提示"),tr("没有此账号！"),QMessageBox::Ok);
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
