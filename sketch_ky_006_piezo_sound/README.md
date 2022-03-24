# KY-006 Piezo - Passive buzzer module

The KY-006 Passive Piezoelectric Buzzer module can produce a range of sound tones depending on the input signal fequency. To generate single-tone sounds use the KY-012 Active Buzzer.

Compatible with popular microcontrollers like Arduino, Raspberry Pi, ESP32 and others.

| Frontview | Board |
| --------- | ----- |
| ![image](https://user-images.githubusercontent.com/44589560/159856748-5ce50374-81fb-4282-858f-3206a7991642.png) | ![image](https://user-images.githubusercontent.com/44589560/159856700-78390a95-81fb-409c-8b8e-75e64991aa74.png) |

## KY-006 SPECIFICATIONS
This module consists of a passive buzzer and 3 male header pins. You can use it generate tones between 1.5 to 2.5kHz by switching it on and off repeatedly at different frequencies either using delays or PWM.

| Spec | Value |
| -- | -- |
| Operating Voltage	| 1.5V ~ 15V DC |
| Tone Generation Range	| 1.5kHz ~ 2.5kHz |
| Board Dimensions	| 18.5mm x 15mm [0.728in x 0.591in] |

## CONNECTION DIAGRAM
Connect the module signal (S) to pin 8 on the Arduino and ground (-) to GND.

The middle pin is not used.

| KY-006 | Arduino |
| ------ | ------- |
| S	 | Pin 8   |
| middle |         |
| –	 | GND     |

![image](https://user-images.githubusercontent.com/44589560/159856994-e4638495-b7ac-4205-8cce-657ecb41c0d6.png)

# KY-006 ARDUINO CODE
The following Arduino sketch will generate two different tones by rapidly turning on and off the buzzer at different frequencies using a delay.

```C++
int buzzer = 8; // set the buzzer control digital IO pin

void setup() {
	pinMode(buzzer, OUTPUT); // set pin 8 as output
}

void loop() {
	for (int i = 0; i < 100; i++) {  // make a sound
		digitalWrite(buzzer, HIGH); // send high signal to buzzer 
		delay(1); // delay 1ms
		digitalWrite(buzzer, LOW); // send low signal to buzzer
		delay(1);
	}

delay(50);
	for (int j = 0; j < 100; j++) { //make another sound
		digitalWrite(buzzer, HIGH);
		delay(2); // delay 2ms
		digitalWrite(buzzer, LOW);
		delay(2);
	}
  
	delay(500);
}
```
