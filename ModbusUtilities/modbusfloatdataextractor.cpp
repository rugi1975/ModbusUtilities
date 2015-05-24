#include "modbusfloatdataextractor.h"
#include<QDebug>
ModbusFloatDataExtractor::ModbusFloatDataExtractor(QObject *parent) :
    QObject(parent)
{
}
const float *ModbusFloatDataExtractor::extractData(const char *ptr,int size)
{


    /// This function receive the pointer and extract float data from four sucesssive location keeping data in big endian
    /// format. Size is the byte size , hence , there will be total size/4 numbers of 32 bit float number in IEEE 754 format.
    /// They are extracted and kept in the
    /// buffer intData. Starting address of intData is returned. It is the responsibility of the caller
    /// to correctly read the integer data as caller have the knowledge of Size.
    //qDebug()<<"Size="<<size;
    if(size>0)
    {
        int parameterIndex=0;

        for(int byteCounter=0;byteCounter<size;byteCounter=byteCounter+4)
         {
             fb.bytes[0]=*(ptr+byteCounter+3);
             fb.bytes[1]=*(ptr+byteCounter+2);
             fb.bytes[2]=*(ptr+byteCounter+1);
             fb.bytes[3]=*(ptr+byteCounter+0);

             floatData[parameterIndex]=fb.f;
             parameterIndex++;
             qDebug()<<"Float Data"<<floatData[parameterIndex]<<QByteArray::fromRawData(ptr,4).toHex();
        }


    return floatData;
    }
    else
    {
        qDebug()<<"Invalid Size"<<size;

       /// Since Size can not be negative so it is a error situation. A Null pointer is returned.
       /// CAller must take care of the situation.
        return NULL;
    }
}
