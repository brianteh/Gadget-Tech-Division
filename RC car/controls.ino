
void Forward(int power_a,int power_b){
  
  analogWrite(enA, power_a);
  analogWrite(enB, power_b);
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void Backward(int power_a,int power_b){

  analogWrite(enA, power_a);
  analogWrite(enB, power_b);

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void SharpRight(int power_a,int power_b){

  analogWrite(enA, power_a);
  analogWrite(enB, power_b);
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void SharpLeft(int power_a,int power_b){

  analogWrite(enA, power_a);
  analogWrite(enB, power_b);
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void Left(int diff){
  
  analogWrite(enA, 255-diff);
  analogWrite(enB, 255);
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void Right(int diff){
  
  analogWrite(enA, 255);
  analogWrite(enB, 255-diff);
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void ReverseLeft(int diff){
  
  analogWrite(enA, 255-diff);
  analogWrite(enB, 255);

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void ReverseRight(int diff){
  
  analogWrite(enA, 255);
  analogWrite(enB, 255-diff);

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void Stop(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
