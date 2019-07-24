#define onesPin       18
#define tensPin       19  
#define hundredsPin   16  
#define thousandsPin  17 

int current;
void setup() {
  current = 0;
  // put your setup code here, to run once:
  pinMode(thousandsPin, OUTPUT);
  digitalWrite(thousandsPin, HIGH);
  pinMode(hundredsPin, OUTPUT);
  digitalWrite(hundredsPin, HIGH);
  pinMode(onesPin, OUTPUT);
  digitalWrite(onesPin, HIGH);
  pinMode(tensPin, OUTPUT);
  digitalWrite(tensPin, HIGH);
  
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

  
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
}
void loop() {
  
  
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  delay(1000);
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  allOff();
  if(current == 0)
  {
    digitalWrite(thousandsPin, HIGH);
    current++;
  } 
  else if(current == 1)
  {
    digitalWrite(hundredsPin, HIGH);
    current++;
  } 
  else if(current == 2)
  {
    digitalWrite(onesPin, HIGH);
    current++;
  } 
  else if(current == 3)
  {
    digitalWrite(tensPin, HIGH);
    current = 0;
  }
}

void allOff()
{
  digitalWrite(thousandsPin, LOW);
  digitalWrite(hundredsPin, LOW);
  digitalWrite(onesPin, LOW);
  digitalWrite(tensPin, LOW);
  
}
 
