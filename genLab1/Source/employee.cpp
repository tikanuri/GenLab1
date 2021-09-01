#include "employee.h"

const QStringList Employee::MaleNameString = {
    "Алексей",
    "Александр",
    "Борис",
    "Василий",
    "Виталий",
    "Вадим",
    "Геннадий",
    "Дмитрий",
    "Евгений",
    "Иван",
    "Олег",
    "Павел",
    "Сергей"
};

const QStringList Employee::FemaleNameString = {
    "Анна",
    "Алёна",
    "Анастасия",
    "Валерия",
    "Галина",
    "Дарья",
    "Ева",
    "Евгения",
    "Екатерина",
    "Елизавета",
    "Ирина",
    "Мария",
    "Надежда",
    "Ольга",
    "Софья",
    "Яна"
};

const QStringList Employee::SurnameString = {
    "Терехин",
    "Прохоров",
    "Савельев",
    "Воробьёв",
    "Иванов",
    "Сидоров",
    "Алексеев",
    "Васильев",
    "Минеев",
    "Козлов",
    "Мельников",
    "Семакин",
    "Давыдов",
    "Логинов",
    "Яковлев",
    "Филиппов",
    "Сапожков",
    "Медведев",
    "Звягин"
};

const QStringList Employee::PatronymicString = {
    "Алексеев", //Алексеевич Алексеевна
    "Александров",
    "Борисов",
    "Васильев",
    "Витальев",
    "Вадимов",
    "Геннадьев",
    "Дмитриев",
    "Евгеньев",
    "Иванов",
    "Олегов",
    "Павлов",
    "Сергеев"
};

uint32_t Employee::cnt = 0;

Employee::Employee()
{
    cnt++;
    fullName = "%2%3 %1 %4%5";
    sex = static_cast<EmployeeSex>(QRandomGenerator::global()->bounded((quint32)EmployeeSex::EnumCount));
    yearOfBirth = QRandomGenerator::global()->bounded(1950,2003);

    if(sex)//Female
    {
        fullName = fullName.arg(FemaleNameString[QRandomGenerator::global()->bounded(FemaleNameString.size())]);
        fullName = fullName.arg(SurnameString[QRandomGenerator::global()->bounded(SurnameString.size())]).arg("а");
        fullName = fullName.arg(PatronymicString[QRandomGenerator::global()->bounded(PatronymicString.size())]).arg("на");
    }
    else//Male
    {
        fullName = fullName.arg(MaleNameString[QRandomGenerator::global()->bounded(MaleNameString.size())]);
        fullName = fullName.arg(SurnameString[QRandomGenerator::global()->bounded(SurnameString.size())]).arg("");
        fullName = fullName.arg(PatronymicString[QRandomGenerator::global()->bounded(PatronymicString.size())]).arg("ич");
    }
}

const QString Employee::toQString()
{
    QString str("%1;%2;%3;%4\n");
    return str.arg(cnt).arg(fullName).arg(yearOfBirth).arg((uint32_t)sex);
}
