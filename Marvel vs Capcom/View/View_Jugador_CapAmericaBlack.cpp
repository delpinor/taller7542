#include "View_Jugador_CapAmericaBlack.h"

#include <sstream>
View_Jugador_CapAmericaBlack::View_Jugador_CapAmericaBlack() {

}

void View_Jugador_CapAmericaBlack::initialize(Jugador *model, LTexture * texturaJugador) {
	this->texturaJugador = texturaJugador;
	texturaJugador->setColor(80,140,0);

	this->jugador = model;

	getSpritesCaminar();
	getSpritesSaltar();
	getSpritesAgachar();
	getSpritesCambioPersonaje();
	this->zIndex = model->get_zindex();
}

void View_Jugador_CapAmericaBlack::getSpritesCaminar() {
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

void View_Jugador_CapAmericaBlack::getSpritesSaltar() {
	gSpriteSaltar[0].x = 104;
	gSpriteSaltar[0].y = 423;
	gSpriteSaltar[0].w = 90;
	gSpriteSaltar[0].h = 160;

	gSpriteSaltar[1].x = 198;
	gSpriteSaltar[1].y = 424;
	gSpriteSaltar[1].w = 90;
	gSpriteSaltar[1].h = 160;

	gSpriteSaltar[2].x = 404;
	gSpriteSaltar[2].y = 424;
	gSpriteSaltar[2].w = 90;
	gSpriteSaltar[2].h = 160;

	gSpriteSaltar[3].x = 305;
	gSpriteSaltar[3].y = 424;
	gSpriteSaltar[3].w = 90;
	gSpriteSaltar[3].h = 160;

	gSpriteSaltar[4].x = 305;
	gSpriteSaltar[4].y = 424;
	gSpriteSaltar[4].w = 90;
	gSpriteSaltar[4].h = 160;

	gSpriteSaltar[5].x = 404;
	gSpriteSaltar[5].y = 424;
	gSpriteSaltar[5].w = 90;
	gSpriteSaltar[5].h = 160;

	gSpriteSaltar[6].x = 497;
	gSpriteSaltar[6].y = 427;
	gSpriteSaltar[6].w = 88;
	gSpriteSaltar[6].h = 119;
}

void View_Jugador_CapAmericaBlack::getSpritesAgachar() {
	gSpriteAgachar[0].x = 4;
	gSpriteAgachar[0].y = 481;
	gSpriteAgachar[0].w = 88;
	gSpriteAgachar[0].h = 119;
}

void View_Jugador_CapAmericaBlack::getSpritesCambioPersonaje() {
	gSpriteCambiarPersonaje[0].x = 97;
	gSpriteCambiarPersonaje[0].y = 581;
	gSpriteCambiarPersonaje[0].w = 100;
	gSpriteCambiarPersonaje[0].h = 163;
}

void View_Jugador_CapAmericaBlack::render(int camX, int camY, SDL_Renderer * gRenderer) {

	if (this->jugador->estaAgachado()){
		SDL_Rect* currentClip;
		currentClip = &gSpriteAgachar[0];

		this->texturaJugador->render(this->jugador->getPosX() - camX,	this->jugador->getPosY() - camY,currentClip, 0, NULL,this->jugador->getDireccion(), gRenderer);


	}else{


	if (this->jugador->estaActivo()){
			SDL_Rect* currentClip;
			int maxFrames;
			int minFrames;
			if(this->jugador->estaCambiandoPersonaje()){
				currentClip = &gSpriteCambiarPersonaje[0];
			}
			else if (this->model->estado->getVelY() != 0) {
				if (this->model->estado->getVelY() >= 18)
					frame = 0;
				minFrames = MINFRAMESALTA;
				maxFrames = MAXFRAMESALTA;
				if (frame / maxFrames >= maxFrames)
					frame = minFrames;
				currentClip = &gSpriteSaltar[frame / MAXFRAMESALTA];
			} else {
				minFrames = MINFRAMECAMINA;
				maxFrames = MAXFRAMECAMINA;
				if (frame / maxFrames >= maxFrames)
					frame = minFrames;
				currentClip = &gSpriteCaminar[frame / MAXFRAMECAMINA];
			}
			if ((this->jugador->getVelX() != 0) || (this->jugador->getVelY() != 0)) {
				++frame;

			}
			this->texturaJugador->render(this->jugador->getPosX() - camX,	this->jugador->getPosY() - camY,currentClip, 0, NULL,this->jugador->getDireccion(), gRenderer);
		}
	}
}


