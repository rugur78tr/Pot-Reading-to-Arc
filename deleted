#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();

TFT_eSprite value_sprite = TFT_eSprite(&tft);

TFT_eSprite arc_sprite = TFT_eSprite(&tft);

const int potPin = A0;
int potValue = 0;




void setup() 
{
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);

  value_sprite.createSprite(50,25);
  value_sprite.fillSprite(TFT_GREENYELLOW);



  arc_sprite.createSprite(75,75);
  arc_sprite.fillSprite(TFT_BLACK);




}

void loop() 
{

  value_sprite.fillSprite(TFT_BLACK);

  arc_sprite.fillSprite(TFT_BLACK);
  
  potValue = analogRead(A0);
  int veri = map(potValue, 0, 1023, 0, 100); 
  

  
  value_sprite.setTextSize(2);
  value_sprite.drawNumber(veri, 0,10);
  value_sprite.pushSprite(65, 30);



    //3
  int arcValue = map(veri, 0, 100, 45, 315);
  if (arcValue != 315)
  {
    arc_sprite.drawSmoothArc(arc_sprite.width()/2, arc_sprite.height()/2, 35, 25, 45, arcValue, TFT_YELLOW, TFT_BLACK);
    arc_sprite.drawSmoothArc(arc_sprite.width()/2, arc_sprite.height()/2, 35, 25, arcValue, 315, TFT_DARKGREEN, TFT_BLACK);
    arc_sprite.pushSprite(50, 60);
  }
  else 
  {
    arc_sprite.drawSmoothArc(arc_sprite.width()/2, arc_sprite.height()/2, 35, 25, 45, 315, TFT_YELLOW, TFT_BLACK);
    arc_sprite.pushSprite(50, 60);
  }
  
  


  

  

  delay(25);
    

  



}
