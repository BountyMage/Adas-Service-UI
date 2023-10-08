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

#define ServiceDataType QVector<int>
//ALAD_SysStatus members macro
#define NOA_Status 0
#define LateralControlStatus 1

//FCS_SLIF_IHBC_Status_Struct members macro
#define SLIF_Warning 0
#define Status_AliveCounter 1
#define IHBC_Switch 2
#define IHBC_Status 3
#define Status_CheckSum 4
#define Speedlimit 5
#define IHBC_LightDistribReq 6
#define SLIF_Switch 7
#define SpeedLimitCancelled 8
#define SLIF_Status 9

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);
     ~Server();
    void setALAD_SysStatus(ServiceDataType data);

signals:


public slots:
    void run();


private:
    std::shared_ptr<CommonAPI::Runtime> runtime = nullptr;
    std::shared_ptr<v1_0::commonapi::ADAS_SystStatus_ServiceStubDefault> myService = nullptr;

};

void intToADASEnum(ServiceDataType in, v1_0::commonapi::ADAS_SystStatus_Service::ADAS_SystStatus_Struct& out);
#endif // SERVER_H
