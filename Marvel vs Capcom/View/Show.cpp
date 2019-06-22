#include "Show.h"
Show::Show(SDL_Renderer * gRen){
	gRenderer = gRen;
	//Mensaje de Inicio de batalla
	gReady.loadFromFile("Images/ready_ok.png", gRenderer, 400, 300);

	//Mensaje de Inicio de batalla
	gWin.loadFromFile("Images/win.png", gRenderer, 300, 156);

	//Mensaje de Inicio de batalla
	gLose.loadFromFile("Images/lose.png", gRenderer, 300, 131);

	//Mensaje de resultados
	gAmerica.loadFromFile("Images/america-foto.png", gRenderer, 320, 107);
	//Mensaje de resultados
	gChunlee.loadFromFile("Images/chunli-foto.png", gRenderer, 320, 107);
	//Mensaje de resultados
	gSpider.loadFromFile("Images/spider-foto.png", gRenderer, 320, 107);
	//Mensaje de resultados
	gVenom.loadFromFile("Images/venom-foto.png", gRenderer, 320, 107);

	//Mensaje de resultados
	gBorde.loadFromFile("Images/borde_resultado.png", gRenderer, 320, 107);

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
void Show::render(TIPOLEYENDA tipo, std::string mensaje, Equipo * equipos[2]){
	// 1 READY
	if(tipo == READY){
		CargarTexto(mensaje);
		gTexto.render(300, 100, NULL,0.0, NULL, SDL_FLIP_NONE,gRenderer);
		gReady.render(155, 200, NULL, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
	}

	bool ganoEquipo0 = false;
	if(tipo == RESULTADOS){
			if(equipos[0]->getRondasGanadas() > equipos[1]->getRondasGanadas()){
				gWin.render(50, 160,300, 156, NULL, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
				gLose.render(460, 160,300,131, NULL, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
				ganoEquipo0 = true;
			}else{
				gWin.render(460, 160,300, 156, NULL, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
				gLose.render(50, 160,300,131, NULL, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
			}
			//Personajes
			RenderPersonaje(50,350,equipos[0]->getJugadorActivo()->getNombre());
			RenderPersonaje(50,461,equipos[0]->getJugadorInactivo()->getNombre());
			RenderPersonaje(430,350,equipos[1]->getJugadorActivo()->getNombre());
			RenderPersonaje(430,461,equipos[1]->getJugadorInactivo()->getNombre());

	}
}
void Show::RenderPersonaje(int x, int y, std::string nombre){
	std::cout << "Campeon: " << nombre << std::endl;
	if( nombre == "Captain America"){
		gAmerica.render(x, y, NULL, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
	}

	if( nombre == "Venom"){
		gVenom.render(x,y, NULL, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
	}

	if( nombre == "Spiderman"){
		gSpider.render(x, y, NULL, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
	}

	if( nombre == "Chun Li"){
		gChunlee.render(x, y, NULL, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
	}
	gBorde.setAlpha( std::rand() % (255 + 1 - 100) + 100);
	//Marco de color
	gBorde.render(x, y, NULL, 0.0, NULL, SDL_FLIP_NONE, gRenderer);

}
Show::~Show(){
	gReady.free();
}
