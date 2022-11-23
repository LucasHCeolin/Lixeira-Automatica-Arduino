#include <Servo.h>

Servo servo1;

int trigPin = 9; //Define o pino Trig do Ultrassônico
int echoPin = 8; //Define o pino Echo do Ultrassônico

long distance;
long duration;
 
void setup(){
  
servo1.attach(7); 
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);

}
 
void loop(){
  
  ultra(); //Chama a função que controla o sensor ultrassônico
  servo1.write(0); //Deixe o servo motor na posição de 0 graus
  
  if(distance <= 20){ //O servo motor vai para a posição de 90 graus se a distancia for menor ou igual a 20 centímetros 
  servo1.write(90);
  }
}
 
void ultra(){ //Inicio da função responsável pelo controle do Ultrassônico
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;
  }
