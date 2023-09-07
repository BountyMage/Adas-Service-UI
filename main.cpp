#include "mainwindow.h"

#include <QApplication>
#include <QThread>
#include <QDebug>
#include <cstdlib>

int main(int argc, char *argv[])
{
    std::string configPath = "D:/document/qtproj/ADAD-Service/server.json";
    std::string command = "VSOMEIP_CONFIGURATION=" + configPath;
    _putenv(const_cast<char*>(command.c_str()));

    QApplication a(argc, argv);
    MainWindow mainwindow;

    QThread wThread;
    Server worker;

    mainwindow.show();

    worker.moveToThread(&wThread);
    QObject::connect(&wThread,&QThread::started,&worker,&Server::run);
    wThread.start();

    return a.exec();
}
