#include "Agachar.h"

Agachar::Agachar(Model* model) :
		CommandCtrl(model) {
}

Agachar::~Agachar() {
	//dtor
}

void Agachar::execute() {

	this->model->jugadorActivoSeAgacha();

}

