#pragma once
#include "../Model/LTexture.h"
#include <sstream>
#include <stdio.h>
#include <string>
#include <iostream>
class Timer{
private:
	SDL_Renderer * gRenderer;
	LTexture gTimeTextTexture;
	LTexture gFondoTimer;
	TTF_Font * gFont = NULL;
	SDL_Color textColor = { 0, 0, 0, 255 };
	std::stringstream timeText;

public:
	Timer(SDL_Renderer * gRenderer);
	~Timer();
	void render(int tiempo);

};
