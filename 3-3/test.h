#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QDebug>

class Test : public QObject
{
    Q_OBJECT

public:
    explicit Test(QObject *parent = nullptr);
    ~Test();

    void testing();

signals:
    void alarm(QString noise);

public slots:
    void wake(QString noise);

};

#endif // TEST_H
