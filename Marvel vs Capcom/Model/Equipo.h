/*
 * Equipo.h
 *
 *  Created on: 2 abr. 2019
 *      Author: maciel
 */

#ifndef MODEL_EQUIPO_H_
#define MODEL_EQUIPO_H_
#include <vector>
#include <list>
#include <stdio.h>
#include <stdlib.h>
#include "Model_Jugador.h"
#include "../Command/Command.h"
#include <queue>

class Equipo {
public:
	Equipo();
	virtual ~Equipo();

	virtual Jugador* getJugadorNro(int i);
	virtual Jugador* getJugadorActivo();

	virtual void agregarCambio(Command* cambio);
	virtual void jugadorActivoAumentaVelocidadEnX();
	virtual void jugadorActivoAumentaVelocidadEnY();
	virtual void jugadorActivoSalta();
	virtual void jugadorActivoDisminuyeVelocidadEnX();
	virtual void jugadorActivoDisminuyeVelocidadEnY();
	virtual void jugadorActivoSeAgacha();
	virtual int getCantidadJugadores();
	virtual void update(int i);
	virtual void move();

	Jugador* jugadores;
	unsigned int nroJugadorActivo;
	std::queue<Command*> cambios;
};

#endif /* MODEL_EQUIPO_H_ */
