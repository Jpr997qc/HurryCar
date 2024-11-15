#ifndef MODULE_H
#define MODULE_H

#include <Arduino.h>

const int Baud = 115200;

const String SSID = "s23u"; //預設連接的WiFi名稱
const String Password = "ttest113"; //WiFi的密碼
const String AP_SSID = "Hurry"; //未連接WiFi時的AP名稱
const String AP_Password = "ttest113"; //AP的密碼
const int MaxRetries = 6; // 每次1秒

const byte AnalogyPing = A0;
const float LogicLevel = 3.3;
const float ADCResolution = 4095.0;
const float HighVoltage = 8.3;
const float LowVoltage = 5.4;

void TaskLCD(void *pvParameters);

void WiFiInitialization();
void LCDInitialization();

int BatteryPercentage(
    byte AnalogyPing, 
    float LogicLevel, 
    float ADCResolution, 
    float HighVoltage, 
    float LowVoltage);

#endif