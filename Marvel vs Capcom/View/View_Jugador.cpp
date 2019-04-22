#include "View_Jugador.h"

#include <sstream>
View_Jugador::View_Jugador() {
}

void View_Jugador::initialize(Jugador * model,
		LTexture * texturaJugador) {
	this->texturaJugador = texturaJugador;
	this->model = model;
	this->zIndex = model->get_zindex();
}

void View_Jugador::render(int camX, int camY, SDL_Renderer * gRenderer) {
}

int View_Jugador::getZIndex(){
	return this->zIndex;
}

