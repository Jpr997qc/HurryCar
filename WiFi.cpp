#include <Arduino.h>
#include "Module.h"
#include <WiFi.h>

void WiFiInitialization(){
    int RetryCount = 0;
    
    // 連接WiFi
    WiFi.begin(SSID.c_str(), Password.c_str());

    // 等待連接
    Serial.print("WiFi connection ");
    while (WiFi.status() != WL_CONNECTED && RetryCount < MaxRetries) {
        delay(1000);
        RetryCount++;
        Serial.print(".");
    }

    printf("\n");

    // 連接成功
    if (WiFi.status() == WL_CONNECTED) {
        Serial.printf("Connected to %s\n", SSID.c_str());
    } else {
        // 連接失敗，啟動AP模式
        Serial.println("Failed to connect to WiFi. Setting up AP mode...");
        WiFi.softAP(AP_SSID.c_str(), AP_Password.c_str());
        Serial.printf("AP mode is activated, SSID: %s, Password: %s\n", AP_SSID.c_str(), AP_Password.c_str());
    }
}