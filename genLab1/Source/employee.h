#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <QString>
#include <QList>
#include <QRandomGenerator>

class Employee
{
    static const QStringList MaleNameString;
    static const QStringList FemaleNameString;
    static const QStringList SurnameString;
    static const QStringList PatronymicString;
    static uint32_t cnt;

    enum EmployeeSex
    {
        Male,
        Female,
        EnumCount
    };

public:
    Employee();
    const QString toQString();
    static void resetCnt(){cnt=0;};

private:
    QString fullName;
    uint16_t yearOfBirth;
    EmployeeSex sex;
};

#endif // EMPLOYEE_H
