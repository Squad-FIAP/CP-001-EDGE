#include <Arduino.h>

int sensorPin = 0;
float Celsius;
float Fahrenheit;
float Kelvin;
int sensorValue;

void setup(){
Serial.begin(9600);
Serial.println("initialising.....");
}

void loop(){
GetTemp();
Serial.println("Celcius:");
Serial.println(Celsius);
Serial.print("Fahrenheit:");
Serial.println(Fahrenheit);
Serial.println();
delay(2000);
}

void GetTemp(){
sensorValue=analogRead(sensorPin); //Lê o sensor
Kelvin=(((float(sensorValue)/1023)*5)*100);//converte em kelvin
Celsius=Kelvin-273.15; // converte Kelvin em Celcius
Fahrenheit=(Celsius*1.8)+32;//converte Celcius para Fahrenheit
}