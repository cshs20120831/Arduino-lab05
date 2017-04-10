#include <Keypad.h>
#include "SevSeg.h"
SevSeg sevseg;
const byte ROWS = 4; // 4 Rows
const byte COLS = 4; // 4 Columns
char keys[ROWS][COLS] = 
{
  {'0', '1', '2', '3'}, {'4','5','6', '7'},
  {'8', '9', 'A', 'B'}, {'C', 'D', 'E', 'F'}
};
byte rowPins[ROWS] = {5, 4, 3, 2};
byte colPins[COLS] = {9, 8, 7, 6};
Keypad keypad = Keypad( makeKeymap(keys), rowPins,colPins, ROWS, COLS );
void setup() 
{
  Serial.begin(9600); 
  byte numDigits = 1;
  byte digitPins[] = {A2};
  byte segmentPins[] = {11, 10, A3, A1, A0, 12, 13, A4};
  sevseg.begin(COMMON_CATHODE, numDigits, digitPins,segmentPins);
}
void loop()
{
  char key;
  key = keypad.getKey();

  int a;
 
  if (key != NO_KEY)
  {
    if(key >='A' && key <='F')
     {
      a = key-'A';
      } 
    else
    {
      a = key-'0';
      }
    Serial.println(key);
    sevseg.setNumber(a,1);
    sevseg.refreshDisplay();
  
  }
  else
  {
    sevseg.refreshDisplay();

    
  }



}
