#ifndef SERIALTHREAD_H
#define SERIALTHREAD_H

#include <QThread>
#include "serialportreceive.h"
#include "qextserialport.h"

extern QString zh;
extern int zhi[3];

class SerialThread : public QThread
{
    Q_OBJECT
public:
    explicit SerialThread(QObject *parent = 0);
    int send(QByteArray str);
private:
    void run();
    QextSerialPort *myCom;
    SerialPortReceive *SerialReceive;
signals:
    void serialFinished(const QByteArray &);
    
public slots:
    void onReadyRead();
    
};

#endif // SERIALTHREAD_H
