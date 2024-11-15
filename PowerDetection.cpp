/*
接線時需將輸入電壓降低5倍
esp32的邏輯電平和ADC分辨率: 3.3, 4095.0
arduino uno的邏輯電平和ADC分辨率: 5.0, 1023.0
2顆18650電池的電壓範圍: 5.4 ~ 8.3
*/

#include <Arduino.h>
#include "Module.h"

int BatteryPercentage(
    byte AnalogyPing,
    float LogicLevel,
    float ADCResolution,
    float HighVoltage,
    float LowVoltage
){
    float voltage = analogRead(AnalogyPing) * (LogicLevel / ADCResolution) * 5;

    // 檢查電壓是否在範圍內
    if (voltage > HighVoltage) {
        return 100;
    } else if (voltage < LowVoltage) {
        return 0;
    }

    // 將電壓轉換為百分比
    int percentage = round((voltage - LowVoltage) / (HighVoltage - LowVoltage) * 100);

    return percentage;
}