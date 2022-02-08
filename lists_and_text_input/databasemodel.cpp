#include <QDebug>

#include "databasemodel.h"
//-------------------------------------------------------------------------------------------------
using namespace listandtextinput;
//-------------------------------------------------------------------------------------------------
DatabaseModel::DatabaseModel(QString dbDir, QString dbName) :
    p_dbDir(dbDir),
    p_dbName(dbName)
{
    p_db = QSqlDatabase::addDatabase("QSQLITE", "test_connection");
    p_db.setDatabaseName(p_dbDir.absoluteFilePath(p_dbName));
    if (!p_db.open())
    {
        return;
    }
    p_sqlQuery = QSqlQuery(p_db);
    createTable();
}
//-------------------------------------------------------------------------------------------------
DatabaseModel::~DatabaseModel()
{
    p_db.close();
}
//-------------------------------------------------------------------------------------------------
void DatabaseModel::insertDataStructure(DataStructure element)
{
    if(!p_db.isOpen())
    {
        return;
    }
    QString query = "INSERT INTO test(name, description) VALUES('" + element.name() +
                    "', '" + element.description() + "');";
    if(!p_sqlQuery.exec(query))
    {
        return;
    }
}
//-------------------------------------------------------------------------------------------------
void DatabaseModel::deleteDataStructure(DataStructure element)
{
    if(!p_db.isOpen())
    {
        qWarning()<<"The connection to the database is not open.";
        return;
    }
    QString query = "DELETE FROM test WHERE name='" + element.name() +
                    "' AND description='" + element.description() + "';";
    if(!p_sqlQuery.exec(query))
    {
        qWarning()<<"The element was not deleted.";
        return;
    }
}
//-------------------------------------------------------------------------------------------------
QList<DataStructure> DatabaseModel::getAllDataFromTable()
{
    if(!p_db.isOpen())
    {
        qWarning()<<"The connection to the database is not open.";
        return QList<DataStructure> ();
    }
    QString query = "SELECT name, description FROM test;";
    if(p_sqlQuery.exec(query))
    {
        QList<DataStructure> result;
        while(p_sqlQuery.next())
        {
            QString db_name = p_sqlQuery.value(0).toString();
            QString db_description = p_sqlQuery.value(1).toString();
            DataStructure element(db_name, db_description);
            result.push_back(element);
        }
        qDebug()<<"Get data from database "<<result.size()<<"elements";
        return result;
    }
    else
    {
        qWarning()<<"The query '"<<query<<"' does not execute with success.";
        return QList<DataStructure> ();
    }
}
//-------------------------------------------------------------------------------------------------
void DatabaseModel::createTable()
{
    if(!p_db.isOpen())
    {
        qWarning()<<"The connection to the database is not open.";
        return;
    }
    QString query = "CREATE TABLE IF NOT EXISTS test (name VARCHAR(50) NOT NULL, description VARCHAR(200));";
    if(!p_sqlQuery.exec(query))
    {
        qWarning()<<"The database was not created";
        return;
    }
}
//-------------------------------------------------------------------------------------------------
