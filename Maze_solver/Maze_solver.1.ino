/*the code uses arduino to control a robot car with
 *4 motors and 3 ultrasonic sensors 
 *to move autonomously in a maze and find the way out*/
 
//defining variables
//motors
int M1=2;
int M2=3;
int M3=4;
int M4=5;
//front ultrasonic
int trig1=6;
int echo1=7;
long duration1;
int distance1;
//right ultrasonic
int trig2=8;
int echo2=9;
long duration2;
int distance2;
//left ultrasonic
int trig3=10;
int echo3=11;
long duration3;
int distance3;

void setup() {
  //setting motors as output
  pinMode(M1,OUTPUT);
  pinMode(M2,OUTPUT);
  pinMode(M3,OUTPUT);
  pinMode(M4,OUTPUT);
  //setting up the ultraonics trigs and echos
  pinMode(trig1,OUTPUT);
  pinMode(echo1,INPUT);

  pinMode(trig2,OUTPUT);
  pinMode(echo2,INPUT);

  pinMode(trig3,OUTPUT);
  pinMode(echo3,INPUT);
}
//functions
//function to make the robot move backwards
void back(){
  digitalWrite(M1,HIGH);
  digitalWrite(M2,LOW);
  digitalWrite(M3,HIGH);
  digitalWrite(M4,LOW);
}
//function to make the robot move forwards
void forward(){
  digitalWrite(M1,LOW);
  digitalWrite(M2,HIGH);
  digitalWrite(M3,LOW);
  digitalWrite(M4,HIGH);
}
//function to make the robot move left
void left(){
  digitalWrite(M1,HIGH);
  digitalWrite(M2,LOW);
  digitalWrite(M3,LOW);
  digitalWrite(M4,HIGH);
}
//function to make the robot move right
void right(){
  digitalWrite(M1,LOW);
  digitalWrite(M2,HIGH);
  digitalWrite(M3,HIGH);
  digitalWrite(M4,LOW);
}
//function to make the robot stop moving
void Stop(){
  digitalWrite(M1,LOW);
  digitalWrite(M2,LOW);
  digitalWrite(M3,LOW);
  digitalWrite(M4,LOW);
}
//ultrasonics functions to calculate the distances
void ultrasonic1 (){
  digitalWrite (trig1,LOW);
  delayMicroseconds (2);
  digitalWrite (trig1,HIGH);
  delayMicroseconds (10);
  digitalWrite (trig1,LOW);

  duration1= pulseIn(echo1,HIGH);
  distance1=duration1/58; //distance = duration*0.034/2;
}
void ultrasonic2 (){
  digitalWrite (trig2,LOW);
  delayMicroseconds (2);
  digitalWrite (trig2,HIGH);
  delayMicroseconds (10);
  digitalWrite (trig2,LOW);

  duration2= pulseIn(echo2,HIGH);
  distance2=duration2/58;
}
  void ultrasonic3 (){
  digitalWrite (trig3,LOW);
  delayMicroseconds (2);
  digitalWrite (trig3,HIGH);
  delayMicroseconds (10);
  digitalWrite (trig3,LOW);

  duration3= pulseIn(echo3,HIGH);
  distance3=duration3/58;
  }

void loop () {
    ultrasonic1 ();
    ultrasonic2 ();
    ultrasonic3 ();
  if (distance1<=30){
    ultrasonic2 ();
    ultrasonic3 ();
    if(distance2>distance3){
      right();
    }
    else if(distance3>distance2){
      left();
    }
  }
  if (distance2<=30){
    ultrasonic1 ();
    ultrasonic3 ();
    if(distance1>distance3){
      forward();
    }
    else if(distance3>distance1){
      left();
    }
    }
  if (distance3<=30){
    ultrasonic2 ();
    ultrasonic1 ();
    if(distance1>distance2){
      forward();
    }
    else if(distance2>distance1){
      right();
    }
  }
}
