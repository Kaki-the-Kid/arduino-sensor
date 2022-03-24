# HC-SR04 - Ultrasonic Sensor

<img src="https://howtomechatronics.com/wp-content/uploads/2015/07/Ultrasonic-Sensor-HC-SR04-and-Arduino-Complete-Guide-2-768x432.jpg?ezimgfmt=ng%3Awebp%2Fngcb2" />

Ultralydssensor HC-SR04 er en sensor, der kan måle afstand. Den udsender en ultralyd ved 40.000 Hz (40 kHz), som bevæger sig gennem luften, og hvis der er en genstand eller forhindring på dens vej, vil den hoppe tilbage til modulet. I betragtning af rejsetiden og lydens hastighed kan du beregne afstanden.

Konfigurationsstiften på HC-SR04 er VCC (1), TRIG (2), ECHO (3) og GND (4). Forsyningsspændingen for VCC er +5V, og du kan tilslutte TRIG- og ECHO-stift til enhver digital I/O i dit Arduino-kort.

## Specifikationer
![image](https://user-images.githubusercontent.com/44589560/159899007-ae43fb3b-ab6a-4b67-955d-44e2f68c9138.png)

## Forbindelses diagram

![image](https://user-images.githubusercontent.com/44589560/159899137-8d0b5c4d-c3ab-473c-9a66-011866b3d5fa.png)

# Funktion
For at generere ultralyden skal vi indstille triggerstiften til en høj tilstand i 10 µs. Det vil udsende et 8-cyklus sonisk burst, som vil rejse med lydens hastighed, og det vil blive modtaget i Echo Pin. Echo Pin udsender den tid i mikrosekunder, som lydbølgen rejste.

![image](https://user-images.githubusercontent.com/44589560/159899366-f9403a1b-a197-4f92-adc9-611903a6b51d.png)

For eksempel, hvis objektet er 20 cm væk fra sensoren, og lydens hastighed er 340 m/s eller 0,034 cm/µs, skal lydbølgen bevæge sig omkring 588 mikrosekunder. Men det, du får fra Echo-stiften, vil være det dobbelte af det tal, fordi lydbølgen skal rejse fremad og hoppe tilbage. Så for at få afstanden i cm skal vi gange den modtagne rejsetidsværdi fra ekkostiften med 0,034 og dividere den med 2.

![image](https://user-images.githubusercontent.com/44589560/159899432-4d19153a-cfd5-4925-b112-aa342ee7d7b9.png)

Til programmeringskoden skal vi først definere Trigger Pin og Echo Pin, der er forbundet til Arduino board. I dette projekt er EchoPin knyttet til D2 og TrigPin til D3. Definer derefter variabler for afstanden (int) og varigheden (lang).

I løkken skal du først sikre dig, at trigPin'en er klar, så vi skal indstille den på en LAV tilstand i kun 2 µs. Nu for at generere ultralydsbølgen skal vi indstille trigPin til HIGH State i 10 µs. Ved at bruge pulseIn()-funktionen skal du aflæse rejsetiden og sætte denne værdi ind i variablen "varighed". Denne funktion har 2 parametre, den første er navnet på ekko-stiften og for den anden kan du skrive enten HØJ eller LAV. I dette tilfælde betyder HIGH, at pulseIn()-funktionen vil vente på, at stiften bliver HØJ forårsaget af den tilbagekastede lydbølge, og den vil begynde at timing, så vil den vente på, at stiften bliver LAV, når lydbølgen slutter, hvilket vil stop timingen. Til sidst vil funktionen returnere længden af ​​pulsen i mikrosekunder. For at få afstanden vil vi gange varigheden med 0,034 og dividere den med 2, som vi forklarede denne ligning tidligere. Til sidst vil vi udskrive værdien af ​​afstanden på den serielle monitor.

