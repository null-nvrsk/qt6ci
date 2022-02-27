#include <QCoreApplication>
#include <QSettings>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString filename = a.applicationDirPath() + "/settings.ini";
    qInfo() << filename;

    QSettings settings(filename, QSettings::Format::IniFormat);

    settings.beginGroup("people");
    settings.setValue("John", 38);
    settings.endGroup();

    settings.sync();

    settings.beginGroup("people");
    qInfo() << "Timmy:" << settings.value("Timmy", QVariant("Person not found!"));
    qInfo() << "John:" << settings.value("John", QVariant("Person not found!"));
    settings.endGroup();

    return a.exec();
}
