#include <ThingSpeak.h>
#include "ThingSpeak.h"
#include <DallasTemperature.h>
#include <OneWire.h>
#include<ESP8266WiFi.h>


const char ssid[] = "sayo80";
const char password[] = "Kiitsayanti#24";
unsigned long myChannelNumber =726155;
const char*myWriteAPIkey = "4UTCVV18A9H9U1SX ";

//float resolution =3.3/1023;
float temp;
WiFiClient client;

#define ONE_WIRE_BUS  5                      //D1 pin of nodemcu

OneWire oneWire(ONE_WIRE_BUS);
 
DallasTemperature DS18B20(&oneWire);            // Pass the oneWire reference to Dallas Temperature.
char tempCS[7];
void setup()
{
 
  //WiFi.disconnect();
  delay(10);
  Serial.begin(115200);
  Serial.println("Connecting to WiFi");
  WiFi.begin(ssid,password);
  
  Serial.println();
  Serial.println();



  
  while(WiFi.status()!=WL_CONNECTED)
        {
            delay(10);
            Serial.println(".");
            }

  Serial.println("");
  Serial.println("Connected to WiFi.......");
  Serial.println(ssid);
  Serial.println();
  ThingSpeak.begin(client);
  DS18B20.begin(); 
  

}
void getTemperature(){
  float tempC;
  
  do {
    DS18B20.requestTemperatures();
    float temp=DS18B20.getTempCByIndex(0);
    dtostrf(temp,2,2,tempCS);
    Serial.print(temp);
    Serial.println("*C");
    Serial.println();
   
    delay(100);
  }while(tempC==85.0 || tempC==(-127.0));
  
}

void loop()
{ 
                
 getTemperature();
  Serial.println("waiting to upload reading....... ");
  Serial.println();
  
  ThingSpeak.setField(1,tempCS);
  ThingSpeak.writeFields(myChannelNumber,myWriteAPIkey);
 
  Serial.println("data uploaded to cloud");
  Serial.println();
  Serial.println();
 
  //delay(1000);
}
