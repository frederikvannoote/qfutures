#include <QCoreApplication>
#include <QThreadPool>
#include <QDebug>
#include <QTimer>
#include "myclass.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyClass obj1;
    obj1.start();

    QTimer t;
    QObject::connect(&t, &QTimer::timeout, []() {
        qDebug() << "Active threads:" << QThreadPool::globalInstance()->activeThreadCount();
    });
    t.setInterval(100);
    t.start();

    QTimer::singleShot(10000, &a, &QCoreApplication::quit);

    return a.exec();
}
