#define LED
#define KNOB A0 // (Blue) Potentionometer Knob
#define CLK 10
#define DIO 11
TM1637 disp(CLK,DIO);

void setup() {
}
void loop() {
  // put your main code here, to run repeatedly:
Serial.print("poop");
}
