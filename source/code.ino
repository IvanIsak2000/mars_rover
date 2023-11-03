#define in1 5 //L298n Motor Driver pins.
#define in2 6
#define in3 10
#define in4 11
#define LED 13

int front_light = 2 ;
int back_light = 3;
int conn_light = 4;

int command;
int HighSpeed = 240; // 0 - 255.
int LowSpeed = 200;
void setup(){
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(front_light, OUTPUT);
  pinMode(back_light, OUTPUT);
  pinMode(conn_light, OUTPUT);  
  Serial.begin(9600);  
}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.read();
    Connected(); 
    Stop();
    switch (command) {
      case 'B':
        forward();
        break;
        
      case 'F':
        back();
        break;
        
      case 'L':
        left();
        break;
        
      case 'R':
        right();
        break;
        
      case 'A' :
        FrontLight();
        break;
        
      case 'V':
        BackLight();
        break;

      case 's' :
        Stop();
        break;    
    }
  }
}

void forward() {
  analogWrite(in1, HighSpeed);
  analogWrite(in3, HighSpeed);
  delay(250);
  Stop();
}

void back() {
  analogWrite(in2, HighSpeed);
  analogWrite(in4, HighSpeed);
  delay(250);
  Stop();

}

void left() {
  analogWrite(in3,LowSpeed);
  analogWrite(in2,LowSpeed);
  delay(250);
  Stop();
}

void right() {
  analogWrite(in4,LowSpeed);
  analogWrite(in1,LowSpeed);
  delay(250);
  Stop();
 
}

void Stop() {
  analogWrite(in1, 0);
  analogWrite(in2, 0);
  analogWrite(in3, 0);
  analogWrite(in4, 0);
}


void FrontLight(){
  digitalWrite(front_light, HIGH);
  delay(500);
  digitalWrite(front_light, LOW);
}

void BackLight(){
  digitalWrite(back_light, HIGH);
  delay(500);
  digitalWrite(back_light, LOW);
}

void Connected(){
  digitalWrite(conn_light, HIGH);
  delay(100);
  digitalWrite(conn_light, LOW);
  
 }

  
