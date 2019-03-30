#include "ViewModel.h"
#include <SDL2/SDL.h>

ViewModel::ViewModel(Model* model, SDL_Renderer* gRenderer, SDL_Rect* camara,
		LTexture * texturaPantalla, LTexture texturaJugador[]) {
	this->cantidadjugadores = model->getCantidadJugadores();
	this->viewPantalla.initialize(gRenderer, texturaPantalla);
	this->viewJugadores[0] = new View_Jugador_CapAmerica();
	this->viewJugadores[1] = new View_Jugador_Venom();
	this->camara = camara;
	this->gRenderer = gRenderer;

	for (int i = 0; i < cantidadjugadores; ++i) {
		this->viewJugadores[i]->initialize(model->getJugadorNro(i),&texturaJugador[i]);
	}
}

ViewModel::~ViewModel() {
	delete[] this->viewJugadores;
}

void ViewModel::render() {
	this->viewPantalla.render(this->camara, this->gRenderer);

	for (int i = 0; i < cantidadjugadores; ++i) {
		this->viewJugadores[i]->render(this->camara->x, this->camara->y,
				this->gRenderer);
	}
}

