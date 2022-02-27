#include <QCoreApplication>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QRandomGenerator>

QString makeData()
{
    QString data;
    data.append("Unicode test\r\n");

    for (int i = 0; i < 10; i++)
    {
        // Not working on 6.2.3!!!
        // It is UTF-16, not UTF-8
        int number = QRandomGenerator::global()->bounded(65535); // 1112063
        data.append(QChar(number));
        data.append("\r\n");
    }

    return data;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString data = makeData();
    qInfo() << data;

    QFile file("data.txt");
    if(file.open(QIODevice::WriteOnly))
    {
        QTextStream stream(&file);
        stream.setEncoding(QStringConverter::Utf8);
        stream << data;
        stream.flush();

        file.close();
    }


    qInfo() << "Done";
    qInfo() << "UTF-8: " << data.toUtf8();
    qInfo() << "ASCII: " << data.toLatin1();

    return a.exec();
}
