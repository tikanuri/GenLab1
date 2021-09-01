#ifndef RECORD_H
#define RECORD_H
#include <QString>
#include <QList>
#include <QRandomGenerator>

class Record
{
    static const QStringList SubjectString;
    static uint32_t cnt;

    enum RecordType
    {
        Lecture,
        Practice,
        Laboratory,
        Exam,
        EnumCount
    };

public:
    Record();
    const QString toQString();
    static void resetCnt(){cnt=0;};

private:
    QString subject;
    RecordType type;
    uint16_t classRoom;

};

#endif // RECORD_H
