#include "server.h"

Server::Server(QObject *parent) : QObject(parent)
{
    qInfo() << this << "Constructed" << QThread::currentThread();
}

Server::~Server()
{
    qInfo() << this << "Deconstructed" << QThread::currentThread();
}

void Server::run()
{
    runtime = CommonAPI::Runtime::get();
    myService = std::make_shared<v1_0::commonapi::ADAS_SystStatus_ServiceStubDefault>();
    runtime->registerService("local", "commonapi.ADAS_SystStatus_Service", myService,"server");
    std::cout << "Successfully Registered Service!" << std::endl;

//    v1_0::commonapi::ADAS_SystStatus_Service::ADAS_SystStatus_Struct set_data;
//    set_data.setADCU_LateralControlStatus(v1::commonapi::ADAS_SystStatus_Service::ADCU_LateralControlStatus_Enum::Passive);
//    set_data.setADCU_NOA_Status(v1::commonapi::ADAS_SystStatus_Service::ADCU_NOA_Status_Enum::Active);

//    myService->setADAS_SystStatusAttribute(set_data);

    while (true) {
        std::cout << "Waiting for calls... (Abort with CTRL+C)" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(30));
    }
}

void Server::setALAD_SysStatus(ConnDataType data)
{
    v1_0::commonapi::ADAS_SystStatus_Service::ADAS_SystStatus_Struct set_data;
    intToADASEnum(data,set_data);
    myService->setADAS_SystStatusAttribute(set_data);
    qInfo() << "setALAD_SysStatus called";
}

void intToADASEnum(ConnDataType in, v1_0::commonapi::ADAS_SystStatus_Service::ADAS_SystStatus_Struct& out)
{
//        std::vector<v1::commonapi::ADAS_SystStatus_Service::ADCU_LateralControlStatus_Enum> temp = {v1::commonapi::ADAS_SystStatus_Service::ADCU_LateralControlStatus_Enum::OFF,
//                                                                                    v1::commonapi::ADAS_SystStatus_Service::ADCU_LateralControlStatus_Enum::Passive,
//                                                                                         v1::commonapi::ADAS_SystStatus_Service::ADCU_LateralControlStatus_Enum::Standby,
//                                                                                         v1::commonapi::ADAS_SystStatus_Service::ADCU_LateralControlStatus_Enum::Active,
//                                                                                         v1::commonapi::ADAS_SystStatus_Service::ADCU_LateralControlStatus_Enum::TakeOverRequest,
//                                                                                         v1::commonapi::ADAS_SystStatus_Service::ADCU_LateralControlStatus_Enum::SafeStop,
//                                                                                         v1::commonapi::ADAS_SystStatus_Service::ADCU_LateralControlStatus_Enum::TemporaryError,
//                                                                                         v1::commonapi::ADAS_SystStatus_Service::ADCU_LateralControlStatus_Enum::PermanentError};

//        std::vector<v1::commonapi::ADAS_SystStatus_Service::ADCU_NOA_Status_Enum> temp2 = {v1::commonapi::ADAS_SystStatus_Service::ADCU_NOA_Status_Enum::OFF,
//                                                                                    v1::commonapi::ADAS_SystStatus_Service::ADCU_NOA_Status_Enum::Passive,
//                                                                                         v1::commonapi::ADAS_SystStatus_Service::ADCU_NOA_Status_Enum::Standby,
//                                                                                         v1::commonapi::ADAS_SystStatus_Service::ADCU_NOA_Status_Enum::Active,
//                                                                                         v1::commonapi::ADAS_SystStatus_Service::ADCU_NOA_Status_Enum::TakeOverRequest,
//                                                                                         v1::commonapi::ADAS_SystStatus_Service::ADCU_NOA_Status_Enum::SafeStop,
//                                                                                         v1::commonapi::ADAS_SystStatus_Service::ADCU_NOA_Status_Enum::TemporaryError,
//                                                                                         v1::commonapi::ADAS_SystStatus_Service::ADCU_NOA_Status_Enum::PermanentError};


    out.setADCU_NOA_Status(v1::commonapi::ADAS_SystStatus_Service::ADCU_NOA_Status_Enum(v1::commonapi::ADAS_SystStatus_Service::ADCU_NOA_Status_Enum::Literal(in[NOA_Status])));
    out.setADCU_LateralControlStatus(v1::commonapi::ADAS_SystStatus_Service::ADCU_LateralControlStatus_Enum(v1::commonapi::ADAS_SystStatus_Service::ADCU_LateralControlStatus_Enum::Literal(in[LateralControlStatus])));
}
