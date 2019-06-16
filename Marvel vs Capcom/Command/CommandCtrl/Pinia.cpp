#include "Pinia.h"

Pinia::Pinia(Model* model) :
		CommandCtrl(model) {
}

Pinia::~Pinia() {
	//dtor
}

void Pinia::execute(int i) {

	this->model->equipos[i]->jugadorActivoPinia();

}

