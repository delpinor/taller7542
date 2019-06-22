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
	int anchoPantalla, altoPantalla;
	int anchoPantallaZ1;
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


public:
	bool PantallaFija =  false;
	void refrescarPosicion(SDL_Rect * cam);

	FondoParallax(SDL_Window * ventana, SDL_Renderer * renderer, std::string rutaZ1, std::string rutaZ2, std::string rutaZ3);

	void cargaInicial(std::string rutaZ1, std::string rutaZ2, std::string rutaZ3);
	void moverDerecha(int velocidad);
	void moverIzquierda(int velocidad);
	void render(int fondoId);
	~FondoParallax();
};
