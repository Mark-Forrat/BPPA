#include <Arduino.h>

// Задаем пины для управления двигателем
const int motorPin = 9; // Пин для управления скоростью (PWM)

// Задаем начальную и конечную скорости
const int minSpeed = 130;
const int maxSpeed = 255;

// Задаем время ускорения и замедления в миллисекундах
const int rampTime = 10000;

void setup() {
  // Настраиваем пин двигателя на вывод
  pinMode(motorPin, OUTPUT);
  
  // Настраиваем скорость передачи данных для последовательного порта
  Serial.begin(9600);
}

void loop() {
  // Плавное увеличение скорости
  for (int speed = minSpeed; speed <= maxSpeed; speed++) {
    analogWrite(motorPin, speed);
    Serial.println(speed);
    delay(rampTime / (maxSpeed - minSpeed));
  }

  // Плавное снижение скорости
  for (int speed = maxSpeed; speed >= minSpeed; speed--) {
    analogWrite(motorPin, speed);
    Serial.println(speed);
    delay(rampTime / (maxSpeed - minSpeed));
  }
}
