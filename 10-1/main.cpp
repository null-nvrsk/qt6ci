#include <QCoreApplication>
#include <QDir>
#include <QFile>

QByteArray makedata()
{
    QByteArray data;
    for(int i = 0; i < 10; i++)
    {
        data.append(72);
        data.append(101);
        data.append(108);
        data.append(108);
        data.append(111);
        data.append(33);
        data.append(13);
        data.append(10);
    }

    return data;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QByteArray data = makedata();
    qInfo() << data;

    QFile file("data.txt");
    if(file.open(QIODevice::WriteOnly))
    {
        file.write(data);
        file.close();
    }

    qInfo() << "Done";

    return a.exec();
}
