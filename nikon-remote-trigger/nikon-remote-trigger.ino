
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address

int starDelaySeconds = 5;
int currentState = 0;
boolean triggerIsRunning = LOW;
void setup()   /*----( SETUP: RUNS ONCE )----*/
{
  Serial.begin(9600);  // Used to type in characters

  lcd.begin(16,2);   // initialize the lcd for 16 chars 2 lines, turn on backlight
/*
//-------- Write characters on the display ------------------
// NOTE: Cursor Position: (CHAR, LINE) start at 0  
  lcd.setCursor(0,0); //Start at character 4 on line 0
  lcd.print("Hello, world!");
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("HI!YourDuino.com");
  delay(8000);  

// Wait and then tell user they can start the Serial Monitor and type in characters to
// Display. (Set Serial Monitor option to "No Line Ending")
  lcd.clear();
  lcd.setCursor(0,0); //Start at character 0 on line 0
  lcd.print("Use Serial Mon");
  lcd.setCursor(0,1);
  lcd.print("Type to display");  
*/

}/*--(end setup )---*/


void loop()   /*----( LOOP: RUNS CONSTANTLY )----*/
{
   switch (currentState) {
      case 0:
        if(triggerIsRunning == LOW){
        lcd.setCursor(0,0);
        lcd.print("Star tracker");
        lcd.setCursor(0,1);
        lcd.print("Intervall:");
        lcd.setCursor(11,1);
        lcd.print(starDelaySeconds);
        Serial.println("State 0 indication code here!");
        }
        else runStarMode(starDelaySeconds);

      case 1:
        Serial.println("State 1 indication code here!");
        break;
      case 2:
        Serial.println("State 2 indication code here!");
        break;
      default:
      break;

}
}
void runStarMode(int starDelaySeconds){


}


/* ( THE END ) */


