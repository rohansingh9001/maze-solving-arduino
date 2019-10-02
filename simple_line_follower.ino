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
int fast = 175;
int slow = 130;


//turning functions  
  void turn_left() {
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);
  }
  void turn_right() {
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
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
    analogWrite(RM, fast);
    analogWrite(LM, fast);
  }

  else if (!(digitalRead(L)) ^ !(digitalRead(LL)))     // Turn right
  {
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    analogWrite(RM, fast);
    analogWrite(LM, slow);

  }

  else if (!(digitalRead(R)) ^ !(digitalRead(RR)))     // turn left
  {
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    analogWrite(RM, slow);
    analogWrite(LM, fast);

  }

  else if (!(digitalRead(LL)) && !(digitalRead(RR)))    // stop
  {
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
  }
  else if (!(digitalRead(RR)) && !(digitalRead(R))) { //right turn
    turn_left();
    delay(180);
    
  }
  else if (!(digitalRead(LL)) && !(digitalRead(L))) {  //left turn
    turn_right();
    delay(180);
    
}


//  while (!(digitalRead(L)) || !(digitalRead(LL)) || !(digitalRead(RR)) || !(digitalRead(R)) || !(digitalRead(CC))) {
//    digitalWrite(LM1, LOW);
//    digitalWrite(LM2, LOW);
//    digitalWrite(RM1, LOW);
//    digitalWrite(RM2, LOW);
//    turn_right();
//   }
   
    
  


}
