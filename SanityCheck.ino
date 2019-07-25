void setup() {
  // put your setup code here, to run once:
  pinMode(16, OUTPUT);
  digitalWrite(16, HIGH);
  pinMode(17, OUTPUT);
  digitalWrite(17, HIGH);
  pinMode(18, OUTPUT);
  digitalWrite(18, HIGH);
  pinMode(19, OUTPUT);
  digitalWrite(19, HIGH);
  
  DDRD = 255;
  PORTD = 0;
}

void loop() {
  // put your main code here, to run repeatedly:

}
