#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSet<QString> people;
    people << "John" << "Mary" << "Roth" << "Denis";
    people.insert("Andre");

    foreach(QString person, people)
        qInfo() << person;

    qInfo() << "Mary in collection?" << people.contains("Mary");

    return a.exec();
}
