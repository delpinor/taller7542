#include "View_Jugador_CapAmerica.h"

#include <sstream>
View_Jugador_CapAmerica::View_Jugador_CapAmerica() {

}

void View_Jugador_CapAmerica::initialize(Jugador *model, LTexture * texturaJugador) {
	this->texturaJugador = texturaJugador;
	this->jugador = model;
	getSpritesCaminar();
	getSpritesSaltar();
	getSpritesAgachar();
	getSpritesAnimacion();
	this->zIndex = model->get_zindex();
	getSpritesCambioPersonaje();
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

	gSpriteCaminar[6].x = 5;
	gSpriteCaminar[6].y = 280;
	gSpriteCaminar[6].w = 100;
	gSpriteCaminar[6].h = 130;


	gSpriteCaminar[7].x = 105;
	gSpriteCaminar[7].y = 280;
	gSpriteCaminar[7].w = 90;
	gSpriteCaminar[7].h = 130;

	gSpriteCaminar[8].x = 195;
	gSpriteCaminar[8].y = 280;
	gSpriteCaminar[8].w = 90;
	gSpriteCaminar[8].h = 130;

	gSpriteCaminar[9].x = 295;
	gSpriteCaminar[9].y = 280;
	gSpriteCaminar[9].w = 105;
	gSpriteCaminar[9].h = 130;

	gSpriteCaminar[10].x = 400;
	gSpriteCaminar[10].y = 285;
	gSpriteCaminar[10].w = 90;
	gSpriteCaminar[10].h = 130;

	gSpriteCaminar[11].x = 495;
	gSpriteCaminar[11].y = 285;
	gSpriteCaminar[11].w = 90;
	gSpriteCaminar[11].h = 130;
}

void View_Jugador_CapAmerica::getSpritesAnimacion() {



		gSpriteAnimacion[0].x = 100;
		gSpriteAnimacion[0].y = 150;
		gSpriteAnimacion[0].w = 90;
		gSpriteAnimacion[0].h = 130;


		gSpriteAnimacion[1].x = 105;
		gSpriteAnimacion[1].y = 280;
		gSpriteAnimacion[1].w = 90;
		gSpriteAnimacion[1].h = 130;

		gSpriteAnimacion[2].x = 295;
		gSpriteAnimacion[2].y = 280;
		gSpriteAnimacion[2].w = 103;
		gSpriteAnimacion[2].h = 130;


		gSpriteAnimacion[3].x = 239;
		gSpriteAnimacion[3].y = 861;
		gSpriteAnimacion[3].w = 99;
		gSpriteAnimacion[3].h = 130;

		gSpriteAnimacion[4].x = 98;
		gSpriteAnimacion[4].y = 861;
		gSpriteAnimacion[4].w = 140;
		gSpriteAnimacion[4].h = 130;

		gSpriteAnimacion[5].x = 1;
		gSpriteAnimacion[5].y = 858;
		gSpriteAnimacion[5].w = 92;
		gSpriteAnimacion[5].h = 130;

}

void View_Jugador_CapAmerica::getSpritesSaltar() {
	gSpriteSaltar[0].x = 4;
	gSpriteSaltar[0].y = 481;
	gSpriteSaltar[0].w = 88;
	gSpriteSaltar[0].h = 119;

	gSpriteSaltar[1].x = 104;
	gSpriteSaltar[1].y = 421;
	gSpriteSaltar[1].w = 86;
	gSpriteSaltar[1].h = 165;

	gSpriteSaltar[2].x = 296;
	gSpriteSaltar[2].y = 424;
	gSpriteSaltar[2].w = 106;
	gSpriteSaltar[2].h = 90;

	gSpriteSaltar[3].x = 404;
	gSpriteSaltar[3].y = 424;
	gSpriteSaltar[3].w = 88;
	gSpriteSaltar[3].h = 97;

	gSpriteSaltar[4].x = 493;
	gSpriteSaltar[4].y = 425;
	gSpriteSaltar[4].w = 109;
	gSpriteSaltar[4].h = 166;

	gSpriteSaltar[5].x = 4;
	gSpriteSaltar[5].y = 481;
	gSpriteSaltar[5].w = 88;
	gSpriteSaltar[5].h = 119;
}
void View_Jugador_CapAmerica::getSpritesAgachar() {
	gSpriteAgachar[0].x = 5;
	gSpriteAgachar[0].y = 588;
	gSpriteAgachar[0].w = 90;
	gSpriteAgachar[0].h = 130;
}

void View_Jugador_CapAmerica::getSpritesCambioPersonaje() {
	gSpriteCambiarPersonaje[0].x = 97;
	gSpriteCambiarPersonaje[0].y = 581;
	gSpriteCambiarPersonaje[0].w = 100;
	gSpriteCambiarPersonaje[0].h = 163;
}


void View_Jugador_CapAmerica::render(int camX, int camY,
		SDL_Renderer * gRenderer) {
	SDL_Rect* currentClip;
	contador++;
	if (this->jugador->estaAgachado()) {
		contador = 0;
		currentClip = &gSpriteAgachar[0];
		this->texturaJugador->render(this->jugador->getPosX() - camX,
				this->jugador->getPosY() - camY, currentClip, 0, NULL,
				this->jugador->getDireccion(), gRenderer);

	} else {

		if (this->jugador->estaActivo()) {

			int maxFrames;
			int minFrames;
			if (this->jugador->estaCambiandoPersonaje()) {
				contador = 0;
				Logger::Log(LOGGER_NIVEL::DEBUG,"view CapAmerica:: cambiando personaje", " ");
				currentClip = &gSpriteCambiarPersonaje[0];

			} else if (this->jugador->estado->getVelY() != 0) {
				if (this->jugador->estado->getVelY() >= 18) {
					frame = 0;
				}
				contador = 0;
				minFrames = MINFRAMESALTA;
				maxFrames = MAXFRAMESALTA;
				if (frame / maxFrames >= maxFrames + 1) {
					frame = minFrames;
				}
				currentClip = &gSpriteSaltar[frame / MAXFRAMESALTA];

			} else if ((this->jugador->estaActivo())
					&& (this->jugador->estado->getVelY() == 0)
					&& (this->jugador->estado->getVelX() == 0)
					&& (contador > 100)) {
				Logger::Log(LOGGER_NIVEL::DEBUG, "view CapAmerica:: animacion"," ");
				currentClip = &gSpriteAnimacion[frame / MAXFRAMEANIMACION];
				minFrames = MINFRAMEANIMACION;
				maxFrames = MAXFRAMEANIMACION;
				if (frame / maxFrames >= maxFrames + 1) {
					frame = minFrames;
					contador = 0;
				}
				++frame;
			} else {
				minFrames = MINFRAMECAMINA;
				maxFrames = MAXFRAMECAMINA;
				if (frame / maxFrames >= maxFrames + 1) {
					frame = minFrames;
				}
				currentClip = &gSpriteCaminar[frame / MAXFRAMECAMINA];
			}
			if ((this->jugador->getVelX() != 0)
					|| (this->jugador->getVelY() != 0)) {
				++frame;
				contador = 0;
			}
			this->texturaJugador->render(this->jugador->getPosX() - camX,
					this->jugador->getPosY() - camY, currentClip, 0, NULL,
					this->jugador->getDireccion(), gRenderer);

		}
	}

}


