// C++ code
//

const int analogInPin = A0;  
const int manten = 10;
const int paro = 11;
const int rojo = 7;
const int amarillo = 6;
const int verde = 5;

int paro1=0;
int manten1=0;

void setup() {
  pinMode(rojo, OUTPUT);
  pinMode(amarillo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(paro, INPUT);
  pinMode(manten, INPUT);
  pinMode(9, INPUT);
  pinMode(8, INPUT);
  
}

void loop() {
  
  paro1=digitalRead(paro);
  manten1=digitalRead(manten);
  
  if(manten1==LOW){
  	if(paro1==LOW){
    	delay(500);
    	digitalWrite(amarillo,LOW);
    	digitalWrite(rojo,HIGH);
    	delay(5000);
    	digitalWrite(rojo,HIGH);
    	digitalWrite(amarillo,HIGH);
    	delay(1000);
    	digitalWrite(rojo,LOW);
    	digitalWrite(amarillo,LOW);
    	digitalWrite(verde,HIGH);
    	delay(3000);
    	digitalWrite(verde,LOW);
    	digitalWrite(amarillo,HIGH);
    	delay(500);
  	}
  	else{
    	digitalWrite(rojo,LOW);
    	digitalWrite(verde,LOW);
    	digitalWrite(amarillo,LOW);
  	}
  }
  else{
    digitalWrite(amarillo,HIGH);
    delay(500);
    digitalWrite(amarillo,LOW);
    delay(500);
  }  
}