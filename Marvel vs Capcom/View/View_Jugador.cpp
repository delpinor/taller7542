#include "View_Jugador.h"

#include <sstream>
View_Jugador::View_Jugador() {
}

void View_Jugador::initialize(Jugador *model,
		LTexture * texturaJugador) {
	this->texturaJugador = texturaJugador;
	this->model = model;
	switch (this->model->Personaje()) { /// cambiar por algo mejor cuando resuelva coleccion
		case CAPAMERICA:

			gSpriteClips[0].x = 0;
			gSpriteClips[0].y = 150;
			gSpriteClips[0].w = 90;
			gSpriteClips[0].h = 130;

			gSpriteClips[1].x = 100;
			gSpriteClips[1].y = 150;
			gSpriteClips[1].w = 90;
			gSpriteClips[1].h = 130;

			gSpriteClips[2].x = 200;
			gSpriteClips[2].y = 150;
			gSpriteClips[2].w = 90;
			gSpriteClips[2].h = 130;

			gSpriteClips[3].x = 300;
			gSpriteClips[3].y = 150;
			gSpriteClips[3].w = 90;
			gSpriteClips[3].h = 130;

			gSpriteClips[4].x = 400;
			gSpriteClips[4].y = 150;
			gSpriteClips[4].w = 90;
			gSpriteClips[4].h = 130;

			gSpriteClips[5].x = 500;
			gSpriteClips[5].y = 150;
			gSpriteClips[5].w = 90;
			gSpriteClips[5].h = 130;
			break;
		case VENOM:

			gSpriteClips[0].x = 0;
			gSpriteClips[0].y = 3240;
			gSpriteClips[0].w = 138;
			gSpriteClips[0].h = 133;

			gSpriteClips[1].x = 144;
			gSpriteClips[1].y = 3240;
			gSpriteClips[1].w = 138;
			gSpriteClips[1].h = 133;

			gSpriteClips[2].x = 284;
			gSpriteClips[2].y = 3240;
			gSpriteClips[2].w = 138;
			gSpriteClips[2].h = 133;

			gSpriteClips[3].x = 428;
			gSpriteClips[3].y = 3240;
			gSpriteClips[3].w = 138;
			gSpriteClips[3].h = 133;

			gSpriteClips[4].x = 596;
			gSpriteClips[4].y = 3240;
			gSpriteClips[4].w = 138;
			gSpriteClips[4].h = 133;

			gSpriteClips[5].x = 749;
			gSpriteClips[5].y = 3240;
			gSpriteClips[5].w = 138;
			gSpriteClips[5].h = 133;
			break;
		}
}

void View_Jugador::render(int camX, int camY, SDL_Renderer * gRenderer) {

	SDL_Rect* currentClip = &gSpriteClips[frame / MAXFRAMECAMINA];
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


