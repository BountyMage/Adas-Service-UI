#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <QThread>
#include <QDebug>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/ADAS_SystStatus_ServiceStubDefault.hpp>
#include <v1/commonapi/ADAS_SystStatus_ServiceProxyBase.hpp>

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);
     ~Server();

signals:

public slots:
    void run();

};

#endif // SERVER_H
