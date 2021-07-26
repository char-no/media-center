#include "photogallery.h"
#include "string.h"
#include "GLCD.h"
#include "LED.h"
#include "KBD.h"
#include "shane.c"
#include "granny.c"
#include "lewis.c"


void photogallery(void){
	int pic = 0;

	LED_Init ();
  GLCD_Init();
	GLCD_Clear(White);
	GLCD_SetBackColor(Green);
	GLCD_SetTextColor(Purple);
	GLCD_DisplayString(5, 0, 1, "   Photo  Gallery   ");

	while (get_button() != KBD_DOWN){   //DOWN is exit to main menu
	if (get_button() == KBD_RIGHT){
		GLCD_Clear(White);
		pic +=1;
		if (pic == 4)
			pic = 1;
	}
	if (get_button() == KBD_LEFT){
		GLCD_Clear(White);
		pic -=1;
		if (pic == 0)
			pic = 3;
	}
	
	
	switch(pic){
		case 1:
			GLCD_Bitmap (40, 15, 230, 209, SHANE_PIXEL_DATA);
		break;
		case 2:
			GLCD_Bitmap (65, 20, 192, 192, GRANNY_PIXEL_DATA);
		break;
		case 3:
			GLCD_Bitmap (45, 4, 234, 231, LEWIS_PIXEL_DATA);
		break;
	}
	}
}
