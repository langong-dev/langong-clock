#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QThread>
#include <QTime>
#include <QString>
#include <QMessageBox>

void mkhelp ()
{

    QMessageBox *msgBox;
    msgBox = new QMessageBox(
                "Help",
                "<b>Set clocks</b><br>Input min and sec in input boxes and click <code>Start</code> to start clock<br><b>Stop clock</b><br>Press 'P' or click menu 'Clock->Stop'",
                QMessageBox::Information,
                QMessageBox::Cancel | QMessageBox::Escape,
                0,
                0);
    msgBox->show();
}

void mkabout ()
{

    QMessageBox *msgBox;
    msgBox = new QMessageBox(
                "About",
                "LanGong Clock is made by <a href=\"https://langong-dev.github.io\">LanGong Dev Team</a> and undered MIT-License. Published at GitHub, <a href=\"https://github.com/langong-dev/langong-clock\">Repo langong-dev/langong-clock</a>. And made with QT5.<br>&copy; 2020 LanGong.",
                QMessageBox::Information,
                QMessageBox::Cancel | QMessageBox::Escape,
                0,
                0);
    msgBox->show();
}

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


void MainWindow::on_actionHelp_triggered()
{
    mkhelp();
}

void MainWindow::on_actionAbout_triggered()
{
    mkabout();
}
