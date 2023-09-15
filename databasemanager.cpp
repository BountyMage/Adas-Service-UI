#include "databasemanager.h"

DataBaseManager::DataBaseManager(QObject *parent) : QObject(parent)
{

}

DataBaseManager::~DataBaseManager()
{

}
void DataBaseManager::connClose(){
    mydb.close();
    mydb.removeDatabase(QSqlDatabase::defaultConnection);
}

bool DataBaseManager::connOpen(){
    mydb = QSqlDatabase::addDatabase("QSQLITE");

    QString filePath = QDir::currentPath() + "/database/servicedata.db";
    mydb.setDatabaseName(filePath);

    if(!mydb.open()){
        qDebug()<<("Failed to open");
        return false;
    }
    else{
        qDebug()<<("Connected...");
        return true;
    }

}

void DataBaseManager::changeUnitData(QString tablename, QString linename, QString column, int val){
    QSqlQuery qry;
    qry.prepare("update "+tablename+" set '"+column+"' = '"+QString::number(val)+"' where Scene = '"+linename+"'");
    qDebug()<<("tablename: ")<<tablename<<("column: ")<<column<<("val: ")<<val;
    qry.exec();

}

void DataBaseManager::addNewLine(QString tablename, QString linename){
    QSqlQuery qry;
    qry.prepare("INSERT INTO "+tablename+" (Scene) VALUES ('"+linename+"')");
    qry.exec();

}

void DataBaseManager::addNewScene_single(QString tablename,  QString linename, QVector<int>& val){
    int m_amount = 2;
    addNewLine(tablename,linename);
    for(int i = 0;i<m_amount;i++){
       changeUnitData(tablename,linename,QString::number(i),val[i]);
    }
}

void DataBaseManager::loadScene_single(QString scenename, QString servicename, ServiceDataType& out)
{
    QSqlQuery qry;
    qry.prepare("select * from "+servicename+" where Scene = '"+scenename+"'");
    qry.exec();

    int size = out.size();
    while (qry.next()) {

        for(int i =0;i<size;i++)
        {
            out[i] = qry.value(i+1).toInt(); // 获取第一列的值
            // 处理获取到的数据
            qDebug()<<("out ")<<i<<" = "<<out[i];
        }
    }
}
