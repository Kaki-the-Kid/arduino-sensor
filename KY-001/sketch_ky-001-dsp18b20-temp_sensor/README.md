# KY-001 Temperature Sensor Module

KY-001 Temperature Sensor Module allows ambient temperature measurement using digital serial bus. It is possible to connect more than one module on the same bus.

Compatible with popular electronics platforms like Arduino, Raspberry Pi and ESP32.

| ![image](https://user-images.githubusercontent.com/44589560/159486545-f6b58e87-e271-4fe9-a596-2dd5940f5c26.png)
| ![image](https://user-images.githubusercontent.com/44589560/159486603-f9657810-b704-4954-a544-0509e348b212.png) |

KY-001 Specifikationer
This module consists of a DS18B20 single-bus digital temperature sensor, an LED, a resistor and 3 male header pins.

| Operating Voltage             |	3.0V to 5.5V                      |
| Temperature Measurement Range |	-55°C to 125°C [-57°F to 257°F]   |
| Measurement Accuracy Range    |	±0.5°C                            |
| Board Dimensions              |	18.5mm x 15mm [0.728in x 0.591in] |

CONNECTION DIAGRAM
Connect the power line (middle) and ground (-) on the module to +5V and GND on the Arduino respectively. Connect the signal pin (S) to pin 2 on the Arduino.

| KY-001 | Arduino |
| ++++++ | +++++++ |
| S      |Pin 2    |
| middle |	+5V    |
| –	     |GND      |

![image](https://user-images.githubusercontent.com/44589560/159487143-65ef6be7-3720-44ed-8d7d-61bf66c52c95.png)

KY-001 ARDUINO CODE
The following Arduino sketch will use the OneWire library to communicate serially with the module and it’ll output the temperature read by the device. 

Links to the required libraries can be found on the Downloads section below.

