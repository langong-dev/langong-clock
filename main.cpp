#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.crt();
    w.setFixedSize(w.width(), w.height());
    w.show();
    return a.exec();
}
