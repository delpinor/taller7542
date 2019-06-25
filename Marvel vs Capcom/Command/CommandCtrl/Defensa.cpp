/*
 * Defensa.cpp
 *
 *  Created on: 22 jun. 2019
 *      Author: jorge
 */

#include "Defensa.h"

Defensa::Defensa(Model* model) :
CommandCtrl(model) {
}

void Defensa::execute(int i) {

	this->model->equipos[i]->jugadorActivoSeDefiende() ;

}

Defensa::~Defensa() {
	// TODO Auto-generated destructor stub
}

