// Checkout my channel https://youtube.com/c/HKBHD to view more cool videos and projects

#include  <ESP8266WiFi.h>

#include <Firebase.h>
#include <FirebaseArduino.h>
#include <FirebaseCloudMessaging.h>
#include <FirebaseError.h>
#include <FirebaseHttpClient.h>
#include <FirebaseObject.h>

#include <SoftwareSerial.h>
SoftwareSerial uno(D6,D7); //(RX,TX)


int RecVal;


#define WIFI_SSID "HKB" // Change the name of your WIFI
#define WIFI_PASSWORD "hehehaha" // Change the password of your WIFI
#define FIREBASE_HOST "something.firebaseio.com" //Firebase Database URL
#define FIREBASE_AUTH "auth code" // Database Secret Code



void setup() {

 
   WiFi.begin (WIFI_SSID, WIFI_PASSWORD);
   while (WiFi.status() != WL_CONNECTED) {
    delay(500);
   Serial.begin(9600);
   // NodeMCU1.begin(4800);
   // NodeMCU2.begin(4800);
    uno.begin(4800); // Same baudrate(4800) in Uno for Serial Communication
   
  }
   
  pinMode(2,OUTPUT);
  digitalWrite(2,LOW); // In-Built LED turn ON when WiFi is connected
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  
}

void loop() {

  RecVal=Firebase.getString("Direction").toInt(); // "Direction" is the name of the field in Database
  
  Serial.println(RecVal);
  uno.write(RecVal);
  delay(500); //Change the value with respect to the response or network speed
}
