#include "View_Jugador_Venom.h"

#include <sstream>
View_Jugador_Venom::View_Jugador_Venom() {

}

void View_Jugador_Venom::initialize(Jugador *model, LTexture * texturaJugador) {
	this->texturaJugador = texturaJugador;
	this->model = model;

	getSpritesCaminar();
}

void View_Jugador_Venom::getSpritesCaminar() {
	gSpriteCaminar[0].x = 4;
	gSpriteCaminar[0].y = 3251;
	gSpriteCaminar[0].w = 126;
	gSpriteCaminar[0].h = 123;

	gSpriteCaminar[1].x = 163;
	gSpriteCaminar[1].y = 3249;
	gSpriteCaminar[1].w = 107;
	gSpriteCaminar[1].h = 133;

	gSpriteCaminar[2].x = 304;
	gSpriteCaminar[2].y = 3240;
	gSpriteCaminar[2].w = 101;
	gSpriteCaminar[2].h = 133;

	gSpriteCaminar[3].x = 442;
	gSpriteCaminar[3].y = 3240;
	gSpriteCaminar[3].w = 117;
	gSpriteCaminar[3].h = 133;

	gSpriteCaminar[4].x = 598;
	gSpriteCaminar[4].y = 3240;
	gSpriteCaminar[4].w = 134;
	gSpriteCaminar[4].h = 133;

	gSpriteCaminar[5].x = 761;
	gSpriteCaminar[5].y = 3240;
	gSpriteCaminar[5].w = 117;
	gSpriteCaminar[5].h = 133;

	gSpriteCaminar[6].x = 911;
	gSpriteCaminar[6].y = 3240;
	gSpriteCaminar[6].w = 96;
	gSpriteCaminar[6].h = 133;

	gSpriteCaminar[7].x = 1034;
	gSpriteCaminar[7].y = 3240;
	gSpriteCaminar[7].w = 119;
	gSpriteCaminar[7].h = 133;

	gSpriteCaminar[8].x = 2;
	gSpriteCaminar[8].y = 3390;
	gSpriteCaminar[8].w = 129;
	gSpriteCaminar[8].h = 133;

	gSpriteCaminar[9].x = 164;
	gSpriteCaminar[9].y = 3390;
	gSpriteCaminar[9].w = 144;
	gSpriteCaminar[9].h = 133;
}

void View_Jugador_Venom::render(int camX, int camY, SDL_Renderer * gRenderer) {

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

