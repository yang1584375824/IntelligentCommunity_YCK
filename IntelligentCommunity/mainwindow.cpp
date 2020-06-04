#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("智慧社区管理系统");
    this->setWindowIcon(QIcon(":/logo.png"));
    this->setFixedSize(1032,359); //固定主窗口
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("ic.db");    //如果本目录下没有该文件,则会在本目录下生成,否则连接该文件
    if (!db.open()) {
        QMessageBox::critical(0, "Cannot open database1",
                              "Unable to establish a database connection.", QMessageBox::Cancel);
    }
    ui->lineEdit->setFocus();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked(bool checked)//登录
{

    if(xuanze == 2) //物业管理
    {
        QSqlQuery query;
            query.prepare("select * from worker where id=?");
            query.addBindValue(ui->lineEdit->text());
            query.exec();
            if(query.next())
            {
               if (query.value(1).toString() == ui->lineEdit_2->text())
                {
                   //创建物业管理窗口
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
    }else if(xuanze == 1){ // 业主登录
        QSqlQuery query;
            query.prepare("select * from owner where id=?");
            query.addBindValue(ui->lineEdit->text());
            query.exec();
            if(query.next())
            {
               if (query.value(1).toString() == ui->lineEdit_2->text())
                {

                   //创建业主窗口
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
    }else{
        QMessageBox::warning(this,tr("提示"), tr("请选择您的身份"), QMessageBox::Ok);
    }
}

void MainWindow::on_commandLinkButton_clicked(bool checked)//管理员登录
{

}

void MainWindow::on_pushButton_2_clicked(bool checked)//关闭窗口
{
    ui->setupUi(this);
    this->close();
}

void MainWindow::on_radioButton_3_clicked()//业主选择
{
    xuanze = 1;
}

void MainWindow::on_radioButton_2_clicked()//物业选择
{
    xuanze = 2;
}
