  // connect motor controller pins to Arduino digital pins
// motor one
int enA = 9;
int in1 = 8;
int in2 = 7;
// motor two
int enB = 3;
int in3 = 2;
int in4 = 4;
void setup() {
  Serial.begin(9600); 
 // set all the motor control pins to outputs
 pinMode (enA, OUTPUT);
pinMode (in1, OUTPUT);
pinMode (in2, OUTPUT);
pinMode (enB, OUTPUT);
pinMode (in3, OUTPUT);
pinMode (in4, OUTPUT);
}
boolean midOnLine() {
  return (analogRead(A4) < 150);
}
boolean leftOnLine() {
  return (analogRead(A2)  > 150);
 }
boolean WleftOnLine(){
  return (analogRead(A3)  > 150);
 }
boolean rightOnLine() {
  return (analogRead(A0) > 150);
 }
boolean WrightOnLine(){
  return (analogRead(A1) > 150);
 }
   
void loop() {
//Serial.println(analogRead(A0));
//Serial.println((analogRead(A0)  < 30));
//Serial.println(digitalRead(A0));
Serial.println(analogRead(A4));
delay(100);

Serial.println();
   if (rightOnLine()) 
   Serial.println("1R");
   
   else 
   
   Serial.println("0R");
   delay(10); 

   if (leftOnLine()) 
   Serial.println("1L"); 
   else 
   Serial.println("0L");
   delay(10);

 //if (midOnLine()) 
 //{
  //digitalWrite(in3, LOW);
  //digitalWrite(in4, LOW);
  //analogWrite(enA, 80);
  //delay(100);
 //}
  //else{
    //digitalWrite(in3, LOW);
  //digitalWrite(in4, LOW);
  //analogWrite(enA, 80);
  //delay(50);
  //}

    if  (leftOnLine())
  {  
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(enA, 100);

     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, 60);
  
 delay(50);  
    }
    
     else {
     
     digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
   analogWrite(enA,100);
    
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enB, 100);

    delay(50);
    
    }

  if (WleftOnLine()) 
  {
   digitalWrite(in1, HIGH);
     digitalWrite(in2, LOW);
     analogWrite(enA, 60);
  }
    if  (rightOnLine())
  {  
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(enA, 0);

     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, 0);
  
 //delay(50);
    }
    
     else {
     
     digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(enA, 100);
    
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enB, 100);
    
    }

    if (WrightOnLine()){
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(enA, 0);

    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enB, 60);
  }
}
