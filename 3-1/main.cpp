#include <QCoreApplication>
#include "test.h"

void notifications()
{
    Test mom;
    Test child;

    mom.setObjectName("Mom");
    child.setObjectName("Child");

    QObject::connect(&mom, &Test::alarm, &child, &Test::wake, Qt::AutoConnection);

    mom.testing();
//    child.wake("NOW");
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    notifications();

    return a.exec();
}
