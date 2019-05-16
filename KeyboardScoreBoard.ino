#include "Keyboard.h"

#define NBR_TCH 11
int myPins[NBR_TCH] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

#define B_RED_Bottom      0
#define B_WHITE_Bottom    1
#define B_BLACK           2
#define B_BLUE            3
#define B_RED_Left        4
#define B_GREEN_Left      5
#define B_GREEN_Right     6
#define B_RED_Right       7
#define B_YELLOW_Left     8
#define B_WHITE_Top       9
#define B_YELLOW_Right    10

#define K_NUMPAD_1        225
#define K_NUMPAD_2        226
#define K_NUMPAD_3        227
#define K_NUMPAD_4        228
#define K_NUMPAD_5        229
#define K_NUMPAD_6        230
#define K_NUMPAD_7        231
#define K_NUMPAD_8        232
#define K_NUMPAD_9        233
#define K_NUMPAD_0        234
  
int buttonState[NBR_TCH];
int previousButtonState[NBR_TCH];

void setup() {
  for (int i = 0; i <= NBR_TCH; i++) {
    pinMode(myPins[i], INPUT_PULLUP);
    buttonState[i]=HIGH;
    previousButtonState[i]=HIGH;
  }
  Keyboard.begin();
}

void loop() {
  delay(100);
  for (int i = 0; i <= NBR_TCH; i++){
    buttonState[i] = digitalRead(myPins[i]);
    if (i == B_WHITE_Top){
      if (buttonState[i] == LOW){
        Keyboard.press(KEY_LEFT_CTRL);     
      }
      else {
         Keyboard.release(KEY_LEFT_CTRL);
      }
    }
    if ((buttonState[i] != previousButtonState[i]) && (buttonState[i] == LOW)){
      switch (i) {
        case B_RED_Bottom:
        Keyboard.write(K_NUMPAD_0);
        break;
      
        case B_WHITE_Bottom:
        Keyboard.write(K_NUMPAD_2);
        break;
  
        case B_BLACK:
        Keyboard.write(K_NUMPAD_5);   
        break;
  
        case B_BLUE:
        Keyboard.write(K_NUMPAD_8);   
        break;
        
        case B_RED_Left:
        Keyboard.write(K_NUMPAD_1);   
        break;
        
        case B_GREEN_Left:
        Keyboard.write(K_NUMPAD_4);
        break;
        
        case B_GREEN_Right:
        Keyboard.write(K_NUMPAD_6);
        break;
        
        case B_RED_Right:
        Keyboard.write(K_NUMPAD_3);
        break;

        case B_YELLOW_Left:
        Keyboard.write(K_NUMPAD_7);
        break;
        
        case B_WHITE_Top:
        break;

        case B_YELLOW_Right:
        Keyboard.write(K_NUMPAD_9);
        break;
      }
    }
    previousButtonState[i] = buttonState[i];
  }
}
