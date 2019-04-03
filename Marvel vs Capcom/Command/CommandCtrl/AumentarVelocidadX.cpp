#include "AumentarVelocidadX.h"

AumentarVelocidadX::AumentarVelocidadX(Model* model) :
		CommandCtrl(model) {
}

AumentarVelocidadX::~AumentarVelocidadX() {
	//dtor
}

void AumentarVelocidadX::execute(int i) {

	this->model->equipos[i].jugadorActivoAumentaVelocidadEnX();

}
