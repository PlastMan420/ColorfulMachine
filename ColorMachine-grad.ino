#include <Arduino_FreeRTOS.h>
#include <semphr.h>

#include <LiquidCrystal.h>
#include "LcdKeypad.h"
#include "MenuData.h"

#include "colorsensor.h"
#include "StepperAbstractions.h"
#include "JsonAbstractions.h"

#define DEBUG true

// Menu Init ////////////////////////////////////
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

enum AppModeValues
{
  APP_NORMAL_MODE,
  APP_MENU_MODE,
  APP_PROCESS_MENU_CMD
};

byte appMode = APP_NORMAL_MODE;

MenuManager Menu1(sampleMenu_Root, menuCount(sampleMenu_Root));

char strbuf[LCD_COLS + 1]; // one line of lcd display
byte btn;

void refreshMenuDisplay (byte refreshMode);
byte getNavAction();

//Operating System Items //////////////////////////////
TaskHandle_t menuTaskHandle;
TaskHandle_t sensorTaskHandle;

SemaphoreHandle_t xSerialSemaphore;

///////////////////////////////////////////////////////

void setup()
{
  Serial.begin(115200);

  // Create a mutx for serial. Created as a global object in the main file since it's a shared resource.
  if ( xSerialSemaphore == NULL )  // Check to confirm that the Serial Semaphore has not already been created.
  {
    xSerialSemaphore = xSemaphoreCreateMutex();  // Create a mutex semaphore we will use to manage the Serial Port
    if ( ( xSerialSemaphore ) != NULL )
      xSemaphoreGive( ( xSerialSemaphore ) );  // Make the Serial Port available for use, by "Giving" the Semaphore.
  }
  
  // Menu Setup /////////////////////////////////////////
  backLightOn();
  // set up the LCD's number of columns and rows:
  lcd.begin(LCD_COLS, LCD_ROWS);

  // fall in to menu mode by default.
  appMode = APP_MENU_MODE;
  refreshMenuDisplay(REFRESH_DESCEND);
  setBacklightBrightness(1);
  //////////////////////////////////////////////////////

///////////////// HARDWARE ///////////////////////////////////////////
  // Color sensor //
  pinMode(TCS_LED, OUTPUT);
  digitalWrite(TCS_LED, LOW); //LEDs OFF
  // Stepper Motor
  StepperInit();


  // Operating System ///////////////////////////////////

  ////////////// TASKS ////////////////
  // LCD Menu Task
  xTaskCreate(
    TaskMenu
    , "Menu"
    , 128
    , NULL 
    , 3
    , &menuTaskHandle
  );

  // Color Sensor Task.
  xTaskCreate(
    TaskColorSensor
    , "3200"
    , 128
    , NULL
    , 2
    , &sensorTaskHandle
  );

  vTaskSuspend(sensorTaskHandle);
  /////////////////////////////////////
  //////////////////////////////////////////////////////

} //setup

void loop()
{}

void TaskMenu(void *pvParameters)
{
  (void) pvParameters;

  for(;;)
  {
      int analogReading = analogRead (A0);
      //Serial.println(analogReading);
      btn = getButton();
      switch (appMode)
      {
        case APP_NORMAL_MODE :
          if (btn == BUTTON_UP_LONG_PRESSED)
          {
            appMode = APP_MENU_MODE;
            refreshMenuDisplay(REFRESH_DESCEND);
          }
          break;
        case APP_MENU_MODE :
        {
          byte menuMode = Menu1.handleNavigation(getNavAction, refreshMenuDisplay);

          if (menuMode == MENU_EXIT)
          {
            lcd.clear();
            lcd.print("Hold UP for menu");
            appMode = APP_NORMAL_MODE;
          }
          else if (menuMode == MENU_INVOKE_ITEM)
          {
            appMode = APP_PROCESS_MENU_CMD;

            // Indicate selected item.
            if (Menu1.getCurrentItemCmdId())
            {
              lcd.setCursor(0, 1);
              strbuf[0] = 0b01111110; // forward arrow representing input prompt.
              strbuf[1] = 0;
              lcd.print(strbuf);
            }
          }
          break;
        }
        case APP_PROCESS_MENU_CMD :
        {
          byte processingComplete = processMenuCommand(Menu1.getCurrentItemCmdId());

          if (processingComplete)
          {
            appMode = APP_MENU_MODE;
            // clear forward arrow
            lcd.setCursor(0, 1);
            strbuf[0] = ' '; // clear forward arrow
            strbuf[1] = 0;
            lcd.print(strbuf);
          }
          break;
        }
      }
    //}
      vTaskDelay(5);  // one tick delay (15ms) in between reads for stability
  }
}

// void interruptHandler() {
//   BaseType_t xHigherPriorityTaskWoken = pdFALSE;
//   vTaskNotifyGiveFromISR(menuTaskHandle, &xHigherPriorityTaskWoken);
//   if (xHigherPriorityTaskWoken) {
//     taskYIELD();
//   }
// }

//----------------------------------------------------------------------
// Addition or removal of menu items in MenuData.h will require this method
// to be modified accordingly. 
byte processMenuCommand(byte cmdId)
{
  byte complete = false;  // set to true when menu command processing complete.

  if (btn == BUTTON_SELECT_PRESSED)
  {
    complete = true;
  }

  switch (cmdId)
  {
    // TODO Process menu commands here:
      case mnuCmdColorSensor:
        vTaskResume(sensorTaskHandle);
        break;
      default:
        Serial.println(F("Nothing"));
    break;
  }

  return complete;
}


//----------------------------------------------------------------------
// Callback to convert button press to navigation action.
byte getNavAction()
{
  byte navAction = 0;
  byte currentItemHasChildren = Menu1.currentItemHasChildren();
  
  if (btn == BUTTON_UP_PRESSED || btn == BUTTON_UP_LONG_PRESSED) navAction = MENU_ITEM_PREV;
  else if (btn == BUTTON_DOWN_PRESSED || btn == BUTTON_DOWN_LONG_PRESSED) navAction = MENU_ITEM_NEXT;
  else if (btn == BUTTON_SELECT_PRESSED || (btn == BUTTON_RIGHT_PRESSED && currentItemHasChildren)) navAction = MENU_ITEM_SELECT;
  //else if (btn == BUTTON_LEFT_PRESSED) navAction = MENU_BACK;
  return navAction;
}


//----------------------------------------------------------------------
const char EmptyStr[] = "";

// Callback to refresh display during menu navigation, using parameter of type enum DisplayRefreshMode.
void refreshMenuDisplay (byte refreshMode)
{
  char nameBuf[LCD_COLS+1];

/*
  if (refreshMode == REFRESH_DESCEND || refreshMode == REFRESH_ASCEND)
  {
    byte menuCount = Menu1.getMenuItemCount();
    
    // uncomment below code to output menus to serial monitor
    if (Menu1.currentMenuHasParent())
    {
      Serial.print("Parent menu: ");
      Serial.println(Menu1.getParentItemName(nameBuf));
    }
    else
    {
      Serial.println("Main menu:");
    }
    
    for (int i=0; i<menuCount; i++)
    {
      Serial.print(Menu1.getItemName(nameBuf, i));

      if (Menu1.itemHasChildren(i))
      {
        Serial.println("->");
      }
      else
      {
        Serial.println();
      }
    }
  }
*/

  lcd.setCursor(0, 0);
  if (Menu1.currentItemHasChildren())
  {
    rpad(strbuf, Menu1.getCurrentItemName(nameBuf));
    strbuf[LCD_COLS-1] = 0b01111110;            // Display forward arrow if this menu item has children.
    lcd.print(strbuf);
    lcd.setCursor(0, 1);
    lcd.print(rpad(strbuf, EmptyStr));          // Clear config value in display
  }
  else
  {
    byte cmdId;
    rpad(strbuf, Menu1.getCurrentItemName(nameBuf));
    
    if ((cmdId = Menu1.getCurrentItemCmdId()) == 0)
    {
      strbuf[LCD_COLS-1] = 0b01111111;          // Display back arrow if this menu item ascends to parent.
      lcd.print(strbuf);
      lcd.setCursor(0, 1);
      lcd.print(rpad(strbuf, EmptyStr));        // Clear config value in display.
    }
    else
    {
      lcd.print(strbuf);
      lcd.setCursor(0, 1);
      lcd.print(" ");
      
      // TODO Display config value.
    }
  }
}
