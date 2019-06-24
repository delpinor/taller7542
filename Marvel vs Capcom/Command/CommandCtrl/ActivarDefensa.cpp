/*
 * Defensa.cpp
 *
 *  Created on: 23 jun. 2019
 *      Author: maciel
 */

#include "ActivarDefensa.h"

ActivarDefensa::ActivarDefensa(Model* model) :
		CommandCtrl(model) {
}

void ActivarDefensa::execute(int i) {

	this->model->equipos[i]->jugadorActivoActivarDefensa();

}

ActivarDefensa::~ActivarDefensa() {
	// TODO Auto-generated destructor stub
}

