#include <Arduino.h>
#include <FirebaseESP32.h>
#include <WiFi.h>

#define FIREBASE_HOST "esp-32-test-6963e.firebaseio.com" // the project name address from firebase id
#define FIREBASE_AUTH "tCNMveAlWxQtXhP0JzpS55TEk1C9KvMwoxXgjuPx" // the secret key generated from firebase

#define WIFI_SSID "Upadhya Family"      // input your home or public wifi name
#define WIFI_PASSWORD "mantriCY163" //password of wifi ssid

FirebaseData data;
String path = "/Node";
String NodeID = "Status";

String val;

void setup()
{
    Serial.begin(9600);

    pinMode(LED_BUILTIN, OUTPUT);

    WiFi.begin(WIFI_SSID, WIFI_PASSWORD); //try to connect with wifi
    Serial.print("Connecting to ");
    Serial.print(WIFI_SSID);
    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        delay(500);
    }
    Serial.println();
    Serial.print("Connected to ");
    Serial.println(WIFI_SSID);
    Serial.print("IP Address is : ");
    Serial.println(WiFi.localIP()); //print local IP address

    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH); // connect to firebase
}

void loop(){

    if(data.dataType() == "boolean"){
        Serial.print("boolean");
    }
    if (data.dataType() == "string")
    {
        Serial.print("string");
    }
    if (data.dataType() == "int")
    {
        Serial.print("int");
    }
}
