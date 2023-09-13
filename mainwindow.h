#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "server.h"
#include <vector>
#include <iostream>
#include<QtDebug>
#include "paneloperatelogic.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

//current panel values for service data


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void requestALAD_SysStatusDataChange(ConnDataType data);

private slots:
    void on_comboBox_ALAD_SysStatus_NOA_Status__currentIndexChanged(int index);

    void on_comboBox_ALAD_SysStatus_LateralControlStatus__currentIndexChanged(int index);

    void on_setDataButton_clicked();


private:
    Ui::MainWindow *ui;
    void comboBoxSettingFrontObject();
    void comboBoxSettingSLIFIHBCStatus();
    void comboBoxSettingTLAInfo();
    void comboBoxSettingAEB();
    void comboBoxSettingDisplay();
    void comboBoxSettingALAD();

};
#endif // MAINWINDOW_H
