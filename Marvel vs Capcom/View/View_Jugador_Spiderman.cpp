#include "View_Jugador_Spiderman.h"

#include <sstream>
View_Jugador_Spiderman::View_Jugador_Spiderman() {

}

void View_Jugador_Spiderman::initialize(Jugador *model, LTexture * texturaJugador) {
	this->texturaJugador = texturaJugador;
	this->model = model;
	getSpritesCaminar();
	getSpritesSaltar();
	getSpritesAgachar();
	this->zIndex = model->get_zindex();
	getSpritesCambioPersonaje();
}

void View_Jugador_Spiderman::getSpritesCaminar() {
	gSpriteCaminar[0].x = 22;
	gSpriteCaminar[0].y = 118;
	gSpriteCaminar[0].w = 78;
	gSpriteCaminar[0].h = 91;


	gSpriteCaminar[1].x = 109;
	gSpriteCaminar[1].y = 118;
	gSpriteCaminar[1].w = 76;
	gSpriteCaminar[1].h = 91;

	gSpriteCaminar[2].x = 191;
	gSpriteCaminar[2].y = 118;
	gSpriteCaminar[2].w = 72;
	gSpriteCaminar[2].h = 91;

	gSpriteCaminar[3].x = 265;
	gSpriteCaminar[3].y = 118;
	gSpriteCaminar[3].w = 78;
	gSpriteCaminar[3].h = 91;

	gSpriteCaminar[4].x = 349;
	gSpriteCaminar[4].y = 118;
	gSpriteCaminar[4].w = 61;
	gSpriteCaminar[4].h = 91;

	gSpriteCaminar[5].x = 425;
	gSpriteCaminar[5].y = 118;
	gSpriteCaminar[5].w = 57;
	gSpriteCaminar[5].h = 91;

	gSpriteCaminar[6].x = 496;
	gSpriteCaminar[6].y = 118;
	gSpriteCaminar[6].w = 61;
	gSpriteCaminar[6].h = 91;


	gSpriteCaminar[7].x = 568;
	gSpriteCaminar[7].y = 118;
	gSpriteCaminar[7].w = 59;
	gSpriteCaminar[7].h = 91;

	gSpriteCaminar[8].x = 633;
	gSpriteCaminar[8].y = 118;
	gSpriteCaminar[8].w = 61;
	gSpriteCaminar[8].h = 91;

	gSpriteCaminar[9].x = 707;
	gSpriteCaminar[9].y = 118;
	gSpriteCaminar[9].w = 59;
	gSpriteCaminar[9].h = 91;

	gSpriteCaminar[10].x = 774;
	gSpriteCaminar[10].y = 118;
	gSpriteCaminar[10].w = 57;
	gSpriteCaminar[10].h = 91;

	gSpriteCaminar[11].x = 840;
	gSpriteCaminar[11].y = 118;
	gSpriteCaminar[11].w = 69;
	gSpriteCaminar[11].h = 91;

}

void View_Jugador_Spiderman::getSpritesSaltar() {
	gSpriteSaltar[0].x = 18;
	gSpriteSaltar[0].y = 431;
	gSpriteSaltar[0].w = 69;
	gSpriteSaltar[0].h = 54;

	gSpriteSaltar[1].x = 122;
	gSpriteSaltar[1].y = 230;
	gSpriteSaltar[1].w = 67;
	gSpriteSaltar[1].h = 132;

	gSpriteSaltar[2].x = 196;
	gSpriteSaltar[2].y = 230;
	gSpriteSaltar[2].w = 84;
	gSpriteSaltar[2].h = 101;

	gSpriteSaltar[3].x = 290;
	gSpriteSaltar[3].y = 230;
	gSpriteSaltar[3].w = 98;
	gSpriteSaltar[3].h = 77;

	gSpriteSaltar[4].x = 398;
	gSpriteSaltar[4].y = 230;
	gSpriteSaltar[4].w = 98;
	gSpriteSaltar[4].h = 60;

	gSpriteSaltar[5].x = 500;
	gSpriteSaltar[5].y = 230;
	gSpriteSaltar[5].w = 88;
	gSpriteSaltar[5].h = 60;

	gSpriteSaltar[6].x = 603;
	gSpriteSaltar[6].y = 230;
	gSpriteSaltar[6].w = 98;
	gSpriteSaltar[6].h = 60;

	gSpriteSaltar[7].x = 709;
	gSpriteSaltar[7].y = 230;
	gSpriteSaltar[7].w = 98;
	gSpriteSaltar[7].h = 68;

	gSpriteSaltar[8].x = 815;
	gSpriteSaltar[8].y = 230;
	gSpriteSaltar[8].w = 110;
	gSpriteSaltar[8].h = 99;

	gSpriteSaltar[9].x = 928;
	gSpriteSaltar[9].y = 230;
	gSpriteSaltar[9].w = 110;
	gSpriteSaltar[9].h = 134;

	gSpriteSaltar[10].x = 1040;
	gSpriteSaltar[10].y = 230;
	gSpriteSaltar[10].w = 106;
	gSpriteSaltar[10].h = 134;

	gSpriteSaltar[11].x = 1177;
	gSpriteSaltar[11].y = 396;
	gSpriteSaltar[11].w = 100;
	gSpriteSaltar[11].h = 97;

	gSpriteSaltar[12].x = 1276;
	gSpriteSaltar[12].y = 429;
	gSpriteSaltar[12].w = 86;
	gSpriteSaltar[12].h = 62;

	gSpriteSaltar[13].x = 1362;
	gSpriteSaltar[13].y = 423;
	gSpriteSaltar[13].w = 92;
	gSpriteSaltar[13].h = 68;

	gSpriteSaltar[14].x = 1460;
	gSpriteSaltar[14].y = 396;
	gSpriteSaltar[14].w = 116;
	gSpriteSaltar[14].h = 91;
}
void View_Jugador_Spiderman::getSpritesAgachar() {
	gSpriteAgachar[0].x = 10;
	gSpriteAgachar[0].y = 963;
	gSpriteAgachar[0].w = 116;
	gSpriteAgachar[0].h = 73;
}

void View_Jugador_Spiderman::getSpritesCambioPersonaje() {
	gSpriteCambiarPersonaje[0].x = 122;
	gSpriteCambiarPersonaje[0].y = 230;
	gSpriteCambiarPersonaje[0].w = 67;
	gSpriteCambiarPersonaje[0].h = 132;
}


void View_Jugador_Spiderman::render(int camX, int camY, SDL_Renderer * gRenderer) {

	if (this->model->estaAgachado()){
		SDL_Rect* currentClip;
		currentClip = &gSpriteAgachar[0];

		this->texturaJugador->render(this->model->getPosX() - camX,	this->model->getPosY() - camY,currentClip, 0, NULL,this->model->getDireccion(), gRenderer);


	}else{

	if (this->model->estaActivo()){
			SDL_Rect* currentClip;
			int maxFrames;
			int minFrames;
			if(this->model->estaCambiandoPersonaje()){
				currentClip = &gSpriteCambiarPersonaje[0];
			}
			else if (this->model->estado->getVelY() != 0){
				currentClip = &gSpriteSaltar[frame / MAXFRAMESALTA];
				minFrames = MINFRAMESALTA;
				maxFrames = MAXFRAMESALTA;
				if (frame / maxFrames >= maxFrames) {
					frame = minFrames;
				}
				if (this->model->estado->getVelY() >= 18)
					frame = 0;
			}
			else{
				currentClip = &gSpriteCaminar[frame / MAXFRAMECAMINA];
				minFrames = MINFRAMECAMINA;
				maxFrames = MAXFRAMECAMINA;
				if (frame / maxFrames >= maxFrames) {
					frame = minFrames;
				}
			}
			if ((this->model->getVelX() != 0) || (this->model->getVelY() != 0)) {
				++frame;

			}
			this->texturaJugador->render(this->model->getPosX() - camX,	this->model->getPosY() - camY,currentClip, 0, NULL,this->model->getDireccion(), gRenderer);
		}
	}
}


