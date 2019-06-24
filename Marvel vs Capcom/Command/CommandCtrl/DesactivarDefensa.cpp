/*
 * DesactivarDefensa.cpp
 *
 *  Created on: 23 jun. 2019
 *      Author: maciel
 */

#include "DesactivarDefensa.h"

DesactivarDefensa::DesactivarDefensa(Model* model) :
		CommandCtrl(model) {
}

void DesactivarDefensa::execute(int i) {
	this->model->equipos[i]->contadorGolpe = 0;
	this->model->equipos[i]->jugadorActivoDesactivarDefensa();

}

DesactivarDefensa::~DesactivarDefensa() {
	// TODO Auto-generated destructor stub
}

