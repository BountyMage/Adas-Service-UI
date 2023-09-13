#include"paneloperatelogic.h"
#include "server.h"
#include <vector>
#include <iostream>
#include<QtDebug>


ConnDataType CurrentALAD_SysStatus(2);

void changeCurrentALAD_SysStatus_NOA_Status(int index){

    CurrentALAD_SysStatus[NOA_Status] = index;
    qDebug()<<"NOA_Status change to "<< index;
}

void changeCurrentALAD_SysStatus_LateralControlStatus(int index){
//    std::vector<v1::commonapi::ADAS_SystStatus_Service::ADCU_LateralControlStatus_Enum> temp = {v1::commonapi::ADAS_SystStatus_Service::ADCU_LateralControlStatus_Enum::OFF,
//                                                                                v1::commonapi::ADAS_SystStatus_Service::ADCU_LateralControlStatus_Enum::Passive,
//                                                                                     v1::commonapi::ADAS_SystStatus_Service::ADCU_LateralControlStatus_Enum::Standby,
//                                                                                     v1::commonapi::ADAS_SystStatus_Service::ADCU_LateralControlStatus_Enum::Active,
//                                                                                     v1::commonapi::ADAS_SystStatus_Service::ADCU_LateralControlStatus_Enum::TakeOverRequest,
//                                                                                     v1::commonapi::ADAS_SystStatus_Service::ADCU_LateralControlStatus_Enum::SafeStop,
//                                                                                     v1::commonapi::ADAS_SystStatus_Service::ADCU_LateralControlStatus_Enum::TemporaryError,
//                                                                                     v1::commonapi::ADAS_SystStatus_Service::ADCU_LateralControlStatus_Enum::PermanentError};

    CurrentALAD_SysStatus[LateralControlStatus] = index;
    qDebug()<<"LateralControlStatus change to "<< index;
}
