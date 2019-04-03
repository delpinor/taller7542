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
#include <vector>
#define maxCantJugadores 2


class ViewEquipo {
public:
	ViewEquipo();
	virtual ~ViewEquipo();

	bool hayAlgunJugadorActivoEnEspera();
	void initialize(Equipo* equipo, LTexture texturaJugador[]);
	void render(int camX, int camY, SDL_Renderer * gRenderer);

	View_Jugador* viewJugadores[maxCantJugadores];
	int cantidadjugadores;
};

#endif /* VIEW_VIEWEQUIPO_H_ */
