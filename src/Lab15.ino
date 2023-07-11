#include "oled-wing-adafruit.h"
#include "Particle.h"
#include <Wire.h>

SYSTEM_THREAD(ENABLED);

OledWingAdafruit display;

void setup()
{
  display.setup();
  display.clearDisplay();
  display.display();

  pinMode(D5, INPUT_PULLUP);

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
		display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.println("reset was watchdog");
    display.display();
  }
  else if (System.resetReason() != RESET_REASON_WATCHDOG)
  {
		display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.println("normal reset");
    display.display();
  }
}