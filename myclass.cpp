#include "myclass.h"
#include <QDebug>
#include <QThread>
#include <QtConcurrent/QtConcurrent>
#include <QTime>


MyClass::MyClass(QObject *parent) : QObject(parent)
{

}

void MyClass::start()
{
    for (int i=0; i<5; i++)
    {
        QFuture<void> f = QtConcurrent::run(this, &MyClass::veryLongTask, i);

        QFutureWatcher<void> *watcher = new QFutureWatcher<void>(this);
        connect(watcher, &QFutureWatcher<void>::finished, this, &MyClass::print);
        watcher->setObjectName(QString("watcher %1").arg(i));
        watcher->setFuture(f);
    }
}

void MyClass::print()
{
    qDebug() << QTime::currentTime().toString(Qt::ISODateWithMs) << "Future has ended" << sender()->objectName();
}

void MyClass::veryLongTask(int id)
{
    qDebug() << QTime::currentTime().toString(Qt::ISODateWithMs) << "Starting very long task" << id;
    QThread::sleep(5);
    qDebug() << QTime::currentTime().toString(Qt::ISODateWithMs) << "Very long task" << id << "ended.";
}
