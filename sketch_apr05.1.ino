#include <Keypad.h>
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
}
void loop()
{
  char key = keypad.getKey();
  if (key != NO_KEY)
  {
    Serial.println(key);
  }
}
