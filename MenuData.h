#ifndef _colorsensorMenu_
#define _colorsensorMenu_
#include "MenuManager.h"
#include <avr/pgmspace.h>

/*

Generated using LCD Menu Builder at https://lcd-menu-bulder.cohesivecomputing.co.uk/
For more information, visit https://www.cohesivecomputing.co.uk/hackatronics/arduino-lcd-menu-library/

All our hackatronics projects are free for personal use. If you find them helpful or useful, please consider
making a small donation to our hackatronics fund using the donate buttons on our web pages. Thank you.
		
*/

enum colorsensorMenuCommandId
{
  mnuCmdBack = 0,
  mnuCmdColorSensor,
  mnuCmdSettings,
  mnuCmdcolor_0,
  mnuCmddrops01,
  mnuCmddrops02,
  mnuCmddrops03,
  mnuCmddrops04,
  mnuCmddrops05,
  mnuCmdcolor_1,
  mnuCmddrops11,
  mnuCmddrops12,
  mnuCmddrops13,
  mnuCmddrops14,
  mnuCmddrops15,
  mnuCmdcolor_2,
  mnuCmddrops21,
  mnuCmddrops22,
  mnuCmddrops23,
  mnuCmddrops24,
  mnuCmddrops25,
  mnuCmdcolor_3,
  mnuCmddrops31,
  mnuCmddrops32,
  mnuCmddrops33,
  mnuCmddrops34,
  mnuCmddrops35,
  mnuCmdcolor_4,
  mnuCmddrops41,
  mnuCmddrops42,
  mnuCmddrops43,
  mnuCmddrops44,
  mnuCmddrops45,
  mnuCmdcolor_5,
  mnuCmddrops51,
  mnuCmddrops52,
  mnuCmddrops53,
  mnuCmddrops54,
  mnuCmddrops55,
  mnuCmdcolor_6,
  mnuCmddrops61,
  mnuCmddrops62,
  mnuCmddrops63,
  mnuCmddrops64,
  mnuCmddrops65,
  mnuCmdcolor_7,
  mnuCmddrops71,
  mnuCmddrops72,
  mnuCmddrops73,
  mnuCmddrops74,
  mnuCmddrops75,
  mnuCmdcolor_8,
  mnuCmddrops81,
  mnuCmddrops82,
  mnuCmddrops83,
  mnuCmddrops84,
  mnuCmddrops85
};

PROGMEM const char colorsensorMenu_back[] = "Back";
PROGMEM const char colorsensorMenu_exit[] = "Exit";

PROGMEM const char colorsensorMenu_2_1_1[] = "1 Slot_1";
PROGMEM const char colorsensorMenu_2_1_2[] = "2 Slot_2";
PROGMEM const char colorsensorMenu_2_1_3[] = "3 Slot_3";
PROGMEM const char colorsensorMenu_2_1_4[] = "4 Slot_4";
PROGMEM const char colorsensorMenu_2_1_5[] = "5 Slot_5";
PROGMEM const MenuItem colorsensorMenu_List_2_1[] = {{mnuCmddrops01, colorsensorMenu_2_1_1}, {mnuCmddrops02, colorsensorMenu_2_1_2}, {mnuCmddrops03, colorsensorMenu_2_1_3}, {mnuCmddrops04, colorsensorMenu_2_1_4}, {mnuCmddrops05, colorsensorMenu_2_1_5}, {mnuCmdBack, colorsensorMenu_back}};

PROGMEM const char colorsensorMenu_2_2_1[] = "1 Slot_1";
PROGMEM const char colorsensorMenu_2_2_2[] = "2 Slot_2";
PROGMEM const char colorsensorMenu_2_2_3[] = "3 Slot_3";
PROGMEM const char colorsensorMenu_2_2_4[] = "4 Slot_4";
PROGMEM const char colorsensorMenu_2_2_5[] = "5 Slot_5";
PROGMEM const MenuItem colorsensorMenu_List_2_2[] = {{mnuCmddrops11, colorsensorMenu_2_2_1}, {mnuCmddrops12, colorsensorMenu_2_2_2}, {mnuCmddrops13, colorsensorMenu_2_2_3}, {mnuCmddrops14, colorsensorMenu_2_2_4}, {mnuCmddrops15, colorsensorMenu_2_2_5}, {mnuCmdBack, colorsensorMenu_back}};

PROGMEM const char colorsensorMenu_2_3_1[] = "1 Slot_1";
PROGMEM const char colorsensorMenu_2_3_2[] = "2 Slot_2";
PROGMEM const char colorsensorMenu_2_3_3[] = "3 Slot_3";
PROGMEM const char colorsensorMenu_2_3_4[] = "4 Slot_4";
PROGMEM const char colorsensorMenu_2_3_5[] = "5 Slot_5";
PROGMEM const MenuItem colorsensorMenu_List_2_3[] = {{mnuCmddrops21, colorsensorMenu_2_3_1}, {mnuCmddrops22, colorsensorMenu_2_3_2}, {mnuCmddrops23, colorsensorMenu_2_3_3}, {mnuCmddrops24, colorsensorMenu_2_3_4}, {mnuCmddrops25, colorsensorMenu_2_3_5}, {mnuCmdBack, colorsensorMenu_back}};

PROGMEM const char colorsensorMenu_2_4_1[] = "1 Slot_1";
PROGMEM const char colorsensorMenu_2_4_2[] = "2 Slot_2";
PROGMEM const char colorsensorMenu_2_4_3[] = "3 Slot_3";
PROGMEM const char colorsensorMenu_2_4_4[] = "4 Slot_4";
PROGMEM const char colorsensorMenu_2_4_5[] = "5 Slot_5";
PROGMEM const MenuItem colorsensorMenu_List_2_4[] = {{mnuCmddrops31, colorsensorMenu_2_4_1}, {mnuCmddrops32, colorsensorMenu_2_4_2}, {mnuCmddrops33, colorsensorMenu_2_4_3}, {mnuCmddrops34, colorsensorMenu_2_4_4}, {mnuCmddrops35, colorsensorMenu_2_4_5}, {mnuCmdBack, colorsensorMenu_back}};

PROGMEM const char colorsensorMenu_2_5_1[] = "1 Slot_1";
PROGMEM const char colorsensorMenu_2_5_2[] = "2 Slot_2";
PROGMEM const char colorsensorMenu_2_5_3[] = "3 Slot_3";
PROGMEM const char colorsensorMenu_2_5_4[] = "4 Slot_4";
PROGMEM const char colorsensorMenu_2_5_5[] = "5 Slot_5";
PROGMEM const MenuItem colorsensorMenu_List_2_5[] = {{mnuCmddrops41, colorsensorMenu_2_5_1}, {mnuCmddrops42, colorsensorMenu_2_5_2}, {mnuCmddrops43, colorsensorMenu_2_5_3}, {mnuCmddrops44, colorsensorMenu_2_5_4}, {mnuCmddrops45, colorsensorMenu_2_5_5}, {mnuCmdBack, colorsensorMenu_back}};

PROGMEM const char colorsensorMenu_2_6_1[] = "1 Slot_1";
PROGMEM const char colorsensorMenu_2_6_2[] = "2 Slot_2";
PROGMEM const char colorsensorMenu_2_6_3[] = "3 Slot_3";
PROGMEM const char colorsensorMenu_2_6_4[] = "4 Slot_4";
PROGMEM const char colorsensorMenu_2_6_5[] = "5 Slot_5";
PROGMEM const MenuItem colorsensorMenu_List_2_6[] = {{mnuCmddrops51, colorsensorMenu_2_6_1}, {mnuCmddrops52, colorsensorMenu_2_6_2}, {mnuCmddrops53, colorsensorMenu_2_6_3}, {mnuCmddrops54, colorsensorMenu_2_6_4}, {mnuCmddrops55, colorsensorMenu_2_6_5}, {mnuCmdBack, colorsensorMenu_back}};

PROGMEM const char colorsensorMenu_2_7_1[] = "1 Slot_1";
PROGMEM const char colorsensorMenu_2_7_2[] = "2 Slot_2";
PROGMEM const char colorsensorMenu_2_7_3[] = "3 Slot_3";
PROGMEM const char colorsensorMenu_2_7_4[] = "4 Slot_4";
PROGMEM const char colorsensorMenu_2_7_5[] = "5 Slot_5";
PROGMEM const MenuItem colorsensorMenu_List_2_7[] = {{mnuCmddrops61, colorsensorMenu_2_7_1}, {mnuCmddrops62, colorsensorMenu_2_7_2}, {mnuCmddrops63, colorsensorMenu_2_7_3}, {mnuCmddrops64, colorsensorMenu_2_7_4}, {mnuCmddrops65, colorsensorMenu_2_7_5}, {mnuCmdBack, colorsensorMenu_back}};

PROGMEM const char colorsensorMenu_2_8_1[] = "1 Slot_1";
PROGMEM const char colorsensorMenu_2_8_2[] = "2 Slot_2";
PROGMEM const char colorsensorMenu_2_8_3[] = "3 Slot_3";
PROGMEM const char colorsensorMenu_2_8_4[] = "4 Slot_4";
PROGMEM const char colorsensorMenu_2_8_5[] = "5 Slot_5";
PROGMEM const MenuItem colorsensorMenu_List_2_8[] = {{mnuCmddrops71, colorsensorMenu_2_8_1}, {mnuCmddrops72, colorsensorMenu_2_8_2}, {mnuCmddrops73, colorsensorMenu_2_8_3}, {mnuCmddrops74, colorsensorMenu_2_8_4}, {mnuCmddrops75, colorsensorMenu_2_8_5}, {mnuCmdBack, colorsensorMenu_back}};

PROGMEM const char colorsensorMenu_2_9_1[] = "1 Slot_1";
PROGMEM const char colorsensorMenu_2_9_2[] = "2 Slot_2";
PROGMEM const char colorsensorMenu_2_9_3[] = "3 Slot_3";
PROGMEM const char colorsensorMenu_2_9_4[] = "4 Slot_4";
PROGMEM const char colorsensorMenu_2_9_5[] = "5 Slot_5";
PROGMEM const MenuItem colorsensorMenu_List_2_9[] = {{mnuCmddrops81, colorsensorMenu_2_9_1}, {mnuCmddrops82, colorsensorMenu_2_9_2}, {mnuCmddrops83, colorsensorMenu_2_9_3}, {mnuCmddrops84, colorsensorMenu_2_9_4}, {mnuCmddrops85, colorsensorMenu_2_9_5}, {mnuCmdBack, colorsensorMenu_back}};

PROGMEM const char colorsensorMenu_2_1[] = "1 Black";
PROGMEM const char colorsensorMenu_2_2[] = "2 White";
PROGMEM const char colorsensorMenu_2_3[] = "3 Gray";
PROGMEM const char colorsensorMenu_2_4[] = "4 Red";
PROGMEM const char colorsensorMenu_2_5[] = "5 Green";
PROGMEM const char colorsensorMenu_2_6[] = "6 Blue";
PROGMEM const char colorsensorMenu_2_7[] = "7 Orange";
PROGMEM const char colorsensorMenu_2_8[] = "8 Yellow";
PROGMEM const char colorsensorMenu_2_9[] = "9 Purple";
PROGMEM const MenuItem colorsensorMenu_List_2[] = {{mnuCmdcolor_0, colorsensorMenu_2_1, colorsensorMenu_List_2_1, menuCount(colorsensorMenu_List_2_1)}, {mnuCmdcolor_1, colorsensorMenu_2_2, colorsensorMenu_List_2_2, menuCount(colorsensorMenu_List_2_2)}, {mnuCmdcolor_2, colorsensorMenu_2_3, colorsensorMenu_List_2_3, menuCount(colorsensorMenu_List_2_3)}, {mnuCmdcolor_3, colorsensorMenu_2_4, colorsensorMenu_List_2_4, menuCount(colorsensorMenu_List_2_4)}, {mnuCmdcolor_4, colorsensorMenu_2_5, colorsensorMenu_List_2_5, menuCount(colorsensorMenu_List_2_5)}, {mnuCmdcolor_5, colorsensorMenu_2_6, colorsensorMenu_List_2_6, menuCount(colorsensorMenu_List_2_6)}, {mnuCmdcolor_6, colorsensorMenu_2_7, colorsensorMenu_List_2_7, menuCount(colorsensorMenu_List_2_7)}, {mnuCmdcolor_7, colorsensorMenu_2_8, colorsensorMenu_List_2_8, menuCount(colorsensorMenu_List_2_8)}, {mnuCmdcolor_8, colorsensorMenu_2_9, colorsensorMenu_List_2_9, menuCount(colorsensorMenu_List_2_9)}, {mnuCmdBack, colorsensorMenu_back}};

PROGMEM const char colorsensorMenu_1[] = "1 start sorting";
PROGMEM const char colorsensorMenu_2[] = "2 Settings";
PROGMEM const MenuItem colorsensorMenu_Root[] = {{mnuCmdColorSensor, colorsensorMenu_1}, {mnuCmdSettings, colorsensorMenu_2, colorsensorMenu_List_2, menuCount(colorsensorMenu_List_2)}, {mnuCmdBack, colorsensorMenu_exit}};

/*
case mnuCmdColorSensor :
	break;
case mnuCmddrops01 :
	break;
case mnuCmddrops02 :
	break;
case mnuCmddrops03 :
	break;
case mnuCmddrops04 :
	break;
case mnuCmddrops05 :
	break;
case mnuCmddrops11 :
	break;
case mnuCmddrops12 :
	break;
case mnuCmddrops13 :
	break;
case mnuCmddrops14 :
	break;
case mnuCmddrops15 :
	break;
case mnuCmddrops21 :
	break;
case mnuCmddrops22 :
	break;
case mnuCmddrops23 :
	break;
case mnuCmddrops24 :
	break;
case mnuCmddrops25 :
	break;
case mnuCmddrops31 :
	break;
case mnuCmddrops32 :
	break;
case mnuCmddrops33 :
	break;
case mnuCmddrops34 :
	break;
case mnuCmddrops35 :
	break;
case mnuCmddrops41 :
	break;
case mnuCmddrops42 :
	break;
case mnuCmddrops43 :
	break;
case mnuCmddrops44 :
	break;
case mnuCmddrops45 :
	break;
case mnuCmddrops51 :
	break;
case mnuCmddrops52 :
	break;
case mnuCmddrops53 :
	break;
case mnuCmddrops54 :
	break;
case mnuCmddrops55 :
	break;
case mnuCmddrops61 :
	break;
case mnuCmddrops62 :
	break;
case mnuCmddrops63 :
	break;
case mnuCmddrops64 :
	break;
case mnuCmddrops65 :
	break;
case mnuCmddrops71 :
	break;
case mnuCmddrops72 :
	break;
case mnuCmddrops73 :
	break;
case mnuCmddrops74 :
	break;
case mnuCmddrops75 :
	break;
case mnuCmddrops81 :
	break;
case mnuCmddrops82 :
	break;
case mnuCmddrops83 :
	break;
case mnuCmddrops84 :
	break;
case mnuCmddrops85 :
	break;
*/

/*
<?xml version="1.0"?>
<RootMenu xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:xsd="http://www.w3.org/2001/XMLSchema">
	<Config IdPrefix="mnuCmd" VarPrefix="colorsensorMenu" UseNumbering="true" IncludeNumberHierarchy="false"
		MaxNameLen="15" MenuBackFirstItem="false" BackText="Back" ExitText="Exit" AvrProgMem="true"/>

	<MenuItems>
		<Item Id="ColorSensor" Name="start sorting"/>

		<Item Id="Settings" Name="Settings">
			<MenuItems>

				<Item Id="color_0" Name="Black">
					<MenuItems>
						<Item Id="drops01" Name="Slot_1"/>
						<Item Id="drops02" Name="Slot_2"/>
						<Item Id="drops03" Name="Slot_3"/>
						<Item Id="drops04" Name="Slot_4"/>
						<Item Id="drops05" Name="Slot_5"/>
					</MenuItems>
				</Item>

				<Item Id="color_1" Name="White">
				<MenuItems>
						<Item Id="drops11" Name="Slot_1"/>
						<Item Id="drops12" Name="Slot_2"/>
						<Item Id="drops13" Name="Slot_3"/>
						<Item Id="drops14" Name="Slot_4"/>
						<Item Id="drops15" Name="Slot_5"/>
					</MenuItems>
				</Item>

				<Item Id="color_2" Name="Gray">
					<MenuItems>
						<Item Id="drops21" Name="Slot_1"/>
						<Item Id="drops22" Name="Slot_2"/>
						<Item Id="drops23" Name="Slot_3"/>
						<Item Id="drops24" Name="Slot_4"/>
						<Item Id="drops25" Name="Slot_5"/>
					</MenuItems>
				</Item>

				<Item Id="color_3" Name="Red">
					<MenuItems>
						<Item Id="drops31" Name="Slot_1"/>
						<Item Id="drops32" Name="Slot_2"/>
						<Item Id="drops33" Name="Slot_3"/>
						<Item Id="drops34" Name="Slot_4"/>
						<Item Id="drops35" Name="Slot_5"/>
					</MenuItems>
				</Item>

				<Item Id="color_4" Name="Green">
					<MenuItems>
						<Item Id="drops41" Name="Slot_1"/>
						<Item Id="drops42" Name="Slot_2"/>
						<Item Id="drops43" Name="Slot_3"/>
						<Item Id="drops44" Name="Slot_4"/>
						<Item Id="drops45" Name="Slot_5"/>
					</MenuItems>
				</Item>
				
				<Item Id="color_5" Name="Blue">
					<MenuItems>
						<Item Id="drops51" Name="Slot_1"/>
						<Item Id="drops52" Name="Slot_2"/>
						<Item Id="drops53" Name="Slot_3"/>
						<Item Id="drops54" Name="Slot_4"/>
						<Item Id="drops55" Name="Slot_5"/>
					</MenuItems>
				</Item>

				<Item Id="color_6" Name="Orange">
					<MenuItems>
						<Item Id="drops61" Name="Slot_1"/>
						<Item Id="drops62" Name="Slot_2"/>
						<Item Id="drops63" Name="Slot_3"/>
						<Item Id="drops64" Name="Slot_4"/>
						<Item Id="drops65" Name="Slot_5"/>
					</MenuItems>
				</Item>

				<Item Id="color_7" Name="Yellow">
					<MenuItems>
						<Item Id="drops71" Name="Slot_1"/>
						<Item Id="drops72" Name="Slot_2"/>
						<Item Id="drops73" Name="Slot_3"/>
						<Item Id="drops74" Name="Slot_4"/>
						<Item Id="drops75" Name="Slot_5"/>
					</MenuItems>
				</Item>

				<Item Id="color_8" Name="Purple">
					<MenuItems>
						<Item Id="drops81" Name="Slot_1"/>
						<Item Id="drops82" Name="Slot_2"/>
						<Item Id="drops83" Name="Slot_3"/>
						<Item Id="drops84" Name="Slot_4"/>
						<Item Id="drops85" Name="Slot_5"/>
					</MenuItems>
				</Item>


			</MenuItems>
		</Item>

	</MenuItems>
</RootMenu>
*/
#endif
