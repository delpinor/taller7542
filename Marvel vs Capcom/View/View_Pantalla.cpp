#include "View_Pantalla.h"

View_Pantalla::View_Pantalla() {
}

void View_Pantalla::initialize(SDL_Renderer * gRenderer,
		LTexture * texturaPantalla) {
	this->texturaPantalla = texturaPantalla;

}

void View_Pantalla::render(SDL_Rect * camara, SDL_Renderer * gRenderer) {
	this->texturaPantalla->render(0, 0, camara, 0.0, NULL, SDL_FLIP_NONE,
			gRenderer);
}
