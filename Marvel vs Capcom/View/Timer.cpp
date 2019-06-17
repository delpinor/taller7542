#include "../Model/LTexture.h"
#include "Timer.h"
using namespace std;
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

		//Set startTime
		startTime = SDL_GetTicks();

		//Load timer background
		gFondoTimer.loadFromFile("Images/timer.png", gRenderer, 100, 100);

}
void Timer::Reset(){
	startTime = SDL_GetTicks();
}
void Timer::render(SDL_Rect * camara){

	Uint32 tiempo = (SDL_GetTicks() - startTime)/100;

	//Set text to be rendered
	timeText.str( "" );
	timeText << tiempo;
	int pxCentrar = 0;
	if(tiempo > 99){
		pxCentrar = 43;

	}else{
		if(tiempo < 10){
			pxCentrar = 55;
		}else{
			pxCentrar = 48;
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
	int posX = (camara->w/2 - 60);
	gFondoTimer.render(posX,  2, NULL, 0.0, NULL, SDL_FLIP_NONE, gRenderer);

	gTimeTextTexture.render(posX+pxCentrar, 18, NULL,0.0, NULL, SDL_FLIP_NONE,gRenderer);



}
void Timer::Apagar(){
	//Free loaded images
	gTimeTextTexture.free();

	//Free global font
	TTF_CloseFont( gFont );
	gFont = NULL;
}
