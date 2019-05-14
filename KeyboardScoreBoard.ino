#include "Keyboard.h"

#define NBR_TCH 11
int myPins[NBR_TCH] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
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

  for (int i = 0; i <= NBR_TCH; i++) 
  {
    buttonState[i] = digitalRead(myPins[i]);

    if (i == 9){
      if (buttonState[i] == LOW){
        Keyboard.press(KEY_LEFT_CTRL);     
      }
      else {
         Keyboard.release(KEY_LEFT_CTRL);
      }
    }

    
    if ((buttonState[i] != previousButtonState[i]) && (buttonState[i] == LOW))
    {
      switch (i) {

      
        case 0:
        Keyboard.write(234); //NUMPAD_0
        break;
      
        case 1:
        Keyboard.write(232); //NUMPAD_8
        break;
  
        case 2:
        Keyboard.press(KEY_LEFT_CTRL);   
        Keyboard.write(232); //NUMPAD_8
        break;
  
        case 3:
        Keyboard.write(229); //NUMPAD_5
        break;
        
        case 4:
        Keyboard.write(228); //NUMPAD_4
        break;
        
        case 5:
        Keyboard.write(231); //NUMPAD_7
        break;
        
        case 6:
        Keyboard.write(233); //NUMPAD_9
        break;
        
        case 7:
        Keyboard.write(230); //NUMPAD_6
        break;

        case 8:
        Keyboard.write(225); //NUMPAD_1
        break;
        
        case 9:
        Keyboard.write(226); //NUMPAD_2
        break;

        case 10:
        Keyboard.write(227); //NUMPAD_3
        break;
      }
    }
    if ((buttonState[i] != previousButtonState[i]) && (buttonState[i] == HIGH))
    {
      switch (i) {
        case 9:
        Keyboard.release(KEY_LEFT_CTRL);
        break;
      }
    }
    previousButtonState[i] = buttonState[i];
  }
}
