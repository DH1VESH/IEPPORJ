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
int buttonstate1 = 0;
int buttonstate2 = 0;
int arrayLED[4] = {7,6,5,4 };
void LEDselect(int y, int b, int g, int r){
    digitalWrite(y, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(g, LOW);
    digitalWrite(r, LOW);}
int checkbuttons();
int readbuttons();
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

//Button Toggle
bool prevButtonState = false;
int currButtonState;

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

  //Button Toggle
  bool currButtonState = digitalRead(K2PIN);
}


void loop() {

//Button Toggle
prevButtonState = currButtonState;
currButtonState = digitalRead(K2PIN);


 
  int button = checkbuttons();

  int knobValue = analogRead(KNOB); 
  int knobLEDselect = map(knobValue, 0, 1023, 0, 100); 
  int knobTIMEselect = map(knobValue, 0, 1023, 0, 24);  
  int displayselect = map(knobLEDselect, 0, 100, 0, 4);  

  buttonstate1 = digitalRead (K1PIN);
  buttonstate2 = digitalRead (K2PIN);

  if (button == 2){


  Serial.print("KNOB: ");
  Serial.print (knobValue);
  Serial.print(" ");
  Serial.print(knobLEDselect);
  Serial.println(" ");

if (currButtonState == LOW && prevButtonState == HIGH) {
  disp.display(displayselect + 1);
  if (knobLEDselect<=25){
    LEDselect(7, 6, 5, 4);}
  else if (knobLEDselect>25 ;knobLEDselect<=50){
    LEDselect(6, 5, 4, 7);}
  else if (knobLEDselect>50 ; knobLEDselect<=75){
    LEDselect(5, 4, 7, 6);}
  else if (knobLEDselect>75;knobLEDselect<=100){
    LEDselect(4, 7, 6, 5);}
}
  prevButtonState = currButtonState;
  
  }

}

