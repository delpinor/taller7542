//BEGIN HEAD
//BEGIN DESCRIPTION
//END   DESCRIPTION

//BEGIN INCLUDES
//local headers
#pragma once
#include <iostream>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
class FondoParallax{
private:
	int anchoPantalla;
	int altoPantalla;
	SDL_Surface *temp_surface;

	SDL_Texture * fondoZ1;
	SDL_Rect rectZ1_Hasta;
	SDL_Rect rectZ1_Desde;

	SDL_Texture * fondoZ2;
	SDL_Rect rectZ2_Hasta;
	SDL_Rect rectZ2_Desde;

	SDL_Texture * fondoZ3;
	SDL_Rect rectZ3_Hasta;
	SDL_Rect rectZ3_Desde;
	SDL_Window * ventana;
	SDL_Renderer * renderer;
	int pos_x_anterior;
	void cargaInicial();

public:
	void refrescar(SDL_Rect * cam);
	FondoParallax(SDL_Window * ventana, SDL_Renderer * renderer, int ancho, int alto);
	void moverDerecha(int velocidad);
	void moverIzquierda(int velocidad);
	~FondoParallax();
};
