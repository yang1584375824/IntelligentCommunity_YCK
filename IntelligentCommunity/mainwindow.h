#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked(bool checked);

    void on_commandLinkButton_clicked(bool checked);

    void on_pushButton_2_clicked(bool checked);

//    void on_radioButton_3_clicked();

//    void on_radioButton_2_clicked();

private:
    Ui::MainWindow *ui;
//        volatile int xuanze;
};

#endif // MAINWINDOW_H
