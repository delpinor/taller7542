#include "Arrojar.h"

Arrojar::Arrojar(Model* model) :
		CommandCtrl(model) {
}

Arrojar::~Arrojar() {
	//dtor
}

void Arrojar::execute(int i) {

	this->model->equipos[i]->jugadorActivoArrojar(this->model->equipos[i]->equipoRival->jugadores[this->model->equipos[i]->equipoRival->nroJugadorActivo]);

}

