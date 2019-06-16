#include "Pinion.h"

Pinion::Pinion(Model* model) :
		CommandCtrl(model) {
}

Pinion::~Pinion() {
	//dtor
}

void Pinion::execute(int i) {

	this->model->equipos[i]->jugadorActivoPinion();

}

