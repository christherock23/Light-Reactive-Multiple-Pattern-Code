#define BUTTON_LEAD 4
//#define BRIGHTNESS_BUTTON 19

bool buttonState = LOW;
bool lastButtonState = LOW;
int mode = 1; //Default mode is one.

/* monitor button press */
bool buttonListener() {
  bool modeChanged = false;

  buttonState = digitalRead(BUTTON_LEAD);

  if (buttonState != lastButtonState) {
    if (buttonState == LOW) {
      mode++;
      modeChanged = true;
      delay(250);             // Debounce delay. I checked the best parameter and 250 was it.
    }
  }
  lastButtonState = buttonState;

  return modeChanged;
}

/*
int brightness1 = 42;
int brightness2 = 84;
int brightness3 = 126;
int brightness4 = 168;
int brightness5 = 210;
int brightness6 = 255;

int brightness = 1;

bool brightnessButtonState = LOW;
bool lastBrightnessButtonState = LOW;

bool brightnessButtonListener(){
  bool brightnessChanged = false;

  brightnessButtonState = digitalRead(BRIGHTNESS_BUTTON);

  if(brightnessButtonState != lastBrightnessButtonState) {
    if (brightnessButtonState == LOW) {
      brightness++;
      brightnessChanged = true;
      delay(250);
    }
  }
  lastBrightnessButtonState = brightnessButtonState;

  return brightnessChanged;
}
*/
