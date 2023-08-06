// Motor A connections
int enA = 10;
int in1 = 7;
int in2 = 6;
// Motor B connections
int enB = 9;
int in3 = 5;
int in4 = 4;

void setup() {
  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  // Turn off motors - Initial state
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  Serial.begin(115200); //9600 for hc05
}

void loop() {
 
 if(Serial.available()){
    int state = Serial.read();
    Serial.println(state);
    switch (state){
      case 83:  //Stop
        Stop();
        break;
      case 70:  //Forward
        Forward(255,255);
        break;
      case 66:  //Backward
        Backward(255,255);
        break;
      case 71:  //Left
        Left(100);
        break;
      case 73:  //Right
        Right(100);
        break;
      case 72:  //ReverseLeft
        ReverseLeft(100);
        break;
      case 74:  //ReverseRight
        ReverseRight(100);
        break;
      case 76:  //SharpLeft
        SharpLeft(255,255);
        break;
      case 82:  //SharpRight
        SharpRight(255,255);
        break;
      
        
    }
    
    
 }
}
