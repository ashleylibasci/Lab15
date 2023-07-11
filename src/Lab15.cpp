/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#line 1 "/Users/ashleylibasci/IoTFolderLabs/Lab15/src/Lab15.ino"
#include "oled-wing-adafruit.h"
#include "Particle.h"
#include <Wire.h>

void setup();
void loop();
#line 5 "/Users/ashleylibasci/IoTFolderLabs/Lab15/src/Lab15.ino"
SYSTEM_THREAD(ENABLED);

OledWingAdafruit display;

void setup()
{
  display.setup();
  display.clearDisplay();
  display.display();

  pinMode(D5, INPUT);

  Watchdog.init(WatchdogConfiguration().timeout(5000));
  Watchdog.start();
}

void loop()
{
  display.loop();

  if (digitalRead(D5) == HIGH)
  {
    Watchdog.refresh();
  }

  if (System.resetReason() == RESET_REASON_WATCHDOG)
  {
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.println("reset was watchdog");
    display.display();
  }
  else if (System.resetReason() != RESET_REASON_WATCHDOG)
  {
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.println("reset NOT watchdog");
    display.display();
  }
}