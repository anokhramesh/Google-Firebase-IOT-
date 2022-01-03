#include <FirebaseESP8266.h>

#include  <ESP8266WiFi.h>

#define ssid "dewa406"
#define password "Ramesh16384"
#define FIREBASE_HOST "fir-iot-70103.firebaseio.com"
#define FIREBASE_AUTH "e59hFEOhWgOM4pXPqyZW5S0Fr1wTqGb3V3XSzaBL"

FirebaseData firebaseData;
int LEDPIN_1 = D0; //initialize the LED1 to D0 Pin
int LEDPIN_2 = D1; //initialize the LED2 to D1 Pin
int LEDPIN_3 = D2; //initialize the LED3 to D2 Pin
int LEDPIN_4 = D3; //initialize the LED4 to D3 Pin


void setup() {
  
 Serial.begin(9600);
   WiFi.begin (ssid, password);
   while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println ("");
  Serial.println ("WiFi Connected!");
  Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
    pinMode(LEDPIN_1,OUTPUT);//initialize the LED1 OUTPUT HIGH 
    pinMode(LEDPIN_2,OUTPUT);//initialize the LED2 OUTPUT HIGH 
    pinMode(LEDPIN_3,OUTPUT);//initialize the LED3 OUTPUT HIGH 
    pinMode(LEDPIN_4,OUTPUT);//initialize the LED4 OUTPUT HIGH 
}

void loop() {
  
  if (Firebase.get(firebaseData,"/Led1")) {
    if (firebaseData.dataType() == "string") {
      String led1 = firebaseData.stringData();
          if (led1=="1"){
              digitalWrite(LEDPIN_1,HIGH); //led 1 is ON
          }
          else if (led1=="0"){
              digitalWrite(LEDPIN_1,LOW);//led 2 if OFF
            }}}
  if (Firebase.get(firebaseData,"/Led2")) {
    if (firebaseData.dataType() == "string") {
      String led2 = firebaseData.stringData();
          if (led2=="1"){
              digitalWrite(LEDPIN_2,HIGH);//led2 is ON
          }
              else if (led2=="0"){
              digitalWrite(LEDPIN_2,LOW);// Led2 os OFF
            }}}
  if (Firebase.get(firebaseData,"/Led3")) {
    if (firebaseData.dataType() == "string") {
      String led3 = firebaseData.stringData();
          if (led3=="1"){
              digitalWrite(LEDPIN_3,HIGH);//Led3 is ON
          }
              else if (led3=="0"){
              digitalWrite(LEDPIN_3,LOW);//Led3 is OFF
            }}}
                      
  if (Firebase.get(firebaseData,"/Led4")) {
    if (firebaseData.dataType() == "string") {
      String led4 = firebaseData.stringData();
          if (led4=="1"){
              digitalWrite(LEDPIN_4,HIGH);//Led is ON
          }
              else if (led4=="0"){
              digitalWrite(LEDPIN_4,LOW);//Led is OFF
            }}}         
            }
