#include <QCoreApplication>
#include "myclass.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyClass obj1;
    obj1.start();

    return a.exec();
}
