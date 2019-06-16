#include "Patadon.h"

Patadon::Patadon(Model* model) :
		CommandCtrl(model) {
}

Patadon::~Patadon() {
	//dtor
}

void Patadon::execute(int i) {

	this->model->equipos[i]->jugadorActivoPatadon();

}

