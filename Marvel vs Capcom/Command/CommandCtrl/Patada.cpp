#include "Patada.h"

Patada::Patada(Model* model) :
		CommandCtrl(model) {
}

Patada::~Patada() {
	//dtor
}

void Patada::execute(int i) {

	this->model->equipos[i]->jugadorActivoPatada(this->model->equipos[i]->equipoRival->jugadores[this->model->equipos[i]->equipoRival->nroJugadorActivo]);

}

