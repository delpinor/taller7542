#include "Show.h"
Show::Show(SDL_Renderer * gRen){
	gRenderer = gRen;
	//Mensaje de Inicio de batalla
	gReady.loadFromFile("Images/ready_ok.png", gRenderer, 400, 300);

	//Mensaje de Inicio de batalla
	gWin.loadFromFile("Images/youwin.png", gRenderer, 400, 300);

	//Mensaje de Inicio de batalla
	gLose.loadFromFile("Images/youlose.png", gRenderer, 400, 300);

	//Fuente para los mensajes!!
	gFont = TTF_OpenFont("Fuentes/fuente_reloj.ttf", 70);
}
void Show::CargarTexto(std::string textoMensaje){
	texto.str( "" );
	texto << textoMensaje;
	//Render text
	if(!gTexto.loadFromRenderedText(texto.str(), textColor, gRenderer, gFont)){
		printf("Carga texto");
	}
}
void Show::render(TIPOLEYENDA tipo, std::string mensaje){
	// 1 READY
	if(tipo == READY){
		CargarTexto(mensaje);
		gTexto.render(280, 100, NULL,0.0, NULL, SDL_FLIP_NONE,gRenderer);
		gReady.render(150, 200, NULL, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
	}
	if(tipo == YOUWIN){
		CargarTexto(mensaje);
		gTexto.render(280, 100, NULL,0.0, NULL, SDL_FLIP_NONE,gRenderer);
		gWin.render(150, 200, NULL, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
	}
	if(tipo == YOULOSE){
		CargarTexto(mensaje);
		gTexto.render(280, 100, NULL,0.0, NULL, SDL_FLIP_NONE,gRenderer);
		gLose.render(150, 200, NULL, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
	}
}
Show::~Show(){
	gReady.free();
}
