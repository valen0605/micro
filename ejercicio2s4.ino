const int potenciometroPin = A0;
const int ledAzulPin = D1;
const int ledRojoPin = D8;
const int ledInternoPin = D4;

float voltajeMinimo = 1.5 ; //voltaje minimo
int valorMinimo = (voltajeMinimo / 5.0) * 1023;//voltaje minimo

float voltajeMedio = 2.50; //voltaje medio
int valorMedio = (voltajeMedio / 5.0) * 1023;//voltaje medio

float voltajeAlto = 5.0; //voltaje alto
int valorAlto = (voltajeAlto / 5.0) * 1023;//voltaje alto

void setup() {
  pinMode(ledAzulPin, OUTPUT);
  pinMode(ledRojoPin, OUTPUT);
  pinMode(ledInternoPin, OUTPUT);
  Serial.begin(9600);
  digitalWrite(ledInternoPin, HIGH);
  delay(200);// Parpadeo del LED interno
}

void loop() {
  int valorPotenciometro = analogRead(potenciometroPin);
  float potenciometro = (valorPotenciometro *0.05) /1023;
  Serial.print("valor pot:");
  Serial.println(potenciometro*100,2);

  if (valorPotenciometro >= valorMedio && valorPotenciometro < valorAlto) {//el Led Azul para un valor igual osuperior al valor medio
    digitalWrite(ledAzulPin, HIGH);
    delay(200);
  } 
  else if (valorPotenciometro < valorMedio || valorPotenciometro>= valorAlto)  {
    digitalWrite(ledAzulPin, LOW);
    delay(200);
  }

  if (valorPotenciometro >= valorAlto ) { // ValorAlto que equivale a 5 voltios*1023
    digitalWrite(ledRojoPin, HIGH);
    delay(200);
  } 
  else {
    digitalWrite(ledRojoPin, LOW);
    delay(200);
  }

  if (valorPotenciometro < valorMedio && valorPotenciometro>valorMinimo) {
    digitalWrite(ledInternoPin, LOW);
    delay(200);// Parpadeo del LED interno
    digitalWrite(ledInternoPin, HIGH);
    delay(200);// Parpadeo del LED interno
  }

  if (valorPotenciometro < valorMinimo) {
    parpadearTresLEDs();
    delay(200);
  }

  delay(100); 
}

void parpadearTresLEDs() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(ledAzulPin, HIGH);
    digitalWrite(ledRojoPin, HIGH);
    digitalWrite(ledInternoPin, LOW);
    delay(500);
    digitalWrite(ledAzulPin, LOW);
    digitalWrite(ledRojoPin, LOW);
    digitalWrite(ledInternoPin, HIGH);
    delay(500);
  }
}