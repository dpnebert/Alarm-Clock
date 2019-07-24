#define onesPin       19
#define tensPin       18  
#define hundredsPin   16  
#define thousandsPin  17 
bool hex;




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
int ones; //time integer, seconds place
int tens; //time integer, tens place
void setup() {

  Serial.begin(9600);
  Serial.print("Hello, "); //for debugging
  Serial.println("World");
  
  hex = true;
  ones = 0;
  tens = 0;
  // put your setup code here, to run once:
  pinMode(thousandsPin, OUTPUT);
  digitalWrite(thousandsPin, LOW);
  pinMode(hundredsPin, OUTPUT);
  digitalWrite(hundredsPin, LOW);
  pinMode(onesPin, OUTPUT);
  digitalWrite(onesPin, LOW);
  pinMode(tensPin, OUTPUT);
  digitalWrite(tensPin, LOW);
  
  DDRD = 255; //sets data direction register D to be an output
  PORTD = 255; //when port D is 0 lights are on. 255 lights off
}
void loop() {
  
  digitalWrite(onesPin, HIGH);
  digitalWrite(tensPin, HIGH);
  
  delay(1000);

  // Moves the value of the ones element
  // 
  displayCharacter(characters[ones]);
  
  if(ones == 9)
  {
    ones = 0;
    tens++;
  }
  else
  {
    ones++;
  }  
}
void displayCharacter(char c) {
  PORTD = c;
}
