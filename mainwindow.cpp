#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QThread>
#include <QTime>
#include <QString>

int nsec, nmin;

QString ch (int a, int b)
{
    QString s;
    if (a < 10)
    {
        s += "0";
    }
    s += QString::number(a);
    s += ":";
    if (b < 10)
    {
        s += "0";
    }
    s += QString::number(b);
    return s;
}

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
    nsec = ui->spinBox->value();
    nmin = ui->spinBoxm->value();
    if (nmin < 0 || nsec < 0)
    {
        ui->lcdNumber->display("Error");
    }
    ui->lcdNumber->display(ch(nmin,nsec));
    if (!(nmin <= 0 && nsec <= 0))
    {
        while (true)
        {
            nsec--;
            QTime _Timer = QTime::currentTime().addMSecs(1000);
            while( QTime::currentTime() < _Timer )
                QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
            if (nsec < 0)
            {
                nsec += 60;
                nmin --;
            }
            if (nmin <=0 && nsec <= 0)
            {
                break;
            }
            ui->lcdNumber->display(ch(nmin,nsec));
        }
    }
    ui->lcdNumber->display("00:00");
    QApplication::beep();
}

void MainWindow::crt()
{
    ui->lcdNumber->display("00:00");
}

void MainWindow::on_actionStop_clock_triggered()
{
    nsec = nmin = 0;
}

