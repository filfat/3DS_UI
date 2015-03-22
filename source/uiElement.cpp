/*
	  ____  _____   _____       _    _ _____ 
	 |___ \|  __ \ / ____|     | |  | |_   _|
	   __) | |  | | (___ ______| |  | | | |  
	  |__ <| |  | |\___ \______| |  | | | |  
	  ___) | |__| |____) |     | |__| |_| |_ 
	 |____/|_____/|_____/       \____/|_____|
			 � Filiph Sandstr�m 2015

		TODO(In this file):
		* Alot
		CONTRIBUTORS(In this file):
		* Filiph Sandstr�m (filfat)

		   SEE "LICENSE" FOR THE LICENSE
*/
#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "3DS_UI/uiElement.h"
#include "3DS_UI/uiWindow.h"
#include "3DS_UI/defines.h"

/* uiElement */
uiElement::uiElement() {
	type = 0;
}

void uiElement::render() { } //Override me
void uiElement::setCallback(void(*ccallback)(void)) {
	callback = ccallback;
}
/* uiTextBlock */
uiTextBlock::uiTextBlock(std::string cname) {
	type = 1;
	name = cname;
}
void uiTextBlock::configure(s16 nx, s16 ny, font_s cfont, std::string text) {
	/*content = text;
	font = cfont;
	x = nx;
	y = (ny + (STATUSBAR_H + NAVBAR_H)) + font.height;
}
void uiTextBlock::render(uiWindow &window) {
#ifdef DEBUG
	svcOutputDebugString("rendering uiTextBlock", 255);
#endif
	gfxDrawText(window.settings.isTopScreen ? GFX_TOP : GFX_BOTTOM, GFX_LEFT, &font, (char*)content.c_str(), x, y);
	if(window.settings.is3DEnabled)
		gfxDrawText(GFX_TOP, GFX_RIGHT, &font, (char*)content.c_str(), x, y);*/
}

/* uiTextBox */
uiTextBox::uiTextBox(std::string cname) {
	type = 2;
}
void uiTextBox::configure(s16 nx, s16 ny, font_s cfont, std::string placeholderText, RGB bg, RGB borderColor) {
	x = nx;
	y = ny;
	placeholder = placeholderText;
	background = bg;
	border = borderColor;
}
void uiTextBox::render() {
	//TODO
}

/* uiPopUp */
uiPopUp::uiPopUp(std::string cname) {
	type = 4;
}

void uiPopUp::configure(std::string title, std::string msg, std::string b1, std::string b2, font_s titleFont, font_s cfont, RGB cborder, RGB bg, RGB titleBg, RGB cb1, RGB cb2) {
	message = msg;
	header = title;
	button1 = b1;
	button2 = b2;
	font = cfont;
	headerFont = titleFont;
	border = cborder;
	background = bg;
	headerBackground = titleBg;
	button1Color = cb1;
	button2Color = cb2;
}

void uiPopUp::render() {
	//TODO: Interactable & Add values to defines.h
//	if (window.settings.isTopScreen) return; //PopUp is bottom-screen only!
//#ifdef DEBUG
//	svcOutputDebugString("rendering uiPopUp", 255);
//#endif
//	drawFillRect(UIPOPUP_BORDER_X, 58, UIPOPUP_BORDER_Y, 191, border.R, border.G, border.B, window.framebuf1);									//Border
//	drawFillRect(UIPOPUP_X, 60, UIPOPUP_Y, 85, background.R, background.G, background.B, window.framebuf1);						//Body
//	drawFillRect(UIPOPUP_X, 85, UIPOPUP_Y, 189, headerBackground.R, headerBackground.G, headerBackground.B, window.framebuf1);	//Header
//	gfxDrawText(GFX_BOTTOM, GFX_LEFT, &headerFont, (char*)header.c_str(), UIPOPUP_HEADER_X, UIPOPUP_HEADER_Y);
//	gfxDrawText(GFX_BOTTOM, GFX_LEFT, &font, (char*)message.c_str(), 0, 0);
//
//	drawFillRect(50, 151, 141, 179, button1Color.R, button1Color.G, button1Color.B, window.framebuf1);
//	gfxDrawText(GFX_BOTTOM, GFX_LEFT, &font, (char*)button1.c_str(), 58, 177);
//	if (button2 != "")
//	{
//		drawFillRect(166, 151, 257, 179, button2Color.R, button2Color.G, button2Color.B, window.framebuf1);
//		gfxDrawText(GFX_BOTTOM, GFX_LEFT, &font, (char*)button2.c_str(), 174, 177);
//	}
}