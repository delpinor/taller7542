#include "../Model/LTexture.h"
#include "Barras.h"
using namespace std;
Barras::Barras(SDL_Renderer * gRen){
		//Set renderer
		gRenderer = gRen;

		//Open the font
		gFont = TTF_OpenFont( "Fuentes/fuente_reloj.ttf", 20);
		if( gFont == NULL )	{
				printf( "DL_ttf Error: %s\n", TTF_GetError() );
			}


		gBordeIzquierda.loadFromFile("Images/barra_borde_izquierda.png", gRenderer, 350, 30);
		gFondoIzquierda.loadFromFile("Images/barra_vida.png", gRenderer, 320, 25);

		gBordeDerecha.loadFromFile("Images/barra_borde_derecha.png", gRenderer, 350, 30);
		gFondoDerecha.loadFromFile("Images/barra_vida.png", gRenderer, 320, 25);



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
void Barras::render(SDL_Rect * camara){

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
	//vida.w = 320;
	vida.w = 120;
	vida.h = 24;

	// Barra Superior
	gFondoIzquierda.render(posXIzquierdo+15, 12,120,24, &vida, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
	gBordeIzquierda.render(posXIzquierdo, 10, &barras, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
	CargarTexto("Nombre 1");
	gTextoPersonaje.render(posXIzquierdo+15+100, 11, NULL,0.0, NULL, SDL_FLIP_NONE,gRenderer);


	gFondoDerecha.render(posXDerecha+15, 12, &vida, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
	gBordeDerecha.render(posXDerecha, 10, &barras, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
	CargarTexto("Nombre 2");
	gTextoPersonaje.render(posXDerecha+15+100, 11, NULL,0.0, NULL, SDL_FLIP_NONE,gRenderer);

	//Barra inferior
	gFondoIzquierda.render(posXIzquierdo+15, 12+30, &vida, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
	gBordeIzquierda.render(posXIzquierdo, 10+30, &barras, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
	CargarTexto("Nombre 3");
	gTextoPersonaje.render(posXIzquierdo+15+100, 11+30, NULL,0.0, NULL, SDL_FLIP_NONE,gRenderer);

	gFondoDerecha.render(posXDerecha+15, 12+30, &vida, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
	gBordeDerecha.render(posXDerecha, 10+30, &barras, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
	CargarTexto("Nombre 4");
	gTextoPersonaje.render(posXDerecha+15+100, 11+30, NULL,0.0, NULL, SDL_FLIP_NONE,gRenderer);



}
void Barras::Apagar(){
	//Free loaded images
	gBordeIzquierda.free();
	gFondoIzquierda.free();

	gBordeDerecha.free();
	gFondoDerecha.free();
}
