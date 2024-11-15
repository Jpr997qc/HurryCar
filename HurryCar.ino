#include "Module.h"

void setup(){
  Serial.begin(Baud);

  WiFiInitialization();
  LCDInitialization();

  //Pointers, Names, Stack Size, Parameters, Priority, Handle
  xTaskCreate(TaskLCD, "所有LCD顯示相關的功能", 2048, NULL, 1, NULL);
}

void loop(){
}