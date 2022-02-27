#include <QCoreApplication>
#include <QStringList>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QStringList names { "John" };
    names << "Mary" << "Denis";
    names.append("Kate");

    names.replaceInStrings("a", "@");
    qInfo() << names;

    names.replaceInStrings("@", "a");
    names.sort();
    qInfo() << names;

    QString people = names.join(", ");
    qInfo() << people;

    QStringList myList = names.filter("n");
    qInfo() << myList;

    QString me = "John";
    qInfo() << "Contains:" << names.contains(me);
    qInfo() << "Index:" << names.indexOf(me);
    qInfo() << "Value:" << names.at(0);

    return a.exec();
}
