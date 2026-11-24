# Alarma de proximidad con Arduino

## Integrantes
| Nombre | Usuario de GitHub |
|---|---|
| Javi | javiermercadoarreola-cloud |
| Johan | johanrodriguezv22-cmyk |

## Problema que atiende y objetivo
Muchas personas y objetos necesitan una señal clara cuando algo se acerca demasiado: un vehículo que retrocede, un estudiante cerca de un equipo delicado o una zona restringida. Este proyecto mide la distancia a un objeto y avisa visual y sonoramente si está demasiado cerca.

- **Usuarios:** conductores, personas en talleres o laboratorios, vigilancia básica.
- **Objetivo:** si el objeto está a **15 cm o menos**, se enciende el **LED rojo** y suena el **buzzer**. Si está a **16 cm o más** (o no hay objeto), se enciende el **LED verde** y el buzzer se apaga.

## Sensores, lenguaje y herramientas
| Elemento | Uso |
|---|---|
| Arduino UNO | Microcontrolador |
| HC-SR04 | Sensor ultrasónico de proximidad (mide la distancia en cm) |
| MH Flying Fish | Sensor infrarrojo de obstáculos (salida digital, opcional con `USAR_MH`) |
| LED rojo y LED verde + 2 resistencias de 220 Ω | Indicadores |
| Buzzer | Alerta sonora |
| C++ (Arduino) | Lenguaje, estándar de Arduino |
| Visual Studio Code + PlatformIO / Arduino IDE | Desarrollo y carga del programa |
| Git + GitHub | Control de versiones y colaboración |

## Conexiones
| Componente | Pin Arduino |
|---|---|
| HC-SR04 VCC / GND | 5V / GND |
| HC-SR04 TRIG | 9 |
| HC-SR04 ECHO | 10 |
| MH OUT (VCC y GND a 5V y GND) | 2 |
| LED verde (con resistencia) | 11 |
| LED rojo (con resistencia) | 5 |
| Buzzer (+) | 6 |

Las patas cortas de los LED y el negativo del buzzer van a GND.

## Instalación y ejecución
1. Armar el circuito según la tabla de conexiones, con el Arduino desconectado.
2. Clonar el repositorio: `git clone <URL-del-repositorio>`.
3. Abrir la carpeta en Visual Studio Code con la extensión **PlatformIO** (o abrir el código en Arduino IDE).
4. Conectar el Arduino por USB, elegir la placa **Arduino Uno** y el puerto correcto.
5. Compilar y subir el programa (**Build** y **Upload**).
6. Abrir el **Monitor Serie** a 9600 baudios para ver las lecturas.

## Funcionamiento general
Cada 200 ms el programa mide la distancia con el HC-SR04 y la imprime en el monitor serie.

- Distancia entre 0 y 15 cm: LED rojo y buzzer encendidos, LED verde apagado.
- Distancia de 16 cm o más, o sin eco: LED verde encendido, rojo y buzzer apagados.

El sensor MH puede sumarse a la alerta cambiando `USAR_MH` a `true` en el código. Su alcance se ajusta con el tornillo del propio módulo. Por defecto queda desactivado y el sistema se guía solo por el HC-SR04.

## Pruebas realizadas
_(Completar con lo observado y enlazar las evidencias de la carpeta `evidencias/`)_

| Condición | Resultado esperado | Resultado obtenido |
|---|---|---|
| Sin objeto enfrente | LED verde, buzzer apagado | _escribe lo que viste_ |
| Objeto a 30 cm | LED verde, buzzer apagado | _escribe lo que viste_ |
| Objeto a 16 cm | LED verde, buzzer apagado | _escribe lo que viste_ |
| Objeto a 15 cm | LED rojo y buzzer | _escribe lo que viste_ |
| Objeto a 5 cm | LED rojo y buzzer | _escribe lo que viste_ |

Evidencias: fotografía del circuito, video de funcionamiento y captura del monitor serie en la carpeta `evidencias/`.

## Aportaciones de cada integrante
- **_Nombre 1_:** _por ejemplo: lectura del HC-SR04 y lógica de LED y buzzer_
- **_Nombre 2_:** _por ejemplo: integración del MH y pruebas del circuito_
- **_Nombre 3_:** _por ejemplo: README y evidencias_

## Limitaciones y posibles mejoras
- El HC-SR04 pierde precisión con superficies blandas, inclinadas o muy pequeñas.
- El MH no mide distancia, solo detecta obstáculos, y se calibra a mano con su tornillo.
- El MH puede confundirse con luz solar directa.
- Mejoras: segundo HC-SR04 para vigilar dos lados, pantalla LCD con la distancia, buzzer con tono según la cercanía y registro de lecturas en tarjeta SD.
