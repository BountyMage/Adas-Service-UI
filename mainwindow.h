#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "server.h"
#include <vector>
#include <iostream>
#include <QtDebug>
#include "paneloperatelogic.h"
#include "databasemanager.h"
#include <QInputDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE




class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Server* worker;
    DataBaseManager* dbm;
    QComboBox* scenelist;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void displayLoadedServiceData();
    void loadSceneList(QComboBox& box);
    void load_Scene();

signals:

private slots:
    void on_comboBox_ALAD_SysStatus_NOA_Status__currentIndexChanged(int index);

    void on_comboBox_ALAD_SysStatus_LateralControlStatus__currentIndexChanged(int index);

    //void on_setDataButton_clicked();

    void on_addSceneButton_clicked();

    void on_actionOpej_triggered();



    void on_actionSave_triggered();

    void on_actionSave_as_triggered();

    void on_actionActivate_triggered();

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
