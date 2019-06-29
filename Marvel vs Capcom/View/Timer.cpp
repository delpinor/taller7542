#include "../Model/LTexture.h"
#include "Timer.h"
using namespace std;
#define ANCHO_PANTALLA 800
Timer::Timer(SDL_Renderer * gRen){
		//Ref. renderer
		gRenderer =  gRen;
		//Open the font
		gFont = TTF_OpenFont( "Fuentes/fuente_reloj.ttf", 25);
		if( gFont == NULL )	{
				printf( "DL_ttf Error: %s\n", TTF_GetError() );
			}
		//Set text color as black
		textColor = { 0,255, 0, 0 };


		//Load timer background
		gFondoTimer.loadFromFile("Images/timer.png", gRenderer, 100, 100);

}
void Timer::render(int tiempo){

	//Uint32 tiempo = (SDL_GetTicks() - startTime)/1000;

	//Set text to be rendered
	timeText.str( "" );
	timeText << tiempo;
	int pxCentrar = 0;
	if(tiempo > 99){
		pxCentrar = 42;

	}else{
		if(tiempo < 10){
			pxCentrar = 54;
		}else{
			pxCentrar = 49;
		}
	}

	//Render text
	if(!gTimeTextTexture.loadFromRenderedText(timeText.str(), textColor, gRenderer, gFont)){
		printf("Carga texto");
	}
	//Render textures
	//gPromptTextTexture.render(camara->x+(camara->w/2), 100, NULL, 0.0, NULL, SDL_FLIP_NONE,gRenderer);
    //void render( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );


	//Alinear cuando el valor del timepo es menor a 100 y 10.
	gFondoTimer.render(342, -6, NULL, 0.0, NULL, SDL_FLIP_NONE, gRenderer);

	gTimeTextTexture.render(342+pxCentrar, 10, NULL,0.0, NULL, SDL_FLIP_NONE,gRenderer);



}
Timer::~Timer(){
	//Free loaded images
	gTimeTextTexture.free();
	gFondoTimer.free();

	//Free global font
	TTF_CloseFont( gFont );
	gFont = NULL;
}
