#include <Arduino.h>
#include <FirebaseESP32.h>
#include <WiFi.h>

//Define required Credentials
#define FIREBASE_HOST "esp-32-test-6963e.firebaseio.com"
#define FIREBASE_AUTH "tCNMveAlWxQtXhP0JzpS55TEk1C9KvMwoxXgjuPx"
#define WIFI_SSID "Upadhya Family"
#define WIFI_PASSWORD "mantriCY163"

FirebaseData firebaseData;

void setup(){
    Serial.begin(9600);
    
    //Connect to WiFi
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print("Connecting to WiFi");
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
    Firebase.reconnectWiFi(true);
    Firebase.setReadTimeout(firebaseData, 1000*60);
    Firebase.setwriteSizeLimit(firebaseData, "tiny");

    String path = "/Node%202";

    Serial.print("Starting...");

    for (uint8_t i = 0; i < 15; i++){
        if (Firebase.getInt(firebaseData, path)){
            Serial.println(firebaseData.intData());
            delay(5000);
            /*
            Serial.print("Passed!");
            Serial.println("PATH: " + firebaseData.dataPath());
            Serial.println("TYPE: " + firebaseData.dataType());
            Serial.println("ETag: " + firebaseData.ETag());
            Serial.print("VALUE: ");
            Serial.println("------------------------------------");
            Serial.println();
            */
        }

        else{
            Serial.println("FAILED");
            Serial.println("REASON: " + firebaseData.errorReason());
            Serial.println("------------------------------------");
            Serial.println();
        }
    }
}

void loop(){}