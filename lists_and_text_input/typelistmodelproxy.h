#ifndef TYPELISTMODELPROXY_H
#define TYPELISTMODELPROXY_H
//-------------------------------------------------------------------------------------------------
#include <QSortFilterProxyModel>
//-------------------------------------------------------------------------------------------------
namespace listandtextinput
{
//-------------------------------------------------------------------------------------------------
class TypeListModelProxy : public QSortFilterProxyModel
{
public:
    explicit TypeListModelProxy();
};
//-------------------------------------------------------------------------------------------------
} // namespace listandtextinput
//-------------------------------------------------------------------------------------------------
#endif // TYPELISTMODELPROXY_H
