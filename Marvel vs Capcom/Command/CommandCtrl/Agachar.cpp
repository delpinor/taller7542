#include "Agachar.h"

Agachar::Agachar(Model* model) :
		CommandCtrl(model) {
}

Agachar::~Agachar() {
	//dtor
}

void Agachar::execute(int i) {

	this->model->equipos[i]->jugadorActivoSeAgacha();

}

