#define echo 11 //echo
#define trig 12 //trig
#define MR1 7 //Right motor 1
#define MR2 6 //2 
#define RE 9  // enable 
#define ML1 5 // Left motor 
#define ML2 4
#define LE 3

long tme, range; 

void setup() {
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);

  pinMode(ML1, OUTPUT);
  pinMode(ML2, OUTPUT);
  pinMode(LE, OUTPUT); 
  pinMode(MR1, OUTPUT);
  pinMode(MR2, OUTPUT);
  pinMode(RE, OUTPUT);


  Serial.begin(9600);

}

void loop() {


  digitalWrite(trig, LOW); 
  delayMicroseconds(5);
  digitalWrite(trig, HIGH); 
  delayMicroseconds(8);
  digitalWrite(trig, LOW); 

  tme = pulseIn(echo, HIGH); 
  range = tme / 29.1 / 2; 
  Serial.println(range);

  if (range < 8) // range <8
  {
    back();  
    delay(150);
    right();  
    delay(250);
  }
  else {  
    forward(); 
  }

}



void forward(){  

  digitalWrite(MR1, HIGH); 
  digitalWrite(MR2, LOW); 
  analogWrite(RE, 200); 

  digitalWrite(ML1, HIGH); 
  digitalWrite(ML2, LOW); 
  analogWrite(LE, 200); 
  
  
}


void right(){ 

  digitalWrite(MR1, HIGH); 
  digitalWrite(MR2, LOW); 
  analogWrite(RE, 0); // right motor signal 0 stopped

  digitalWrite(ML1, HIGH); 
  digitalWrite(ML2, LOW); 
  analogWrite(LE, 150); // left motor signal
  
  
}


void back(){ 

  digitalWrite(MR1, LOW); 
  digitalWrite(MR2, HIGH); 
  analogWrite(RE, 150); // pwm signal

  digitalWrite(ML1, LOW); 
  digitalWrite(ML2, HIGH); 
  analogWrite(LE, 150); // pwm signal
  
}
