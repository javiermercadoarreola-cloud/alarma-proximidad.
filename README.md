# Alarma de proximidad con Arduino

Repositorio: [github.com/javiermercadoarreola-cloud/alarma-proximidad.](https://github.com/javiermercadoarreola-cloud/alarma-proximidad.)

## Integrantes
- José Javier Mercado Arreola: creación del repositorio, estructura inicial del proyecto y configuración de PlatformIO
- Johan Rodríguez Valencia: código final del Arduino, pruebas, evidencias y documentación

## Problema y utilidad
Sistema que avisa cuando un objeto o persona se acerca demasiado a un punto.
Sirve, por ejemplo, para vigilar el espacio frente a una puerta, una zona
restringida o como ayuda de estacionamiento.

## Componentes
- Arduino UNO
- Sensor ultrasónico HC-SR04 (mide la distancia en cm)
- Sensor infrarrojo MH Flying Fish (detector de obstáculos, salida digital)
- LED rojo y LED verde, cada uno con resistencia de 220 Ω
- Buzzer
- Protoboard y cables jumper

## Lenguaje y herramientas
- Lenguaje: C++ para Arduino
- Entorno: Visual Studio Code con PlatformIO
- Control de versiones: Git y GitHub

## Conexiones
| Componente | Pin Arduino |
|---|---|
| HC-SR04 TRIG | 9 |
| HC-SR04 ECHO | 10 |
| MH OUT | 2 |
| LED rojo (con resistencia) | 5 |
| LED verde (con resistencia) | 11 |
| Buzzer (+) | 6 |
| VCC de sensores | 5V |
| GND (sensores, LED y buzzer) | GND |

## Funcionamiento
- A **15 cm o menos**: se enciende el LED rojo y suena el buzzer.
- A **16 cm o más** (o sin objeto): se enciende el LED verde y el buzzer se apaga.
- El Serial Monitor (9600 baudios) muestra la distancia y el estado.
- El sensor MH quedó desactivado en el código (`USAR_MH = false`) porque
  detectaba de más y mantenía el buzzer sonando. La alerta depende solo del HC-SR04.

## Cómo ejecutarlo
1. Instalar Visual Studio Code y la extensión PlatformIO IDE.
2. Clonar el repositorio y abrir la carpeta en VS Code.
3. Armar el circuito según la tabla de conexiones.
4. Conectar el Arduino por USB, compilar (Build) y subir (Upload).
5. Abrir el Serial Monitor a 9600 baudios.

El código está en `src/main.cpp`.

## Pruebas
| Prueba | Resultado esperado | Resultado obtenido |
|---|---|---|
| Mano a 5 cm | Rojo y buzzer | LED rojo encendido |
| Mano a 15 cm | Rojo y buzzer | LED rojo encendido |
| Mano a 16 cm | Verde, buzzer apagado | LED verde encendido |
| Mano a 30 cm | Verde, buzzer apagado | LED verde encendido |
| Sin objeto enfrente | Verde, buzzer apagado | LED verde encendido |

## Evidencias
## Evidencias
- Video de la prueba: [video-prueba.mp4](evidencias/video-prueba.mp4)
  Muestra el circuito funcionando: LED rojo y buzzer con la mano a 15 cm o menos, LED verde a 16 cm o más y sin objeto.

## Dificultades y soluciones
- El LED verde no encendía en el pin 4. Se cambió al pin 11 y funcionó.
- El sensor MH detectaba siempre y mantenía el buzzer sonando. Se desactivó
  en el código y la alerta se guía por el HC-SR04.
- Al subir el código se había elegido el puerto equivocado. Se seleccionó el
  puerto del Arduino UNO.
- El nombre del repositorio quedó con un punto al final, lo que dificultó clonarlo.

## Limitaciones y mejoras
- El MH no mide distancia, solo detecta presencia, y su alcance se ajusta a mano
  con el potenciómetro.
- El infrarrojo se afecta con la luz solar directa.
- Mejora: calibrar el MH y volver a activarlo, o usar un segundo HC-SR04
  para medir en cm en otro lado.

## Reparto del trabajo e historial
- José Javier Mercado Arreola: commit "Estructura inicial del proyecto con HC-SR04 y MH" y rama de configuración de PlatformIO.
- Johan Rodríguez Valencia: commit con el código final (límite de 15 cm, LED verde en pin 11, MH desactivado) y rama `documentacion-pruebas` con README y evidencias.
- Cambios integrados mediante ramas y pull requests, revisados por el otro integrante.
