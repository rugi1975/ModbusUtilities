#ifndef MODBUSFLOATDATAEXTRACTOR_H
#define MODBUSFLOATDATAEXTRACTOR_H

#include <QObject>

class ModbusFloatDataExtractor : public QObject
{
    Q_OBJECT
public:
    explicit ModbusFloatDataExtractor(QObject *parent = 0);

    const float *  extractData(const char *,int size);
signals:

public slots:



private:

static const int MAX_SIZE=4096;
float floatData[MAX_SIZE];

union floatByte
{
    char bytes[4];
    float f;
};

floatByte fb;
};

#endif // MODBUSFLOATDATAEXTRACTOR_H
