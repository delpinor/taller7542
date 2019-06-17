#include "../Model/LTexture.h"
#include <sstream>
#include <stdio.h>
#include <string>
#include <iostream>
class Barras{
private:
	LTexture gBordeIzquierda;
	LTexture gFondoIzquierda;

	LTexture gBordeDerecha;
	LTexture gFondoDerecha;

	SDL_Renderer * gRenderer;

public:
	Barras(SDL_Renderer * gRenderer);
	void Reset();
	void Apagar();
	void render(SDL_Rect * cam);

};
