# KY-015 - DHT11 modul - Temperatur og fugtsensor

Modul med den populære digitale temperatur og fugtsensor DHT11. Sensoren sender en seriel strøm af data med målinger der kan udlæses af en mikrocontroller. Eksempelkode kan downloades her på produktsiden.

Måleområde temperatur: 0-50C Måleområde fugtighed: 20-90%

![image](https://user-images.githubusercontent.com/44589560/159655274-2c3baea4-aa06-4f7f-82a8-65481a56a8de.png)

## KY-015 Specifikationer
This module consist of a DHT11 digital humidity and temperature sensor, a 1 kΩ resistor and 3 male header pins. The DHT11 uses an internal thermistor and a capacitive humidity sensor to determine the surrounding conditions, an internal chip is responsible for converting the readings to a serial digital signal.

| Syntax                             | Description                |
| ---------------------------------- | -------------------------- |
| Operating Voltage                  | 3.3V to 5.5V               |
| Humidity measurement range         | 20% to 90% RH              |
| Humidity measurement accuracy      | ±5% RH                     |
| Humidity measurement resolution    | 1% RH                      |
| Temperature measurement range      | 0ºC to 50ºC [32ºF to 122ºF]|
| Temperature measurement accuracy   | ±2º C                      |
| Temperature measurement resolution | 1º C                       |
| Signal transmission range          | 20m                        |

## Forbindelses Diagram
Connect the Power line (middle) and ground (-) to +5 and GND respectively. Connect signal (S) to pin 8 on the Arduino.

| KY-015 | Arduino |
| ------ |-------- |
| S      |	Pin 8  |
| middle |	+5V    |
| –      |	GND    |

![image](https://user-images.githubusercontent.com/44589560/159655307-632f49f5-b732-4694-9c95-af8a55e8666a.png)

KY-015 ARDUINO CODE
The following sketch uses pin 8 on the Arduino to serially send and receive data from the KY-015 sensor. Serial communication is archived by sending specific series of high/low signals to the sensor and waiting for a response. Temperature and humidity data is read bit by bit and returned as an array of bytes.

```C++
int DHpin = 8; // input/output pin
byte dat[5];

byte read_data()
{
  byte i = 0;
  byte result = 0;
  for (i = 0; i < 8; i++) {
      while (digitalRead(DHpin) == LOW); // wait 50us
      delayMicroseconds(30); //The duration of the high level is judged to determine whether the data is '0' or '1'
      
      if (digitalRead(DHpin) == HIGH)
        result |= (1 << (8 - i)); //High in the former, low in the post
        
    while (digitalRead(DHpin) == HIGH); //Data '1', waiting for the next bit of reception
    }
    
  return result;
}

void start_test()
{
  digitalWrite(DHpin, LOW); //Pull down the bus to send the start signal
  delay(30); //The delay is greater than 18 ms so that DHT 11 can detect the start signal
  
  digitalWrite(DHpin, HIGH);
  delayMicroseconds(40); //Wait for DHT11 to respond
  
  pinMode(DHpin, INPUT);
  while(digitalRead(DHpin) == HIGH);
  delayMicroseconds(80); //The DHT11 responds by pulling the bus low for 80us;
  
  if(digitalRead(DHpin) == LOW)
    delayMicroseconds(80); //DHT11 pulled up after the bus 80us to start sending data;
    
  for(int i = 0; i < 5; i++) //Receiving temperature and humidity data, check bits are not considered;
    dat[i] = read_data();
    
  pinMode(DHpin, OUTPUT);
  digitalWrite(DHpin, HIGH); //After the completion of a release of data bus, waiting for the host to start the next signal
}

void setup()
{
  Serial.begin(9600);
  pinMode(DHpin, OUTPUT);
}

void loop()
{
  start_test();
  Serial.print("Humdity = ");
  Serial.print(dat[0], DEC); //Displays the integer bits of humidity;
  Serial.print('.');
  Serial.print(dat[1], DEC); //Displays the decimal places of the humidity;
  Serial.println('%');
  Serial.print("Temperature = ");
  Serial.print(dat[2], DEC); //Displays the integer bits of temperature;
  Serial.print('.');
  Serial.print(dat[3], DEC); //Displays the decimal places of the temperature;
  Serial.println('C');
  byte checksum = dat[0] + dat[1] + dat[2] + dat[3];
  
  if (dat[4] != checksum) 
    Serial.println("-- Checksum Error!");
  else
    Serial.println("-- OK");
 
  delay(1000);
}
```
