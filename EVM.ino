#include <Adafruit_LiquidCrystal.h>

const int C1_BUTTON = A0;
const int C2_BUTTON = A1;
const int CONFIRM_BUTTON = A2;
const int CANCEL_BUTTON = A3;

int c1_count = 0;
int c2_count = 0;

Adafruit_LiquidCrystal lcd_1(0);

void setup()
{
  lcd_1.begin(16, 2);

  pinMode(C1_BUTTON, INPUT_PULLUP);
  pinMode(C2_BUTTON, INPUT_PULLUP);
  pinMode(CONFIRM_BUTTON, INPUT_PULLUP);
  pinMode(CANCEL_BUTTON, INPUT_PULLUP);

  printCount();
}

void loop()
{
  if (digitalRead(C1_BUTTON) == LOW)
  {
    while (digitalRead(C1_BUTTON) == LOW);   //debounce
    delay(20);

    confirmVote(1);
  }

  else if (digitalRead(C2_BUTTON) == LOW)
  {
    while (digitalRead(C2_BUTTON) == LOW);
    delay(20);

    confirmVote(2);
  }
}

void confirmVote(int candidate)
{
  lcd_1.clear();
  lcd_1.setCursor(0,0);
  lcd_1.print("Candidate ");
  lcd_1.print(candidate);

  lcd_1.setCursor(0,1);
  lcd_1.print("YES=A2  NO=A3");

  while (true)
  {
    if (digitalRead(CONFIRM_BUTTON) == LOW)
    {
      while (digitalRead(CONFIRM_BUTTON) == LOW);
      delay(20);

      if (candidate == 1)
        c1_count++;
      else
        c2_count++;

      lcd_1.clear();
      lcd_1.setCursor(0,0);
      lcd_1.print("Vote Recorded");

      delay(2000);

      printCount();
      return;
    }

    if (digitalRead(CANCEL_BUTTON) == LOW)
    {
      while (digitalRead(CANCEL_BUTTON) == LOW);
      delay(20);

      lcd_1.clear();
      lcd_1.setCursor(0,0);
      lcd_1.print("Vote Cancelled");

      delay(2000);

      printCount();
      return;
    }
  }
}

void printCount()
{
  lcd_1.clear();

  lcd_1.setCursor(0,0);
  lcd_1.print("EVM");

  lcd_1.setCursor(0,1);
  lcd_1.print("C1:");
  lcd_1.print(c1_count);
  
  lcd_1.setCursor(8,1);
  lcd_1.print("C2:");
  lcd_1.print(c2_count);

  lcd_1.setBacklight(1);
}