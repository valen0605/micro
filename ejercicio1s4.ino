#define azulito D4
#define azul D1
#define rojo D8
#define boton D3

int boton1=0;
int estadoazul=LOW, estadoazulito=LOW;
unsigned long tiempo,tx=1000,tx2=500;

void setup() {
 pinMode(azulito,OUTPUT);
 pinMode(azul,OUTPUT);
 pinMode(rojo,OUTPUT);
 pinMode(boton,INPUT);
}
void loop() {
 
 boton1=digitalRead(boton);
 digitalWrite(azul,estadoazul);
 digitalWrite(azulito,estadoazulito);
 tiempo=millis();
 
 if(tiempo-tx>=500){
  	tx=tiempo;
    estadoazul=!estadoazul; 
 }
 if(tiempo-tx2>=500){
 	tx2=tiempo;
   estadoazulito=!estadoazulito; 
 } 
  
 if(boton1==HIGH){//PullUp
 	digitalWrite(rojo,LOW);
 	delay(200);//antirebote
 }

 if(boton1==LOW){//PullUp
 	digitalWrite(rojo,HIGH);
 	delay(200);//antirebote
 }
 
}