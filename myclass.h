#pragma once
#include <QObject>

class MyClass : public QObject
{
    Q_OBJECT
public:
    explicit MyClass(QObject *parent = nullptr);

signals:

public slots:
    void start();

private Q_SLOTS:
    void print();

private:
    void veryLongTask(int id);
};
