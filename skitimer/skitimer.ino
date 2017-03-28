#include "Timer.h"
Timer t;
int pin = 13;
#define G 22
#define F 23
#define A 24
#define B 25
#define E 26
#define D 27
#define C 28
#define DP 29
 
 
#define GND1 52
#define GND2 53
#define GND3 50
#define GND4 51
 
int timer=0;
int minute=0;
int val = 0;
int sensorValue = 0;
 
int pauza = 0;
int start = 0;
 
int i=0;
void setup() {
 
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  Serial.begin(9600);
  t.every(10, VremeCount);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(DP, OUTPUT);
   
  pinMode(GND1, OUTPUT);
  pinMode(GND2, OUTPUT);
  pinMode(GND3, OUTPUT);
  pinMode(GND4, OUTPUT);
}    
void loop() {
  t.update();
  sensorValue = digitalRead(2);
  Serial.println(sensorValue);
  int startread = digitalRead(3);
  if(startread == 1) {
      start = 1;
  }
  if(sensorValue == 1) {
    pauza = 1;
  }
}
 
void VremeCount() {
  if(pauza == 0 && start == 1) {
      i++;
  }
    showdigits (i);
    if (i>10000) {i=0;};
   
    if (i%2) { digitalWrite(DP, LOW); }
     
    else  {digitalWrite(DP, HIGH); };
}
void digit0 () {
 
 
digitalWrite(A, LOW);
digitalWrite(B, LOW);
digitalWrite(C, LOW);
digitalWrite(D, LOW);
digitalWrite(E, LOW);
digitalWrite(F, LOW);
 
 
digitalWrite(G, HIGH);
 
};
 
void digit1 () {
 
digitalWrite(A,HIGH);
digitalWrite(B, LOW);
digitalWrite(C, LOW);
digitalWrite(D, HIGH);
digitalWrite(E, HIGH);
digitalWrite(F, HIGH);
digitalWrite(G, HIGH);
};
 
void digit2 () {
 
digitalWrite(A,LOW);
digitalWrite(B, LOW);
digitalWrite(C, HIGH);
digitalWrite(D, LOW);
digitalWrite(E, LOW);
digitalWrite(F, HIGH);
digitalWrite(G, LOW);
};
 
void digit3 () {
 
digitalWrite(A,LOW);
digitalWrite(B, LOW);
digitalWrite(C, LOW);
digitalWrite(D, LOW);
digitalWrite(E, HIGH);
digitalWrite(F, HIGH);
digitalWrite(G, LOW);
};
 
void digit4 () {
 
digitalWrite(A,HIGH);
digitalWrite(B, LOW);
digitalWrite(C, LOW);
digitalWrite(D, HIGH);
digitalWrite(E, HIGH);
digitalWrite(F, LOW);
digitalWrite(G, LOW);
};
 
void digit5 () {
 
digitalWrite(A,LOW);
digitalWrite(B, HIGH);
digitalWrite(C, LOW);
digitalWrite(D, LOW);
digitalWrite(E, HIGH);
digitalWrite(F, LOW);
digitalWrite(G, LOW);
};
 
void digit6 () {
 
digitalWrite(A,LOW);
digitalWrite(B, HIGH);
digitalWrite(C, LOW);
digitalWrite(D, LOW);
digitalWrite(E, LOW);
digitalWrite(F, LOW);
digitalWrite(G, LOW);
};
 
void digit7 () {
 
digitalWrite(A,LOW);
digitalWrite(B, LOW);
digitalWrite(C, LOW);
digitalWrite(D, HIGH);
digitalWrite(E, HIGH);
digitalWrite(F, HIGH);
digitalWrite(G, HIGH);
};
 
void digit8 () {
 
digitalWrite(A, LOW);
digitalWrite(B, LOW);
digitalWrite(C, LOW);
digitalWrite(D, LOW);
digitalWrite(E, LOW);
digitalWrite(F, LOW);
digitalWrite(G, LOW);
 
};
 
void digit9 () {
 
digitalWrite(A, LOW);
digitalWrite(B, LOW);
digitalWrite(C, LOW);
digitalWrite(D, LOW);
digitalWrite(E, HIGH);
digitalWrite(F, LOW);
digitalWrite(G, LOW);
 
};
 
void showdigit (int digit)
 
{
 
 switch (digit) {
 
 case 0:
 digit0 ();
 break;
 
 case 1:
 digit1 ();
 break;
 
 case 2:
 digit2 ();
 break;
 
 case 3:
 digit3 ();
 break;
 
 case 4:
 digit4 ();
 break;
 
 case 5:
 digit5 ();
 break;
 
 case 6:
 digit6 ();
 break;
 
 case 7:
 digit7 ();
 break;
 
 case 8:
 digit8 ();
 break;
 
 case 9:
 digit9 ();
 break;
 
 default:
 
 break;
 
 };
 
};
 
 
void showdigits (int number)
{
 
showdigit(number/1000);  // DESETINE
digitalWrite(GND2, HIGH);
digitalWrite(GND3, LOW);
digitalWrite(GND1, LOW);
digitalWrite(GND4, LOW);
delay (1);
 if(number/1000 >= 6) {
  minute++;
  i=0;
 }
 
number = number%1000;  // SEKUNDE
digitalWrite(GND2, LOW);
 showdigit(number/100);
digitalWrite(GND3, HIGH);
 delay (1);
 
number =number%100;    //STOTINJKE
digitalWrite(GND3, LOW);
showdigit(number/10);
digitalWrite(GND4, HIGH);
delay (1);
 
digitalWrite(GND4, LOW); //MINUTE
showdigit(minute);
digitalWrite(GND1, HIGH);
 delay (1);
 
};
