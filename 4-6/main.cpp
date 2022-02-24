#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QObject parent;
    parent.setObjectName("Parent");

    QObject child;
    child.setObjectName("Child");

    child.setParent(&parent);

    qInfo() << child.parent();

    qInfo() << parent.children();

    return a.exec();
}
