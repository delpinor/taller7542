#include "../Model/LTexture.h"
#include "Barras.h"
using namespace std;
#define ANCHO_VIDA 279
Barras::Barras(SDL_Renderer * gRen){
		//Set renderer
		gRenderer = gRen;

		//Open the font
		gFont = TTF_OpenFont( "Fuentes/fuente_reloj.ttf", 20);
		if( gFont == NULL )	{
				printf( "DL_ttf Error: %s\n", TTF_GetError() );
			}
		//Fotos personajes
		gFotoSpider.loadFromFile("Images/pj_spider.gif", gRenderer, 60, 60);
		gFotoChunli.loadFromFile("Images/pj_chunli.gif", gRenderer, 60, 60);
		gFotoVenom.loadFromFile("Images/pj_venom.gif", gRenderer, 60, 60);
		gFotoAmerica.loadFromFile("Images/pj_america.gif", gRenderer, 60, 60);


		gBordeIzquierda.loadFromFile("Images/barra_borde_izquierda.png", gRenderer, 300, 30);
		gFondoIzquierda.loadFromFile("Images/barra_vida_b.png", gRenderer, ANCHO_VIDA, 25);

		gBordeDerecha.loadFromFile("Images/barra_borde_derecha.png", gRenderer, 300, 30);
		gFondoDerecha.loadFromFile("Images/barra_vida_b.png", gRenderer, ANCHO_VIDA, 25);

		gBordeIzquierdaInf.loadFromFile("Images/barra_borde_izquierda.png", gRenderer, 250, 30);
		gBordeDerechaInf.loadFromFile("Images/barra_borde_derecha.png", gRenderer, 250, 30);

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
void Barras::CargarTexto(string nombre, SDL_Color color){
	//Set text to be rendered
	nombrePersonaje.str( "" );
	nombrePersonaje << nombre;
	//Render text
	if(!gTextoPersonaje.loadFromRenderedText(nombrePersonaje.str(), color, gRenderer, gFont)){
		printf("Carga texto");
	}
}
void Barras::SetVida(int equipo, int jugador, int vida){
	// 324 es una parte de 100.
	double vidaBarra = (2.79)*vida;
	if(equipo == 0){
		if(jugador == 0){
			vidaEquipo0_titular = vidaBarra;
		}else{
			vidaEquipo0_suplente = vidaBarra*0.83;
		}
	}else{
		if(jugador == 0){
			vidaEquipo1_titular = vidaBarra;
		}else{
			vidaEquipo1_suplente = vidaBarra*0.83;
		}
	}
}
void Barras::RenderFoto(int x, int y, std::string nombre){
	if( nombre == "Captain America"){
		gFotoAmerica.render(x, y, NULL, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
	}

	if( nombre == "Venom"){
		gFotoVenom.render(x,y, NULL, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
	}

	if( nombre == "Spiderman"){
		gFotoSpider.render(x, y, NULL, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
	}

	if( nombre == "Chun Li"){
		gFotoChunli.render(x, y, NULL, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
	}
}
void Barras::ActulializarColores(Equipo * equipos[2]){
	//Colores
	Uint8 colorRojo;
	Uint8 colorVerde;

	//color para el fondo =  TITULARES

	colorRojo = 255-(1*equipos[0]->getJugadorActivo()->GetVida());
	colorVerde = 2.55*equipos[0]->getJugadorActivo()->GetVida();
	gFondoIzquierda.setColor(colorRojo, colorVerde, 20);

	colorRojo = 255-(1*equipos[1]->getJugadorActivo()->GetVida());
	colorVerde = 2.55*equipos[1]->getJugadorActivo()->GetVida();
	gFondoDerecha.setColor(colorRojo, colorVerde, 20);

	//color para el fondo =  SUPLENTES

	colorRojo = 255-(1*equipos[0]->getJugadorInactivo()->GetVida());
	colorVerde = 2.55*equipos[0]->getJugadorInactivo()->GetVida();
	gFondoIzquierdaInf.setColor(colorRojo, colorVerde, 20);


	colorRojo = 255-(1*equipos[1]->getJugadorInactivo()->GetVida());
	colorVerde = 2.55*equipos[1]->getJugadorInactivo()->GetVida();
	gFondoDerechaInf.setColor(colorRojo, colorVerde, 20);


}
void Barras::render(Equipo * equipos[2]){
	// Color nombres
	SDL_Color colorNombres = { 4, 147, 199, 255 };

	// Color score
	SDL_Color colorScore= { 255, 255, 255, 255 };


	// Calcular el ancho de la barra
	SetVida(0, 0, equipos[0]->getJugadorActivo()->GetVida());
	SetVida(0, 1, equipos[0]->getJugadorInactivo()->GetVida());

	SetVida(1, 0, equipos[1]->getJugadorActivo()->GetVida());
	SetVida(1, 1, equipos[1]->getJugadorInactivo()->GetVida());

	//Obtener el nombre del personaje TITULARES
	std::string nombreEquipo0Titular = equipos[0]->getJugadorActivo()->getNombre();
	std::string nombreEquipo1Titular = equipos[1]->getJugadorActivo()->getNombre();

	//Obtener el nombre del personaje SUPLENTES
	std::string nombreEquipo0Suplente = equipos[0]->getJugadorInactivo()->getNombre();
	std::string nombreEquipo1Suplente = equipos[1]->getJugadorInactivo()->getNombre();

	//Rondas ganadas
	int rondasEquipo0 = equipos[0]->getRondasGanadas();
	int rondasEquipo1 = equipos[1]->getRondasGanadas();

	//Posicionescde las barras de vida
	int posXIzquierdo = 52;
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
	CargarTexto(nombreEquipo0Titular, colorNombres);
	gTextoPersonaje.render(posXIzquierdo+115, 11, NULL,0.0, NULL, SDL_FLIP_NONE,gRenderer);


	gFondoDerecha.render(posXDerecha+13+ANCHO_VIDA-vidaEquipo1_titular, 11,vidaEquipo1_titular ,24,&vida, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
	gBordeDerecha.render(posXDerecha, 10, &barras, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
	CargarTexto(nombreEquipo1Titular, colorNombres);
	gTextoPersonaje.render(posXDerecha+135, 11, NULL,0.0, NULL, SDL_FLIP_NONE,gRenderer);

	//Barra inferior
	gFondoIzquierdaInf.render(posXIzquierdo+8, 41,vidaEquipo0_suplente,24, &vida, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
	gBordeIzquierdaInf.render(posXIzquierdo, 40, &barras, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
	CargarTexto(nombreEquipo0Suplente, colorNombres);
	gTextoPersonaje.render(posXIzquierdo+115, 11+30, NULL,0.0, NULL, SDL_FLIP_NONE,gRenderer);

	gFondoDerechaInf.render(posXDerecha+13+ANCHO_VIDA-vidaEquipo1_suplente, 41,vidaEquipo1_suplente ,24,&vida, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
	gBordeDerechaInf.render(posXDerecha+50, 40, &barras, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
	CargarTexto(nombreEquipo1Suplente, colorNombres);
	gTextoPersonaje.render(posXDerecha+135, 11+30, NULL,0.0, NULL, SDL_FLIP_NONE,gRenderer);

	//Rondas ganadas

	CargarTexto(std::to_string(rondasEquipo0) + " : " + std::to_string(rondasEquipo1), colorScore);
	gTextoPersonaje.render(386, 60,30,24, NULL, 0.0, NULL, SDL_FLIP_NONE, gRenderer);

	//Foto Equipo 0
	RenderFoto(1, 11, nombreEquipo0Titular);

	//Foto Equipo 1
	RenderFoto(739, 11, nombreEquipo1Titular);


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

	gFotoSpider.free();
	gFotoChunli.free();
	gFotoVenom.free();
	gFotoAmerica.free();
}
