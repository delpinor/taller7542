/*
 * PatadaAgachado.cpp
 *
 *  Created on: 22 jun. 2019
 *      Author: jorge
 */

#include "PatadaAgachado.h"

PatadaAgachado::PatadaAgachado(Model* model) :
		CommandCtrl(model) {
}
void PatadaAgachado::execute(int i) {

	this->model->equipos[i]->jugadorActivoPatada_agachado(this->model->equipos[i]->equipoRival->jugadores[this->model->equipos[i]->equipoRival->nroJugadorActivo]);

}

PatadaAgachado::~PatadaAgachado() {
	// TODO Auto-generated destructor stub
}

