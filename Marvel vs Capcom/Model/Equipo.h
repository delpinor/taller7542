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
#include <map>

class Equipo {
public:
		// jugador es el quivalente a persoanje
		//equipo es quivalente a jugador

	Jugador* jugadores[2];
	 int nroJugadorActivo;
	std::queue<Command*> cambios;

public:
	Equipo();

	Equipo(std::map<int, Jugador> jugador);
	// Método que agregar jugadores al equipo
		// con num se indica el indice
	void inicializar();
	void agregar_Jugador(int num, Jugador * jugador);
	virtual ~Equipo();

	virtual Jugador* getJugadorNro(int i);
	virtual Jugador* getJugadorActivo();
	virtual Jugador* getJugadorInactivo();
	virtual void setJugadorActivo(int i);


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

};

#endif /* MODEL_EQUIPO_H_ */
