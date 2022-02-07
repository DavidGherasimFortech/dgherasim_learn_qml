#ifndef TYPELISTMODELMANAGER_H
#define TYPELISTMODELMANAGER_H
//-------------------------------------------------------------------------------------------------
#include <QObject>
#include <QAbstractListModel>

#include "typelistmodel.h"
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
    explicit TypeListModelManager(QObject *parent = nullptr);
    ~TypeListModelManager();
    Q_INVOKABLE void insertDataStructure(QString name, QString description);
    enum DataStructureRoles
    {
        NameRole = Qt::UserRole,
        DescriptionRole
    };
    void updateTypeListModel();
    QAbstractListModel *typeListModel() const;
private:
    TypeListModel *m_typeListModel;
};
//-------------------------------------------------------------------------------------------------
} // namespace listandtextinput
//-------------------------------------------------------------------------------------------------
#endif // TYPELISTMODELMANAGER_H
