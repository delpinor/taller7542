/*
 * ViewEquipo.cpp
 *
 *  Created on: 2 abr. 2019
 *      Author: maciel
 */
#include "ViewEquipo.h"
#include <SDL2/SDL.h>

ViewEquipo::ViewEquipo() {
	cantidadjugadores = 2;
	this->viewJugadores[0] = new View_Jugador_CapAmerica();
	this->viewJugadores[1] = new View_Jugador_Venom();
}


void ViewEquipo::initialize(Equipo * equipo, LTexture texturaJugador[]) {
	for (int i = 0; i < cantidadjugadores; ++i) {
			this->viewJugadores[i]->initialize(equipo->getJugadorNro(i),&texturaJugador[i]);
		}
}

void ViewEquipo::render(int camX, int camY, SDL_Renderer * gRenderer){
	for (int i = 0; i < cantidadjugadores; ++i) {
			this->viewJugadores[i]->render(camX, camY, gRenderer);
		}
}

ViewEquipo::~ViewEquipo() {
	// TODO Auto-generated destructor stub
}

