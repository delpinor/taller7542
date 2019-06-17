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

	LTexture gTextoPersonaje;
	SDL_Renderer * gRenderer;

	TTF_Font * gFont = NULL;
	SDL_Color textColor = { 255, 165, 0, 255 };
	std::stringstream nombrePersonaje;
	void CargarTexto(std::string nombre);


public:
	Barras(SDL_Renderer * gRenderer);
	void Reset();
	void Apagar();
	void render(SDL_Rect * cam);

};
