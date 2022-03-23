# KY-001 Temperature Sensor Module

KY-001 Temperature Sensor Module allows ambient temperature measurement using digital serial bus. It is possible to connect more than one module on the same bus.

Compatible with popular electronics platforms like Arduino, Raspberry Pi and ESP32.

| ![image](https://user-images.githubusercontent.com/44589560/159486545-f6b58e87-e271-4fe9-a596-2dd5940f5c26.png)      | ![image](https://user-images.githubusercontent.com/44589560/159486603-f9657810-b704-4954-a544-0509e348b212.png) |

## KY-001 Specifikationer
This module consists of a DS18B20 single-bus digital temperature sensor, an LED, a resistor and 3 male header pins.<br />

| Syntax      | Description |
| ----------- | ----------- |
| Operating Voltage      | 3.0V to 5.5V       |
| Temperature Measurement Range   | -55°C to 125°C (-57°F to 257°F)        |
| Measurement Accuracy Range   | ±0.5°C        |
| Board Dimensions   | 18.5mm x 15mm (0.728in x 0.591in)        |


## Forbindelses Diagram
Connect the power line (middle) and ground (-) on the module to +5V and GND on the Arduino respectively. Connect the signal pin (S) to pin 2 on the Arduino.

| KY-001 | Arduino |
| ------ | ------- |
| S      | Pin 2   |
| middle | +5V     |
| –	     | GND     | 

![image](https://user-images.githubusercontent.com/44589560/159487143-65ef6be7-3720-44ed-8d7d-61bf66c52c95.png)

# KY-001 Arduino code
The following Arduino sketch will use the OneWire library to communicate serially with the module and it’ll output the temperature read by the device. 

Links to the required libraries can be found on the Downloads section below.

```c++
#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into pin 2 on the Arduino
#define ONE_WIRE_BUS 2

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

void setup(void)
{
  // start serial port
  Serial.begin(9600);
  Serial.println("Dallas Temperature IC Control Library Demo");
  // Start up the library
  sensors.begin(); // IC Default 9 bit. If you have troubles consider upping it 12. Ups the delay giving the IC more time to process the temperature measurement
}

void loop(void)
{ 
  // call sensors.requestTemperatures() to issue a global temperature 
  // request to all devices on the bus
  Serial.print("Requesting temperatures...");
  sensors.requestTemperatures(); // Send the command to get temperatures
  Serial.println("DONE");
  Serial.print("Temperature for Device 1 is: ");
  Serial.print(sensors.getTempCByIndex(0)); // Why "byIndex"? You can have more than one IC on the same bus. 0 refers to the first IC on the wire
}
```
