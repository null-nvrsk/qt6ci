#include <QCoreApplication>
#include <QSettings>
#include <QStringList>
#include <QRandomGenerator>

void saveAge(QSettings *setting, QString group, QString name, int age)
{
    setting->beginGroup(group);
    setting->setValue(name, age);
    setting->endGroup();
}

int getAge(QSettings *setting, QString group, QString name)
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
        qWarning() << "Failed to convert to int";
        return 0;
    }

    return value;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QCoreApplication::setOrganizationName("DevNull");
    QCoreApplication::setOrganizationDomain("dev-null.com");
    QCoreApplication::setApplicationName("Tester");

    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());

    saveAge(&settings, "people", "John", 36);
    saveAge(&settings, "beer", "Boble", 1);
    saveAge(&settings, "beer", "John", 7);

    QStringList people;
    people << "John" << "Mary" << "Denis" << "Helga";

    foreach(QString person, people)
    {
        int value = QRandomGenerator::global()->bounded(100);
        saveAge(&settings, "test", person, value);
    }

    settings.sync();
    qInfo() << "File:" << settings.fileName();

    foreach(QString group, settings.childGroups())
    {
        settings.beginGroup(group);
        qInfo() << "Group" << group;

        foreach(QString key, settings.childKeys())
        {
            qInfo() << "....key:" << key << "=" << settings.value(key).toString();
        }


        settings.endGroup();
    }

    return a.exec();
}
