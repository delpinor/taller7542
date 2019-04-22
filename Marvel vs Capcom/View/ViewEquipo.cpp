/*
 * ViewEquipo.cpp
 *
 *  Created on: 2 abr. 2019
 *      Author: maciel
 */
#include "ViewEquipo.h"
#include <SDL2/SDL.h>

ViewEquipo::ViewEquipo(Equipo* equipo) {

	cantidadjugadores = 2;
	this->viewJugadores[0] = cargarVistaPersonaje(equipo->jugadores[0]->getNombre());
	this->viewJugadores[1] = cargarVistaPersonaje(equipo->jugadores[1]->getNombre());
}

View_Jugador * ViewEquipo::cargarVistaPersonaje(std::string nombrePersonaje) {

	if (nombrePersonaje == "Venom")
		return new View_Jugador_Venom();
	if (nombrePersonaje == "Captain America")
		return new View_Jugador_CapAmerica();
	if (nombrePersonaje == "default")
		return new View_Jugador_Default();
	if (nombrePersonaje == "Captain America Black")
		return new View_Jugador_CapAmericaBlack();
	if (nombrePersonaje == "Venom Black")
		return new View_Jugador_VenomBlack();
	if (nombrePersonaje == "Spiderman")
		return new View_Jugador_Spiderman();
}

void ViewEquipo::initialize(Equipo * equipo, LTexture texturaEquipo[]) {

	for (int i = 0; i < cantidadjugadores; ++i) {
			this->viewJugadores[i]->initialize(equipo->getJugadorNro(i),&texturaEquipo[i]);
		}
}

void ViewEquipo::render(int camX, int camY, SDL_Renderer * gRenderer){
	for (int i = 0; i < cantidadjugadores; ++i) {
			this->viewJugadores[i]->render(camX, camY, gRenderer);
		}
}

void ViewEquipo::render(int camX, int camY, SDL_Renderer * gRenderer, int zIndex){
	for (int i = 0; i < cantidadjugadores; ++i) {
		if(this->viewJugadores[i]->getZIndex() == zIndex){
			this->viewJugadores[i]->render(camX, camY, gRenderer);
		}
	}
}

ViewEquipo::~ViewEquipo() {
	// TODO Auto-generated destructor stub
}

