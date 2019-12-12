#ifndef ARDUINO_H
#define ARDUINO_H
#include<QByteArray>
#include<QtSerialPort/QSerialPort>
#include<QtSerialPort/QSerialPortInfo>
#include <QString>
#include <QDebug>


class Arduino
{
public:
    Arduino();
    ~Arduino();
    void connect_arduino();
    void close_arduino();

    QSerialPort* getserial(){return arduino;}
    QString getarduino_port_name();
    QByteArray read_arduino();
    void write_arduino(QByteArray d);
private:

    QSerialPort *arduino;
    static const quint16 arduino_uno_vendor_id = 9025;
    static const quint16 arduino_uno_product_id = 67;
    QByteArray arduinoData;
    bool arduino_is_available;
    QString arduino_uno_port_name ;







};

#endif // ARDUINO_H
