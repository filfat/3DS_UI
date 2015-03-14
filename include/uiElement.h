/*

				3DS GUI (WIP NAME)
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
	~uiElement();

	void render(uiWindow &window);
	s16 x, y;
	s16 type;
protected:
};

class uiTextBlock : public uiElement {
private:
	std::string content;
	font_s font;
public:
	uiTextBlock();
	void configure(s16 x, s16 y, font_s font, std::string text);
	void render(uiWindow &window);
};