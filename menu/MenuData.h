#ifndef _sampleMenu_
#define _sampleMenu_
#include "MenuManager.h"
#include <avr/pgmspace.h>

/*

Generated using LCD Menu Builder at https://lcd-menu-bulder.cohesivecomputing.co.uk/
For more information, visit https://www.cohesivecomputing.co.uk/hackatronics/arduino-lcd-menu-library/

All our hackatronics projects are free for personal use. If you find them helpful or useful, please consider
making a small donation to our hackatronics fund using the donate buttons on our web pages. Thank you.
		
*/

enum sampleMenuCommandId
{
  mnuCmdBack = 0,
  mnuCmdTopItem1,
  mnuCmdHardware,
  mnuCmdColorSensor,
  mnuCmdResetToDefaults
};

PROGMEM const char sampleMenu_back[] = "Back";
PROGMEM const char sampleMenu_exit[] = "Exit";

PROGMEM const char sampleMenu_2_1[] = "1 color sense";
PROGMEM const MenuItem sampleMenu_List_2[] = {{mnuCmdColorSensor, sampleMenu_2_1}, {mnuCmdBack, sampleMenu_back}};

PROGMEM const char sampleMenu_1[] = "1 Top item 1";
PROGMEM const char sampleMenu_2[] = "2 Hardware";
PROGMEM const char sampleMenu_3[] = "3 Reset";
PROGMEM const MenuItem sampleMenu_Root[] = {{mnuCmdTopItem1, sampleMenu_1}, {mnuCmdHardware, sampleMenu_2, sampleMenu_List_2, menuCount(sampleMenu_List_2)}, {mnuCmdResetToDefaults, sampleMenu_3}, {mnuCmdBack, sampleMenu_exit}};

/*
case mnuCmdTopItem1 :
	break;
case mnuCmdColorSensor :
	break;
case mnuCmdResetToDefaults :
	break;
*/

/*
<?xml version="1.0"?>
<RootMenu xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:xsd="http://www.w3.org/2001/XMLSchema">
  <Config IdPrefix="mnuCmd" VarPrefix="sampleMenu" UseNumbering="true" IncludeNumberHierarchy="false"
          MaxNameLen="15" MenuBackFirstItem="false" BackText="Back" ExitText="Exit" AvrProgMem="true"/>
  <MenuItems>
    <Item Id="TopItem1" Name="Top item 1"/>
    <Item Id="Hardware" Name="Hardware">
      <MenuItems>
        <Item Id="ColorSensor" Name="color sense"/>
      </MenuItems>
    </Item>
    <Item Id="ResetToDefaults" Name="Reset"/>
  </MenuItems>
</RootMenu>
*/
#endif
