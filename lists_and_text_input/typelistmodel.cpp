#include <typelistmodel.h>
#include <string>
//-------------------------------------------------------------------------------------------------
using namespace listandtextinput;
//-------------------------------------------------------------------------------------------------
TypeListModel::TypeListModel()
{
}
//-------------------------------------------------------------------------------------------------
TypeListModel::~TypeListModel()
{
}
//-------------------------------------------------------------------------------------------------
int TypeListModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid())
    {
        return 0;
    }
    return p_types.count();
}
//-------------------------------------------------------------------------------------------------
QVariant TypeListModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
    {
        return QVariant();
    }
//    const DataStructure &data = p_types.at(index.row());
    const DataStructure &data = p_types[index.row()];
    switch (role)
    {
    case NameRole:
        return data.name();
    case DescriptionRole:
        return data.description();
    default:
        break;
    }
    return QVariant();
}
//-------------------------------------------------------------------------------------------------
QHash<int,QByteArray> TypeListModel::roleNames() const
{
    static QHash<int, QByteArray> mapping {
        {NameRole, "name"},
        {DescriptionRole, "description"}
    };
    return mapping;
}
//-------------------------------------------------------------------------------------------------
int TypeListModel::count() const
{
    return p_types.count();
}
//-------------------------------------------------------------------------------------------------
void TypeListModel::add(QString name, QString description)
{
    DataStructure newObj = DataStructure(name, description);
    p_types.push_back(newObj);
}
//-------------------------------------------------------------------------------------------------
