

int L1 = 2;   // most left digit
int L2 = 3;
int L3 = 4;
int L4 = 5;

int A = 6;    //Segment A
int B = 7;
int C = 8;
int D = 9;
int E = 10;
int F = 11;
int G = 12;
int DP = 13;

int delaytime = 1;


void pickL(int L)     // function to set all digits to off and then turn on the ones according to the numbers we enter.
{

  digitalWrite(L1, LOW); //turining all digits off
  digitalWrite(L2, LOW);
  digitalWrite(L3, LOW);
  digitalWrite(L4, LOW);


  switch (L)
  {
    case 1: digitalWrite(L1, HIGH); break;  //Turning most left digit on
    case 2: digitalWrite(L2, HIGH); break;  //Turning second left digit on
    case 3: digitalWrite(L3, HIGH); break;  //Turning tihird left digit on
    default: digitalWrite(L4, HIGH); break; //Turning most right digit on


  }
}

void pickDigit(char digit)    //function to takes in a digit and turn on segments according to the number
{
  switch (digit)
  {
    case 0:
      digitalWrite(A, LOW);   // Turning segment A on
      digitalWrite(B, LOW);   // Turning segment B on
      digitalWrite(C, LOW);   // Turning segment C on
      digitalWrite(D, LOW);   // Turning segment D on
      digitalWrite(E, LOW);   // Turning segment E on
      digitalWrite(F, LOW);   // Turning segment F on
      digitalWrite(G, HIGH);  // Turning segment G OFF
      digitalWrite(DP, HIGH);  // Turning segment DP OFF
      break;

    case 1:
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      digitalWrite(DP, HIGH);  // Turning segment DP OFF
      break;

    case 2:
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      digitalWrite(E, LOW);
      digitalWrite(F, HIGH);
      digitalWrite(G, LOW);
      digitalWrite(DP, HIGH);  // Turning segment DP OFF
      break;

    case 3:
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, LOW);
      digitalWrite(DP, HIGH);  // Turning segment DP OFF
      break;

    case 4:
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, LOW);
      digitalWrite(G, LOW);
      digitalWrite(DP, HIGH);  // Turning segment DP OFF
      break;

    case 5:
      digitalWrite(A, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      digitalWrite(E, HIGH);
      digitalWrite(F, LOW);
      digitalWrite(G, LOW);
      digitalWrite(DP, HIGH);  // Turning segment DP OFF
      break;

    case 6:
      digitalWrite(A, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      digitalWrite(E, LOW);
      digitalWrite(F, LOW);
      digitalWrite(G, LOW);
      digitalWrite(DP, HIGH);  // Turning segment DP OFF
      break;

    case 7:
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      digitalWrite(DP, HIGH);
      break;

    case 8:
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      digitalWrite(E, LOW);
      digitalWrite(F, LOW);
      digitalWrite(G, LOW);
      digitalWrite(DP, HIGH);
      break;

    case 9:
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      digitalWrite(E, HIGH);
      digitalWrite(F, LOW);
      digitalWrite(G, LOW);
      digitalWrite(DP, HIGH);
      break;

    default:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, LOW);
      digitalWrite(DP, HIGH);
      break;
  }
}

void display4digits(int number) //seperating the 4 digit number into 4 seperate numbers and assign them to the variable
{
  unsigned int thousands = number / 1000;           //seperating the thousands digit
  unsigned int hundreds = (number / 100) % 10;      //seperating the hundrends digit
  unsigned int tens = (number / 10) % 10;           //seperating the tens digit
  unsigned int ones = number % 10;                  //seperating the ones digit


  pickDigit(thousands);             //calling the the function that turns on the segments to display the correct number
  if (thousands < 1);
  else
    pickL(1);                          // turning on the 7segment for the thousands number
  delay(delaytime);

  pickDigit(hundreds);
  if (hundreds < 1 && thousands < 1);
  else
    pickL(2);
  delay(delaytime);

  pickDigit(tens);
  if (tens < 1 && hundreds < 1 && thousands < 1);
  else
    pickL(3);
  delay(delaytime);

  pickDigit(ones);
  pickL(4);
  delay(delaytime);
}


void setup()
{
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(L4, OUTPUT);

  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(DP, OUTPUT);

  Serial.begin(9600);

}


void loop()
{
  int x;

  while (x >= 0)
  {
    // delay(1000);
    display4digits(x);   //calling the function the separates the 4 digit number
    // x--;
  }

}
