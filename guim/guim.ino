#include <Servo.h>
int distancia,distancia1,distancia2;
int enA =6;
int der_ade =7;
int der_atr =4;
int enB =5;
int izq_ade=2;
int izq_atr=3;
 int trig =9;
int echo =10;
 int pwm =150;
 long tiempo = 0;
Servo cabeza;
 void setup(){
  Serial.begin(9600);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(der_ade, OUTPUT);
  pinMode(der_atr, OUTPUT);
  pinMode(izq_ade, OUTPUT);
  pinMode(izq_atr, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  cabeza.attach(11);
  cabeza.write(90);
 }
void loop(){
  medir();
  adelante();
  if(distancia <= 12){
    parar();
    delay(1000);
    
    cabeza.write(0);
    medir();
    distancia1 = distancia;
    delay(1000);
    
    cabeza.write(180);
    medir();
    distancia2 =distancia;
    delay(1000);
    
    if(distancia1 > distancia2){
      derecha();
      delay(1000);
      cabeza.write(90);
    }else 
      if(distancia2 > distancia1){
        izquierda();
        delay(1000);
        cabeza.write(90);
    }
  }else if(distancia >12){
    adelante();
  }
}
void adelante(){
  digitalWrite(der_ade,HIGH);
  digitalWrite(der_atr,LOW);
  digitalWrite(izq_ade,HIGH);
  digitalWrite(izq_atr,LOW);
  analogWrite(enA,pwm);
  analogWrite(enB,pwm);
  Serial.println("adelante");
}
void atras(){
  digitalWrite(der_ade,LOW);
        digitalWrite(der_atr,HIGH);
        digitalWrite(izq_ade,LOW);
        digitalWrite(izq_atr,HIGH);
        analogWrite(enA,pwm);
        analogWrite(enB,pwm);
        Serial.println("atras");
}
void derecha(){
  digitalWrite(der_ade,LOW);
        digitalWrite(der_atr,HIGH);
        digitalWrite(izq_ade,HIGH);
        digitalWrite(izq_atr,LOW);
        analogWrite(enA,pwm);
        analogWrite(enB,pwm);
        Serial.println("derecha");
 }
void izquierda(){
  digitalWrite(der_ade,HIGH);
        digitalWrite(der_atr,LOW);
        digitalWrite(izq_ade,LOW);
        digitalWrite(izq_atr,HIGH);
        analogWrite(enA,pwm);
        analogWrite(enB,pwm);
        Serial.println("izquierda");
}
void parar(){
        digitalWrite(der_ade,LOW);
        digitalWrite(der_atr,LOW);
        digitalWrite(izq_ade,LOW);
        digitalWrite(izq_atr,LOW);
        analogWrite(enA,pwm);
        analogWrite(enB,pwm);
        Serial.println("parar");
}
void medir(){/*
   digitalWrite(trig, LOW);  
   delayMicroseconds(4);
   digitalWrite(trig, HIGH); 
   delayMicroseconds(10);
   digitalWrite(trig, LOW);
   log  duration = pulseIn(echo, HIGH);
   distancia = duration * 10 / 292/ 2;*/
   digitalWrite(trig,LOW);//recibimiento del pulso.
   delayMicroseconds(5);
   digitalWrite(trig, HIGH);//envió del pulso.
   delayMicroseconds(10);
   tiempo=pulseIn(echo, HIGH);//fórmula para medir el pulso entrante.
   distancia= long(0.017*tiempo);
   Serial.println("distancia");
   Serial.println(distancia);
}





 
