/***************************************
 * Project              : Digital Clock with Arduino Uni Board
 * Date                 : 29 - 6 - 2016
 * Programming Language : C
 * Kits                 : LCD 16x2 , Potentiometer ,Bluetooth
 * Programmer           : Mohamed Nagy Mostafa
 ***************************************/
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

LiquidCrystal lcd(2,3,4,5,6,7); //RS E D4 D5 D6 D7
SoftwareSerial HC05(8,9); //TX RX

#define HOURS  24
#define SECONDS 60
#define MINUTES 60
#define NUMBER_OF_ITEMS 3
#define NON_FOCUS -1
#define HALF_SECOND 500

/// Buttons 
#define LEFT_BUTTON 76
#define RIGHT_BUTTON 82
#define UP_BUTTON 70
#define DOWN_BUTTON 66

short hour,mint,sec;
short index = NON_FOCUS; //Focusing item's index
short command; //The Button that is clicked
bool focusAvaliable = false; 

void display();
// To show clock on the screen 

void focusToRight(short &index);
// To move The focus to right */

void focusToLeft(short &index);
// To move The focus to left */

void increasing(short &index,short *items[]);
// To increase the value of The selected item 

void decreasing(short &index,short *items[]);
// To decrease the value of The selected item 

void focusing(short index,short *items[]);
// To show The focus in the screen 

void check(short command,short *item[]);
// To see the choice of the user

void checkZero(short number);
// To add zero in the left side of number of hr/min/sec 
// When the number is lower than 10

 
void checkNight(short hour);
// To control of showing Pm/Am

void setup() 
{
    /// LCD Settings
    lcd.begin(16,2);
    lcd.clear();
    
    /// Bluetooth Settings
    HC05.begin(9600);
    
    /// Testing Settings
    Serial.begin(9600);
}

void loop() 
{  
    for(hour = 0 ; hour != HOURS ; hour++)
        for(mint = 0 ; mint != MINUTES ; mint++)
            for(sec = 0 ; sec != SECONDS ; sec++)
            {
                short *item[NUMBER_OF_ITEMS] = {&hour,&mint,&sec};
                command = HC05.read();
                check(command ,item);
                
                lcd.clear();
                display();
                delay(HALF_SECOND);
                
                focusing(index,item);
                
                delay(HALF_SECOND);
                display();
                
                delete item[NUMBER_OF_ITEMS];
            }
}

void display()
{
  checkZero(hour);
  lcd.print(":");
  checkZero(mint);
  lcd.print(":");
  checkZero(sec);
  checkNight(hour);
}

// @params command : number of button that clicked by user
// item[] pointer of array that have the current hr/min/sec
void check(short command, short *item[])
{
    switch(command)
    {
        case RIGHT_BUTTON:
            focusToRight(index);
            break;
        case LEFT_BUTTON:
            focusToLeft(index);
            break;
        case UP_BUTTON:
            increasing(index,item);
            break;
        case DOWN_BUTTON:
            decreasing(index,item);
            break;
        default:
            return;
    }
}

void focusToRight(short &index)
{
    if(index < NUMBER_OF_ITEMS - 1)
    {
        index++;
        focusAvaliable= true;
    }
    else if(index == NUMBER_OF_ITEMS - 1)
    {
        focusAvaliable= false;
        index = NON_FOCUS;
    }
    else
    {
        index = 0;
        focusAvaliable= true;
    }
}

void focusToLeft(short &index)
{
    if(index > 0 )
    {
        index--;
        focusAvaliable= true;
    }
    else if(index == 0)
    {
        index = NON_FOCUS;
        focusAvaliable= false;
    }
    else
    {
         index = NUMBER_OF_ITEMS - 1;
         focusAvaliable= true;
    }
}

void increasing(short &index,short *items[])
{
    
      // Testing ...
      Serial.print("Increasing");
    Serial.println(index);
    
    if(index == 0)
    {
        if(*items[index] < HOURS - 1)
        {
            ++*items[index];
        }
        else
        {
            *items[index] = 0;
        }
    }
    
    if(index == 1)
    {
        if(*items[index] < MINUTES - 1)
        {
            ++*items[index];
        }
        else
        {
            *items[index] = 0;
        }
    }
    
    if(index == 2)
    {
        if(*items[index] < SECONDS - 1)
        {
            ++*items[index];
        }
        else
        {
            *items[index] = 0;
        }
    }
}

void decreasing(short &index,short *items[])
{
    Serial.print("Decreasing");
    Serial.println(index);
    
    if(index == 0)
    {
        if(*items[index] < HOURS && *items[index] > 0)
        {
            --*items[index];
        }
        else
        {
            *items[index] = HOURS - 1;
        }
    }
    if(index == 1)
    {
        if(*items[index] < MINUTES && *items[index] > 0)
        {
            --*items[index];
        }
        else
        {
            *items[index] = MINUTES - 1;
        }
    }
    if(index == 2)
    {
        if(*items[index] < SECONDS && *items[index] > 0)
        {
            --*items[index];
        }
        else
        {
            *items[index] = SECONDS - 1;
        }
    }
}

void focusing(short index,short *items[])
{
    if(index == 0 && focusAvaliable == true)
    {
        lcd.clear();
        lcd.setCursor(2,0);
        lcd.print(":");
        checkZero(mint);
        lcd.print(":");
        checkZero(sec);
    }
    
    else if(index == 1 && focusAvaliable == true)
    {
        lcd.clear();
        checkZero(hour);
        lcd.print(":");
        lcd.setCursor(5,0);
        lcd.print(":");
        checkZero(sec);
    }
    
    else if(index == 2 && focusAvaliable == true)
    {
        lcd.clear();
        checkZero(hour);
        lcd.print(":");
        checkZero(mint);
        lcd.print(":");
    }
    
    else
    {
        lcd.clear();
        checkZero(hour);
        lcd.print(":");
        checkZero(mint);
        lcd.print(":");
        checkZero(sec);
    }
    checkNight(hour);
}

void checkZero(short number)
{
    if( number < 10)
    {
        lcd.print(0);
        lcd.print(number);
    }
    else
        lcd.print(number);
}

void checkNight(short hour)
{
    lcd.setCursor(9,0);
    
    if(hour < 12)
        lcd.print("Am");
    else
        lcd.print("Pm");
}
