#include "../Model/LTexture.h"
#include "Barras.h"
using namespace std;
Barras::Barras(SDL_Renderer * gRen){
		//Set renderer
		gRenderer = gRen;
//		//Open the font
//		gFont = TTF_OpenFont( "Fuentes/fuente_reloj.ttf", 25);
//		if( gFont == NULL )	{
//				printf( "DL_ttf Error: %s\n", TTF_GetError() );
//			}
//		//Set text color as black
//		textColor = { 0,255, 0, 0 };
//
//		//Set startTime
//		startTime = SDL_GetTicks();

		gBordeIzquierda.loadFromFile("Images/barra_borde_izquierda.png", gRenderer, 350, 30);
		gFondoIzquierda.loadFromFile("Images/barra_vida.png", gRenderer, 320, 25);

		gBordeDerecha.loadFromFile("Images/barra_borde_derecha.png", gRenderer, 350, 30);
		gFondoDerecha.loadFromFile("Images/barra_vida.png", gRenderer, 320, 25);



}
void Barras::Reset(){
	//startTime = SDL_GetTicks();
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
	vida.w = 320;
	vida.h = 24;

	gFondoIzquierda.render(posXIzquierdo+15, 12, &vida, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
	gBordeIzquierda.render(posXIzquierdo, 10, &barras, 0.0, NULL, SDL_FLIP_NONE, gRenderer);

	gFondoDerecha.render(posXDerecha+15, 12, &vida, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
	gBordeDerecha.render(posXDerecha, 10, &barras, 0.0, NULL, SDL_FLIP_NONE, gRenderer);

}
void Barras::Apagar(){
	//Free loaded images
	gBordeIzquierda.free();
	gFondoIzquierda.free();

	gBordeDerecha.free();
	gFondoDerecha.free();
}
