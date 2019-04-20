/*
 * ViewEquipo.h
 *
 *  Created on: 2 abr. 2019
 *      Author: maciel
 */

#ifndef VIEW_VIEWEQUIPO_H_
#define VIEW_VIEWEQUIPO_H_
#include "../Model/Equipo.h"
#include "View_Jugador.h"
#include "View_Jugador_CapAmerica.h"
#include "View_Jugador_Venom.h"
#include "View_Jugador_VenomBlack.h"
#include "View_Jugador_Default.h"
#include <vector>

#include "View_Jugador_CapAmericaBlack.h"
#define maxCantJugadores 2


class ViewEquipo {
public:
	ViewEquipo(Equipo* Equipo);
	virtual ~ViewEquipo();

	View_Jugador * cargarVistaPersonaje(std::string nombrePersonaje);
	bool hayAlgunJugadorActivoEnEspera();
	void initialize(Equipo* equipo, LTexture texturaJugador[]);
	void render(int camX, int camY, SDL_Renderer * gRenderer);
	void render(int camX, int camY, SDL_Renderer * gRenderer, int zIndex);

	View_Jugador* viewJugadores[maxCantJugadores];
	int cantidadjugadores;
};

#endif /* VIEW_VIEWEQUIPO_H_ */
