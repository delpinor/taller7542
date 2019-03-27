#include "Model.h"
#include "../View/ViewModel.h"
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <list>
#include <iostream>
#include <string>
#include <unistd.h>

#define CANTJUGADORESTOTALES 2
#define LOCALES 1

Model::Model() {
	this->jugadores = new Jugador[CANTJUGADORESTOTALES];
	this->jugadores[0].setPersonaje(0); //testing
	this->jugadores[1].setPersonaje(1); //testing
	this->nroJugadorActivo = 1;
	this->getJugadorActivo()->activar();
}

Model::~Model() {
	delete[] this->jugadores;
}

Jugador* Model::getJugadorNro(int i) {
	return &(this->jugadores[i]);
}
Jugador* Model::getJugadorActivo() {
	return &(this->jugadores[this->nroJugadorActivo]);
}

void Model::agregarCambio(Command* cambio) {
	if (cambio != NULL)
		this->cambios.push(cambio);
}

void Model::update() {
	if (!this->cambios.empty()) {
		Command* cambio = this->cambios.front();
		cambio->execute();
		this->cambios.pop();
	}
	this->moverJuego();
}

void Model::moverJuego() {

	for (int i = 0; i < CANTJUGADORESTOTALES; ++i) {
		this->jugadores[i].move();
	}
}

void Model::setCamara(SDL_Rect * camara) {
	this->camara = camara;
}

void Model::jugadorActivoAumentaVelocidadEnX() {
	this->jugadores[this->nroJugadorActivo].aumentarVelocidadX();
}

void Model::jugadorActivoAumentaVelocidadEnY() {
	this->jugadores[this->nroJugadorActivo].aumentarVelocidadY();
}

void Model::jugadorActivoSalta() {
	this->jugadores[this->nroJugadorActivo].Saltar();
}

void Model::jugadorActivoDisminuyeVelocidadEnX() {
	this->jugadores[this->nroJugadorActivo].disminuirVelocidadX();
}

void Model::jugadorActivoDisminuyeVelocidadEnY() {
	this->jugadores[this->nroJugadorActivo].disminuirVelocidadY();
}

void Model::jugadorActivoSeAgacha() {
	this->jugadores[this->nroJugadorActivo].Agachar();
}

int Model::getCantidadJugadores() {
	return CANTJUGADORESTOTALES;
}

