//#include <dht.h>
#include "DHT.h"
#include <LiquidCrystal.h>


#define DHTTYPE DHT22  
#define DHT11_PIN 7

DHT dht(DHT11_PIN, DHTTYPE);

int led1 = 8;
int led2 = 9;
char data;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup(){
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  Serial.begin(9600);
  lcd.begin(16, 2);
    dht.begin();
    
    
    
    
}

void loop()
{
  
Serial.println(dht.readTemperature());

      

  lcd.print("Temp = ");
  lcd.print(dht.readTemperature());
  data=Serial.read();

   if(data=='2')
 //  if(dht.readTemperature()>19)
    {
      digitalWrite(led1,HIGH);
      digitalWrite(led2,LOW);
     // Serial.write('1');
      }
  
    else if(data=='1')
  // else if(dht.readTemperature()<=19)
    {
      digitalWrite(led2,HIGH);
      digitalWrite(led1,LOW);
    
      }
      else if (data=='0'){ 
        digitalWrite(led1,LOW);
      digitalWrite(led2,LOW);
     // Serial.write('0');
        
        }
        else if(data=='4')
        {
          Serial.println(dht.readTemperature());
          
          }
 
     
  delay(1000);
  lcd.clear();
     
    
  
}
