
void Forward(int power_a,int power_b){
  
  analogWrite(enA, power_a);
  analogWrite(enB, power_b);

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
 
}
void Backward(int power_a,int power_b){

  analogWrite(enA, power_a);
  analogWrite(enB, power_b);

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
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

void Left(int power,int diff){
  
  analogWrite(enA, power);
  analogWrite(enB, power-diff);
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void Right(int power,int diff){
  
  analogWrite(enA, power-diff);
  analogWrite(enB, power);
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void ReverseLeft(int power,int diff){
  
  analogWrite(enA, power);
  analogWrite(enB, power-diff);

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void ReverseRight(int power,int diff){
  
  analogWrite(enA, power-diff);
  analogWrite(enB, power);

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void Stop(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
