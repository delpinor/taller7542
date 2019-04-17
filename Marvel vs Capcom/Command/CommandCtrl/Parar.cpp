#include "Parar.h"

Parar::Parar(Model* model) :
		CommandCtrl(model) {
}

Parar::~Parar() {
	//dtor
}

void Parar::execute(int i) {

	this->model->equipos[i]->jugadorActivoSePara();

}

