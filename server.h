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

#define ConnDataType QVector<int>

#define NOA_Status 0
#define LateralControlStatus 1


class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);
     ~Server();
    void setALAD_SysStatus(ConnDataType data);

signals:


public slots:
    void run();


private:
    std::shared_ptr<CommonAPI::Runtime> runtime = nullptr;
    std::shared_ptr<v1_0::commonapi::ADAS_SystStatus_ServiceStubDefault> myService = nullptr;

};

void intToADASEnum(ConnDataType in, v1_0::commonapi::ADAS_SystStatus_Service::ADAS_SystStatus_Struct& out);
#endif // SERVER_H
