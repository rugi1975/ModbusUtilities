#include "modbusintdataextractor.h"

ModbusIntDataExtractor::ModbusIntDataExtractor(QObject *parent) :
    QObject(parent)
{

}
const unsigned short * ModbusIntDataExtractor::extractData(const char *ptr,int size)
{


    /// This function receive the pointer and extract integer data from two sucesssive location keeping data in big endian
    /// format. Size is the byte size , hence , there will be total size/2 numbers of 16 bit register. They are extracted and kept in the
    /// buffer intData. Starting address of intData is returned. It is the responsibility of the caller
    /// to correctly read the integer data as caller have the knowledge of Size.
    //qDebug()<<"Size="<<size;
    if(size>0)
    {
        int parameterIndex=0;

        for(int byteCounter=0;byteCounter<size;byteCounter=byteCounter+2)
         {
             intData[parameterIndex]=(static_cast<unsigned short>(*(ptr+byteCounter+1)))*256+(static_cast<unsigned short>(*(ptr+byteCounter)));
             parameterIndex++;
        }

   // qDebug()<<"Integer Vector to be returned"<<QByteArray(reinterpret_cast<char *>(intData),size).toHex();

    /*for(int i=0;i<size/2;i++)
    {
        qDebug()<<*(intData+i);
    }*/
    return intData;
    }
    else
    {
        qDebug()<<"Invalid Size"<<size;

       /// Since Size can not be negative so it is a error situation. A Null pointer is returned.
       /// CAller must take care of the situation.
        return NULL;
    }
}

/*const QVector<unsigned int> &  ModbusIntDataExtractor::fillData(QVector<unsigned int> & vector, const char *ptr, int size)
{

    int parameterIndex=0;
    for(int byteCounter=0;byteCounter<size;byteCounter=byteCounter+2)
     {
         vector[parameterIndex]=(static_cast<unsigned int>(*(ptr+byteCounter+1)))*256+(static_cast<unsigned int>(*(ptr+byteCounter)));
         parameterIndex++;
    }

qDebug()<<"Integer Vector to be returned"<<vector;
return vector;
}*/
