/*
 * Equipo.cpp
 *
 *  Created on: 2 abr. 2019
 *      Author: maciel
 */

#include "Equipo.h"

Equipo::Equipo() {
	this->jugadores = new Jugador[2];
	this->jugadores[0].setPersonaje(0); //testing
	this->jugadores[1].setPersonaje(1); //testing
	this->nroJugadorActivo = 1;
	this->getJugadorActivo()->activar();
}

Equipo::~Equipo() {
	delete[] this->jugadores;
}


Jugador* Equipo::getJugadorNro(int i) {
	return &(this->jugadores[i]);
}
Jugador* Equipo::getJugadorActivo() {
	return &(this->jugadores[this->nroJugadorActivo]);
}

void Equipo::agregarCambio(Command* cambio) {
	if (cambio != NULL)
		this->cambios.push(cambio);
}

void Equipo::update(int i) {
	if (!this->cambios.empty()) {
		Command* cambio = this->cambios.front();
		cambio->execute(i);
		this->cambios.pop();
	}
}

void Equipo::move(){
	for (int i = 0; i < 2; ++i) {
		this->jugadores[i].move();
	}
}


void Equipo::jugadorActivoAumentaVelocidadEnX() {
	this->jugadores[this->nroJugadorActivo].aumentarVelocidadX();
}

void Equipo::jugadorActivoAumentaVelocidadEnY() {
	this->jugadores[this->nroJugadorActivo].aumentarVelocidadY();
}

void Equipo::jugadorActivoSalta() {
	this->jugadores[this->nroJugadorActivo].Saltar();
}

void Equipo::jugadorActivoDisminuyeVelocidadEnX() {
	this->jugadores[this->nroJugadorActivo].disminuirVelocidadX();
}

void Equipo::jugadorActivoDisminuyeVelocidadEnY() {
	this->jugadores[this->nroJugadorActivo].disminuirVelocidadY();
}

void Equipo::jugadorActivoSeAgacha() {
	this->jugadores[this->nroJugadorActivo].Agachar();
}

int Equipo::getCantidadJugadores() {
	return 2;
}
