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
	int numeroEquipo;
	Jugador* jugadores[2];
	Equipo* equipoRival;
	int nroJugadorActivo;
	bool cambiandoJugador = false;
	std::queue<Command*> cambios;

public:
	Equipo();

	Equipo(std::map<int, Jugador> jugador);
	// Método que agregar jugadores al equipo
		// con num se indica el indice
	void inicializar(int numeroEquipo);
	void agregar_Jugador(int num, Jugador * jugador);
	virtual ~Equipo();

	virtual Jugador* getJugadorNro(int i);
	virtual Jugador* getJugadorActivo();
	virtual Jugador* getJugadorInactivo();
	virtual int getNumeroJugadorInactivo();
	virtual void setJugadorActivo(int i);


	virtual void agregarCambio(Command* cambio);
	virtual void jugadorActivoAumentaVelocidadEnX();
	virtual void jugadorActivoAumentaVelocidadEnY();
	virtual void jugadorActivoSalta();
	virtual void jugadorActivoPinia(Jugador * rival);
	virtual void jugadorActivoPinion(Jugador * rival);
	virtual void jugadorActivoPatada(Jugador * rival);
	virtual void jugadorActivoPatadon(Jugador * rival);
	virtual void jugadorActivoDisminuyeVelocidadEnX();
	virtual void jugadorActivoAumentaVelocidadEnX(int vel);
	virtual void jugadorActivoAumentaVelocidadEnY(int vel);
	virtual void jugadorActivoDisminuyeVelocidadEnY();
	virtual void jugadorActivoSeAgacha();
	virtual void jugadorActivoSePara();
	virtual int getCantidadJugadores();
	virtual void update(int i);
	//virtual void move();
	virtual void move(SDL_Rect* camara);
	virtual void moveCliente(SDL_Rect* camara);
	virtual void iniciarCambioPersonaje();
	virtual void cambiarPersonaje(SDL_Rect* camara);

	void setCambiandoPersonaje(bool cambiandoJugador);
	void setEquipoRival(Equipo* equipoRival);
	Equipo* getEquipoRival();
};

#endif /* MODEL_EQUIPO_H_ */
