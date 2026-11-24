#include <Arduino.h>

// ============================================================
// Alarma de proximidad: HC-SR04 + sensor MH Flying Fish
// <= 15 cm: LED rojo + buzzer | >= 16 cm: LED verde, buzzer apagado
// ============================================================

// ---------- Pines ----------
const int TRIG_PIN  = 9;     // HC-SR04
const int ECHO_PIN  = 10;
const int MH_PIN    = 2;     // Sensor MH Flying Fish (salida OUT)
const int LED_VERDE = 11;
const int LED_ROJO  = 5;
const int BUZZER    = 6;

// ---------- Parámetros ----------
const int DISTANCIA_PELIGRO_CM = 15;   // <= 15 cm = rojo + buzzer

// false = solo decide el HC-SR04 (recomendado para empezar)
// true  = el MH también activa la alerta (calibra antes su tornillito)
const bool USAR_MH = false;

// El MH pone OUT en LOW cuando detecta un obstáculo.
// Si en tus pruebas sale al revés, cambia a false.
const bool MH_ACTIVO_EN_BAJO = true;

// Lee la distancia en cm (-1 si no hay lectura)
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

// Devuelve true si el sensor MH detecta un obstáculo
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
  bool muyCerca = hcCerca || (USAR_MH && mhCerca);

  digitalWrite(LED_ROJO,  muyCerca ? HIGH : LOW);
  digitalWrite(LED_VERDE, muyCerca ? LOW  : HIGH);
  digitalWrite(BUZZER,    muyCerca ? HIGH : LOW);

  Serial.print("HC-SR04: ");
  if (distancia < 0) Serial.print("fuera de rango");
  else { Serial.print(distancia); Serial.print(" cm"); }
  Serial.print(" | MH: ");
  Serial.print(mhCerca ? "DETECTA" : "libre");
  Serial.print(USAR_MH ? "" : " (desactivado)");
  Serial.print(" | Estado: ");
  Serial.println(muyCerca ? "MUY CERCA (ROJO + BUZZER)" : "SEGURO (VERDE)");

  delay(200);
}
