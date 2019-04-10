#include "ViewModel.h"
#include <SDL2/SDL.h>
ViewModel::ViewModel(Model* model, SDL_Renderer* gRenderer, SDL_Rect* camara, LTexture texturaJugador[]) {
	//this->viewPantalla.initialize(gRenderer, texturaPantalla);
	this->viewEquipo[0] = new ViewEquipo();
	this->viewEquipo[1] = new ViewEquipo();
	this->camara = camara;
	this->gRenderer = gRenderer;

	for (int i = 0; i < 2; ++i) {
			this->viewEquipo[i]->initialize(model->getEquipoNro(i),texturaJugador);
		}

}

ViewModel::~ViewModel() {
	delete[] this->viewEquipo;
}

void ViewModel::render() {
	//this->viewPantalla.render(this->camara, this->gRenderer);

	for (int i = 0; i < 2; ++i) {
		this->viewEquipo[i]->render(this->camara->x, this->camara->y,
				this->gRenderer);
	}
}

