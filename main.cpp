#include <QCoreApplication>
#include <QThreadPool>
#include <QDebug>
#include "myclass.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "Active threads:" << QThreadPool::globalInstance()->activeThreadCount();

    QThreadPool::globalInstance()->setMaxThreadCount(50);

    MyClass obj1;
    obj1.start();

    return a.exec();
}
