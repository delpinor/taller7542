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
	this->equipos = new Equipo[2];
	this->equipos[0].setJugadorActivo(0);
	this->equipos[1].setJugadorActivo(1);
}

Model::~Model() {
	delete[] this->equipos;
}

void Model::update() {
	for (int i = 0; i < 2; ++i) {
		this->equipos[i].update(i);
	}
	this->moverJuego();
}


void Model::moverJuego() {

	for (int i = 0; i < CANTJUGADORESTOTALES; ++i) {
		this->equipos[i].move();
	}
}

void Model::setCamara(SDL_Rect * camara) {
	this->camara = camara;
}

Equipo* Model::getEquipoNro(int i) {
	return &(this->equipos[i]);
}


