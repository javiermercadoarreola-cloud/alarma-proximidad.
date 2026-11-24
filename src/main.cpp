#include <Arduino.h>

const int TRIG_PIN  = 9;
const int ECHO_PIN  = 10;
const int MH_PIN    = 2;
const int LED_VERDE = 4;
const int LED_ROJO  = 5;
const int BUZZER    = 6;

const int DISTANCIA_PELIGRO_CM = 10;
const bool MH_ACTIVO_EN_BAJO = true;

long medirDistanciaCm() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duracion = pulseIn(ECHO_PIN, HIGH, 30000);
  if (duracion == 0) return -1;
  return duracion * 0.0343 / 2;
}

bool mhDetecta() {
  int lectura = digitalRead(MH_PIN);
  return MH_ACTIVO_EN_BAJO ? (lectura == LOW) : (lectura == HIGH);
}

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(MH_PIN, INPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_ROJO, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  Serial.println("Sistema iniciado: HC-SR04 + sensor MH.");
}

void loop() {
  long distancia = medirDistanciaCm();
  bool hcCerca = (distancia >= 0 && distancia <= DISTANCIA_PELIGRO_CM);
  bool mhCerca = mhDetecta();
  bool muyCerca = hcCerca || mhCerca;

  digitalWrite(LED_ROJO,  muyCerca ? HIGH : LOW);
  digitalWrite(LED_VERDE, muyCerca ? LOW  : HIGH);
  digitalWrite(BUZZER,    muyCerca ? HIGH : LOW);

  Serial.print("HC-SR04: ");
  if (distancia < 0) Serial.print("fuera de rango");
  else { Serial.print(distancia); Serial.print(" cm"); }
  Serial.print(" | MH: ");
  Serial.print(mhCerca ? "DETECTA" : "libre");
  Serial.print(" | Estado: ");
  Serial.println(muyCerca ? "MUY CERCA (ROJO)" : "SEGURO (VERDE)");

  delay(200);
}