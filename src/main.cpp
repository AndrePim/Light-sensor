#include <Arduino.h>

int sensorPin = A0; // Пин дла датчика освещённости
int ledPin = 13;  // Пин для светодиода
int sensorValue = 0; // Переменная для сохранения значения, поступающего с датчика
int analog = 500; // Пороговое значение для срабатывание датчика

void setup() {
Serial.begin(9600);      // Инициализация последовательного соединения и задание скорости передачи данных в бит/с(бод)
  pinMode(ledPin, OUTPUT); // Установка режима работы пина светодиода на выход}
}
void loop() {
sensorValue = analogRead(sensorPin); // Чтение значения с датчика
  // Сравнение значения с порта А0 с пороговым значением
  if (sensorValue < analog) {
    Serial.println("Light on!"); // Вывод надписи в мониторе последовательного порта
    digitalWrite(ledPin, HIGH);         // Загорается светодиод
  }
  else {
    Serial.println("Light off!"); // Вывод надписи в мониторе последовательного порта
    digitalWrite(ledPin, LOW);         // Светодиод не горит
  }
}