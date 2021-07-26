#include "LED.h"
#include "GLCD.h"
#include "KBD.h"
#include "usbdmain.h"
#include "photogallery.h"

#define __FI	1
#define resetvalue	1


int main (void){
	/*MAIN PROGRAM*/
	int KBD_present = 8, KBD_past = 0, menu_scroll = 1;
	// KBD values for recording joystick states, menu scroll to select programs
	
	KBD_Init();
	LED_Init();
	GLCD_Init();
	
			GLCD_Clear(White);	//Clear the screen and make it black
			GLCD_SetBackColor(Black);
			GLCD_SetTextColor(Green);
	
	for(;;){	//infinite loop

			GLCD_DisplayString(0, 0, __FI, "   COE718 Project   ");
			GLCD_DisplayString(1, 0, __FI, "  Media Center Demo ");
			GLCD_DisplayString(2, 0, __FI, "  <<<<main menu>>>> ");
			GLCD_DisplayString(3, 0, __FI, "                    ");		
			GLCD_DisplayString(4, 0, __FI, " scroll  RIGHT/LEFT ");	
			GLCD_DisplayString(5, 0, __FI, "      select UP     ");
			GLCD_DisplayString(6, 0, __FI, "                    ");
		
		KBD_present = get_button();	//get joystick value
		
		if (KBD_present != KBD_past){		//check for idle state
			
			switch(KBD_present){
				case KBD_LEFT :
					menu_scroll = menu_scroll-1;		//shifts left 1 bit (x2)
					if (menu_scroll == 0)
						menu_scroll = resetvalue;		//if menu goes over 2x2x2, go back to beginning (1)
					break;
				
				case KBD_RIGHT :
					menu_scroll = menu_scroll+1;
				if (menu_scroll == 4)
					menu_scroll = 1;	//if menu goes above the top, shift scroll to bottom
				break;
				
				case KBD_UP :
					
					switch(menu_scroll){
						case 1 :
						GLCD_Clear(Black);
						GLCD_SetBackColor(Green);
						GLCD_SetTextColor(Purple);
						GLCD_DisplayString(5, 0, __FI, "    Photo Gallery   ");
						GLCD_DisplayString(6, 0, __FI, "   DOWN to go back  ");
						photogallery();
						break;
						
						case 2 :
							//audio
						GLCD_Clear(White);
						GLCD_SetBackColor(Green);
						GLCD_SetTextColor(Purple);
						GLCD_DisplayString(5, 0, __FI, "    Audio Player    ");
						GLCD_DisplayString(6, 0, __FI, "   DOWN to go back   ");
						audiomain();
						break;
						
						case 3 :
							//game
						break;
					}
			}
			KBD_past = KBD_present;
		}
		switch (menu_scroll){		//displays current menu scroll position
			case 1 :
				GLCD_SetBackColor(Green);
				GLCD_SetTextColor(Purple);
				GLCD_DisplayString(7, 0, __FI, "^^^Photo  Gallery^^^");
				GLCD_SetBackColor(Black);
				GLCD_SetTextColor(Green);
				GLCD_DisplayString(8, 0, __FI, " <      Game      < ");			
				GLCD_DisplayString(9, 0, __FI, " >  Audio Player  > ");
			break;
			
			case 2 :
				GLCD_SetBackColor(Green);
				GLCD_SetTextColor(Purple);
				GLCD_DisplayString(7, 0, __FI, "^^^ Audio Player ^^^");
				GLCD_SetBackColor(Black);
				GLCD_SetTextColor(Green);
				GLCD_DisplayString(8, 0, __FI, " < Photo Gallery < ");			
				GLCD_DisplayString(9, 0, __FI, " >      Game     > ");
			break;
			
			case 3 :
				GLCD_SetBackColor(Green);
				GLCD_SetTextColor(Purple);
				GLCD_DisplayString(7, 0, __FI, "^^^     Game     ^^^");
				GLCD_SetBackColor(Black);
				GLCD_SetTextColor(Green);
				GLCD_DisplayString(8, 0, __FI, " <  Audio Player  < ");			
				GLCD_DisplayString(9, 0, __FI, " > Photo  Gallery > ");
			break;
			
			default :
			GLCD_SetBackColor(Black);
			GLCD_SetTextColor(Green);
			GLCD_DisplayString(0, 0, __FI, "   COE718 Project   ");
			GLCD_DisplayString(1, 0, __FI, "  Media Center Demo ");
			GLCD_DisplayString(2, 0, __FI, "  <<<<main menu>>>> ");
			GLCD_DisplayString(3, 0, __FI, "                    ");		
			GLCD_DisplayString(4, 0, __FI, " scroll  RIGHT/LEFT ");	
			GLCD_DisplayString(5, 0, __FI, "      select UP     ");
			GLCD_DisplayString(6, 0, __FI, "                    ");	
			break;
		}
	}
}