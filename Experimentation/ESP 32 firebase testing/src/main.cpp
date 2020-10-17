#include <Arduino.h>
#include<FirebaseESP32.h>

//Define required Credentials
#define FIREBASE_HOST "esp-32-test-6963e.firebaseio.com"
#define FIREBASE_AUTH "tCNMveAlWxQtXhP0JzpS55TEk1C9KvMwoxXgjuPx"
#define WIFI_SSID "Upadhya Family"
#define WIFI_PASSWORD "mantriCY163"

FirebaseData firebaseData;

void setup(){
    Serial.begin(9600);
    
    //Connect to WiFi
    Serial.print("Connecting to Wi-Fi");
    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        delay(300);
    }
    Serial.println();
    Serial.print("Connected with IP: ");
    Serial.println(WiFi.localIP());
    Serial.println();

    //Initialize Firebase
    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}