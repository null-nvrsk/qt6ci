#include <QCoreApplication>
#include <QFile>
#include <QDateTime>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString filename = "test.txt";

    QFile file(filename);
    if(file.open(QIODevice::Append))
    {
        QString now = QDateTime::currentDateTime().toString();

        QByteArray data;
        data.append(now.toLocal8Bit());
        data.append(" - ");
        data.append("Hell Word\r\n");

        file.write(data);

        file.close();

        qInfo() << "Append to the file";
    }
    else
    {
        qInfo() << file.errorString();
    }
    return a.exec();
}
