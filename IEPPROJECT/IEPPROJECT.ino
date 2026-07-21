#include <RichShieldTM1637.h>
#include <TM1637Display.h>
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
TM1637 disp(CLK, DIO);
int arrayLED[4] = {7,6,5,4 };
 

void setup() {
  Serial.begin(9600);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(KNOB, INPUT);
  pinMode(K1PIN, INPUT_PULLUP);
  pinMode(K2PIN, INPUT_PULLUP);
  disp.init();
}

void loop() {
  int knobValue = analogRead(KNOB);
  int knobLEDselect = map(knobValue, 0, 1023, 0, 100);  



  Serial.print("KNOB: ");
  Serial.print (knobValue);
  Serial.print(" ");
  Serial.print(knobLEDselect);
  Serial.println(" ");
  disp.display(knobLEDselect);

  

  if (knobLEDselect<=25){
    digitalWrite(LED_YELLOW, HIGH);
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_BLUE, LOW);
    digitalWrite(LED_GREEN, LOW);
  }
  else if (knobLEDselect>25 ;knobLEDselect<=50){
    digitalWrite(LED_BLUE, HIGH);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_GREEN, LOW);
  }
  else if (knobLEDselect>50 ; knobLEDselect<=75){
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(LED_BLUE, LOW);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_RED, LOW);
  }
  else if ( knobLEDselect>75;knobLEDselect<=100){
    digitalWrite(LED_RED, HIGH);
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_BLUE, LOW);
    digitalWrite(LED_YELLOW, LOW);
  }

  
  delay (20);
}
