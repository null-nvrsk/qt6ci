#include <QCoreApplication>
#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>

void list(QDir &root)
{
    qInfo() << "---Listing---";
    foreach(QFileInfo fi, root.entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot, QDir::Name))
    {
        if(fi.isDir()) qInfo() << "Dir: " << fi.filePath();
        if(fi.isFile()) qInfo() << "File: " << fi.filePath();

        if(fi.isDir())
        {
            QDir childDir(fi.filePath());
            qInfo() << "Inspecting: " << childDir.absolutePath();
            list(childDir);
        }
    }

}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QDir dir(QCoreApplication::applicationDirPath());
//    dir.cdUp();
    list(dir);

    return a.exec();
}
