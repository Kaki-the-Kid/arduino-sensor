# HC-SR04 - Ultrasonic Sensor

<img src="https://howtomechatronics.com/wp-content/uploads/2015/07/Ultrasonic-Sensor-HC-SR04-and-Arduino-Complete-Guide-2-768x432.jpg?ezimgfmt=ng%3Awebp%2Fngcb2" />

Ultralydssensor HC-SR04 er en sensor, der kan måle afstand. Den udsender en ultralyd ved 40.000 Hz (40 kHz), som bevæger sig gennem luften, og hvis der er en genstand eller forhindring på dens vej, vil den hoppe tilbage til modulet. I betragtning af rejsetiden og lydens hastighed kan du beregne afstanden.

Konfigurationsstiften på HC-SR04 er VCC (1), TRIG (2), ECHO (3) og GND (4). Forsyningsspændingen for VCC er +5V, og du kan tilslutte TRIG- og ECHO-stift til enhver digital I/O i dit Arduino-kort.

## Specifikationer
![image](https://user-images.githubusercontent.com/44589560/159899007-ae43fb3b-ab6a-4b67-955d-44e2f68c9138.png)

| Spec      | Value |
| ----------- | ----------- |
| Operating Voltage      | 5V DC       |
| Operating Current   | 15mA        |
| Operating Frequency   | 40KHz        |
| Min Range   | 2cm / 1 inch        |
| Max Range   | 400cm / 13 feet        |
| Accuracy   | 3mm        |
| Measuring Angle   | <15°        |
| Dimension   | 45 x 20 x 15mm      |

## Forbindelses diagram

![image](https://user-images.githubusercontent.com/44589560/159899137-8d0b5c4d-c3ab-473c-9a66-011866b3d5fa.png)

## Forbindelses diagram med display
![image](https://user-images.githubusercontent.com/44589560/159900422-59245b94-f622-4160-b6ea-f7348b76bdff.png)

# Funktion
For at generere ultralyden skal vi indstille triggerstiften til en høj tilstand i 10 µs. Det vil udsende et 8-cyklus sonisk burst, som vil rejse med lydens hastighed, og det vil blive modtaget i Echo Pin. Echo Pin udsender den tid i mikrosekunder, som lydbølgen rejste.

![image](https://user-images.githubusercontent.com/44589560/159899366-f9403a1b-a197-4f92-adc9-611903a6b51d.png)

For eksempel, hvis objektet er 20 cm væk fra sensoren, og lydens hastighed er 340 m/s eller 0,034 cm/µs, skal lydbølgen bevæge sig omkring 588 mikrosekunder. Men det, du får fra Echo-stiften, vil være det dobbelte af det tal, fordi lydbølgen skal rejse fremad og hoppe tilbage. Så for at få afstanden i cm skal vi gange den modtagne rejsetidsværdi fra ekkostiften med 0,034 og dividere den med 2.

![image](https://user-images.githubusercontent.com/44589560/159900806-6acf4c1f-2856-45a2-804e-ccca23699479.png)

Til programmeringskoden skal vi først definere Trigger Pin og Echo Pin, der er forbundet til Arduino board. I dette projekt er EchoPin knyttet til D2 og TrigPin til D3. Definer derefter variabler for afstanden (int) og varigheden (lang).

I løkken skal du først sikre dig, at trigPin'en er klar, så vi skal indstille den på en LAV tilstand i kun 2 µs. Nu for at generere ultralydsbølgen skal vi indstille trigPin til HIGH State i 10 µs. Ved at bruge pulseIn()-funktionen skal du aflæse rejsetiden og sætte denne værdi ind i variablen "varighed". Denne funktion har 2 parametre, den første er navnet på ekko-stiften og for den anden kan du skrive enten HØJ eller LAV. I dette tilfælde betyder HIGH, at pulseIn()-funktionen vil vente på, at stiften bliver HØJ forårsaget af den tilbagekastede lydbølge, og den vil begynde at timing, så vil den vente på, at stiften bliver LAV, når lydbølgen slutter, hvilket vil stop timingen. Til sidst vil funktionen returnere længden af ​​pulsen i mikrosekunder. For at få afstanden vil vi gange varigheden med 0,034 og dividere den med 2, som vi forklarede denne ligning tidligere. Til sidst vil vi udskrive værdien af ​​afstanden på den serielle monitor.

# Arduino kode
```C++
/*
  Ultrasonic Sensor HC-SR04 and Arduino Tutorial

  by Dejan Nedelkovski,
  www.HowToMechatronics.com
*/

#include <LiquidCrystal.h> // includes the LiquidCrystal Library

LiquidCrystal lcd(1, 2, 4, 5, 6, 7); // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)
const int trigPin = 9;
const int echoPin = 10;
long duration;
int distanceCm, distanceInch;

void setup() {
  lcd.begin(16, 2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration * 0.034 / 2;
  distanceInch = duration * 0.0133 / 2;
  
  lcd.setCursor(0, 0); // Sets the location at which subsequent text written to the LCD will be displayed
  lcd.print("Distance: "); // Prints string "Distance" on the LCD
  lcd.print(distanceCm); // Prints the distance value from the sensor
  lcd.print(" cm");
  delay(10);
  
  lcd.setCursor(0, 1);
  lcd.print("Distance: ");
  lcd.print(distanceInch);
  lcd.print(" inch");
  delay(10);
}
```
