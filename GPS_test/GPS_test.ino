/*#include<SoftwareSerial.h>
#include <ESP8266WiFi.h>
SoftwareSerial gps = SoftwareSerial(13, 12);
char byteGPS = 0;
char gps_data[200];

void setup() {
  Serial.begin(115200);
  pinMode(13, INPUT);
  pinMode(12, OUTPUT);
  gps.begin(9600);
}

void loop() {

  byteGPS = '0'; // Remove data
  memset(gps_data, '\0', 200);
  Serial.flush();
  while (gps.available())
  {
    while (gps.available())
    {
      byteGPS = gps.read(); // Read the char that is in the GPS serial port
      if (byteGPS == '$') break; 
    }
    int i=0;
    while (gps.available())  // Available3
    {
      //delay(1);
      gps_data[i++] = byteGPS;
      byteGPS = gps.read();
      if ((byteGPS == '\n')) break;
    } 
    if (i > 1)
    {
      Serial.println(gps_data);
      //delay(1);
      //parse_gps_data();
    } 
  } 
}
*/

#include<SoftwareSerial.h>
#include <ESP8266WiFi.h>
//#include<TinyGPS++.h>

#define rx 13
#define tx 12
SoftwareSerial gps_serial(rx,tx);
//TinyGPSPlus gps;
//int dat[200] = {0};
int i,c,t,z;
//char latit[10] = "";
//char longi[10] = "";
char dat[302] = "";
char lati[10],longi[10],sendbuffer[100];
//bool f1 = false,f2 = true,f3 = false;
void setup()
{
  //i = -1;
  i = 0;
  //c = 0;
  Serial.begin(115200);
  gps_serial.begin(9600);
  Serial.flush();
}

//This is the main loop:
void loop()
{
bool fl2 = true;
  //while(gps_serial.available() > 0) Serial.write(gps_serial.read());

//#ifdef TRUE
  while(fl2)
  while(gps_serial.available() > 0)
  {
    byte b = gps_serial.read();
    dat[i++] = (char)b;
    //Serial.print("char ");
    if(i == 300){
      i = 0;
      fl2 = false;
      Serial.println();
      //Serial.println(dat);
      int j,k;
      for(j = 0;j < 280;j++)
        if(dat[j] == 'G' && dat[j+1] == 'G' && dat[j+2] == 'A'){
          Serial.println("Success!");
          for(k = 15;k < 24;k++)
            if(k == 17) lati[k-15] = '.';
            else if(dat[j+k] == '.') continue;
            else lati[k-15] = dat[j+k];  //Serial.print(dat[j+k]);
          lati[k-15] = '\0';  
          Serial.println(lati);
          for(k = 27;k < 35;k++)
            if(k == 30) longi[k-27] = '.';
            else if(dat[j+k] == '.') continue;
            else longi[k-27] = dat[j+k];//Serial.print(dat[j+k]);
          longi[k-27] = '\0';
          Serial.println(longi);
          break;
    }
    else continue;
    //if(j >= 280) Serial.println("Not Found");
      //delay(1000);  
    }

    
    //if((char)b == 'G') Serial.print((char)b);
    //else Serial.println("NOT G");
    //continue;
    //c++;
    
   /* if((char)b == 'G' && f2){
      t = c;
      Serial.println("LOOP1");
      f2 = false;
      f1 = true;
      continue;
    }
    //if((char)b == 'G' && f1)
      if(t - c == 1){
        //f2 = true;
        Serial.println("LOOP2");
        f1 = false;
        f2 = true;
        //f3 = true;
        
      } */

   /* if(f3){
      if((char)b == '$'){
        i = 0;
        c = 0;
        f3 = false;
        f2 = true;
        continue;
      }
      dat[i++] = (char)b;
      //Serial.println(dat[i-1]);
      
    }*/
    //Serial.println("Read char "+(char)b);
    /*if((char)b == 'G' && f2){
      f1 = true;
      t = c;
      f2 = false;
      continue;
    }
    if((char)b == 'G' && f1)
     if(t - c == 1){
      f3 = true;
      i = 0;
      f1 = false;
      continue;
    }
    if(f3)
    {
      dat[i++] = (char)b;
      Serial.print(dat[i-1]);
      if((char)b == '$'){
        //for(int j = 0;j < 100;j++) Serial.println(dat[i]);
        i = 0;
        c = 0;
        f1 = false;
        f2 = true;
        f3 = false;
      }
     }*/
    
  }
for(i = 0;i < strlen(lati);i++) sendbuffer[i] = lati[i];
    sendbuffer[i] = ',';
    i++;
    for(z = 0;z < strlen(longi);z++,i++) sendbuffer[i] = longi[z];
    i=0;

    Serial.println(sendbuffer);
//Serial.println("Out of while");
//#endif
}
/*void loop(){
  if(gps_serial.available()){
  //Serial.write(gps_serial.read());
  byte b = gps_serial.read();
  /*if((char)b == 'G' && f2){
    f1 = true;
    f2 = false;
    break;
  }
  if(f1 && (char)b = 'G'){
    f2 = true;
    break;
  }
  if(f2 && 
  if(b2 && (char
  }*/

/*
void loop(){
  while(gps_serial.available() > 0 && i < 200){
    dat[i] = gps_serial.read();
    Serial.println("NEXT");
    Serial.println("Ith is data is "+dat[i]);
    Serial.println(i);
    i++;
    //Serial.write(gps_serial.read());
    /*if(gps.encode(gps_serial.read())){
      if(gps.location.isValid()) Serial.println(gps.location.lat(),6);
      else Serial.println("No lat");
      Serial.println(gps.location.lat(),6);
    }
    else Serial.println("INVALID");*/
  
  
  /*while(gps_serial.available() > 0){
    gps.encode(gps_serial.read());
    Serial.println("Data received");

    if (gps.altitude.isUpdated())
  Serial.println(gps.altitude.meters());

  Serial.print("LAT=");  Serial.println(gps.location.lat(), 6);
Serial.print("LONG="); Serial.println(gps.location.lng(), 6);
//Serial.print("ALT=");  Serial.println(gps.altitude.meters());
  delay(3000);
  }*/

