// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(A0, OUTPUT);//1
  pinMode(A1, OUTPUT);//2
  pinMode(A2, OUTPUT);//3
  pinMode(A3, OUTPUT);//4
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(A6, OUTPUT);
  pinMode(A7, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(A0, LOW);   // turn the LED on (HIGH is the voltage level)  
  delay(1000);                       // wait for a second
  digitalWrite(A0, HIGH);    // turn the LED off by making the voltage LOW  
  delay(1000);                       // wait for a second

  digitalWrite(A1, LOW);   // turn the LED on (HIGH is the voltage level)  
  delay(1000);                       // wait for a second
  digitalWrite(A1, HIGH);    // turn the LED off by making the voltage LOW  
  delay(1000);                       // wait for a second

  digitalWrite(A2, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(A2, HIGH);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second

  digitalWrite(A3, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(A3, HIGH);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second

//  digitalWrite(A4, LOW);   // turn the LED on (HIGH is the voltage level)
//  delay(1000);                       // wait for a second
//  digitalWrite(A4, HIGH);    // turn the LED off by making the voltage LOW
//  delay(1000);                       // wait for a second
//
//  digitalWrite(A5, LOW);   // turn the LED on (HIGH is the voltage level)
//  delay(1000);                       // wait for a second
//  digitalWrite(A5, HIGH);    // turn the LED off by making the voltage LOW
//  delay(1000);                       // wait for a second
//
//  digitalWrite(A6, LOW);   // turn the LED on (HIGH is the voltage level)
//  delay(1000);                       // wait for a second
//  digitalWrite(A6, HIGH);    // turn the LED off by making the voltage LOW
//  delay(1000);                       // wait for a second
//
//  digitalWrite(A7, LOW);   // turn the LED on (HIGH is the voltage level)
//  delay(1000);                       // wait for a second
//  digitalWrite(A7, HIGH);    // turn the LED off by making the voltage LOW
//  delay(1000);                       // wait for a second
}
