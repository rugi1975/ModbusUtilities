#ifndef MODBUSINTDATAEXTRACTOR_H
#define MODBUSINTDATAEXTRACTOR_H

#include <QObject>
#include<QMap>
#include<QDebug>
class ModbusIntDataExtractor : public QObject
{
    Q_OBJECT
public:
    explicit ModbusIntDataExtractor(QObject *parent = 0);
    const unsigned short *  extractData(const char *,int size);
signals:

public slots:



private:

static const int MAX_SIZE=4096;
unsigned short intData[MAX_SIZE];

};

#endif // MODBUSINTDATAEXTRACTOR_H
