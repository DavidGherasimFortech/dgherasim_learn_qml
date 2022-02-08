#ifndef TYPELISTMODELMANAGER_H
#define TYPELISTMODELMANAGER_H
//-------------------------------------------------------------------------------------------------
#include <QObject>
#include <QAbstractListModel>

#include "typelistmodel.h"
#include "databasemodel.h"
//-------------------------------------------------------------------------------------------------
namespace listandtextinput
{
//-------------------------------------------------------------------------------------------------
class DataStructure;
class TypeListModel;
class TypeListModelProxy;
class TypeListModelManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QAbstractListModel* typeListModel READ typeListModel CONSTANT)
public:
    explicit TypeListModelManager();
    ~TypeListModelManager();
    Q_INVOKABLE void insertDataStructure(QString name, QString description);
    Q_INVOKABLE void deleteDataStructure(QString name, QString description);
    enum DataStructureRoles
    {
        NameRole = Qt::UserRole,
        DescriptionRole
    };
    void updateTypeListModel();
    QAbstractListModel *typeListModel() const;
private:
    TypeListModel *p_typeListModel;
    DatabaseModel *p_databaseModel;
};
//-------------------------------------------------------------------------------------------------
} // namespace listandtextinput
//-------------------------------------------------------------------------------------------------
#endif // TYPELISTMODELMANAGER_H
