/*
 * CambiarJugador.cpp
 *
 *  Created on: 15 abr. 2019
 *      Author: maciel
 */

#include "CambiarPersonaje.h"

CambiarPersonaje::CambiarPersonaje(Model* model):
				  CommandCtrl(model){
	// TODO Auto-generated constructor stub

}

CambiarPersonaje::~CambiarPersonaje() {
	// TODO Auto-generated deconstructor stub
}

void CambiarPersonaje::execute(int i) {
	this->model->equipos[i]->iniciarCambioPersonaje();
//	this->model->equipos[i]->jugadorActivoAumentaVelocidadEnY(20);

//	if(i == 0)
//		this->model->equipos[i]->jugadorActivoAumentaVelocidadEnX(-10);
//	else
//		this->model->equipos[i]->jugadorActivoAumentaVelocidadEnX(10);
}

