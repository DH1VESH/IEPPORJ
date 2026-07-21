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

void setup() {
  int arrayLED[4] = {LED_YELLOW, LED_BLUE, LED_GREEN, LED_RED };
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
  int knobLEDselect = map(knobValue, 0, 1023, 1, 4);  



  Serial.print("KNOB: ");
  Serial.print (knobValue);
  Serial.print(" ");
  Serial.print(knobLEDselect);
  Serial.println(" ");
  disp.display(knobLEDselect);

   
  
  delay (20);
}
