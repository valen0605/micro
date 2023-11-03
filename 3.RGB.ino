#define rojo D3
#define verde D1
#define azul D2

int porR=0;
int porG=0;
int porB=0;
int cont=1;

void setup() {
 pinMode(rojo,OUTPUT);
 pinMode(verde,OUTPUT);
 pinMode(azul,OUTPUT);
  Serial.begin(115200);  //Baudios para Wemos Lollin D1 mini
  }

void loop() {

  if(cont==1){
    
    //Serial.println("Inserte %R: ");
    //delay(10000);
  
  if (Serial.available()) {
    porR = Serial.parseInt();
    if(porR>=255){
      porR=255;
    }
    if (Serial.read() == '\n') { 
      Serial.print("%R recibido: ");
      Serial.println(porR);
      cont=cont+1;
    delay(100);
    }
  }
    
  }
  
  if(cont==2){
    
    //Serial.println("Inserte %G: ");
    //delay(10000);
  
  if (Serial.available()) {
    porG = Serial.parseInt();
    if(porG>=255){
      porG=255;
    }
    if (Serial.read() == '\n') { 
      Serial.print("%G recibido: ");
      Serial.println(porG);
      cont=cont+1;
    delay(100);
    }
  }
    
  }
  
  if(cont==3){
    
    //Serial.println("Inserte %B: ");
    //delay(10000);
  
  if (Serial.available()) {
    porB = Serial.parseInt();
    if(porB>=255){
      porB=255;
    }
    if (Serial.read() == '\n') { 
      Serial.print("%B recibido: ");
      Serial.println(porB);
      cont=cont+1;
    delay(100);
    }
  }
    
  }

if (Serial.available()) {
  if(cont==4 && Serial.read() == '\n'){
    
    Serial.print("RGB: ");
    Serial.print(porR);
    Serial.print(" ");
    Serial.print(porG);
    Serial.print(" ");
    Serial.println(porB);
    delay(100);
    cont=1;
    
  }

}  
  analogWrite(D3, porR);
  analogWrite(D1, porG);
  analogWrite(D2, porB);

}
