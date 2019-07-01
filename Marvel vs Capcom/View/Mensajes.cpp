#include "../Model/LTexture.h"
#include "Mensajes.h"
using namespace std;
Mensajes::Mensajes(SDL_Renderer * gRen){
		//Ref. renderer
		gRenderer =  gRen;
		//Open the font
		gFont = TTF_OpenFont( "Fuentes/fuente_reloj.ttf", 25);
		if( gFont == NULL )	{
				printf( "DL_ttf Error: %s\n", TTF_GetError() );
			}
		//Set text color
		textColor = { 225 ,255, 255, 0 };
}
void Mensajes::render(){
	SDL_RenderClear(this->gRenderer);
	//Set text to be rendered
	texto.str( "" );
	texto << MENSAJECARGA;
	//Render text
	if(!gTextTexture.loadFromRenderedText(texto.str(), textColor, gRenderer, gFont)){
		printf("Carga texto");
	}

	//gFondoTexture.render(0, 0, NULL, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
	gTextTexture.render(340, 280, NULL,0.0, NULL, SDL_FLIP_NONE,gRenderer);

}
void Mensajes::Apagar(){
	//Free loaded images
	gTextTexture.free();

	//Free global font
	TTF_CloseFont( gFont );
	gFont = NULL;
}
