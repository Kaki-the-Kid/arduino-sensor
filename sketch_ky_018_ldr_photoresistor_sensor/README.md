# KY-018 LDR Photoresistor

Dette er en LDR-modstand, også kaldet fotocelle. Afhængigt af lysindfaldet ændres modstanden.

The KY-018 Photoresistor module is used to measure light intensity. The resistance will decrease in the presence of light and increase in the absence of it. The output is analog and determines the intensity of light.

Compatible with many popular microcontrollers like Arduino, ESP32 and others.

|![image](https://user-images.githubusercontent.com/44589560/159688876-e70b3fdb-b9e1-4652-9893-4641d2061039.png)
|![image](https://user-images.githubusercontent.com/44589560/159688897-191d31ca-baad-43f3-99a3-7c61b6e13c32.png)
|

KY-018 SPECIFICATIONS
This module consists of a photoresistor, a 10 kΩ in-line resistor and 3 male header pins.

Operating Voltage	3.3V ~ 5V
Output Type	Analog

CONNECTION DIAGRAM
Connect the Power line (middle) and ground (-) to +5 and GND respectively. Connect signal (S) to pin A2 on the Arduino.

KY-018	Arduino
S	Pin A2
middle	+5V
–	GND

![image](https://user-images.githubusercontent.com/44589560/159688965-00e41d93-42a9-4aab-9a50-029c9f533ddc.png)

KY-018 ARDUINO CODE
The following Arduino sketch will output readings from the photoresistor, cover the module with your hand to prevent light on it and the output values will be low, point a light to the sensor and the values will be high.

```C++
int sensorPin = 2; //define analog pin 2
int value = 0; 

void setup() {
	Serial.begin(9600); 
} 

void loop() {
	value = analogRead(sensorPin); 
	Serial.println(value, DEC); // light intensity
								// high values for bright environment
								// low values for dark environment
	delay(100); 
}
```
