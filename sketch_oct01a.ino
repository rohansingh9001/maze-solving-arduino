

/*------ Arduino Line Follower Code----- */
/*-------definning Inputs------*/
#define LS 12      // left sensor
#define RS 4      // right sensor

/*-------definning Outputs------*/
#define LM1 8       // left motor
#define LM2 9       // left motor
#define RM1 6       // right motor
#define RM2 7       // right motor
#define RM 5
#define LM 10

void setup()
{
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(RM, OUTPUT);
  pinMode(LM, OUTPUT);
}

void loop()
    // Move Forward
  {
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    analogWrite(RM, 255);
    analogWrite(LM, 255);
}
