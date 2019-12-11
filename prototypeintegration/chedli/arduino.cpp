#include "arduino.h"

Arduino::Arduino()
{
serial=new QSerialPort();
}

int Arduino::connect_arduino()
 {

    foreach(const QSerialPortInfo &serial_port_info,QSerialPortInfo ::availablePorts())
    {
        if(serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier())
        {
           qDebug ()<< serial_port_info.vendorIdentifier();
           qDebug ()<< serial_port_info.productIdentifier();

            if(serial_port_info.vendorIdentifier()==arduino_uno_vendor_id && serial_port_info.productIdentifier()==arduino_uno_producy_id)
           {

                arduino_is_available=true;
                arduino_port_name=serial_port_info.portName();
           }
        }
    }
    if(arduino_is_available)
    {
        serial->setPortName(arduino_port_name);

        if(serial->open(QIODevice::ReadWrite))
        {
           serial->setBaudRate(QSerialPort::Baud9600);
           serial->setDataBits(QSerialPort::Data8);
           serial->setParity(QSerialPort::NoParity);
           serial->setStopBits(QSerialPort::OneStop);
           serial->setFlowControl(QSerialPort::NoFlowControl);
           return  0;
       }
        return 1;
    }
    return 0;
 }


int Arduino::close_arduino()
 {
     if(serial->isOpen())
     {
         serial->close();
         return  0;
     }
     return  1;

     }



 QByteArray Arduino::read_arduino()
{
    if(serial->isReadable())
    {
  data=serial->readLine();
        return data;
    }
    return nullptr;
}


int Arduino::write_arduino(QByteArray d){
qDebug()<< d;
    if(serial->isWritable()){
       serial->write(d);
    }
    else{
        qDebug()<<"Couldn't WRite";
    }
    return 0;
}



