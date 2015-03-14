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
#pragma once

#include <iostream>
#include <vector>
#include "3DS_UI.h"
#include "3DS_UI_DRAW.h"

class uiElement {
public:
	uiElement();

	void render(uiWindow &window);
	s16 x, y;
	s16 type;
	std::string name;
};

class uiTextBlock : public uiElement {
private:
	std::string content;
	font_s font;
public:
	uiTextBlock(std::string cname);
	void configure(s16 x, s16 y, font_s font, std::string text);
	void render(uiWindow &window);
};

class uiPopUp : public uiElement {
private:
	std::string header;
	std::string message;
	font_s font;
public:
	uiPopUp(std::string cname);
	void configure(std::string title, std::string msg);
	void render(uiWindow &window);
};