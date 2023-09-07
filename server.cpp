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
    std::shared_ptr<CommonAPI::Runtime> runtime = CommonAPI::Runtime::get();
    std::shared_ptr<v1_0::commonapi::ADAS_SystStatus_ServiceStubDefault> myService =
        std::make_shared<v1_0::commonapi::ADAS_SystStatus_ServiceStubDefault>();
    runtime->registerService("local", "commonapi.ADAS_SystStatus_Service", myService,"server");
    std::cout << "Successfully Registered Service!" << std::endl;

    v1_0::commonapi::ADAS_SystStatus_Service::ADAS_SystStatus_Struct set_data;
    set_data.setADCU_LateralControlStatus(v1::commonapi::ADAS_SystStatus_Service::ADCU_LateralControlStatus_Enum::Passive);
    set_data.setADCU_NOA_Status(v1::commonapi::ADAS_SystStatus_Service::ADCU_NOA_Status_Enum::Active);

    myService->setADAS_SystStatusAttribute(set_data);

    while (true) {
        std::cout << "Waiting for calls... (Abort with CTRL+C)" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(30));
    }
}
