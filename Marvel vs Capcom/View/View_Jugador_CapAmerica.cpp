#include "View_Jugador_CapAmerica.h"

#include <sstream>
View_Jugador_CapAmerica::View_Jugador_CapAmerica() {

}

void View_Jugador_CapAmerica::initialize(Jugador *model, LTexture * texturaJugador) {
	this->texturaJugador = texturaJugador;
	this->model = model;

	getSpritesCaminar();
}

void View_Jugador_CapAmerica::getSpritesCaminar() {
	gSpriteCaminar[0].x = 0;
	gSpriteCaminar[0].y = 150;
	gSpriteCaminar[0].w = 90;
	gSpriteCaminar[0].h = 130;

	gSpriteCaminar[1].x = 100;
	gSpriteCaminar[1].y = 150;
	gSpriteCaminar[1].w = 90;
	gSpriteCaminar[1].h = 130;

	gSpriteCaminar[2].x = 200;
	gSpriteCaminar[2].y = 150;
	gSpriteCaminar[2].w = 90;
	gSpriteCaminar[2].h = 130;

	gSpriteCaminar[3].x = 300;
	gSpriteCaminar[3].y = 150;
	gSpriteCaminar[3].w = 90;
	gSpriteCaminar[3].h = 130;

	gSpriteCaminar[4].x = 400;
	gSpriteCaminar[4].y = 150;
	gSpriteCaminar[4].w = 90;
	gSpriteCaminar[4].h = 130;

	gSpriteCaminar[5].x = 500;
	gSpriteCaminar[5].y = 150;
	gSpriteCaminar[5].w = 90;
	gSpriteCaminar[5].h = 130;

}

void View_Jugador_CapAmerica::render(int camX, int camY, SDL_Renderer * gRenderer) {

	SDL_Rect* currentClip = &gSpriteCaminar[frame / MAXFRAMECAMINA];
	if ((this->model->getVelX() != 0) || (this->model->getVelY() != 0)) {
		++frame;

	}
	if (frame / MAXFRAMECAMINA >= MAXFRAMECAMINA) {
		frame = MINFRAMECAMINA;
	}
	this->texturaJugador->render(this->model->getPosX() - camX,
			this->model->getPosY() - camY, currentClip, 0, NULL,
			this->model->getDireccion(), gRenderer);

}


