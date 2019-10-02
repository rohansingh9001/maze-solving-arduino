/*------ Arduino Line Follower Code----- */
/*-------definning Inputs------*/
#define LL 13      // left sensor
#define RR 3      // right sensor
#define L 12
#define R 4
#define CC 11

/*-------definning Outputs------*/
#define LM1 8       // left motor
#define LM2 9       // left motor
#define RM1 6       // right motor
#define RM2 7       // right motor
#define RM 5
#define LM 10

//speed variables
int fastl = 125;
int fastr = 105;
int slowl = 100;
int slowr = 80;
int turn = 20;
int del = 90;


//turning functions  
  void turn_left() {
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);
    digitalWrite(RM, turn);
    digitalWrite(LM, turn);
  }
  void turn_right() {
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    digitalWrite(RM, turn);
    digitalWrite(LM, turn);
    
  }

  
void setup()
{
  delay(3000);
  Serial.begin(9600);
  pinMode(LL, INPUT);
  pinMode(RR, INPUT);
  pinMode(L, INPUT);
  pinMode(R, INPUT);
  pinMode(CC, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(RM, OUTPUT);
  pinMode(LM, OUTPUT);
}

void loop()
{
 
  Serial.print(digitalRead(LL));
  Serial.print(digitalRead(L));
  Serial.print(digitalRead(CC));
  Serial.print(digitalRead(R));
  Serial.print(digitalRead(RR));
  Serial.println();


  if (!(digitalRead(CC)) && (digitalRead(R)) && digitalRead(RR) && digitalRead(LL) && digitalRead(L))    // Move Forward
  {
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    analogWrite(RM, fastr);
    analogWrite(LM, fastl);
  }

  else if (!(digitalRead(L)) ^ !(digitalRead(LL)))     // Turn right
  {
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    analogWrite(RM, fastr);
    analogWrite(LM, slowl);

  }

  else if (!(digitalRead(R)) ^ !(digitalRead(RR)))     // turn left
  {
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    analogWrite(RM, slowr);
    analogWrite(LM, fastl);

  }

  else if (!(digitalRead(LL)) && !(digitalRead(RR)))    // stop
  {
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
  }
  else if (!(digitalRead(RR)) && !(digitalRead(R)) && !(digitalRead(CC)) && digitalRead(LL) && digitalRead(L)) { //right turn
    turn_left();
    delay(del);
    
  }
  else if (!(digitalRead(LL)) && !(digitalRead(L)) && !(digitalRead(CC)) && digitalRead(RR) && digitalRead(R) ) {  //left turn
    turn_right();
    delay(del);
    
}


//  while (!(digitalRead(L)) || !(digitalRead(LL)) || !(digitalRead(RR)) || !(digitalRead(R)) || !(digitalRead(CC))) {
//    digitalWrite(LM1, LOW);
//    digitalWrite(LM2, LOW);
//    digitalWrite(RM1, LOW);
//    digitalWrite(RM2, LOW);
//    turn_right();
//   }
//  else {
//    turn_right();
//    delay(del - 10);
//  }
   
    
  


}
