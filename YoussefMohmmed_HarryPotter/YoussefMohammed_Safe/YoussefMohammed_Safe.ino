long double counter0 = 0; 
long double counter1 = 0; 
long double counter2 = 0; 
long double alpha=0;
long double beta=0;
long double gama=0;
long double ppr=360; // pulses per rotation for 



/////////////////////////////////////////////
  void EA0() {
  if(digitalRead(2)!=digitalRead(3)) {
  counter0++;
  }else{
  counter0--;
  }
  }
   
  void EB0() {
  if(digitalRead(2)==digitalRead(3)) {
  counter0++;
  }else{
  counter0--;
  }
  }


/////////////////////////////////////////////////////
  void EA1() {
  // ai0 is activated if DigitalPin nr 3 is going from LOW to HIGH
  // Check with pin 2 to determine the direction
  if(digitalRead(18)!=digitalRead(19)) {
  counter1--;
  }else{
  counter1++;
  }
  }

  void EB1() {
  // ai0 is activated if DigitalPin nr 3 is going from LOW to HIGH
  // Check with pin 2 to determine the direction
  if(digitalRead(18)==digitalRead(19)) {
  counter1--;
  }else{
  counter1++;
  }
  }


/////////////////////////////////////////////////////

  void EA2() {
  // ai0 is activated if DigitalPin nr 3 is going from LOW to HIGH
  // Check with pin 2 to determine the direction
  if(digitalRead(20)!=digitalRead(21)) {
  counter2--;
  }else{
  counter2++;
  }
  }

    void EB2() {
  // ai0 is activated if DigitalPin nr 3 is going from LOW to HIGH
  // Check with pin 2 to determine the direction
  if(digitalRead(20)==digitalRead(21)) {
  counter2--;
  }else{
  counter2++;
  }
  }


void setup() {
  Serial.begin (9600);
pinMode(2, INPUT_PULLUP);
pinMode(3, INPUT_PULLUP); 

pinMode(18, INPUT_PULLUP);
pinMode(19, INPUT_PULLUP); 

pinMode(20, INPUT_PULLUP);
pinMode(21, INPUT_PULLUP); 


attachInterrupt(digitalPinToInterrupt(2), EA0, CHANGE);
attachInterrupt(digitalPinToInterrupt(3), EB0, CHANGE);

attachInterrupt(digitalPinToInterrupt(18), EA1, CHANGE);
attachInterrupt(digitalPinToInterrupt(19), EB1, CHANGE);

attachInterrupt(digitalPinToInterrupt(20), EA2, CHANGE);
attachInterrupt(digitalPinToInterrupt(21), EB2, CHANGE);
}
   
void loop() {
alpha=(counter0/ppr)*360;
beta=(counter1/ppr)*360;
gama=(counter2/ppr)*360;
if (alpha==37 && beta==10 && gama==54) 
{
digitalWrite(13,HIGH);
}
else{
  digitalWrite(13,LOW);
}
}


