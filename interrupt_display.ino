/*
 * This code has a one second timer using
 * the bool variable flag to indicate one
 * second has elapsed, and will continue
 * to do so.
 * 
 * It uses PORTB and PORTC for the display.
 * Four bits to the lower nibble of PORTB and
 * four bits to the lower nibble of PORTC
 * Select pins are 2, 3, 4, 5
 * 
 */
// Can't be used with buttons
//#define timerClock    6
#define selectA       5
#define selectB       4  
#define selectC       3  
#define selectD       2

#define inputPinA     6
#define inputPinB     7

/*            A
 *          F   B
 *            G
 *          E   C
 *            D
 *                Dp
 *          
 *          
 *          
 *          
 *         8  7654321 
 *      0b(Dp)GFEDCBA
 *      
 *      MUST MAKE BIT ZERO
 *      TO TURN ON LED.
 */

// Setting constant for one second
// Doing math on this number can give
// you any timer delay you want
//
// The timer delay is calculated using
// the speed of the microcontroller
// and the programmed prescaler.
// To get more precision or ability
// for longer delays, modify formula:
// 3036 = 65536 - (16MHz/256/1Hz)
// http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf
const uint8_t tcnt_one_second = 3036;


                          //   D
                          //   pGFEDCBA
const char characters[16]= { 0b01000000, //0
                             0b01111001, //1
                             0b00100100, //2
                             0b00110000, //3
                             0b00011001, //4
                             0b00010010, //5
                             0b00000010, //6
                             0b01111000, //7
                             0b00000000, //8
                             0b00011000, //9
                             0b00001000, //A
                             0b00000011, //B
                             0b01000110, //C
                             0b00100001, //D
                             0b00000110, //E
                             0b00001110  //F
                           };
                       
const char displays[] = { selectA,
                          selectB,
                          selectC,
                          selectD };

const char inputButtons[] = { inputPinA, inputPinB };
                          
const int Timer_one_second = 3036;
int tick_rate;
int delay_ms;
bool flag;
int radixCeiling;
int ones;
bool onesDecimal;
int tens;
int hundreds;
int thousands;
int incrementDir;
bool counting;
void loop() {  
  
  updatePortValues(characters[ones]);
  pulseSelectLine(selectD);
    
  updatePortValues(characters[tens]);
  pulseSelectLine(selectC);  
  
  updatePortValues(characters[hundreds]);
  pulseSelectLine(selectB);  

  if(thousands != 0)
  {
    updatePortValues(characters[thousands]);
    pulseSelectLine(selectA);
  }
  

  if(flag)
  { 
    // toggle pin for scope to see
    // the timer's clock
    PORTD ^= 0b01000000; 
    
    flag = false;
    if(counting == true && incrementDir = 1)
    {
      incrementDisplay(&ones, &tens, &hundreds, &thousands);    
    }
  }
}

















void incrementDisplay(int *ones, int *tens, int *hundreds, int *thousands)
{
  if(ones == radixCeiling)
    {
      ones = 0;
      tens++;
    }
    else
    {
      ones++;
    }
    if(tens == radixCeiling)
    {
      tens = 0;
      hundreds++;
    }
    if(hundreds == radixCeiling)
    {
      hundreds = 0;
      thousands++;
    }
    if(thousands == radixCeiling)
    {
      thousands = 0;
    }
}


// ALL THE CODE BELOW HERE IS SETUP
//
// PLEASE DON'T CHANGE ANYTHING
// 
// Just read the comments

// Setup look to call all the initialization methods
void setup() {
  Serial.begin(9600);
  
  tick_rate = Timer_one_second;
  
  radixCeiling = 15;
  delay_ms = 3;
  flag = false;
  ones = 0;
  onesDecimal = true;
  tens = 0;
  hundreds = 0;
  thousands = 0;
  incrementDir = 1;
  counting = true;

  //pinMode(timerClock, OUTPUT);
  //digitalWrite(timerClock, LOW);
  
  initTimer();
  initPorts();
  initSelectPins();  
  initButtons();
}



// Turn the pin 'select' HIGH for the
// delay_ms length of time, then 
// turns 'select' back to LOW
//
void pulseSelectLine(int select)
{
  digitalWrite(select, HIGH);
  delay(delay_ms);
  digitalWrite(select, LOW);
}

// We give it eight bits, and this
// method reads the lower half into
// PORTB, and the upper in to PORTC
void updatePortValues(char character)
{  
  PORTB = character & 0b00001111; // lower
  PORTC = (character >> 4); // uppper
}


ISR(TIMER1_OVF_vect)        // interrupt service routine that wraps a user defined function supplied by attachInterrupt
{
  TCNT1 = tick_rate;            // preload timer
  flag = true;
}
void initTimer()
{
  // http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf
  char cSREG;
  cSREG = SREG; /* store SREG value */
  cli();                    // disable all interrupts
  SREG = cSREG; /* restore SREG value (I-bit) */
    
  TCCR1A = 0;               // Zero out the timer control
  TCCR1B = 0;               // registers

  TCNT1 = tick_rate;             // preload timer 65536-16MHz/256/1Hz
  TCCR1B |= (1 << CS12);    // 256 prescaler 
  TIMSK1 |= (1 << TOIE1);   // enable timer overflow interrupt
  sei();                    // enable all interrupts

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
  digitalWrite(selectD, LOW);
  pinMode(selectC, OUTPUT);
  digitalWrite(selectC, LOW);
  pinMode(selectB, OUTPUT);
  digitalWrite(selectB, LOW);
  pinMode(selectA, OUTPUT);
  digitalWrite(selectA, LOW);
}
void initButtons()
{
  pinMode(inputButtons[0], OUTPUT);
  digitalWrite(inputButtons[0], LOW);
  pinMode(inputButtons[1], OUTPUT);
  digitalWrite(inputButtons[1], LOW);
}
