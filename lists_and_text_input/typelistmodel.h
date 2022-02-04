#ifndef TYPELISTMODEL_H
#define TYPELISTMODEL_H
//-------------------------------------------------------------------------------------------------
#include <QAbstractListModel>
#include <QObject>

#include "datastructure.h"
//-------------------------------------------------------------------------------------------------
namespace listandtextinput
{
class DataStructure;
//-------------------------------------------------------------------------------------------------
class TypeListModel : public QAbstractListModel
{
public:
    enum DataStructureRoles
    {
        NameRole = Qt::UserRole,
        DescriptionRole
    };
    TypeListModel();
    ~TypeListModel();
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;
    void add(QString name, QString description);
    void update();
private:
    QList<DataStructure> p_types;
};
//-------------------------------------------------------------------------------------------------
} // namespace listandtextinput
//-------------------------------------------------------------------------------------------------
#endif // TYPELISTMODEL_H
