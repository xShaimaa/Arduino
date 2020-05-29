/*the code uses arduino to control a robot car with
 *4 motors and a bluetooth module 
 *to control its dirictions using a simple mobile aplication*/
 
//defining variables
//motors
#define n1 A0
#define n2 A1
#define n3 A2
#define n4 A3
//the incoming data from the app
int data;
//hint: connect the TX and RX of the bluetooth module to RX and TX in the Arduino board

void setup(){
  Serial.begin(9600);
  //setting motors as output
  pinMode(A0,OUTPUT); 
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);
  pinMode(A3,OUTPUT);
}
//functions
//function to make the robot move forwards
void forward () { 
  analogWrite(n1,0);
  analogWrite(n2,200);
  analogWrite(n3,0);
  analogWrite(n4,200);
}
//function to make the robot move backwards
void back () {
  analogWrite(n1,200);
  analogWrite(n2,0);
  analogWrite(n3,200);
  analogWrite(n4,0);
}
//function to make the robot move right
void right () {
  analogWrite(n1,200);
  analogWrite(n2,0);
  analogWrite(n3,0);
  analogWrite(n4,200);
}
//function to make the robot move left
void left () {
  analogWrite(n1,0);
  analogWrite(n2,200);
  analogWrite(n3,200);
  analogWrite(n4,0);
}
//function to make the robot stop moving
void STOP () {
  analogWrite(n1,0);
  analogWrite(n2,0);
  analogWrite(n3,0);
  analogWrite(n4,0);
}
void loop() {
  //read the incomming data
  data=Serial.read ();
  if (data=='F'){
    forward();
  }
  else if (data=='B'){
    back();
  }
  else if (data=='R'){
    right();
  }
  else if (data=='L'){
    left();
  }
  else if (data=='S'){
    STOP();
  }
}
