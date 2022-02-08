#ifndef DATABASEMODEL_H
#define DATABASEMODEL_H
//-------------------------------------------------------------------------------------------------
#include <QString>
#include <QtSql/QSqlDatabase>
#include <QDir>
#include <QtSql/QSqlQuery>

#include "datastructure.h"
//-------------------------------------------------------------------------------------------------
namespace listandtextinput
{
//-------------------------------------------------------------------------------------------------
class DatabaseModel : public QObject
{
    Q_OBJECT
public:
    DatabaseModel() = delete;
    DatabaseModel(QString dbDir, QString dbName);
    ~DatabaseModel();
    void insertDataStructure(DataStructure element);
    void deleteDataStructure(DataStructure element);
    QList<DataStructure> getAllDataFromTable();
private:
    void createTable();
    QDir p_dbDir;
    QString p_dbName;
    QSqlDatabase p_db;
    QSqlQuery p_sqlQuery;
};
//-------------------------------------------------------------------------------------------------
} // namespace listandtextinput
//-------------------------------------------------------------------------------------------------
#endif // DATABASEMODEL_H
