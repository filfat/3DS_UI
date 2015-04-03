/*
	  ____  _____   _____       _    _ _____ 
	 |___ \|  __ \ / ____|     | |  | |_   _|
	   __) | |  | | (___ ______| |  | | | |  
	  |__ <| |  | |\___ \______| |  | | | |  
	  ___) | |__| |____) |     | |__| |_| |_ 
	 |____/|_____/|_____/       \____/|_____|
				EXAMPLE 1 "Basic"
			 � Filiph Sandstr�m 2015

		   SEE "LICENSE" FOR THE LICENSE
*/

//Required classes for 3DS_UI
#include <3ds.h>
#include <iostream>
#include <vector>
#include <3DS_UI.h>
#include <3DS_UI/Fonts/OpenSans_Regular.h>

int main() {
	//Initialize services
	srvInit();
	aptInit();
	hidInit(NULL);
	
	//Init 3DS_UI
	uiInit();

	//Enable 3D
	uiSet3D(true);
	
	uiSetBackgroundColor(Colors::Black); //Temp

	//Creates two windows, one for the upper screen and one for the bottom screen
	uiWindow windowTop = uiWindow(true);
	uiWindow windowBottom = uiWindow(false);
	windowTop.set3D(true);

	//Creates a new Rect
	uiRect* rect = new uiRect("Rect1");
	rect->configure({ 50, 70 }, 40, 40, Colors::Magenta);

	//Create a copy of the default font & set the size
	uiTtfFont Font = OpenSansFont;

	//Creates a textBlock
	uiTextBlock* textBlock = new uiTextBlock("TextBlock1");
	textBlock->configure({ 5, 20 }, Font, "Hello World!", Colors::Green);
	
	//Adds the elements to the selected windows
	windowBottom.addElement(rect);
	windowBottom.addElement(textBlock);

	//Sets the windowTop's navbar header
	windowTop.setNavbarHeader("Example 1");

	while (aptMainLoop())
	{
		//Return to the launcher if we press 'A'
		hidScanInput();
		u32 kDown = hidKeysDown();
		if (kDown & KEY_A)
			break;

		//Renders both windows
		
		windowTop.render();
		windowBottom.render();

		//Call when you have rendered the window(s)
		uiFinishRendering();
	}

	//Removes the elements
	windowBottom.removeElement("Rect1");
	windowBottom.removeElement("TextBlock1");

	//Exit UI
	uiExit();

	//Deinitialize services
	hidExit();
	aptExit();
	srvExit();
	return 0;
}
