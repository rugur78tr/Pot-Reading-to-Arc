#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();

TFT_eSprite arc_sprite = TFT_eSprite(&tft);
TFT_eSprite right_sprite = TFT_eSprite(&tft);
TFT_eSprite left_sprite = TFT_eSprite(&tft);

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
  arc_sprite.createSprite(150,130);
  
  right_sprite.setColorDepth(8);
  right_sprite.createSprite(37, 107);

  left_sprite.setColorDepth(8);
  left_sprite.createSprite(37, 107);
  


}

void loop() 
{
  arc_sprite.fillSprite(TFT_BLACK);

  potValue = analogRead(A0);
  int veri = map(potValue, 0, 1023, 0, 100);
  int arcValue = map(veri, 0, 100, 45, 315);

  arc_sprite.drawSmoothArc(arc_sprite.width()/2, arc_sprite.height()/2+10, 74, 56, 45, 315, TFT_DARKGREEN, TFT_BLACK);
  arc_sprite.drawSmoothArc(arc_sprite.width()/2, arc_sprite.height()/2+10, 74, 56, 45, arcValue, TFT_YELLOW, TFT_BLACK);  
  arc_sprite.setFreeFont(&JuraDemiBold30pt7b); arc_sprite.setTextDatum(4); arc_sprite.drawNumber(veri, 75,70 );

  arc_sprite.pushSprite(85, 108);


  int arc_right_value = map(veri, 0, 100, 225, 315);
  right_sprite.fillSprite(TFT_BLACK);
  right_sprite.drawSmoothArc(-40, 54, 74, 56, 225, 315, TFT_DARKGREEN, TFT_BLACK);
  right_sprite.drawSmoothArc(-40, 54, 74, 56, 225, arc_right_value, TFT_YELLOW, TFT_BLACK);
  right_sprite.pushSprite(270, 120);

  int arc_left_value = map(veri, 0, 100, 45, 135);
  left_sprite.fillSprite(TFT_BLACK);
  left_sprite.drawSmoothArc(75, 54, 74, 56, 45, 135, TFT_DARKGREEN, TFT_BLACK);
  left_sprite.drawSmoothArc(75, 54, 74, 56, 45, arc_left_value, TFT_YELLOW, TFT_BLACK);
  left_sprite.pushSprite(13, 120);




}










