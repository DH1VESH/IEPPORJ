#include <RichShieldTM1637.h>
#define BUZZER 3
#define LED_RED     4
#define LED_GREEN   5
#define LED_BLUE    6
#define LED_YELLOW  7
#define KNOB A0 // Potentionometer Knob
#define K1PIN 8 //Button 1
#define K2PIN 9 //Button 2
#define CLK 10
#define DIO 11
TM1637 disp(CLK,DIO);

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
  // put your main code here, to run repeatedly:
Serial.print("poop");
}
