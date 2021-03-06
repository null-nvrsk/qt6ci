#include <QCoreApplication>
#include <QDebug>
#include <QLoggingCategory>

Q_DECLARE_LOGGING_CATEGORY(network);
Q_LOGGING_CATEGORY(network, "network");

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "test";

    qInfo(network) << "test";
    qWarning(network) << "test";

    // turn it off
    QLoggingCategory::setFilterRules("network.debug=false");

    // will not log
    qDebug(network) << "kitty";

    if(!network().isDebugEnabled())
    {
        QLoggingCategory::setFilterRules("network.debug=true");
        qDebug(network) << "We turned it back on!";
    }

    qDebug(network) << "yes";

    return a.exec();
}
