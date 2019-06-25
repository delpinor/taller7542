#include "Pinia.h"

Pinia::Pinia(Model* model) :
		CommandCtrl(model) {
}

Pinia::~Pinia() {
	//dtor
}

void Pinia::execute(int i) {

	this->model->equipos[i]->jugadorActivoPinia(this->model->equipos[i]->equipoRival->jugadores[this->model->equipos[i]->equipoRival->nroJugadorActivo]);

}

