/*
 * PinionAgachado.cpp
 *
 *  Created on: 22 jun. 2019
 *      Author: jorge
 */

#include "PinionAgachado.h"

PinionAgachado::PinionAgachado(Model* model) :
CommandCtrl(model) {
}
void PinionAgachado::execute(int i) {

	this->model->equipos[i]->jugadorActivoPinion_agachado(this->model->equipos[i]->equipoRival->jugadores[this->model->equipos[i]->equipoRival->nroJugadorActivo]);

}


PinionAgachado::~PinionAgachado() {
	// TODO Auto-generated destructor stub
}

