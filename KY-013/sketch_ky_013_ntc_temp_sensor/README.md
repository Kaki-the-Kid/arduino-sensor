# KY-013 - NTC Temperatursensor modul

Modul til måling af temperatur ved hjælp af en NTC modstand. Sensoren fungerer ved at NTC modstanden ændrer værdi efter temperaturen, og denne modstand kan måles ved hjælp af Arduino.
Måleområde: -55C til 125C (præcision 0,5C)

| ![image](https://user-images.githubusercontent.com/44589560/159644018-432ba5e5-6568-4568-9634-edaa46780f6c.png) | ![image](https://user-images.githubusercontent.com/44589560/159644047-fb3b52cf-a021-46d0-993f-87e272fafd1a.png) | 

## KY-013 SPECIFICATIONS
This module consist of a NTC thermistor, a 10 kΩ resistor, and 3 male header pins. The thermistor resistance varies according to its surrounding temperature. The value of resistance can be used to calculate the actual temperature.

| Syntax      | Description |
| ----------- | ----------- |
| Operating Voltage      | 5V       |
| Temperature measurement range   | -55°C to 125°C [-67°F to 257°F]        |
| Measurement Accuracy   | ±0.5°C        |

## Forbindelses Diagram
Connect module power line (middle) and ground (-) to 5V and GND on the Arduino respectively. Connect the module signal pin (S) to pin A0 on the Arduino.

Some KY-013 have a different pin arrangement. Please check your board before connecting.

| KY-013 | Arduino |
| S      | A0      |
| middle | 5V      |
| –      | GND     |

![image](https://user-images.githubusercontent.com/44589560/159645474-7eebe8f3-0f2d-4ab6-ae0d-710596f25f94.png)

KY-013 ARDUINO CODE
The following Arduino Sketch will derive the temperature from the thermistor using the Steinhart-Hart equation. The code will return temperature in Celcius, uncomment line 17 to get temperature in farenheit.

```C++
int ThermistorPin = A0;
int Vo;
float R1 = 10000; // value of R1 on board
float logR2, R2, T;
float c1 = 0.001129148, c2 = 0.000234125, c3 = 0.0000000876741; //steinhart-hart coeficients for thermistor

void setup() {
  Serial.begin(9600);
}

void loop() {
  Vo = analogRead(ThermistorPin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0); //calculate resistance on thermistor
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2)); // temperature in Kelvin
  T = T - 273.15; //convert Kelvin to Celcius
 // T = (T * 9.0)/ 5.0 + 32.0; //convert Celcius to Farenheit
  Serial.print("Temperature: "); 
  Serial.print(T);
  Serial.println(" C"); 
  delay(500);
}
```

