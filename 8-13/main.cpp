#include <QCoreApplication>
#include <QFile>
#include <QDataStream>

bool write(QString filename)
{
    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly))
    {
        qInfo() << file.errorString();
        return false;
    }

    QDataStream stream(&file);
    stream.setVersion(QDataStream::Qt_6_2);

    int age = 36;
    QString name = "John";
    double weight = 85.6;

    qInfo() << "Writing file";
    stream << age << name << weight;

    if(!file.flush())
    {
        qInfo() << file.errorString();
        file.close();
        return false;
    }


    qInfo() << "Closing file";
    file.close();
    return true;
}

bool read(QString filename)
{
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly))
    {
        qInfo() << file.errorString();
        return false;
    }

    QDataStream stream(&file);
    if(stream.version() != QDataStream::Qt_6_2)
    {
        qInfo() << "Wrong file version";
        file.close();
        return false;
    }

    int age;
    QString name;
    double weight;

    qInfo() << "Reading from file";
    stream >> age;
    stream >> name;
    stream >> weight;

    qInfo() << "Closing file";
    file.close();

    qInfo() << "Name: " << name;
    qInfo() << "Age: " << age;
    qInfo() << "Weight: " << weight;

    return true;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString filename = "test.dat";

    if(write(filename)) read(filename);

    return a.exec();
}
