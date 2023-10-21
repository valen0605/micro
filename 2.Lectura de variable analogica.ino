// C++ code
//

const int analogInPin = A0;  //declaración pin de entrada analógica 

float inValue=0;        // valor leido del potenciómetro (0-1023)
float outValue=0;       // valor traducido en voltios (0-5V)

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  // leer valor análogo de entrada:
  inValue = analogRead(analogInPin);
  // función map para conversión a valores de voltaje:
  outValue = map(inValue, 0, 1023, 0, 500);
  outValue=outValue/100;

  // imprimir valores en el monitor serial:
  Serial.print("In value = ");
  Serial.print(inValue,3);
  Serial.print("\t Voltaje = ");
  Serial.println(outValue,3);

  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(2);
}