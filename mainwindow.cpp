#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QThread>
#include <QTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_lcdNumber_overflow()
{
    ui->lcdNumber->display("Error");
}

void MainWindow::on_pushButton_clicked()
{
    int num = ui->spinBox->value();
    if (num < 0)
    {
        ui->lcdNumber->display("Error");
    }
    ui->lcdNumber->display(num);
    while (num--)
    {
        QTime _Timer = QTime::currentTime().addMSecs(1000);
        while( QTime::currentTime() < _Timer )
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        ui->lcdNumber->display(num);
    }
    QApplication::beep();
}
