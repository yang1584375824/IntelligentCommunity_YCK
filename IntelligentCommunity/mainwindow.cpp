#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "adminlogin.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QLineEdit>

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
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    ui->lineEdit->setPlaceholderText("账号/手机号/身份证号码等");
    ui->lineEdit_2->setPlaceholderText("密码");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked(bool checked)//登录
{

//    if(xuanze == 2) //物业管理
//    {
//        int i = 0;
        QSqlQuery query;
        if(query.exec("select * from usrlist"))
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





//            query.prepare("select * from usrlist where id=?");
//            query.addBindValue(ui->lineEdit->text());
//            query.exec();
//            if(query.next())
//            {
//               if (query.value(3).toString() == ui->lineEdit_2->text())
//                {
//                   //创建物业管理窗口
//                   QMessageBox::information(this,tr("提示"),tr("登录成功！"),QMessageBox::Ok);
//                   this->close();
//                   return;
//                }
//                else
//                {
//                    QMessageBox::warning(this, tr("密码错误"),
//                                         tr("请输入正确的密码再登录！"), QMessageBox::Ok);
//                    ui->lineEdit->clear();
//                    ui->lineEdit_2->clear();
//                    ui->lineEdit->setFocus();
//                    i = 1;
//                }
//            }
//            query.prepare("select * from usrlist where tel=?");
//            query.addBindValue(ui->lineEdit->text());
//            query.exec();
//            if(query.next())
//            {
//               if (query.value(3).toString() == ui->lineEdit_2->text())
//                {
//                   //创建物业管理窗口
//                   QMessageBox::information(this,tr("提示"),tr("登录成功！"),QMessageBox::Ok);
//                   this->close();
//                   return;
//                }
//                else
//                {
//                    QMessageBox::warning(this, tr("密码错误"),
//                                         tr("请输入正确的密码再登录！"), QMessageBox::Ok);
//                    ui->lineEdit->clear();
//                    ui->lineEdit_2->clear();
//                    ui->lineEdit->setFocus();
//                    i = 1;
//                }
//            }
//            query.prepare("select * from usrlist where IDcard=?");
//            query.addBindValue(ui->lineEdit->text());
//            query.exec();
//            if(query.next())
//            {
//               if (query.value(3).toString() == ui->lineEdit_2->text())
//                {
//                   //创建物业管理窗口
//                   QMessageBox::information(this,tr("提示"),tr("登录成功！"),QMessageBox::Ok);
//                   this->close();
//                   return;
//                }
//                else
//                {
//                    QMessageBox::warning(this, tr("密码错误"),
//                                         tr("请输入正确的密码再登录！"), QMessageBox::Ok);
//                    ui->lineEdit->clear();
//                    ui->lineEdit_2->clear();
//                    ui->lineEdit->setFocus();
//                    i = 1;
//                }
//            }
//            if(i == 0){
//                QMessageBox::information(this,tr("提示"),tr("没有此账号！"),QMessageBox::Ok);
//                ui->lineEdit->clear();
//                ui->lineEdit_2->clear();
//                ui->lineEdit->setFocus();
//           }
//    }else if(xuanze == 1){ // 业主登录
//        QSqlQuery query;
//            query.prepare("select * from owner where id=?");
//            query.addBindValue(ui->lineEdit->text());
//            query.exec();
//            if(query.next())
//            {
//               if (query.value(1).toString() == ui->lineEdit_2->text())
//                {

//                   //创建业主窗口
//                  QMessageBox::information(this,tr("提示"),tr("登录成功！"),QMessageBox::Ok);
//                   this->close();
//                   return;
//                }
//                else
//                {
//                    QMessageBox::warning(this, tr("密码错误"),
//                                         tr("请输入正确的密码再登录！"), QMessageBox::Ok);
//                    ui->lineEdit->clear();
//                    ui->lineEdit_2->clear();
//                    ui->lineEdit->setFocus();
//                }
//            }
//            else{
//                QMessageBox::information(this,tr("提示"),tr("没有此账号！"),QMessageBox::Ok);
//                ui->lineEdit->clear();
//                ui->lineEdit_2->clear();
//                ui->lineEdit->setFocus();
//            }
//    }else{
//        QMessageBox::warning(this,tr("提示"), tr("请选择您的身份！"), QMessageBox::Ok);
//    }

}
void MainWindow::on_commandLinkButton_clicked(bool checked)//管理员登录
{
    adminlogin *admin = new adminlogin;
    admin->setWindowTitle("管理员登录");
    admin->setWindowIcon(QIcon(":/logo.png"));
    admin->show();
    this->hide();
}

void MainWindow::on_pushButton_2_clicked(bool checked)//关闭窗口
{
    ui->setupUi(this);
    this->close();
}

//void MainWindow::on_radioButton_3_clicked()//业主选择
//{
//    xuanze = 1;
//}

//void MainWindow::on_radioButton_2_clicked()//物业选择
//{
//    xuanze = 2;
//}
