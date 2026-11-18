/*
  Light Up Epoxy Resin Table: automatic LED control
  -------------------------------------------------
  A light sensor (LDR) checks the room brightness. When the room gets dark,
  the LED strip under the epoxy resin fades ON smoothly. When the room is
  bright again, it fades OFF.

  EDIT: Change the pins and thresholds below to match your own build.

  Wiring (typical setup):
    - LED strip + (12V)   -> power supply +
    - LED strip -         -> MOSFET drain
    - MOSFET gate         -> Arduino pin 9 (through a 220 ohm resistor)
    - MOSFET source       -> GND (shared with Arduino GND and power supply -)
    - 10k resistor from the MOSFET gate to GND (keeps the LED off at start-up)
    - LDR: one leg to 5V, other leg to A0; 10k resistor from A0 to GND
*/

// ---------- Settings (edit these) ----------
const uint8_t LED_PIN    = 9;    // PWM pin that drives the MOSFET gate
const uint8_t SENSOR_PIN = A0;   // LDR voltage divider input

// Sensor readings go from 0 (dark) to 1023 (bright).
// Two thresholds prevent flickering when the light level is near the limit.
const int TURN_ON_BELOW  = 350;  // darker than this  -> LEDs on
const int TURN_OFF_ABOVE = 450;  // brighter than this -> LEDs off

const uint8_t MAX_BRIGHTNESS = 255;  // 0-255, lower it for a softer glow
const uint8_t FADE_STEP      = 5;    // bigger = faster fade
const unsigned long FADE_INTERVAL_MS = 15;
// -------------------------------------------

bool ledsOn = false;
int  brightness = 0;
unsigned long lastFade = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  analogWrite(LED_PIN, 0);
  Serial.begin(9600);
  Serial.println("Epoxy table LED controller started");
}

void loop() {
  int light = analogRead(SENSOR_PIN);

  // Decide whether LEDs should be on, using the two thresholds
  if (!ledsOn && light < TURN_ON_BELOW) {
    ledsOn = true;
  } else if (ledsOn && light > TURN_OFF_ABOVE) {
    ledsOn = false;
  }

  // Fade smoothly towards the target brightness
  int target = ledsOn ? MAX_BRIGHTNESS : 0;
  if (millis() - lastFade >= FADE_INTERVAL_MS) {
    lastFade = millis();
    if (brightness < target) {
      brightness = min(brightness + FADE_STEP, target);
    } else if (brightness > target) {
      brightness = max(brightness - FADE_STEP, target);
    }
    analogWrite(LED_PIN, brightness);
  }

  // Debug output: open Serial Monitor at 9600 baud to calibrate thresholds
  static unsigned long lastPrint = 0;
  if (millis() - lastPrint >= 500) {
    lastPrint = millis();
    Serial.print("Light: ");
    Serial.print(light);
    Serial.print("  LEDs: ");
    Serial.println(ledsOn ? "ON" : "OFF");
  }
}
