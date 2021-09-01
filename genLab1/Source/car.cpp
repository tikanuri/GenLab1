#include "car.h"

const QStringList Car::NameString = {
    "Ford Focus",
    "Audi A6",
    "BMW X5",
    "BMW X6",
    "ВАЗ 2101",
    "Лада Веста"
};

uint32_t Car::cnt = 0;

Car::Car()
{
    cnt++;
    name = NameString[QRandomGenerator::global()->bounded(NameString.size())];
    color = static_cast<CarColor>(QRandomGenerator::global()->bounded((quint32)CarColor::EnumCount));
    yearOfIssue = QRandomGenerator::global()->bounded(1980,2021);
}

const QString Car::toQString()
{
    QString str("%1;%2;%3;%4\n");
    return str.arg(cnt).arg(name).arg((uint32_t)color).arg(yearOfIssue);
}
