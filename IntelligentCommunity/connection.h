#ifndef CONNECTION_H
#define CONNECTION_H
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>

static bool createConnection()
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("ic.db");    //如果本目录下没有该文件,则会在本目录下生成,否则连接该文件
    if (!db.open()) {
        QMessageBox::critical(0, "Cannot open database1",
                              "Unable to establish a database connection.", QMessageBox::Cancel);
        return false;
    }

    return true;
}


#endif // CONNECTION_H
