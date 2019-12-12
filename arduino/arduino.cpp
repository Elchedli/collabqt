#include "arduino.h"

Arduino::Arduino()
{
arduino=new QSerialPort();
arduino_is_available=false;
}

void Arduino::connect_arduino()
 {


     foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
         //  check if the serialport has both a product identifier and a vendor identifier
         if(serialPortInfo.hasProductIdentifier() && serialPortInfo.hasVendorIdentifier()){
             //  check if the product ID and the vendor ID match those of the arduino uno
             if((serialPortInfo.productIdentifier() == arduino_uno_product_id)
                     && (serialPortInfo.vendorIdentifier() == arduino_uno_vendor_id)){
                 arduino_is_available = true; //    arduino uno is available on this port
                 arduino_uno_port_name = serialPortInfo.portName();
             }
         }
     }


     if(arduino_is_available){
         qDebug() << "Found the arduino port...\n";
         arduino->setPortName(arduino_uno_port_name);
         arduino->open(QSerialPort::ReadWrite);
         arduino->setBaudRate(QSerialPort::Baud9600);
         arduino->setDataBits(QSerialPort::Data8);
         arduino->setFlowControl(QSerialPort::NoFlowControl);
         arduino->setParity(QSerialPort::NoParity);
         arduino->setStopBits(QSerialPort::OneStop);


     }else{
         qDebug() << "Couldn't find the correct port for the arduino.\n";
     }

 }

 void Arduino::close_arduino()
 {
     if(arduino->isOpen())
     {
         arduino->close();

     }

}

QByteArray Arduino::read_arduino()
{
  qDebug()<<"test123";
  char buffer[50];

do

  {

      //  arduinoData = arduino->readLine();//}
      //  arduino->readLine(buffer,50);

        arduino->readLine(buffer,50);
        qDebug()<<"test02320";
  }
   while(strcmp(buffer,"")==0);

        //arduinoData.remove(4,2);

        //qDebug()<<arduinoData;
//qDebug()<<"------";


qDebug()<<"here";

qDebug()<<buffer;
arduinoData=buffer;
qDebug()<<arduinoData;
return arduinoData;




}

void Arduino::write_arduino(QByteArray d)
{

    if(arduino->isWritable())
       {arduino->write(d);
        arduino->flush();
                 arduino->waitForBytesWritten(1000);
    }
    else
        qDebug()<<"Couldn't WRite";

}

Arduino::~Arduino()
{

}
