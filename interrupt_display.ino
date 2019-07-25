/*
 * This code has a one second timer using
 * the bool variable flag to indicate one
 * second has elapsed, and will continue
 * to do so.
 * 
 * It uses PORTB and PORTC for the display.
 * Select pins are 2, 3, 4, 5
 * 
 * TODO: Put lower nibble in PORTB and
 * upper nibble in PORTC
 * TODO: Add method for pulsing character
 */





#define selectA       2
#define selectB       3  
#define selectC       4  
#define selectD       5

char characters[16]= {              //0 is light on, 1 is light off
                        0b00000011, //0
                        0b10011111, //1
                        0b00100101, //2
                        0b00001101, //3
                        0b10011001, //4
                        0b01001001, //5
                        0b01000001, //6
                        0b00011111, //7
                        0b00000001, //8
                        0b00011001, //9
                        0b00010001, //A
                        0b11000001, //B
                        0b01100011, //C
                        0b10000101, //D
                        0b01100001, //E
                        0b01110001  //F
                        };

char LEDs[] = { selectA, selectB, selectC, selectD };






bool flag;
int count;
void setup() {
  Serial.begin(9600);
  flag = false;
  count = 0;

  initTimer();
  initPorts();
  initSelectPins();
}
void loop() {
  // put your main code here, to run repeatedly:
  if(flag)
  {
    Serial.println(count);
    flag = false;
    count++;
  }
  
}


ISR(TIMER1_OVF_vect)        // interrupt service routine that wraps a user defined function supplied by attachInterrupt
{
  TCNT1 = 3036;            // preload timer
  flag = true;
}
void initTimer()
{
    // initialize timer1 
  noInterrupts();           // disable all interrupts
  TCCR1A = 0;
  TCCR1B = 0;

  TCNT1 = 3036;            // preload timer 65536-16MHz/256/2Hz
  TCCR1B |= (1 << CS12);    //  1024prescaler 
  TIMSK1 |= (1 << TOIE1);   // enable timer overflow interrupt
  interrupts();             // enable all interrupts

}
void initPorts()
{
  DDRB = 255;
  DDRC = 255;

  PORTB = 0;
  PORTC = 0;
}
void initSelectPins()
{
  pinMode(selectA, OUTPUT);
  digitalWrite(selectA, HIGH);
}
