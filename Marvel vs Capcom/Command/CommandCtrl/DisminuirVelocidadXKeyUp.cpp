#include "DisminuirVelocidadXKeyUp.h"

DisminuirVelocidadXKeyUp::DisminuirVelocidadXKeyUp(Model* model) :
		CommandCtrl(model) {
}

DisminuirVelocidadXKeyUp::~DisminuirVelocidadXKeyUp() {
	//dtor
}

void DisminuirVelocidadXKeyUp::execute(int i) {
	if(this->model->equipos[i]->getJugadorActivo()->getVelX()!=0)
	this->model->equipos[i]->jugadorActivoDisminuyeVelocidadEnX();

}

