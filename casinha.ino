#include <Servo.h>
#include <Ultrasonic.h>

#define LDR_PIN A0
#define LED1_PIN 8
#define LED2_PIN 9
#define LED3_PIN 10
#define LED4_PIN 11
#define LED5_PIN 12

#define QTD_LUZ 45
#define DISTANCE 23

Servo myservo; // Criando a variável para o servo

int pos = 0; // Definindo um valor inicial para variável que guarda a posição do servo motor
const int echo = 2;
const int trig = 3;

Ultrasonic ultrasonic(trig, echo);

int distance = 0;
int ldrValue = 0;

void setup() {
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);
  pinMode(LED4_PIN, OUTPUT);
  pinMode(LED5_PIN, OUTPUT);
  myservo.attach(6); // Definindo pino responsável pelo controle do servo motor
  Serial.begin(9600); // Iniciando comunicação serial
  myservo.write(pos);
}

void loop() {
  
  distance = ultrasonic.read();
  ldrValue = analogRead(LDR_PIN);

  Serial.println("----------------------");
  Serial.print("Ultrassonico = ");
  Serial.println(distance);
  Serial.print("LDR = ");
  Serial.println(ldrValue);

  if (ldrValue < QTD_LUZ) {
    digitalWrite(LED1_PIN, HIGH);
    digitalWrite(LED2_PIN, HIGH);
    digitalWrite(LED3_PIN, HIGH);
    digitalWrite(LED4_PIN, HIGH);
    digitalWrite(LED5_PIN, HIGH);
  } else {
    digitalWrite(LED1_PIN, LOW);
    digitalWrite(LED2_PIN, LOW);
    digitalWrite(LED3_PIN, LOW);
    digitalWrite(LED4_PIN, LOW);
    digitalWrite(LED5_PIN, LOW);
  }

  if (distance < DISTANCE) {
    if (pos < 100) {
      for (pos = 0; pos <= 100; pos += 1) {
        myservo.write(pos);
        delay(8);
      }
    }
    delay(3000);
  } else {
    if (pos > 0) {
      for (pos; pos >= 0; pos -= 1) {
        myservo.write(pos);
        delay(8);
      } 
      delay(200);
    } 
  }
  
  delay(100);
}
