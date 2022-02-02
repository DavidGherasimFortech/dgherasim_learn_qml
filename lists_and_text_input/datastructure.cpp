#include "datastructure.h"
//-------------------------------------------------------------------------------------------------
using namespace listandtextinput;
//-------------------------------------------------------------------------------------------------
DataStructure::DataStructure(QString name, QString description) :
    p_name(name),
    p_description(description)
{
}
//-------------------------------------------------------------------------------------------------
QString DataStructure::name() const
{
    return p_name;
}
//-------------------------------------------------------------------------------------------------
QString DataStructure::description() const
{
    return p_description;
}
//-------------------------------------------------------------------------------------------------
