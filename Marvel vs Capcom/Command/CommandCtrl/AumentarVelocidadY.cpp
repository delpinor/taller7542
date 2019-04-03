#include "AumentarVelocidadY.h"

AumentarVelocidadY::AumentarVelocidadY(Model* model) :
		CommandCtrl(model) {
}

AumentarVelocidadY::~AumentarVelocidadY() {
	//dtor
}

void AumentarVelocidadY::execute(int i) {

	this->model->equipos[i].jugadorActivoAumentaVelocidadEnY();

}
