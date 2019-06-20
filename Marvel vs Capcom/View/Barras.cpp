#include "../Model/LTexture.h"
#include "Barras.h"
using namespace std;
#define ANCHO_VIDA 324
Barras::Barras(SDL_Renderer * gRen){
		//Set renderer
		gRenderer = gRen;

		//Open the font
		gFont = TTF_OpenFont( "Fuentes/fuente_reloj.ttf", 20);
		if( gFont == NULL )	{
				printf( "DL_ttf Error: %s\n", TTF_GetError() );
			}


		gBordeIzquierda.loadFromFile("Images/barra_borde_izquierda.png", gRenderer, 350, 30);
		gFondoIzquierda.loadFromFile("Images/barra_vida_b.png", gRenderer, ANCHO_VIDA, 25);

		gBordeDerecha.loadFromFile("Images/barra_borde_derecha.png", gRenderer, 350, 30);
		gFondoDerecha.loadFromFile("Images/barra_vida_b.png", gRenderer, ANCHO_VIDA, 25);

		gBordeIzquierdaInf.loadFromFile("Images/barra_borde_izquierda.png", gRenderer, 350, 30);
		gBordeDerechaInf.loadFromFile("Images/barra_borde_derecha.png", gRenderer, 350, 30);

		gFondoIzquierdaInf.loadFromFile("Images/barra_vida_b.png", gRenderer, ANCHO_VIDA, 25);
		gFondoDerechaInf.loadFromFile("Images/barra_vida_b.png", gRenderer, ANCHO_VIDA, 25);



		vidaEquipo0_titular = ANCHO_VIDA;
		vidaEquipo0_suplente = ANCHO_VIDA;
		vidaEquipo1_titular= ANCHO_VIDA;
		vidaEquipo1_suplente =ANCHO_VIDA;



}
void Barras::Reset(){
	//startTime = SDL_GetTicks();
}
void Barras::CargarTexto(string nombre){
	//Set text to be rendered
	nombrePersonaje.str( "" );
	nombrePersonaje << nombre;
	//Render text
	if(!gTextoPersonaje.loadFromRenderedText(nombrePersonaje.str(), textColor, gRenderer, gFont)){
		printf("Carga texto");
	}
}
void Barras::SetVida(int equipo, int jugador, int vida){
	// 324 es una parte de 100.
	double vidaBarra = (3.24)*vida;
	if(equipo == 0){
		if(jugador == 0){
			vidaEquipo0_titular = vidaBarra;
		}else{
			vidaEquipo0_suplente = vidaBarra;
		}
	}else{
		if(jugador == 0){
			vidaEquipo1_titular = vidaBarra;
		}else{
			vidaEquipo1_suplente = vidaBarra;
		}
	}
}
void Barras::ActulializarColores(Equipo * equipos[2]){
	//Colores
	Uint8 colorRojo;
	Uint8 colorVerde;

	//color para el fondo =  TITULARES

	colorRojo = 255-(1*equipos[0]->getJugadorNro(0)->GetVida());
	colorVerde = 2.55*equipos[0]->getJugadorNro(0)->GetVida();
	gFondoIzquierda.setColor(colorRojo, colorVerde, 20);

	colorRojo = 255-(1*equipos[1]->getJugadorNro(0)->GetVida());
	colorVerde = 2.55*equipos[1]->getJugadorNro(0)->GetVida();
	gFondoDerecha.setColor(colorRojo, colorVerde, 20);

	//color para el fondo =  SUPLENTES

	colorRojo = 255-(1*equipos[0]->getJugadorNro(1)->GetVida());
	colorVerde = 2.55*equipos[0]->getJugadorNro(1)->GetVida();
	gFondoIzquierdaInf.setColor(colorRojo, colorVerde, 20);


	colorRojo = 255-(1*equipos[1]->getJugadorNro(1)->GetVida());
	colorVerde = 2.55*equipos[1]->getJugadorNro(1)->GetVida();
	gFondoDerechaInf.setColor(colorRojo, colorVerde, 20);


}
void Barras::render(Equipo * equipos[2]){

	// Calcular el ancho de la barra
	SetVida(0, 0, equipos[0]->getJugadorNro(0)->GetVida());
	SetVida(0, 1, equipos[0]->getJugadorNro(1)->GetVida());
	SetVida(1, 0, equipos[1]->getJugadorNro(0)->GetVida());
	SetVida(1, 1, equipos[1]->getJugadorNro(1)->GetVida());

	//Obtener el nombre del personaje TITULARES
	std::string nombreEquipo0Titular = equipos[0]->getJugadorNro(0)->getNombre();
	std::string nombreEquipo1Titular = equipos[1]->getJugadorNro(0)->getNombre();

	//Obtener el nombre del personaje TITULARES
	std::string nombreEquipo0Suplente = equipos[0]->getJugadorNro(1)->getNombre();
	std::string nombreEquipo1Suplente = equipos[1]->getJugadorNro(1)->getNombre();

	//Posicionescde las barras de vida
	int posXIzquierdo = 2;
	int posXDerecha = 448;

    SDL_Rect barras;
    barras.x = 0;
    barras.y = 0;
    barras.w = 350;
    barras.h = 37;

	SDL_Rect vida;
	vida.x = 0;
	vida.y = 0;
	vida.w = ANCHO_VIDA;
	vida.h = 24;

	//Actualizo colores barrras: Poca vida= Roja // Mucha vida = Verde
	ActulializarColores(equipos);

	// Barra Superior
	gFondoIzquierda.render(posXIzquierdo+8, 11,vidaEquipo0_titular,24, &vida, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
	gBordeIzquierda.render(posXIzquierdo, 10, &barras, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
	CargarTexto(nombreEquipo0Titular);
	gTextoPersonaje.render(posXIzquierdo+115, 11, NULL,0.0, NULL, SDL_FLIP_NONE,gRenderer);


	gFondoDerecha.render(posXDerecha+16+ANCHO_VIDA-vidaEquipo1_titular, 11,vidaEquipo1_titular ,24,&vida, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
	gBordeDerecha.render(posXDerecha, 10, &barras, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
	CargarTexto(nombreEquipo1Titular);
	gTextoPersonaje.render(posXDerecha+135, 11, NULL,0.0, NULL, SDL_FLIP_NONE,gRenderer);

	//Barra inferior
	gFondoIzquierdaInf.render(posXIzquierdo+8, 41,vidaEquipo0_suplente,24, &vida, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
	gBordeIzquierdaInf.render(posXIzquierdo, 40, &barras, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
	CargarTexto(nombreEquipo0Suplente);
	gTextoPersonaje.render(posXIzquierdo+115, 11+30, NULL,0.0, NULL, SDL_FLIP_NONE,gRenderer);

	gFondoDerechaInf.render(posXDerecha+16+ANCHO_VIDA-vidaEquipo1_suplente, 41,vidaEquipo1_suplente ,24,&vida, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
	gBordeDerechaInf.render(posXDerecha, 40, &barras, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
	CargarTexto(nombreEquipo1Suplente);
	gTextoPersonaje.render(posXDerecha+135, 11+30, NULL,0.0, NULL, SDL_FLIP_NONE,gRenderer);



}
Barras::~Barras(){
	//Free loaded images
	gBordeIzquierda.free();
	gFondoIzquierda.free();
	gFondoIzquierdaInf.free();
	gBordeIzquierdaInf.free();

	gBordeDerecha.free();
	gFondoDerecha.free();
	gFondoDerechaInf.free();
	gBordeDerechaInf.free();
}
