#include "typelistmodelmanager.h"
#include "datastructure.h"
#include "typelistmodel.h"
#include "databasemodel.h"
//-------------------------------------------------------------------------------------------------
using namespace listandtextinput;
//-------------------------------------------------------------------------------------------------
TypeListModelManager::TypeListModelManager() :
    p_typeListModel(new TypeListModel),
    p_databaseModel(new DatabaseModel("C:\\Users\\david.gherasim\\AppData\\Local\\lists_and_text_input", "list_model_onboarding.db"))
{
    Q_ASSERT(Q_NULLPTR != p_typeListModel);
    Q_ASSERT(Q_NULLPTR != p_databaseModel);
    QList<DataStructure> db_elements = p_databaseModel->getAllDataFromTable();
    for(auto element : db_elements)
    {
        p_typeListModel->add(element);
    }
}
//-------------------------------------------------------------------------------------------------
TypeListModelManager::~TypeListModelManager()
{
    if(p_typeListModel != nullptr)
    {
        delete(p_typeListModel);
    }
    if(p_databaseModel != nullptr)
    {
        delete(p_databaseModel);
    }
}
//-------------------------------------------------------------------------------------------------
void TypeListModelManager::insertDataStructure(QString name, QString description)
{
    DataStructure element(name, description);
    p_typeListModel->add(element); // Insert into the memory structure
    p_databaseModel->insertDataStructure(element); // Insert into the database table
    updateTypeListModel();
}
//-------------------------------------------------------------------------------------------------
void TypeListModelManager::deleteDataStructure(QString name, QString description)
{
    DataStructure element(name, description);
    p_typeListModel->deleteElement(element);
    p_databaseModel->deleteDataStructure(element);
    updateTypeListModel();
}
//-------------------------------------------------------------------------------------------------
void TypeListModelManager::updateTypeListModel()
{
    p_typeListModel->update();
}
//-------------------------------------------------------------------------------------------------
QAbstractListModel *TypeListModelManager::typeListModel() const
{
    return p_typeListModel;
}
//-------------------------------------------------------------------------------------------------
