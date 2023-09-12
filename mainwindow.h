#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "server.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

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
