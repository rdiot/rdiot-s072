/* Raindrops Detection Sensor Modue (FC-37) [S072] : http://rdiot.tistory.com/61 [RDIoT Demo] */

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
 
LiquidCrystal_I2C lcd(0x27,20,4);  // LCD2004
 
int nRainIn = A0;
int nRainDigitalIn = 2;
int nRainVal;
boolean bIsRaining = false;
String strRaining;
 
void setup()
{
  lcd.init();  // initialize the lcd 
  lcd.backlight();
  lcd.print("start LCD2004");
 
  pinMode(2,INPUT);
  delay(1000);
 
  lcd.clear();
}
 
void loop()
{
 
  lcd.setCursor(0,0);
  lcd.print("S072:Raindrop Detect");
 
  nRainVal = analogRead(nRainIn);  
  bIsRaining = !(digitalRead(nRainDigitalIn));    
  if(bIsRaining)
  {    
    strRaining = "YES";  
  }  
  else
  {    
    strRaining = "NO";  
  }    
 
  lcd.setCursor(0,1);
  lcd.print("Raining?=" + (String)strRaining + " ");
 
  lcd.setCursor(0,2);
  lcd.print("MoistureLevel=" + (String)nRainVal + "  ");
  
  delay(200);
 
}
