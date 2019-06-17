#include "../Model/LTexture.h"
#include <sstream>
#include <stdio.h>
#include <string>
#include <iostream>
#include "../Model/Equipo.h"

class Barras{
private:
	LTexture gBordeIzquierda;
	LTexture gBordeIzquierdaInf;
	LTexture gFondoIzquierda;
	LTexture gFondoIzquierdaInf;


	LTexture gBordeDerecha;
	LTexture gBordeDerechaInf;
	LTexture gFondoDerecha;
	LTexture gFondoDerechaInf;



	LTexture gTextoPersonaje;
	SDL_Renderer * gRenderer;

	TTF_Font * gFont = NULL;
	SDL_Color textColor = { 255, 165, 0, 255 };
	std::stringstream nombrePersonaje;
	void CargarTexto(std::string nombre);
	void SetVida(int equipo, int jugador, int vida);
	void ActulializarColores(Equipo * equipos[2]);

	int vidaEquipo0_titular;
	int vidaEquipo0_suplente;
	int vidaEquipo1_titular;
	int vidaEquipo1_suplente;


public:
	Barras(SDL_Renderer * gRenderer);
	~Barras();
	void Reset();
	void Apagar();
	void render(Equipo * equipos[2]);

};
