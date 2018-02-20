/*This is for CSNE Workshop the demo of feedback
 * Author: Shao-An(Sean), Yin, Feb/20/2018
 */
 
int LEDpins[] = {2,3,4};
int buttons[] = {5,6,7};
int Modeswitch = 8; // feedback or not
int Switch = 9; //Reset for shuffle
int n = 3;
int Modestate = LOW;
int Switchstate = LOW;
int buzzer = 10;
int Series[] = {0, 0, 0}; // Record for series of buttons preesed

//===================================================================
void setup() {
    Serial.begin(115200); 
 for(int i = 0; i<3; i++){
    pinMode(LEDpins[i], OUTPUT);
    pinMode(buttons[i], INPUT_PULLUP);}
    pinMode(Modeswitch, INPUT_PULLUP);
    pinMode(Switch, INPUT_PULLUP);
    pinMode(buzzer, OUTPUT);
}

//===================================================================
void buzzerforcorrect(){
        for ( int ii=0; ii<10; ii++ ) {

        tone(buzzer,1000);

        delay(50);

        tone(buzzer,500);

        delay(50);

     } 
   noTone(buzzer);

    delay(2000);
  }
  
//===================================================================
void shuffle(){
   //Shuffle the random LED 
  for (size_t i = 0; i < n - 1; i++){
      size_t j = random(0, n - i);
      int t = LEDpins[i];
      LEDpins[i] = LEDpins[j];
      LEDpins[j] = t;
  }
 }
 
//===================================================================
void loop() {
// Suffle/ Reset
  for (size_t i = 0; i < n - 1; i++){
      size_t j = random(0, n - i);
      int t = LEDpins[i];
      LEDpins[i] = LEDpins[j];
      LEDpins[j] = t;
  }
if(digitalRead(Switch) == LOW){
// Check the order
 while ((Series[0] != LEDpins[0]) || (Series[1] != LEDpins[1]) || (Series[2] != LEDpins[2])){
     
    // Feedback
 if (Modestate = digitalRead(Modeswitch) == LOW){
  for (int j = 0; j<3; j++){
      digitalWrite(LEDpins[j], HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(1000);                       // wait for a second
      digitalWrite(LEDpins[j], LOW);}
     }
     
     if(digitalRead(buttons[0]) == LOW)
  {
    Series[0] = Series[1];
    Series[1] = Series[2];
    Series[2] = 2;
    while(digitalRead(buttons[0]) == LOW);
  }
    else if(digitalRead(buttons[1]) == LOW)
  {
    Series[0] = Series[1];
    Series[1] = Series[2];
    Series[2] = 3;
    while(digitalRead(buttons[1]) == LOW);
  }
    else if(digitalRead(buttons[2]) == LOW)
  {
    Series[0] = Series[1];
    Series[1] = Series[2];
    Series[2] = 4;
    while(digitalRead(buttons[2]) == LOW);
  }
   Serial.print(Series[0]);
   Serial.print(Series[1]);
   Serial.println(Series[2]);}
buzzerforcorrect();
}
}

