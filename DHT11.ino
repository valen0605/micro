#include <DHT.h>
#define DHTTYPE DHT11
#define DHTPIN D5 
#define rojo D2
#define azul D3


DHT dht(DHTPIN, DHTTYPE);

void setup() {
  pinMode(D5,OUTPUT);
  pinMode(D2,OUTPUT);
  pinMode(D3,OUTPUT); 
  Serial.begin(9600);
  dht.begin();
  Serial.begin(9600);
}

void loop() {

  float temperaturaa = dht.readTemperature()-10.10;
  float humedaad = dht.readHumidity();
  
  Serial.print("Temperatura = ");
  Serial.print(temperaturaa);
  Serial.println(" °C");

  Serial.print("Humedad = ");
  Serial.print(humedaad);
  Serial.println(" %");
 
  delay(2000);

  if(humedaad>=30){
    digitalWrite(D2, HIGH);
  }
  else{
    digitalWrite(D2, LOW);
  }
  if(temperaturaa>=21){
    digitalWrite(D3, HIGH);
  }
  else{
    digitalWrite(D3, LOW);
  }

}