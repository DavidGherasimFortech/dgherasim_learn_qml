#ifndef DATA_H
#define DATA_H
//-------------------------------------------------------------------------------------------------
#include <QString>
//-------------------------------------------------------------------------------------------------
namespace listandtextinput
{
class DataStructure
{
public:
    QString name() const;
    QString description() const;
private:
    QString p_name;
    QString p_description;
};
} // namespace listandtextinput
//-------------------------------------------------------------------------------------------------
#endif // DATA_H
