## KY-023 Dual Axis Joystick Module
KY-032 Dual Axis Joystick-modulet bruger et biaksialt potentiometer til at styre X- og Y-aksen. Når den trykkes ned, aktiverer den en kontakt. Baseret på PS2-controllerens joystick, bruges den til at styre en lang række projekter fra fjernstyrede køretøjer til farve-LED'er.

![image](https://user-images.githubusercontent.com/44589560/159905168-c2fb858e-84ad-44ca-9886-419741152c94.png)

## KY-023 Specifikationer
Dette modul består af to 10kΩ potentiometre vinkelret placeret for at styre X- og Y-akserne ved at ændre modstanden, når joysticket bevæges.
En trykknap aktiveres, når joysticket trykkes ned på Z-aksen. Modules har i alt har 5 hanstifter.


|Operating Voltage	3.3V to 5V
|Board Dimensions	2.6cm x 3.4cm [1.02in x 1.22in]

## Forbindelses diagram
Vi bruger et par analoge ben på Arduino til at læse værdierne fra joystickets potentiometre og en digital pin til at læse værdier fra kontakten.

|KY-023	Arduino
|GND	GND
|+5V	+5V
|VRx	Pin A0
|VRy	Pin A1
|SW	Pin 7

![image](https://user-images.githubusercontent.com/44589560/159906907-13776893-f345-4a4d-a9d3-fb8b8afa85ab.png)

# KY-023 Arduino kode
The following Arduino sketch will continually read values from the joystick’s button and potentiometers.

Moving the joystick up/down will increase/decrease the values of X and moving the joystick left/right will increase/decrease for values of Y, these values range between 0 and 1023. Push the joystick down to activate the Z-axis button.

```C++
int value = 0;

void setup() {
	//pinMode(A0, INPUT);
	//pinMode(A1, INPUT);
  	pinMode(7, INPUT_PULLUP); //set pin 7 as an input and enable the internal pull-up resistor
	Serial.begin(9600);
}

void loop() {
  value = analogRead(A0);	// read X axis value [0..1023]
  Serial.print("X:");
  Serial.print(value, DEC);
  value = analogRead(A1);	// read Y axis value [0..1023]
  Serial.print(" | Y:");
  Serial.print(value, DEC);
  value = digitalRead(7);	// read Button state [0,1]
  Serial.print(" | Button:");
  Serial.println(value, DEC);
  delay(100);
}
```

Indstille af analoge ben som input (linje 4 og 5) er egentlig ikke nødvendigt, analogRead()-funktionen vil automatisk indstille benene A0 og A1 som analog input, når den kaldes. Nogen foretrækker eksplicit, at erklære analoge ben som input af hensyn til læsbarheden.
