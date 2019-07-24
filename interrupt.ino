
bool flag;
int count;
void setup() {
  Serial.begin(9600);
  flag = false;
  count = 0;
  // put your setup code here, to run once:
  // initialize timer1 
  noInterrupts();           // disable all interrupts
  TCCR1A = 0;
  TCCR1B = 0;

  TCNT1 = 3036;            // preload timer 65536-16MHz/256/2Hz
  TCCR1B |= (1 << CS12);    //  1024prescaler 
  TIMSK1 |= (1 << TOIE1);   // enable timer overflow interrupt
  interrupts();             // enable all interrupts
}
ISR(TIMER1_OVF_vect)        // interrupt service routine that wraps a user defined function supplied by attachInterrupt
{
  TCNT1 = 34286;            // preload timer
  flag = true;
}
void loop() {
  // put your main code here, to run repeatedly:
  if(flag)
  {
    Serial.println(count);
    flag = false;
  }

}
