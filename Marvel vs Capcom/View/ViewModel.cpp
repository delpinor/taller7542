#include "ViewModel.h"
#include <SDL2/SDL.h>

ViewModel::ViewModel(Model* model, SDL_Renderer* gRenderer, SDL_Rect* camara, FondoParallax * pantalla, LTexture * texturaJugador) {
	this->cantidadjugadores = model->getCantidadJugadores();
	//this->viewPantalla.initialize(gRenderer, texturaPantalla);
	pantalla->refrescar(camara);
	this->viewJugadores = new View_Jugador[cantidadjugadores];
	this->camara = camara;
	this->gRenderer = gRenderer;
	this->fondoParallax = pantalla;
	for (int i = 0; i < cantidadjugadores; ++i) {
		this->viewJugadores[i].initialize(model->getJugadorNro(i),
				texturaJugador);
	}
}

ViewModel::~ViewModel() {
	delete[] this->viewJugadores;
}

void ViewModel::render() {
	//this->viewPantalla.render(this->camara, this->gRenderer);
	fondoParallax->refrescar(camara);
	for (int i = 0; i < cantidadjugadores; ++i) {
		this->viewJugadores[i].render(this->camara->x, this->camara->y,
				this->gRenderer);
	}
}

