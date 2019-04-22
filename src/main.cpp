#include <Arduino.h>

int light_Sensor_Pin = A0;              // Пин для датчика освещённости
int ledPin = 13;                        // Пин для светодиода
int Light_sensor_Value = 0;             // Переменная для сохранения значения, поступающего с датчика
int Light_Sensor_Threshold_Value = 500; // Пороговое значение для срабатывание датчика

void setup()
{
  Serial.begin(9600);      // Инициализация последовательного соединения и задание скорости передачи данных в бит/с(бод)
  pinMode(ledPin, OUTPUT); // Установка режима работы пина светодиода на выход
}

void loop()
{
  Light_sensor_Value = analogRead(light_Sensor_Pin); // Чтение значения с датчика
  // Сравнение значения с порта А0 с пороговым значением
  if (Light_sensor_Value < Light_Sensor_Threshold_Value)
  {
    Serial.println("Light on!"); // Вывод надписи в мониторе последовательного порта
    digitalWrite(ledPin, HIGH);  // Загорается светодиод
  }
  else
  {
    Serial.println("Light off!"); // Вывод надписи в мониторе последовательного порта
    digitalWrite(ledPin, LOW);    // Светодиод не горит
  }
}