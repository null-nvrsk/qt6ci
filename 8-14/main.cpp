#include <QCoreApplication>
#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>

void list(QDir &root)
{
    qInfo() << "---Listing---";
    foreach(QFileInfo fi, root.entryInfoList(QDir::Filter::Dirs, QDir::Name))
    {
        if(fi.isDir())
        {
            qInfo() << fi.absoluteFilePath();
        }
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QDir dir(QCoreApplication::applicationDirPath());
    qInfo() << dir.dirName();
    qInfo() << dir.absolutePath();

    dir.cdUp();
    qInfo() << dir.absolutePath();
    list(dir);

    dir.mkdir("test");
    list(dir);

    dir.rmdir("test");
    list(dir);

    return a.exec();
}
