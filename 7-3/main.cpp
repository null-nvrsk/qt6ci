#include <QCoreApplication>
#include <QSettings>

void saveAge(QSettings *setting, QString group,QString name, int age)
{
    setting->beginGroup(group);
    setting->setValue(name, age);
    setting->endGroup();
}

int getAge(QSettings *setting, QString group,QString name)
{
    setting->beginGroup(group);

    if(!setting->contains(name))
    {
        qWarning() << "Does not contain" << name << "in" << group;
        setting->endGroup();
        return 0;
    }

    bool ok;
    int value = setting->value(name).toInt(&ok);
    setting->endGroup();

    if(!ok)
    {
        qWarning() << "Could not convert to int";
        return 0;
    }

    return value;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QCoreApplication::setOrganizationName("DevNull");
    QCoreApplication::setOrganizationDomain("devnull.org");
    QCoreApplication::setApplicationName("SetTest");

    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());

    saveAge(&settings, "people", "John", 36);
    saveAge(&settings, "beer", "Pino", 1);
    saveAge(&settings, "beer", "John", 5);

    qInfo() << "Pino" << getAge(&settings, "beer", "Pino");
    qInfo() << "John (people)" << getAge(&settings, "people", "John");
    qInfo() << "John (beer)" << getAge(&settings, "beer", "John");

    return a.exec();
}
