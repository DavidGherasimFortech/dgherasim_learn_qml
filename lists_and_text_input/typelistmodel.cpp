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
    const DataStructure &data = p_types.at(index.row());
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
void TypeListModel::add(QString name, QString description)
{
    p_types.push_back(DataStructure(name, description));
}
//-------------------------------------------------------------------------------------------------
void TypeListModel::deleteElement(QString name)
{
    for(int i = 0; i < p_types.size(); i++)
    {
        if(p_types[i].name() == name )
        {
            p_types.removeAt(i);
        }
    }
}
//-------------------------------------------------------------------------------------------------
DataStructure TypeListModel::at(const int index)
{
    if((index < 0) || (index > p_types.size()))
    {
        return DataStructure(QString(), QString());
    }
    return p_types.at(index);
}
//-------------------------------------------------------------------------------------------------
void TypeListModel::update()
{
    beginResetModel();
    endResetModel();
}
//-------------------------------------------------------------------------------------------------
