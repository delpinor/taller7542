#ifndef VIEW_H
#define VIEW_H

#include "ViewModel.h"
#include "../Model/Model.h"
#include <string>
#include <cstdlib>
#include "FondoParallax.h"

class View {
public:
	View(Model* model);
	virtual ~View();
	void ajustarCamara();
	void render();
	bool inicializar();
	void loadMedia(Model *model);
	void close();
#define ANCHO_JUGADOR 146
#define ALTO_JUGADOR 146
#define ANCHO_VENTANA 800
#define ALTO_VENTANA 600
#define ANCHO_NIVEL 1000
#define ALTO_NIVEL 626
private:
	Model* model;
	Jugador* jugadorAnterior;
	ViewModel* viewModel;
	SDL_Rect* camara;
	SDL_Rect camaraStatic;
	SDL_Renderer* gRenderer;
	SDL_Window* window;
	FondoParallax * pantalla;
	LTexture texturas[2];
	LTexture texturaCaptainAmerica;
	LTexture texturaVenom;
	LTexture texturaJugador;

};

#endif // VIEW_H
