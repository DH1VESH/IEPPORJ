#include <RichShieldTM1637.h>
#include <TM1637Display.h>
#include <Arduino.h>
#define BUZZER     3
#define LED_RED    4
#define LED_GREEN  5
#define LED_BLUE   6
#define LED_YELLOW 7
#define KNOB A0 // Potentionometer Knob
#define K1PIN 8 //Button 1
#define K2PIN 9 //Button 2
#define CLK 10
#define DIO 11
int yellowhours, bluehours, greenhours, redhours;
TM1637 disp(CLK, DIO);
int arrayLED[4] = {7,6,5,4 };


int Hours[4] ;


int k,j;




void LEDselect(int y, int b, int g, int r){
    digitalWrite(y, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(g, LOW);
    digitalWrite(r, LOW);}
int buttons = 0;

int checkbuttons(){
  int prev,curr;
  curr = readbuttons();
  do {
    delay(20);
    prev = curr;
    curr = readbuttons();
  } while (curr != prev);
  return curr;
}

int readbuttons(){
  int k1,k2;
  k1 = !digitalRead (K1PIN);
  k2 = !digitalRead (K2PIN);
  return(k1 | k2 <<1);
}

void setup() {
  Serial.begin(9600);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(KNOB, INPUT);
  pinMode(K1PIN, INPUT_PULLUP);
  pinMode(K2PIN, INPUT_PULLUP);
  pinMode (BUZZER, OUTPUT);
  disp.init();
}

void loop() {
 
  int buttons = checkbuttons() ;
  int knobValue = analogRead(KNOB);
  int knobselect = map(knobValue, 0, 1023, 0, 100);
  int displayLEDselect = map(knobselect, 0, 100, 0, 4);
  int displayTIMEselect = map(knobselect, 0, 100, 1, 24);
  int displayTIMEselect2 = Hours[displayLEDselect];

if (buttons==2)
 {
  disp.display(displayTIMEselect2);
  Serial.print (displayLEDselect + 1);
   if (knobselect<=25){
    LEDselect(7, 6, 5, 4);}
  else if (knobselect>25 ;knobselect<=50){
    LEDselect(6, 5, 4, 7);}
  else if (knobselect>50 ; knobselect<=75){
    LEDselect(5, 4, 7, 6);}
  else if ( knobselect>75;knobselect<=100){
    LEDselect(4, 7, 6, 5);}
 }

else if (buttons==1)
{
 disp.display(displayTIMEselect);
 int serial();
 Serial.print(displayTIMEselect);
 }

else if (buttons==0)
{






}

else if (buttons==3)
{
 int g;
 for (g=0;g<4;g++)
 {
  digitalWrite(7-g, HIGH);
  delay(1000);
  digitalWrite(7-g, LOW);
  Hours[g] = 0;
 }
}
}










