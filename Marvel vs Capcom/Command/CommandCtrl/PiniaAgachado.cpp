/*
 * PiniaAgachado.cpp
 *
 *  Created on: 24 jun. 2019
 *      Author: jorge
 */

#include "PiniaAgachado.h"

PiniaAgachado::PiniaAgachado(Model* model) :
CommandCtrl(model) {
}


PiniaAgachado::~PiniaAgachado() {
	// TODO Auto-generated destructor stub
}

void PiniaAgachado::execute(int i) {

	this->model->equipos[i]->jugadorActivoPinia_agachado(this->model->equipos[i]->equipoRival->jugadores[this->model->equipos[i]->equipoRival->nroJugadorActivo]);

}
