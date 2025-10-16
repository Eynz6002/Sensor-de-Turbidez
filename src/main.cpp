#include "Arduino.h"

int pin_sensor = A0;

void setup() {
  Serial.begin(9600);
}

float ler_sensor() {
  float voltagem_raw = 0;
  
  for (int i = 0; i < 800; i++){
    voltagem_raw += ((float)analogRead(pin_sensor)/1024) * 5;
    delay(1);
  }
  
  return voltagem_raw / 800.0;
}

void loop() {
  float leitura = ler_sensor();
  int NTU;
  
  if(leitura < 2.5) NTU = 3000;
  else if(leitura > 4.2) NTU = 0;
  else NTU = -1120.4 * pow(leitura, 2) + 5742.3 * leitura - 4353.8;
    
  Serial.println("\n============================");
  Serial.print("Voltagem: ");
  Serial.print(leitura);
  Serial.print(" | NTU: ");
  Serial.println(NTU);
  delay(200);
}