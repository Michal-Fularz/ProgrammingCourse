#include "lab_s02e09_mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    lab_s02e09_MainWindow w;
    w.show();

    return a.exec();
}
