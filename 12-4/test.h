#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QDebug>
#include <QMap>
#include <QDataStream>

class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = nullptr);
    void fill();
    QString name();
    void setName(QString value);
    QMap<QString, QString> map();
    void setMap(QMap<QString, QString> newMap);

    friend QDataStream& operator << (QDataStream &stream, const Test &t)
    {
        qInfo() << "Operator <<";
        stream << t._name;
        stream << t._map;
        return stream;
    }

    friend QDataStream& operator >> (QDataStream &stream, Test &t)
    {
        qInfo() << "Operator >>";
        stream >> t._name;
        stream >> t._map;
        return stream;
    }

signals:

private:
    QString _name;
    QMap<QString, QString> _map;
};

#endif // TEST_H
