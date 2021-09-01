#include "record.h"

const QStringList Record::SubjectString = {
    "Метрология",
    "ООП",
    "Математический анализ",
    "Архитектуры процессорных систем",
    "Философия",
    "Иностранный язык",
    "Линейная алгебра",
    "Теория вероятности и математическая статистика",
    "Дискретная математика"
};

uint32_t Record::cnt = 0;

Record::Record()
{
    cnt++;
    subject = SubjectString[QRandomGenerator::global()->bounded(SubjectString.size())];
    type = static_cast<RecordType>(QRandomGenerator::global()->bounded((quint32)RecordType::EnumCount));

    uint16_t k = QRandomGenerator::global()->bounded(3U);
    switch(k)
    {
    case 0:
        classRoom = 1201U + QRandomGenerator::global()->bounded(5U);
        break;
    case 1:
        classRoom = 3101U + QRandomGenerator::global()->bounded(3U)*100 + QRandomGenerator::global()->bounded(40U);
        break;
    case 2:
        classRoom = 4101U + QRandomGenerator::global()->bounded(3U)*100 + QRandomGenerator::global()->bounded(40U);
        break;
    }

}

const QString Record::toQString()
{
    QString str("%1;%2;%3;%4\n");
    return str.arg(cnt).arg(subject).arg((uint32_t)type).arg(classRoom);
}
