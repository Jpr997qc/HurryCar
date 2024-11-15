#include <Arduino.h>
#include "Module.h"
#include <LCDI2C_Multilingual.h>

LCDI2C_Generic lcd(0x27, 16, 2);

void LCDInitialization(){
  lcd.init();
  lcd.backlight();
}

void TaskLCD(void *pvParameters){
  while(1){
    // 顯示電量
    String PowerPercentage = String(BatteryPercentage(AnalogyPing, LogicLevel, ADCResolution, HighVoltage, LowVoltage)) + "%";
    lcd.setCursor(16 - PowerPercentage.length(), 0);
    lcd.print(PowerPercentage);

    vTaskDelay(1000 / portTICK_PERIOD_MS); // 加入延遲1秒
  }
}