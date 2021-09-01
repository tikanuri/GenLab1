#ifndef CAR_H
#define CAR_H
#include <QString>
#include <QList>
#include <QRandomGenerator>

class Car
{

    static const QStringList NameString;
    static uint32_t cnt;

    enum CarColor
    {
        Yellow,
        Red,
        Black,
        White,
        Blue,
        Green,
        Grey,
        Silver,
        EnumCount
    };

public:
    Car();
    const QString toQString();
    static void resetCnt(){cnt=0;};

private:
    QString name;
    CarColor color;
    uint16_t yearOfIssue;

};

#endif // CAR_H
