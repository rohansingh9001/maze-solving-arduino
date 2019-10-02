// IR SENSOR 
//key for various pins in the arduino.
//rr = 12, r = 8, c = 7, ll = 4, l = 2,


// defines the port numbers of the IR sensors on the arduino board
int ll = 4; 
int l = 2;
int c = 7;
int rr = 12;
int r = 8;


//defines variables to use in the loop function
int val_ll = 0;
int val_l = 0;
int val_c = 0;
int val_rr = 0;
int val_r = 0;






void setup() {
  //tells arduino the inputs to be taken from the pins
  Serial.begin(9600);
  pinMode(ll,INPUT);
  pinMode(l,INPUT);
  pinMode(c,INPUT);
  pinMode(r,INPUT);
  pinMode(rr,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

//definition of movement functions
void forward (){
  Serial.println("Move Forward");
}
void right (){
  Serial.println("Turn Right");
}
void left (){
  Serial.println("Turn left");
}
void tjunction (){
  Serial.println("T_Junction");
}
void plusjunction (){
  Serial.println("plusjunction");
}
void deadend (){
  Serial.println("Deadend");
}


  //checks conditions for various turn types
  if(val_ll==1 && val_l==1 && val_c==0 && val_r==1 && val_rr==1){
   forward();
 }
  if(val_ll==0 && val_l==0 && val_c==1 && val_r==1 && val_rr==1) {
    left();   
  }
  if(val_ll==1 && val_l==1 && val_c==1 && val_r==0 && val_rr==0) {
    right();
  }
  if(val_ll==0 && val_l==0 && val_c==1 && val_r==0 && val_rr==0) {
    tjunction();
  }
  if(val_ll==0 && val_l==0 && val_c==0 && val_r==0 && val_rr==0) {
    plusjunction();
  }
  if(val_ll== 1 && val_l== 1 && val_c== 1 && val_r== 1 && val_rr== 1) {
    deadend();
  }
}
