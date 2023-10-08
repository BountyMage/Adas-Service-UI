#include"paneloperatelogic.h"
#include "server.h"
#include <vector>
#include <iostream>
#include<QtDebug>

ServiceDataType CurrentALAD_SysStatus(2);
ServiceDataType CurrentSLIF_IHBCStatus(10);

void changeCurrentALAD_SysStatus(int member, int index){

    CurrentALAD_SysStatus[member] = index;
    qDebug()<<"ALAD_SysStatus member "<<member<< " change to "<< index;
}

//    std::vector<v1::commonapi::ADAS_SystStatus_Service::ADCU_LateralControlStatus_Enum> temp = {v1::commonapi::ADAS_SystStatus_Service::ADCU_LateralControlStatus_Enum::OFF,
//                                                                                v1::commonapi::ADAS_SystStatus_Service::ADCU_LateralControlStatus_Enum::Passive,
//                                                                                     v1::commonapi::ADAS_SystStatus_Service::ADCU_LateralControlStatus_Enum::Standby,
//                                                                                     v1::commonapi::ADAS_SystStatus_Service::ADCU_LateralControlStatus_Enum::Active,
//                                                                                     v1::commonapi::ADAS_SystStatus_Service::ADCU_LateralControlStatus_Enum::TakeOverRequest,
//                                                                                     v1::commonapi::ADAS_SystStatus_Service::ADCU_LateralControlStatus_Enum::SafeStop,
//                                                                                     v1::commonapi::ADAS_SystStatus_Service::ADCU_LateralControlStatus_Enum::TemporaryError,
//                                                                                     v1::commonapi::ADAS_SystStatus_Service::ADCU_LateralControlStatus_Enum::PermanentError};

void changeCurrentSLIF_IHBCStatus(int member, int index){

    CurrentSLIF_IHBCStatus[member] = index;
    qDebug()<<"SLIF_IHBCStatus member "<<member<< " change to "<< index;
}


