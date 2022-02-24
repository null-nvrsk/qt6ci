#include <QCoreApplication>
#include "test.h"

Test* makeTree()
{
    Test* root = new Test(nullptr, "Root");

    for(int p1 = 0; p1 < 5; p1++)
    {
        Test* p1_obj = new Test(root, "Parent-" + QString::number(p1));

        for(int p2 = 0; p2 < 3; p2++)
        {
            Test* p2_obj = new Test(p1_obj, "Child-" + QString::number(p2) + "-" + QString::number(p1));

            for(int p3 = 0; p3 < 2; p3++)
            {
                Test* p3_obj = new Test(p2_obj, "Subchhild-" + QString::number(p3) + "-" + QString::number(p2) + "-" + QString::number(p1));

            }
        }
    }


    return root;
}

void printTree(Test* root, int level = 0)
{
    if(root->children().length() == 0) return;

    QString lead = "-";
    lead.fill('-', level * 5);

    foreach(QObject* obj, root->children())
    {
        Test* child = qobject_cast<Test*>(obj);
        if(!child) return;

        qInfo() << lead << child;

        printTree(child, level + 1);
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Test* tree = makeTree();
    printTree(tree, 1);
    delete tree;

    return a.exec();
}
