/*
 * This code has a one second timer using
 * the bool variable flag to indicate one
 * second has elapsed, and will continue
 * to do so.
 * 
 * It uses PORTB and PORTC for the display.
 * Select pins are 2, 3, 4, 5
 * 
 */





#define selectA       5
#define selectB       4  
#define selectC       3  
#define selectD       2

/*            A
 *          F   B
 *            G
 *          E   C
 *            D
 *                Dp
 *          
 *         8  7654321 
 *      0b(Dp)GFEDCBA
 *      
 *      MUST MAKE BIT ZERO
 *      TO TURN ON LED.
 * 
 *
 */
char characters[16]= { //    GFEDCBA
                          0b11000000, //0
                          0b11111001, //1
                          0b10100100, //2
                          0b10110000, //3
                          0b10011001, //4
                          0b10010010, //5
                          0b10000010, //6
                          0b11111000, //7
                          0b10000000, //8
                          0b10011000, //9
                          0b10001000, //A
                          0b10000011, //B
                          0b11000110, //C
                          0b10100001, //D
                          0b10000110, //E
                          0b10001110, //F
                       };

char displays[] = { selectA, selectB, selectC, selectD };






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
  if(flag)
  {    
    flag = false;
    updatePortValues(characters[count]);
    
    //if incrementing....
    if(count == 15)
    {
      count = 0;
    }
    else
    {
      count++;
    }
  }

  // This happens ever loop, and all it does it tell
  // which select pin to turn on and then waits
  // for the delay (second parameter) length of time
  // before turn off the select pin.  When adding
  // more select pins, we just need to track their
  // values above in the if(flag) block, and add
  // a method call below to do that position after
  // the ones  
  pulseCharacterToSelectLEDs(displays[3], 1);
}













// ALL THE CODE BELOW HERE IS SETUP
//
// PLEASE DON'T CHANGE ANYTHING
// 
// Just read the comments

// Turn the pin 'select' HIGH for the
// delay_ms length of time, then 
// turns 'select' back to LOW
//
void pulseCharacterToSelectLEDs(int select, int delay_ms)
{
  digitalWrite(select, HIGH);
  delay(delay_ms);
  digitalWrite(select, LOW);
  
}

// We give it eight bits, and this
// method reads the lower half into
// PORTB, and the upper in to PORTC
//
void updatePortValues(char character)
{  
  PORTB = character & 0b00001111; // lower
  PORTC = (character >> 4); // uppper
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

  TCNT1 = 3036;            // preload timer 65536-16MHz/256/1Hz
  TCCR1B |= (1 << CS12);    //  1024prescaler 
  TIMSK1 |= (1 << TOIE1);   // enable timer overflow interrupt
  interrupts();             // enable all interrupts

}
void initPorts()
{
  DDRB = 255;
  DDRC = 255;

  PORTB = 255;
  PORTC = 255;
}
void initSelectPins()
{
  pinMode(selectD, OUTPUT);
  digitalWrite(selectD, HIGH);
}
