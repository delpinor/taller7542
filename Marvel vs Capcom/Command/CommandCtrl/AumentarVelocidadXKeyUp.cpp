#include "AumentarVelocidadXKeyUp.h"

AumentarVelocidadXKeyUp::AumentarVelocidadXKeyUp(Model* model) :
		CommandCtrl(model) {
}

AumentarVelocidadXKeyUp::~AumentarVelocidadXKeyUp() {
	//dtor
}

void AumentarVelocidadXKeyUp::execute(int i) {
	if(this->model->equipos[i]->getJugadorActivo()->getVelX()!=0)
	this->model->equipos[i]->jugadorActivoAumentaVelocidadEnX();

}
