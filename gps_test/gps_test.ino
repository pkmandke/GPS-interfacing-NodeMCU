#include <ESP8266WiFi.h>
#include<SoftwareSerial.h>
#include<TinyGPS++.h>
#define rx 13
#define tx 12
SoftwareSerial gps_serial(rx,tx);
TinyGPSPlus gps;

float latitude, longitude, speed_mph, alt;
char sendbuffer[100];

void setup(){
Serial.begin(115200);  //Was 115200 previously
  delay(10);
  gps_serial.begin(9600);

  
}

void loop(){
  if(gps_serial.available() > 0){
    gps.encode(gps_serial.read());
    Serial.println("Data received");
  //  Serial.println(gps_serial.read());

   // if (gps.altitude.isUpdated())
  Serial.println("Elevation=");
  Serial.println(gps.altitude.meters());
  //alt = gps.altitude.meters();
//if (gps.location.lat.isUpdated())
 Serial.println("Lat = ");
 Serial.println(gps.location.lat());
//latitude = gps.location.lat();
//if (gps.location.lng.isUpdated())
 Serial.println("Long=");
 Serial.println(gps.location.lng());
//longitude = gps.location.lng();
/*
 char *p = sendbuffer;
// add speed value
speed_mph = 0;
dtostrf(speed_mph, 2, 6, p);
p += strlen(p);
p[0] = ','; p++;
// concat latitude
dtostrf(latitude, 2, 6, p);
p += strlen(p);
p[0] = ','; p++;
// concat longitude
dtostrf(longitude, 3, 6, p);
p += strlen(p);
p[0] = ','; p++;
// concat altitude
dtostrf(alt, 2, 6, p);
p += strlen(p);
// null terminate
p[0] = 0;
Serial.println("Sending: "); Serial.println(sendbuffer);
*/delay(4000);
  }
}

