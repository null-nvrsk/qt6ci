#include <QCoreApplication>
#include <QSettings>

void info(QSettings &settings)
{
    qInfo() << "File:" << settings.fileName();
    qInfo() << "Keys:" << settings.allKeys();
}

void save(QSettings &settings)
{
    settings.setValue("test", 123);
    qInfo() << settings.status();
    qInfo() << "Saved";
}

void load(QSettings &settings)
{
    info(settings);

    qInfo() << settings.value("test").toString();
    bool ok;
    qInfo() << settings.value("test").toInt(&ok);
    if(!ok)
    {
        qInfo() << "Could not convert to int";
    }

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QCoreApplication::setOrganizationName("DevNull");
    QCoreApplication::setOrganizationDomain("devnull.org");
    QCoreApplication::setApplicationName("SetTest");

//    QSettings settings;
    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());
    if(settings.allKeys().length() == 0)
    {
        qInfo() << "No settings. Saving...";
        save(settings);
    }
    else
    {
        qInfo() << "Loading the settings...";
        load(settings);
    }

    return a.exec();
}
