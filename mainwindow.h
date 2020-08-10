#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void crt();

private slots:
    void on_lcdNumber_overflow();

    void on_pushButton_clicked();

    void on_actionStop_clock_triggered();


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
