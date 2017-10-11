#include "FastLED.h"
#include "Buttons.h"
#include "Patterns.h"

FASTLED_USING_NAMESPACE

int lightPin = A7;  //define a pin for Photo resistor

#define DATA_PIN    2
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
#define NUM_LEDS    25

#define FRAMES_PER_SECOND  120

void setup() {
  Serial.begin(9600);  //Begin serial communcation

  pinMode(BUTTON_LEAD, INPUT_PULLUP);

  delay(3000); // 3 second delay for recovery
  
  // tell FastLED about the LED strip configuration
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  //FastLED.addLeds<LED_TYPE,DATA_PIN,CLK_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);

  // set master brightness control
  FastLED.setBrightness(analogRead(lightPin));
}

// List of patterns to cycle through.  Each is defined as a separate function below.
typedef void (*SimplePatternList[])();
SimplePatternList gPatterns = { 
  rainbow, 
  rainbowWithGlitter, 
  confetti, 
  sinelon, 
  juggle, 
  bpm, 
  pride
  };

uint8_t gCurrentPatternNumber = 0; // Index number of which pattern is current

void loop()
{
  brightness();
  // Call the current pattern function once, updating the 'leds' array
  gPatterns[gCurrentPatternNumber]();

  // send the 'leds' array out to the actual LED strip
  FastLED.show();  
  // insert a delay to keep the framerate modest
  FastLED.delay(1000/FRAMES_PER_SECOND); 

  // do some periodic updates
  EVERY_N_MILLISECONDS( 20 ) { gHue++; } // slowly cycle the "base color" through the rainbow
  if(buttonListener()) { nextPattern(); } //Check if the buttom has been pressed
}

#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))

void nextPattern()
{
  // add one to the current pattern number, and wrap around at the end
  gCurrentPatternNumber = (gCurrentPatternNumber + 1) % ARRAY_SIZE( gPatterns);
}

void brightness(){
  int val = analogRead(lightPin);
  val = map(val, 0, 700, 40, 200);
  if (val > 700){
    val = 700;
  }
  
  FastLED.setBrightness(val);
  Serial.print("sensor = ");
  Serial.print(analogRead(lightPin));
  Serial.print("\t output = ");
  Serial.println(val); //Write the value of the photoresistor to the serial monitor.
  
}
