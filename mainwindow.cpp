#include "mainwindow.h"
#include "ui_mainwindow.h"


extern ConnDataType CurrentALAD_SysStatus;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , worker(new Server)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    comboBoxSettingFrontObject();
    comboBoxSettingSLIFIHBCStatus();
    comboBoxSettingTLAInfo();
    comboBoxSettingAEB();
    comboBoxSettingDisplay();
    comboBoxSettingALAD();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::comboBoxSettingALAD()
{
    this->ui->comboBox_ALAD_Status_Type_->addItem("Reserved");
    this->ui->comboBox_ALAD_Status_Type_->addItem("OFF");
    this->ui->comboBox_ALAD_Status_Type_->addItem("LDW");
    this->ui->comboBox_ALAD_Status_Type_->addItem("RDP & LDW");
    this->ui->comboBox_ALAD_Status_Type_->addItem("LKS & LDW");

    this->ui->comboBox_ALAD_Status_Warning_->addItem("No Warning");
    this->ui->comboBox_ALAD_Status_Warning_->addItem("Please hands on level 1");
    this->ui->comboBox_ALAD_Status_Warning_->addItem("Please hands on level 2");

    this->ui->comboBox_ALAD_Status_Status_->addItem("OFF");
    this->ui->comboBox_ALAD_Status_Status_->addItem("Passive");
    this->ui->comboBox_ALAD_Status_Status_->addItem("Standby");
    this->ui->comboBox_ALAD_Status_Status_->addItem("Active");
    this->ui->comboBox_ALAD_Status_Status_->addItem("Take over request(Reserved)");
    this->ui->comboBox_ALAD_Status_Status_->addItem("Safe stop(Reserved)");
    this->ui->comboBox_ALAD_Status_Status_->addItem("Temporary error");
    this->ui->comboBox_ALAD_Status_Status_->addItem("Permanent error");

    this->ui->comboBox_ALAD_Status_FCS_Status_->addItem("Normal");
    this->ui->comboBox_ALAD_Status_FCS_Status_->addItem("Block");
    this->ui->comboBox_ALAD_Status_FCS_Status_->addItem("Other Temporary Error");
    this->ui->comboBox_ALAD_Status_FCS_Status_->addItem("Permanent Error");

    this->ui->comboBox_ALAD_SysStatus_NOA_Status_->addItem("OFF");
    this->ui->comboBox_ALAD_SysStatus_NOA_Status_->addItem("Passive");
    this->ui->comboBox_ALAD_SysStatus_NOA_Status_->addItem("Standby");
    this->ui->comboBox_ALAD_SysStatus_NOA_Status_->addItem("Active");
    this->ui->comboBox_ALAD_SysStatus_NOA_Status_->addItem("Take over request");
    this->ui->comboBox_ALAD_SysStatus_NOA_Status_->addItem("Safe stop");
    this->ui->comboBox_ALAD_SysStatus_NOA_Status_->addItem("Temporary error");
    this->ui->comboBox_ALAD_SysStatus_NOA_Status_->addItem("Permanent error");

    this->ui->comboBox_ALAD_SysStatus_LateralControlStatus_->addItem("OFF");
    this->ui->comboBox_ALAD_SysStatus_LateralControlStatus_->addItem("Passive");
    this->ui->comboBox_ALAD_SysStatus_LateralControlStatus_->addItem("Standby");
    this->ui->comboBox_ALAD_SysStatus_LateralControlStatus_->addItem("Active");
    this->ui->comboBox_ALAD_SysStatus_LateralControlStatus_->addItem("Take over request");
    this->ui->comboBox_ALAD_SysStatus_LateralControlStatus_->addItem("Safe stop(Reserved)");
    this->ui->comboBox_ALAD_SysStatus_LateralControlStatus_->addItem("Temporary error");
    this->ui->comboBox_ALAD_SysStatus_LateralControlStatus_->addItem("Permanent error");




}

void MainWindow::comboBoxSettingDisplay()
{
    this->ui->comboBox_Display_ALOD_TimeGap_->addItem("None");
    this->ui->comboBox_Display_ALOD_TimeGap_->addItem("TimeGap_1 1s");
    this->ui->comboBox_Display_ALOD_TimeGap_->addItem("TimeGap_2 1.5s");
    this->ui->comboBox_Display_ALOD_TimeGap_->addItem("TimeGap_3 1.9s");

    this->ui->comboBox_Display_ALOD_TimeGapDisp_->addItem("No display");
    this->ui->comboBox_Display_ALOD_TimeGapDisp_->addItem("Display");

    this->ui->comboBox_Display_ALOD_Status_->addItem("OFF mode");
    this->ui->comboBox_Display_ALOD_Status_->addItem("Passive mode");
    this->ui->comboBox_Display_ALOD_Status_->addItem("Stand-By mode");
    this->ui->comboBox_Display_ALOD_Status_->addItem("Active-Control mode");
    this->ui->comboBox_Display_ALOD_Status_->addItem("Brake-Only mode");
    this->ui->comboBox_Display_ALOD_Status_->addItem("Override");
    this->ui->comboBox_Display_ALOD_Status_->addItem("Stand Active");
    this->ui->comboBox_Display_ALOD_Status_->addItem("Stand Wait");
    this->ui->comboBox_Display_ALOD_Status_->addItem("Temporary Failure");
    this->ui->comboBox_Display_ALOD_Status_->addItem("Permanent Failure");

    this->ui->comboBox_Display_ALOD_ControlType_->addItem("None");
    this->ui->comboBox_Display_ALOD_ControlType_->addItem("CC");
    this->ui->comboBox_Display_ALOD_ControlType_->addItem("ACC");
    this->ui->comboBox_Display_ALOD_ControlType_->addItem("ICC");

    this->ui->comboBox_Display_ALOD_Warning_->addItem("No Display");
    this->ui->comboBox_Display_ALOD_Warning_->addItem("Please take over");
    this->ui->comboBox_Display_ALOD_Warning_->addItem("Please hands on");
    this->ui->comboBox_Display_ALOD_Warning_->addItem("Auto lane change failed");

    this->ui->comboBox_Display_FRS_Status_->addItem("Normal");
    this->ui->comboBox_Display_FRS_Status_->addItem("Block");
    this->ui->comboBox_Display_FRS_Status_->addItem("Other Temporary Error");
    this->ui->comboBox_Display_FRS_Status_->addItem("Permanent Error");

    this->ui->comboBox_Display_ALOD_Info_->addItem("No display");
    this->ui->comboBox_Display_ALOD_Info_->addItem("Unable to activate Cruise control");
    this->ui->comboBox_Display_ALOD_Info_->addItem("Cruise control cancelled");
    this->ui->comboBox_Display_ALOD_Info_->addItem("Cruise control active");
    this->ui->comboBox_Display_ALOD_Info_->addItem("Cruise control and AEB temporary unavailable");
    this->ui->comboBox_Display_ALOD_Info_->addItem("Cruise control and AEB block in the front");
    this->ui->comboBox_Display_ALOD_Info_->addItem("Cruise control and AEB ERROR");
    this->ui->comboBox_Display_ALOD_Info_->addItem("Cruise control Switched On");
    this->ui->comboBox_Display_ALOD_Info_->addItem("Cruise control Switched OFF");
    this->ui->comboBox_Display_ALOD_Info_->addItem("Unable to activate for setbelt unlock");
    this->ui->comboBox_Display_ALOD_Info_->addItem("Unable to activate for doors unlock");
    this->ui->comboBox_Display_ALOD_Info_->addItem("Unable to activate for not D shift");
    this->ui->comboBox_Display_ALOD_Info_->addItem("Unable to activate for EPB Active");
    this->ui->comboBox_Display_ALOD_Info_->addItem("Unable to activate for not working speed");
    this->ui->comboBox_Display_ALOD_Info_->addItem("FRS blocked");
    this->ui->comboBox_Display_ALOD_Info_->addItem("Unable to activate for the limp home mode");
}

void MainWindow::comboBoxSettingAEB()
{
    this->ui->comboBox_AEB_Status_->addItem("OFF");
    this->ui->comboBox_AEB_Status_->addItem("ON");
    this->ui->comboBox_AEB_Status_->addItem("AEB temporary error");
    this->ui->comboBox_AEB_Status_->addItem("AEB permanent  error");
    this->ui->comboBox_AEB_Status_->addItem("AEB-PED not avalid");

    this->ui->comboBox_AEB_Warning_->addItem("No warning");
    this->ui->comboBox_AEB_Warning_->addItem("Latent Warning");
    this->ui->comboBox_AEB_Warning_->addItem("Collision Warning to car");
    this->ui->comboBox_AEB_Warning_->addItem("Braking to car");
    this->ui->comboBox_AEB_Warning_->addItem("Collision Warning to PED");
    this->ui->comboBox_AEB_Warning_->addItem("Braking to PED");

    this->ui->comboBox_AEB_FCWSenlevel_->addItem("OFF");
    this->ui->comboBox_AEB_FCWSenlevel_->addItem("low");
    this->ui->comboBox_AEB_FCWSenlevel_->addItem("medium");
    this->ui->comboBox_AEB_FCWSenlevel_->addItem("high");

}

void MainWindow::comboBoxSettingTLAInfo()
{
    this->ui->comboBox_TLA_Info_Sts_->addItem("OFF");
    this->ui->comboBox_TLA_Info_Sts_->addItem("StandBy");
    this->ui->comboBox_TLA_Info_Sts_->addItem("Passive");
    this->ui->comboBox_TLA_Info_Sts_->addItem("Active");
    this->ui->comboBox_TLA_Info_Sts_->addItem("Tem fault");
    this->ui->comboBox_TLA_Info_Sts_->addItem("Per fault");

    this->ui->comboBox_TLA_Info_Left_S_->addItem("No Display");
    this->ui->comboBox_TLA_Info_Left_S_->addItem("Green");
    this->ui->comboBox_TLA_Info_Left_S_->addItem("Green to Yellow");
    this->ui->comboBox_TLA_Info_Left_S_->addItem("Yellow");
    this->ui->comboBox_TLA_Info_Left_S_->addItem("Yellow to Red");
    this->ui->comboBox_TLA_Info_Left_S_->addItem("Red");
    this->ui->comboBox_TLA_Info_Left_S_->addItem("Red to Green");

    this->ui->comboBox_TLA_Info_stright_S_->addItem("No Display");
    this->ui->comboBox_TLA_Info_stright_S_->addItem("Green");
    this->ui->comboBox_TLA_Info_stright_S_->addItem("Green to Yellow");
    this->ui->comboBox_TLA_Info_stright_S_->addItem("Yellow");
    this->ui->comboBox_TLA_Info_stright_S_->addItem("Yellow to Red");
    this->ui->comboBox_TLA_Info_stright_S_->addItem("Red");
    this->ui->comboBox_TLA_Info_stright_S_->addItem("Red to Green");

    this->ui->comboBox_TLA_Info_right_S_->addItem("No Display");
    this->ui->comboBox_TLA_Info_right_S_->addItem("Green");
    this->ui->comboBox_TLA_Info_right_S_->addItem("Green to Yellow");
    this->ui->comboBox_TLA_Info_right_S_->addItem("Yellow");
    this->ui->comboBox_TLA_Info_right_S_->addItem("Yellow to Red");
    this->ui->comboBox_TLA_Info_right_S_->addItem("Red");
    this->ui->comboBox_TLA_Info_right_S_->addItem("Red to Green");

}

void MainWindow::comboBoxSettingSLIFIHBCStatus()
{
    this->ui->IHBC_Status_->addItem("OFF");
    this->ui->IHBC_Status_->addItem("Standby");
    this->ui->IHBC_Status_->addItem("Active");
    this->ui->IHBC_Status_->addItem("Temporary error");
    this->ui->IHBC_Status_->addItem("Permanent error");

    this->ui->SLIF_Status_->addItem("OFF");
    this->ui->SLIF_Status_->addItem("Operating：Fusion mode");
    this->ui->SLIF_Status_->addItem("Operating：Vision only mode");
    this->ui->SLIF_Status_->addItem("Operating：Navigation only mode");
    this->ui->SLIF_Status_->addItem("SLIF failure");
}

void MainWindow::comboBoxSettingFrontObject()
{
    this->ui->comboBox_FOonetype_->addItem("No Display");
    this->ui->comboBox_FOonetype_->addItem("Car");
    this->ui->comboBox_FOonetype_->addItem("Pedestrian");
    this->ui->comboBox_FOonetype_->addItem("Bikecycle");
    this->ui->comboBox_FOonetype_->addItem("Animal");

    this->ui->comboBox_FOtwotype_->addItem("No Display");
    this->ui->comboBox_FOtwotype_->addItem("Car");
    this->ui->comboBox_FOtwotype_->addItem("Pedestrian");
    this->ui->comboBox_FOtwotype_->addItem("Bikecycle");
    this->ui->comboBox_FOtwotype_->addItem("Animal");

    this->ui->comboBox_FOoneColor_->addItem("Grey");
    this->ui->comboBox_FOoneColor_->addItem("Blue");
    this->ui->comboBox_FOoneColor_->addItem("Yellow");
    this->ui->comboBox_FOoneColor_->addItem("Red");
    this->ui->comboBox_FOoneColor_->addItem("White");
    this->ui->comboBox_FOoneColor_->addItem("Orange");

    this->ui->comboBox_FOtwoColor_->addItem("Grey");
    this->ui->comboBox_FOtwoColor_->addItem("Blue");
    this->ui->comboBox_FOtwoColor_->addItem("Yellow");
    this->ui->comboBox_FOtwoColor_->addItem("Red");
    this->ui->comboBox_FOtwoColor_->addItem("White");
    this->ui->comboBox_FOtwoColor_->addItem("Orange");

    this->ui->comboBox_FOoneWarn_->addItem("No Warning");
    this->ui->comboBox_FOoneWarn_->addItem("Warning");

    //this->ui->comboBox_FOtwoWarn_->addItem("No Warning");
    //this->ui->comboBox_FOtwoWarn_->addItem("Warning");

    this->ui->comboBox_FROtype_->addItem("No Display");
    this->ui->comboBox_FROtype_->addItem("Car");
    this->ui->comboBox_FROtype_->addItem("Pedestrian");
    this->ui->comboBox_FROtype_->addItem("Bikecycle");
    this->ui->comboBox_FROtype_->addItem("Animal");

    this->ui->comboBox_FROColor_->addItem("Grey");
    this->ui->comboBox_FROColor_->addItem("Blue");
    this->ui->comboBox_FROColor_->addItem("Yellow");
    this->ui->comboBox_FROColor_->addItem("Red");
    this->ui->comboBox_FROColor_->addItem("White");
    this->ui->comboBox_FROColor_->addItem("Orange");

    this->ui->comboBox_FLOtype_->addItem("No Display");
    this->ui->comboBox_FLOtype_->addItem("Car");
    this->ui->comboBox_FLOtype_->addItem("Pedestrian");
    this->ui->comboBox_FLOtype_->addItem("Bikecycle");
    this->ui->comboBox_FLOtype_->addItem("Animal");

    this->ui->comboBox_FLOColor_->addItem("Grey");
    this->ui->comboBox_FLOColor_->addItem("Blue");
    this->ui->comboBox_FLOColor_->addItem("Yellow");
    this->ui->comboBox_FLOColor_->addItem("Red");
    this->ui->comboBox_FLOColor_->addItem("White");
    this->ui->comboBox_FLOColor_->addItem("Orange");

}

void MainWindow::on_comboBox_ALAD_SysStatus_NOA_Status__currentIndexChanged(int index)
{
    changeCurrentALAD_SysStatus_NOA_Status(index);
}


void MainWindow::on_comboBox_ALAD_SysStatus_LateralControlStatus__currentIndexChanged(int index)
{
    changeCurrentALAD_SysStatus_LateralControlStatus(index);
}

void MainWindow::on_setDataButton_clicked()
{
    worker->setALAD_SysStatus(CurrentALAD_SysStatus);
}
