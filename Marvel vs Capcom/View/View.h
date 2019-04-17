#ifndef VIEW_H
#define VIEW_H

#include "ViewModel.h"
#include "../Model/Model.h"
#include <string>
#include <cstdlib>
#include "FondoParallax.h"

#define ANCHO_JUGADOR 146
#define ALTO_JUGADOR 146
//#define ANCHO_VENTANA 800
//#define ALTO_VENTANA 600
#define ANCHO_NIVEL 1920
#define ALTO_NIVEL 1080

class View {
public:
	View(Model* model);
	void SetPosicionInicialJugadores();
	void ajustarCamara();
	void render();
	bool inicializar(Model *model);
	void loadMedia(Model *model);
	void close();
	virtual ~View();

private:
	Model* model;
	Jugador* jugadorAnterior;
	ViewModel* viewModel;
	SDL_Rect* camara;
	SDL_Rect camaraStatic;
	SDL_Renderer* gRenderer;
	SDL_Window* window;
	FondoParallax * pantalla;
	LTexture texturasEquipo1[2];
	LTexture texturasEquipo2[2];
	LTexture texturaCaptainAmerica;
	LTexture texturaVenom;
	LTexture texturaJugador;
	int ancho_Pantalla, alto_Pantalla;

};

#endif // VIEW_H
