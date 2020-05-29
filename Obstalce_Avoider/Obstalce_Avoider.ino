/*the code uses arduino to control a robot car with
 *4 motors and an ultrasonic sensor 
 *to move autonomously and avoid the obstacles in front of it*/
 
//defining variables
//motors
#define m1 A0
#define m2 A1
#define m3 A2
#define m4 A3
//ultrasonic
#define trig 9
#define echo 10
int distance;
long duration;

void setup() {
  //setting motors as output
  pinMode(m1,OUTPUT);
  pinMode(m2,OUTPUT);
  pinMode(m3,OUTPUT);
  pinMode(m4,OUTPUT);
  //setting up the ultraonic trig and echo
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
}
//functions
//function to make the robot move forwards
void forward () { 
  analogWrite(m1,0);
  analogWrite(m2,200);
  analogWrite(m3,0);
  analogWrite(m4,200);
}
//function to make the robot move backwards
void back () {
  analogWrite(m1,200);
  analogWrite(m2,0);
  analogWrite(m3,200);
  analogWrite(m4,0);
}
//function to make the robot move right
void right () {
  analogWrite(m1,200);
  analogWrite(m2,0);
  analogWrite(m3,0);
  analogWrite(m4,200);
}
//function to make the robot move left
void left () {
  analogWrite(m1,0);
  analogWrite(m2,200);
  analogWrite(m3,200);
  analogWrite(m4,0);
}
//function to make the robot stop moving
void STOP () {
  analogWrite(m1,0);
  analogWrite(m2,0);
  analogWrite(m3,0);
  analogWrite(m4,0);
}
//ultrasonic function to calculate the distance
void ultrasonic () {
  digitalWrite (trig,LOW);
  delayMicroseconds (2);
  digitalWrite (trig,HIGH);
  delayMicroseconds (10);
  digitalWrite (trig,LOW);
  duration = pulseIn (echo,HIGH);
  distance = duration/58 ; 
}

void loop(){
  //calculate the distance
  ultrasonic ();  
  if(distance<=15){
    //if thre is an object ahead of the robot, move away
    back();
    delay (500);
    right();
    delay (500);
  }
  if (distance<=15) {
    left ();
    delay (1000);
  }
  else if (distance>15){
    //if the way is clear, go ahead
    forward ();
  }
}
