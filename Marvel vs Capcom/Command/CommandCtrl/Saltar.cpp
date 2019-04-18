#include "Saltar.h"

Saltar::Saltar(Model* model) :
		CommandCtrl(model) {
}

Saltar::~Saltar() {
	//dtor
}

void Saltar::execute(int i) {

	this->model->equipos[i]->jugadorActivoSalta();

}

