/** Example show dot from WEMOS for D1 Mini with LED 8x8 Matrix shield
 *  
 *  Initial example from:
 *  https://github.com/wemos/WEMOS_Matrix_LED_Shield_Arduino_Library
 *  
 *  Libraries:
 *  https://github.com/wemos/WEMOS_Matrix_LED_Shield_Arduino_Library
 *  
 *  Changed by 
 *  S. Fambach
 *  
 *  Visit https://www.fambach.net if you want
 */

#include "WEMOS_Matrix_LED.h"

MLED mled(5); //set intensity=5
#define ROW 8
#define COL 8
#define SWITCH_DELAY 1000

void setup() {
  // put your setup code here, to run once:

  
}

void clear(){
  for(int y=0;y<ROW;y++)
  {
    for(int x=0;x<COL;x++)
    {
        mled.dot(x,y,0);//clear dot
    
    } 
  }
  mled.display(); 
}

void drawEyes(boolean winkL, boolean winkR){

  // left eye
  mled.dot(1,6, winkL ? 0:1 );
  mled.dot(2,6, winkL ? 0:1 );
  
  mled.dot(1,5);
  mled.dot(2,5);

  //right eye
  mled.dot(5,6, winkR ? 0:1);
  mled.dot(5,5);
  mled.dot(6,6, winkR ? 0:1);
  mled.dot(6,5);
  
}
void drawHappyMouth(){

  // mouth
  mled.dot(1,2);
  mled.dot(2,1);
  mled.dot(3,1);
  mled.dot(4,1);
  mled.dot(5,1);
  mled.dot(6,2);

}

void drawAngryMouth(){
  
  // mouth
  mled.dot(1,1);
  mled.dot(2,2);
  mled.dot(3,2);
  mled.dot(4,2);
  mled.dot(5,2);
  mled.dot(6,1);

  
}

void pixelIt(){
  for(int y=0;y<8;y++)
  {
    for(int x=0;x<8;x++)
    {
        mled.dot(x,y); // draw dot
        mled.display();
        delay(200);
        mled.dot(x,y,0);//clear dot
        mled.display();
        delay(200);        
    }  
  }
  
}


void loop() {

  clear();
  // smile with open eyes
  drawEyes(false,false);
  drawHappyMouth();
  mled.display();
  delay(SWITCH_DELAY);

  // wink left
  drawEyes(true,false);
  mled.display();
  delay(SWITCH_DELAY);

  // wink right
  drawEyes(false,true);
  mled.display();
  delay(SWITCH_DELAY);

  // close eyes
  drawEyes(true,true);
  mled.display();
  delay(SWITCH_DELAY);

  //look angry
  clear();
  drawEyes(false,false);
  drawAngryMouth();
  mled.display();
  delay(SWITCH_DELAY);

}
