#include <hcsr04.h>

 #include <Servo.h>  
 Servo myservo;   
 int pos =0;   
 const int trigPin = 11;  
 const int echoPin = 10;  
 const int led2 = 13;  
 const int led1 = 12;
 long duration;  
 float distance;  
 void setup()   
 {  
  myservo.attach(9);  
  pinMode(trigPin, OUTPUT);  
  pinMode(echoPin, INPUT);   
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);  
  myservo.write(pos);  
 }  
 void loop()   
 {  
  Serial.begin(9600);  
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2);  
  digitalWrite(trigPin, HIGH);  
  delayMicroseconds(10);  
  digitalWrite(trigPin, LOW);  
  duration = pulseIn(echoPin, HIGH);  
  distance = 0.034*(duration/2);  
  Serial.println(distance);  
  if (distance < 50)  
  {  
   digitalWrite(led1,LOW); 
   digitalWrite(led2,HIGH); 
   myservo.write(pos+180);
   Serial.println("Train is near stop");
   Serial.println(distance);  
   delay(100);  
  }  
  else   
  {  
   digitalWrite(led1,HIGH); 
     digitalWrite(led2,LOW);
     Serial.println("Path is clear now");   
    myservo.write(pos);  
  }  
  delay(300);  
 } 
