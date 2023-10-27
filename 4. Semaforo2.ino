// C++ code
//

const int analogInPin = A0;  //declaración pin de entrada analógica  
const int manten = 10;
const int paro = 11;
const int rojo = 7;
const int amarillo = 6;
const int verde = 5;

float inValue=0;        // valor leido del potenciómetro (0-1023)
float outValue=0;       // valor traducido en voltios (0-5V)
int paro1=0;
int manten1=0;
int t1=0,t2=0,t3=0,t4=0,cont=0;

void setup() {
  Serial.begin(9600);
  
  pinMode(rojo, OUTPUT);
  pinMode(amarillo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(paro, INPUT);
  pinMode(manten, INPUT);
  pinMode(9, INPUT);
  pinMode(8, INPUT);
  
}

void loop() {
  
  // leer valor análogo de entrada:
  inValue = analogRead(analogInPin);
  // función map para conversión a valores de voltaje:
  outValue = map(inValue, 0, 1023, 0, 500);
  outValue=outValue/100;

  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(2);
  
  t1=500/outValue;
  t2=5000/outValue;
  t3=1000/outValue;
  t4=3000/outValue;
  
  paro1=digitalRead(paro);
  manten1=digitalRead(manten);
  
  if(manten1==LOW){
  	if(paro1==LOW){
    	delay(t1);
    	digitalWrite(amarillo,LOW);
    	digitalWrite(rojo,HIGH);
      	cont=cont+1;
      	// imprimir valores en el monitor serial:
  		Serial.print("ROJO = ");
  		Serial.print(cont);
  		Serial.print("\tIn value = ");
  		Serial.print(inValue,3);
  		Serial.print("\t Velocidad = ");
  		Serial.println(outValue,3);
    	delay(t2);
    	digitalWrite(rojo,HIGH);
    	digitalWrite(amarillo,HIGH);
    	delay(t3);
    	digitalWrite(rojo,LOW);
    	digitalWrite(amarillo,LOW);
    	digitalWrite(verde,HIGH);
    	delay(t4);
    	digitalWrite(verde,LOW);
    	digitalWrite(amarillo,HIGH);
    	delay(t1);
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