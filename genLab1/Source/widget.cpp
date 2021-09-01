#include "widget.h"
#include "ui_widget.h"

#include <QDebug>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->pushGenerate,&QPushButton::clicked,this,&Widget::generateFile);
    connect(ui->pushPath,&QPushButton::clicked,this,&Widget::browse);
    ui->radio1->toggle();

}

Widget::~Widget()
{
    delete ui;
}


void Widget::generateFile()
{
    const uint32_t cntLine = 5000;
    QString fileName = ui->linePath->text();
    if(fileName.isEmpty())
    {
        ui->labelStat->setText("Папки не существует");
        return;
    }


    int variant;
    if(ui->radio1->isChecked())
    {
        fileName.append("/DataVar1.txt");
        variant = 1;
    }
    else if(ui->radio2->isChecked())
    {
        fileName.append("/DataVar2.txt");
        variant = 2;
    }
    else if(ui->radio3->isChecked())
    {
        fileName.append("/DataVar3.txt");
        variant = 3;
    }

    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly))
    {

        ui->labelStat->setText("Папки не существует");
        return;
    }
    ui->labelStat->setText("Выполняется генерация");

    switch(variant){
    case 1:
        for(uint32_t i=0;i<cntLine;++i)
        {
            Car c;
            file.write(c.toQString().toUtf8());
        }
        Car::resetCnt();
        break;
    case 2:
        for(uint32_t i=0;i<cntLine;++i)
        {
            Employee e;
            file.write(e.toQString().toUtf8());
        }
        Employee::resetCnt();
        break;
    case 3:
        for(uint32_t i=0;i<cntLine;++i)
        {
            Record r;
            file.write(r.toQString().toUtf8());
        }
        Record::resetCnt();
        break;
    }
    file.close();
    ui->labelStat->setText("Генерация выполнена");
}


void Widget::browse()
{
    QString path = QFileDialog::getExistingDirectory();
    ui->linePath->setText(path);
}
