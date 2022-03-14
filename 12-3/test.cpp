#include "test.h"

Test::Test(QObject *parent)
    : QObject{parent}
{

}

void Test::fill()
{
    _name = "test object";
    for(int i = 0; i < 10; i++)
    {
        QString num = QString::number(i);
        QString key = "Key: " + num;
        QString value = "This is item number: " + num;
        _map.insert(key, value);
    }
}

QString Test::name()
{
    return _name;
}

void Test::setName(QString value)
{
    _name = value;
}

QMap<QString, QString> Test::map()
{
    return _map;
}
