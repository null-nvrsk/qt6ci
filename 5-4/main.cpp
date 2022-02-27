#include <QCoreApplication>
#include <QMap>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QMap<QString, int> ages;
    ages.insert("John", 36);
    ages.insert("Mary", 34);
    ages.insert("Cargo", 12);

    qInfo() << "Keys:" << ages.keys();
    qInfo() << "Value: " << ages.values();

    qInfo() << "Mary is" << ages["Mary"] << "years old";

    ages.remove("Cargo");
    qInfo() << "Contains" << ages.contains("Cargo");

    qInfo() << "Keys:" << ages.keys();
    qInfo() << "Value: " << ages.values();

    foreach(QString key, ages.keys())
        qInfo() << key << " = " << ages[key];

    qInfo() << "Test" << ages.value("Test", -1);
    qInfo() << "John" << ages.value("John", -1);

    ages["John"] = 99;
    qInfo() << "John" << ages.value("John", -1);

    return a.exec();
}
