//========================================================================================
//  File Name:
//      main.hpp
//
//
//  Authors:
//      Ian Heaton
//
//========================================================================================
//
#include "berlin_clock.hpp"
#include "mainwindow.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    BerlinClock Bc;

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

