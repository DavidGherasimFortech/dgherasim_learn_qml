#ifndef DATA_H
#define DATA_H
//-------------------------------------------------------------------------------------------------
#include <QString>
#include <QAbstractListModel>
//-------------------------------------------------------------------------------------------------
namespace listandtextinput
{
//-------------------------------------------------------------------------------------------------
class DataStructure
{
public:
    DataStructure() = delete;
    DataStructure(QString name, QString description);
    QString name() const;
    QString description() const;
private:
    QString p_name;
    QString p_description;
};
//-------------------------------------------------------------------------------------------------
} // namespace listandtextinput
//-------------------------------------------------------------------------------------------------
#endif // DATA_H
