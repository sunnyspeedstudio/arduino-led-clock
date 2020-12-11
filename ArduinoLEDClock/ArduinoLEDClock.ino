
#include <ThreeWire.h>
#include <RtcDS1302.h>

ThreeWire myWire(9, 10, 11); // DAT/IO, CLK/SCLK, RST/CE
RtcDS1302<ThreeWire> Rtc(myWire); // RTC used: DS1302, you may have a different one

// Please use the wiring diagram in the same repo
// https://github.com/sunnyspeedstudio/arduino-led-clock

// Understand variable names
// hour and minute
// h1: first digit of the hour
// h2: second digit of the hour
// m1: first digit of the minute
// m2: second digit of the minute
// positions for each digit
// l1: left top position
// l2: left bottom position
// c1: center top position
// c2: center middle position
// c3: center bottom position
// r1: right top position
// r2: right bottom position

// Arduino Mega 2560
int h1l1 = 53;
int h1l2 = 52;
int h1c1 = 51;
int h1c2 = 50;
int h1c3 = 49;
int h1r1 = 48;
int h1r2 = 47;

int h2l1 = 46;
int h2l2 = 45;
int h2c1 = 44;
int h2c2 = 43;
int h2c3 = 42;
int h2r1 = 41;
int h2r2 = 40;

int m1l1 = 39;
int m1l2 = 38;
int m1c1 = 37;
int m1c2 = 36;
int m1c3 = 35;
int m1r1 = 34;
int m1r2 = 33;

int m2l1 = 32;
int m2l2 = 31;
int m2c1 = 30;
int m2c2 = 29;
int m2c3 = 28;
int m2r1 = 27;
int m2r2 = 26;

int dot1 = 25;
int dot2 = 24;

void setup ()
{
  Serial.begin(9600);
  
  pinMode(h1l1, OUTPUT);
  pinMode(h1l2, OUTPUT);
  pinMode(h1c1, OUTPUT);
  pinMode(h1c2, OUTPUT);
  pinMode(h1c3, OUTPUT);
  pinMode(h1r1, OUTPUT);
  pinMode(h1r2, OUTPUT);

  pinMode(h2l1, OUTPUT);
  pinMode(h2l2, OUTPUT);
  pinMode(h2c1, OUTPUT);
  pinMode(h2c2, OUTPUT);
  pinMode(h2c3, OUTPUT);
  pinMode(h2r1, OUTPUT);
  pinMode(h2r2, OUTPUT);

  pinMode(m1l1, OUTPUT);
  pinMode(m1l2, OUTPUT);
  pinMode(m1c1, OUTPUT);
  pinMode(m1c2, OUTPUT);
  pinMode(m1c3, OUTPUT);
  pinMode(m1r1, OUTPUT);
  pinMode(m1r2, OUTPUT);

  pinMode(m2l1, OUTPUT);
  pinMode(m2l2, OUTPUT);
  pinMode(m2c1, OUTPUT);
  pinMode(m2c2, OUTPUT);
  pinMode(m2c3, OUTPUT);
  pinMode(m2r1, OUTPUT);
  pinMode(m2r2, OUTPUT);
  
  pinMode(dot1, OUTPUT);
  pinMode(dot2, OUTPUT);
}

void loop ()
{
  printTime(Rtc.GetDateTime());
  delay(1000);
}

void printTime(const RtcDateTime& dt)
{
  // dt.Hour()
  // dt.Minute()
  // dt.Second()
  Serial.println(dt.Minute());
  Serial.println(dt.Second());
  printDigit(dt.Hour() / 10, h1l1, h1l2, h1c1, h1c2, h1c3, h1r1, h1r2);
  printDigit(dt.Hour() % 10, h2l1, h2l2, h2c1, h2c2, h2c3, h2r1, h2r2);
  printDigit(dt.Minute() / 10, m1l1, m1l2, m1c1, m1c2, m1c3, m1r1, m1r2);
  printDigit(dt.Minute() % 10, m2l1, m2l2, m2c1, m2c2, m2c3, m2r1, m2r2);
  printDots(dt.Second() % 10);
}

void printDots(int x)
{
  if (x % 2 == 0)
  {
    digitalWrite(dot1, HIGH);
    digitalWrite(dot2, HIGH);
  }
  else
  {
    digitalWrite(dot1, LOW);
    digitalWrite(dot2, LOW);
  }
}

void printDigit(int x, int l1, int l2, int c1, int c2, int c3, int r1, int r2)
{
  switch (x)
  {
    case 0:
      digitalWrite(l1, HIGH);
      digitalWrite(l2, HIGH);
      digitalWrite(c1, HIGH);
      digitalWrite(c2, LOW);
      digitalWrite(c3, HIGH);
      digitalWrite(r1, HIGH);
      digitalWrite(r2, HIGH);
      break;
    case 1:
      digitalWrite(l1, LOW);
      digitalWrite(l2, LOW);
      digitalWrite(c1, LOW);
      digitalWrite(c2, LOW);
      digitalWrite(c3, LOW);
      digitalWrite(r1, HIGH);
      digitalWrite(r2, HIGH);
      break;
    case 2:
      digitalWrite(l1, LOW);
      digitalWrite(l2, HIGH);
      digitalWrite(c1, HIGH);
      digitalWrite(c2, HIGH);
      digitalWrite(c3, HIGH);
      digitalWrite(r1, HIGH);
      digitalWrite(r2, LOW);
      break;
    case 3:
      digitalWrite(l1, LOW);
      digitalWrite(l2, LOW);
      digitalWrite(c1, HIGH);
      digitalWrite(c2, HIGH);
      digitalWrite(c3, HIGH);
      digitalWrite(r1, HIGH);
      digitalWrite(r2, HIGH);
      break;
    case 4:
      digitalWrite(l1, HIGH);
      digitalWrite(l2, LOW);
      digitalWrite(c1, LOW);
      digitalWrite(c2, HIGH);
      digitalWrite(c3, LOW);
      digitalWrite(r1, HIGH);
      digitalWrite(r2, HIGH);
      break;
    case 5:
      digitalWrite(l1, HIGH);
      digitalWrite(l2, LOW);
      digitalWrite(c1, HIGH);
      digitalWrite(c2, HIGH);
      digitalWrite(c3, HIGH);
      digitalWrite(r1, LOW);
      digitalWrite(r2, HIGH);
      break;
    case 6:
      digitalWrite(l1, HIGH);
      digitalWrite(l2, HIGH);
      digitalWrite(c1, HIGH);
      digitalWrite(c2, HIGH);
      digitalWrite(c3, HIGH);
      digitalWrite(r1, LOW);
      digitalWrite(r2, HIGH);
      break;
    case 7:
      digitalWrite(l1, LOW);
      digitalWrite(l2, LOW);
      digitalWrite(c1, HIGH);
      digitalWrite(c2, LOW);
      digitalWrite(c3, LOW);
      digitalWrite(r1, HIGH);
      digitalWrite(r2, HIGH);
      break;
    case 8:
      digitalWrite(l1, HIGH);
      digitalWrite(l2, HIGH);
      digitalWrite(c1, HIGH);
      digitalWrite(c2, HIGH);
      digitalWrite(c3, HIGH);
      digitalWrite(r1, HIGH);
      digitalWrite(r2, HIGH);
      break;
    case 9:
      digitalWrite(l1, HIGH);
      digitalWrite(l2, LOW);
      digitalWrite(c1, HIGH);
      digitalWrite(c2, HIGH);
      digitalWrite(c3, HIGH);
      digitalWrite(r1, HIGH);
      digitalWrite(r2, HIGH);
      break;
    default:
      digitalWrite(l1, LOW);
      digitalWrite(l2, LOW);
      digitalWrite(c1, LOW);
      digitalWrite(c2, LOW);
      digitalWrite(c3, LOW);
      digitalWrite(r1, LOW);
      digitalWrite(r2, LOW);
      break;
  }
}
