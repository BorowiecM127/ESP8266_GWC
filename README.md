# ESP8266_GWC

## Description

This project consists of:

- NodeMCU V3 ESP8266 Board
- MH-ET LCD keypad shield
- 2xDS18B20 temperature sensors
- 2PH3091A relay
- GSD326.1A rotary air damper actuator

## Functionality

This project aims to control Siemens air damper actuator via relay, depending on data provided by DS18B20 temperature sensors, all managed by via microcontroller mentioned above.
Wake temperatures and difference between temperatures on both sensors can be selected by user via keypad shield.

Working algorithm is like following:

- turn on actuator after 1 hour
- wait 2 minutes
- check for temperature outside:
  - if it is higher than higher wake temperature, check if t. outside - t. inside > delta for higher wake temperature
    - if it is true, leave actuator on and check for condition above periodically after 15 minutes
    - if above condition is false, turn off actuator
  - if it is lower than lower wake temperature, check if t. inside - t. outside > delta for lower wake temperature
    - if it is true, leave actuator on and check for condition above periodically after 15 minutes
    - if above condition is false, turn off actuator

## Connections

GSD326:

- three-wire cable:
  - blue -> 230V (-)
  - white -> Relay (NO2)
  - brown -> Relay (NO1)
- six-wire cable:
  - BKBU, GYBU -> GND
  - GYPK, BKPK -> +5V
  - BKRD -> ESP8266 (D1)
  - GYRD -> ESP8266 (D0)

DS18B20:

- Y -> ESP8266 (RX)
- R -> +3V
- B -> GND

Relay:

- COM2 -> COM1
- COM1 -> 230V (+)
- VCC -> +5V
- GND -> GND
- IN1 -> ESP8266 (D4)
- IN2 -> ESP8266 (D2)

MH-ET:

- A0 -> ESP8266 (A0)
- RST -> ESP8266 (RST)
- +5V -> ESP8266 (+5V)
- GND -> GND
- Signal pins (Upper right corner, counting from right to left, starting from 0):
  - 4 -> ESP8266 (D3)
  - 5 -> ESP8266 (TX)
  - 6 -> ESP8266 (D5)
  - 7 -> ESP8266 (D6)
  - 8 -> ESP8266 (D7)
  - 9 -> ESP8266 (D8)

## Useful information

Actuator extreme position is indicated by BKRD and GYRD cables. One position is represented by [0, 0] , other by [1, 1]. Any position in between is indicated by [1, 0] or [0, 1] pair (it depends on which cable is connected where on board).

Actuator is opened when it is rotated clockwise, laying with damper handle on the bottom.

Board can not simultaneously send data by USB and to keypad shield, because UART communication uses its TX and RX pins.

## References

https://www.electronicshub.org/esp8266/
https://www.electronicshub.org/esp8266-deep-sleep-mode/
https://www.electronicshub.org/esp8266-web-server/
https://www.electronicshub.org/nodemcu-pinout-esp-12e-pinout/
https://www.youtube.com/watch?v=OGpIy0-ewvE
https://www.youtube.com/watch?v=WFzVzgEA8Fo
https://wiki.keyestudio.com/Ks0256_keyestudio_LCD1602_Expansion_Shield
https://create.arduino.cc/projecthub/electropeak/using-1602-lcd-keypad-shield-w-arduino-w-examples-e02d95
https://randomnerdtutorials.com/esp8266-ds18b20-temperature-sensor-web-server-with-arduino-ide/
https://randomnerdtutorials.com/esp8266-pinout-reference-gpios/
