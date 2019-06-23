#include "TirarPoder.h"

TirarPoder::TirarPoder(Model* model) :
		CommandCtrl(model) {
}

TirarPoder::~TirarPoder() {
	//dtor
}

void TirarPoder::execute(int i) {

	this->model->equipos[i]->jugadorActivoTirarPoder(this->model->equipos[i]->equipoRival->jugadores[this->model->equipos[i]->equipoRival->nroJugadorActivo]);

}

