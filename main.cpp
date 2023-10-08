#include "mainwindow.h"

#include <QApplication>
#include <QThread>
#include <QDebug>
#include <cstdlib>
#include <QMetaType>

//Q_DECLARE_METATYPE(QVector<int>)

int main(int argc, char *argv[])
{
    // 在合适的位置注册自定义类型
    //qRegisterMetaType<QVector<int>>("QVector<int>");

//    std::string configPath = "D:/document/qtproj/ADAD-Service/server.json";
//    std::string command = "VSOMEIP_CONFIGURATION=" + configPath;
//    _putenv(const_cast<char*>(command.c_str()));

//    QApplication a(argc, argv);
//    MainWindow mainwindow;

//    QThread wThread;

//    mainwindow.show();

//    mainwindow.worker->moveToThread(&wThread);
//    QObject::connect(&wThread,&QThread::started,mainwindow.worker,&Server::run);


//    wThread.start();

//    return a.exec();

      QApplication a(argc, argv);
      MainWindow mainwindow;
      mainwindow.setWindowTitle("[ADAS座舱测试台架] 当前场景：未定义");
      QObject::connect(mainwindow.scenelist, &QComboBox::currentTextChanged, &mainwindow, &MainWindow::load_Scene);


      mainwindow.show();
      return a.exec();
}
