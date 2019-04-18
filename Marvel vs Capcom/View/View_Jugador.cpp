#include "View_Jugador.h"

#include <sstream>
View_Jugador::View_Jugador() {
}

void View_Jugador::initialize(Jugador * model,
		LTexture * texturaJugador) {
	this->texturaJugador = texturaJugador;
	this->model = model;
}

void View_Jugador::render(int camX, int camY, SDL_Renderer * gRenderer) {
}


