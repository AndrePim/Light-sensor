#include <Arduino.h>

int sensor_Light_Pin = A0;  // Пин дла датчика освещённости
int ledPin = 13;     // Пин для светодиода
int sensor_Light_Value = 0; // Переменная для сохранения значения, поступающего с датчика
int sensor_Light_Analog = 500;    // Пороговое значение для срабатывание датчика

void setup() {
  Serial.begin(9600);      // Инициализация последовательного соединения и задание скорости передачи данных в бит/с(бод)
  pinMode(ledPin, OUTPUT); // Установка режима работы пина светодиода на выход
}

void loop() {
  sensor_Light_Value = analogRead(sensor_Light_Pin); // Чтение значения с датчика
  // Сравнение значения с порта А0 с пороговым значением
  if (sensor_Light_Value < sensor_Light_Analog) {
    Serial.println("Light on!"); // Вывод надписи в мониторе последовательного порта
    digitalWrite(ledPin, HIGH);  // Загорается светодиод
  }
  else {
    Serial.println("Light off!"); // Вывод надписи в мониторе последовательного порта
    digitalWrite(ledPin, LOW);    // Светодиод не горит
  }
}
