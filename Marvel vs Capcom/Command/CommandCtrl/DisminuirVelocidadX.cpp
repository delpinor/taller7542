#include "DisminuirVelocidadX.h"

DisminuirVelocidadX::DisminuirVelocidadX(Model* model) :
		CommandCtrl(model) {
}

DisminuirVelocidadX::~DisminuirVelocidadX() {
	//dtor
}

void DisminuirVelocidadX::execute(int i) {

	this->model->equipos[i].jugadorActivoDisminuyeVelocidadEnX();

}

