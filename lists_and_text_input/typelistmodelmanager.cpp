#include "typelistmodelmanager.h"
#include "datastructure.h"
#include "typelistmodel.h"
#include "typelistmodelproxy.h"
//-------------------------------------------------------------------------------------------------
using namespace listandtextinput;
//-------------------------------------------------------------------------------------------------
TypeListModelManager::TypeListModelManager(QObject *parent) :
    QObject(parent),
    m_typeListModel(new TypeListModel),
    m_typeListModelProxy(new TypeListModelProxy)
{
    Q_ASSERT(Q_NULLPTR != m_typeListModel);
    Q_ASSERT(Q_NULLPTR != m_typeListModelProxy);
    m_typeListModelProxy->setSourceModel(m_typeListModel);
}
//-------------------------------------------------------------------------------------------------
TypeListModelManager::~TypeListModelManager()
{
    if(m_typeListModel != nullptr)
    {
        delete(m_typeListModel);
    }
    if(m_typeListModelProxy != nullptr)
    {
        delete(m_typeListModelProxy);
    }
}
//-------------------------------------------------------------------------------------------------
void TypeListModelManager::insertDataStructure(QString name, QString description)
{
    m_typeListModel->add(name, description);
    updateTypeListModel();
}
//-------------------------------------------------------------------------------------------------
void TypeListModelManager::updateTypeListModel()
{
    m_typeListModel->update();
}
//-------------------------------------------------------------------------------------------------
QAbstractListModel *TypeListModelManager::typeListModel() const
{
    return m_typeListModel;
}
//-------------------------------------------------------------------------------------------------
QAbstractProxyModel *TypeListModelManager::typeListModelProxy() const
{
    return m_typeListModelProxy;
}
//-------------------------------------------------------------------------------------------------
