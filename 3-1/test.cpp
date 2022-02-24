#include "test.h"

Test::Test(QObject *parent)
    : QObject{parent}
{
    qInfo() << this << "constructor";
}

Test::~Test()
{
    qInfo() << this << "deconstructor";
}

void Test::testing()
{
    QString noise = "WAKE UP!";
    emit alarm(noise);
}

void Test::wake(QString noise)
{
    qInfo() << "From" << sender() << noise;
}
