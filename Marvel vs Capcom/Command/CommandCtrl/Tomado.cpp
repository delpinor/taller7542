/*
 * Agarrar.cpp
 *
 *  Created on: 4 jul. 2019
 *      Author: maciel
 */

#include "Tomado.h"

void Tomado::execute(int i) {

	this->model->equipos[i]->jugadorActivoTomar(this->model->equipos[i]->equipoRival->jugadores[this->model->equipos[i]->equipoRival->nroJugadorActivo]);

}

Tomado::Tomado(Model *model) :
	CommandCtrl(model) {

}

Tomado::~Tomado() {
	// TODO Auto-generated destructor stub
}

