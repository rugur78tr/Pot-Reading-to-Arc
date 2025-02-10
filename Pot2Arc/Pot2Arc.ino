#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();

TFT_eSprite arc_sprite = TFT_eSprite(&tft);

#include "JuraDemiBold8pt7b.h"
#include "JuraDemiBold30pt7b.h"

const int potPin = A0;
int potValue = 0;


void setup() 
{
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);

  
  arc_sprite.setColorDepth(8);
  arc_sprite.createSprite(150,150);
  arc_sprite.fillSprite(TFT_BLACK);

  tft.drawSmoothRoundRect(60, 20, 10, 10, 200, 200, TFT_WHITE);
  tft.setFreeFont(&JuraDemiBold8pt7b);
  tft.drawCentreString("< Pot Readings >", 160, 15, 1);

}

void loop() 
{
  arc_sprite.fillSprite(TFT_BLACK);

  potValue = analogRead(A0);
  int veri = map(potValue, 0, 1023, 0, 100);
  int arcValue = map(veri, 0, 100, 45, 315);

  arc_sprite.drawSmoothArc(arc_sprite.width()/2, arc_sprite.height()/2, 74, 55, 45, arcValue, TFT_YELLOW, TFT_BLACK);  
  arc_sprite.setFreeFont(&JuraDemiBold30pt7b); arc_sprite.setTextDatum(4); arc_sprite.drawNumber(veri, 75,70 );

  arc_sprite.pushSprite(85, 50);

}
