#include "mainwindow.h"
#include <QApplication>
#include<QDebug>
#include<modbusintdataextractor.h>
#include<modbusfloatdataextractor.h>
#include<QtEndian>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    ModbusIntDataExtractor mide;
    QByteArray temp;
    temp.resize(4);
    temp[0]=1;
    temp[1]=1;
    temp[2]=2;
    temp[3]=0;

    mide.extractData(temp,temp.size());

    temp[0]=0;
    temp[1]=4;
    temp[2]=0;
    temp[3]=8;

     mide.extractData(temp,temp.size());

     QByteArray temp1;
     temp1.resize(8);
     temp1[0]=137;
     temp1[1]=4;
     temp1[2]=0;
     temp1[3]=8;
     temp1[4]=100;
     temp1[5]=0;
     temp1[6]=12;
     temp1[7]=0;

     qDebug()<<temp1.size()<<temp1.toHex();

     qDebug()<<" CAlling from Main";



     qDebug()<<mide.extractData(temp1,temp1.size());
    // qDebug()<<mide.extractData(temp1,-1);


     union floatByte
     {
         char bytes[4];
         float f;
     };
     floatByte fb;
     fb.f=3.4;
     QByteArray temp3=QByteArray::fromRawData(fb.bytes,4).toHex();

     ModbusFloatDataExtractor mbfde;
     QByteArray temp2;
     temp2.resize(4);
     temp2[0]=temp3[3];
     temp2[1]=temp3[2];
     temp2[2]=temp3[1];
     temp2[3]=temp3[0];

     mbfde.extractData(temp2,4);
    return a.exec();
}
