#include "typelistmodelmanager.h"
#include "datastructure.h"
#include "typelistmodel.h"
//-------------------------------------------------------------------------------------------------
using namespace listandtextinput;
//-------------------------------------------------------------------------------------------------
TypeListModelManager::TypeListModelManager(QObject *parent) :
    QObject(parent),
    m_typeListModel(new TypeListModel)
{
    Q_ASSERT(Q_NULLPTR != m_typeListModel);
}
//-------------------------------------------------------------------------------------------------
TypeListModelManager::~TypeListModelManager()
{
    if(m_typeListModel != nullptr)
    {
        delete(m_typeListModel);
    }
}
//-------------------------------------------------------------------------------------------------
void TypeListModelManager::insertDataStructure(QString name, QString description)
{
    m_typeListModel->add(name, description);
    updateTypeListModel();
}
//-------------------------------------------------------------------------------------------------
void TypeListModelManager::deleteDataStructure(QString name)
{
    m_typeListModel->deleteElement(name);
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
