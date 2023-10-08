#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include<QtSql>
#include "server.h"

class DataBaseManager : public QObject
{
    Q_OBJECT
public:
    explicit DataBaseManager(QObject *parent = nullptr);
    ~DataBaseManager();

    QSqlDatabase mydb;
    void connClose();
    bool connOpen();
    void changeUnitData(QString tablename, QString linename, QString column, int val);
    void addNewLine(QString tablename, QString linename);
    void addNewScene_single(QString tablename,  QString linename, QVector<int>& val);
    void changeScene_single(QString tablename, QString linename, QVector<int> &val);
    void loadScene_single(QString scenename, QString servicename, ServiceDataType& out);

signals:

};

#endif // DATABASEMANAGER_H
