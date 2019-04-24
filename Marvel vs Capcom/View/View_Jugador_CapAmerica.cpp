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
	gSpriteAnimacion[0].x = 301;
	gSpriteAnimacion[0].y = 6141;
	gSpriteAnimacion[0].w = 106;
	gSpriteAnimacion[0].h = 131;

	gSpriteAnimacion[1].x = 422;
	gSpriteAnimacion[1].y = 6137;
	gSpriteAnimacion[1].w = 77;
	gSpriteAnimacion[1].h = 135;

	gSpriteAnimacion[2].x = 532;
	gSpriteAnimacion[2].y = 6148;
	gSpriteAnimacion[2].w = 78;
	gSpriteAnimacion[2].h = 126;

	gSpriteAnimacion[3].x = 636;
	gSpriteAnimacion[3].y = 6151;
	gSpriteAnimacion[3].w = 80;
	gSpriteAnimacion[3].h = 123;

	gSpriteAnimacion[4].x = 742;
	gSpriteAnimacion[4].y = 6152;
	gSpriteAnimacion[4].w = 94;
	gSpriteAnimacion[4].h = 123;

	gSpriteAnimacion[5].x = 845;
	gSpriteAnimacion[5].y = 6151;
	gSpriteAnimacion[5].w = 117;
	gSpriteAnimacion[5].h = 125;

	gSpriteAnimacion[6].x = 12;
	gSpriteAnimacion[6].y = 6295;
	gSpriteAnimacion[6].w = 115;
	gSpriteAnimacion[6].h = 123;


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

//	gSpriteSaltar[2].x = 355;
//	gSpriteSaltar[2].y = 5399;
//	gSpriteSaltar[2].w = 135;
//	gSpriteSaltar[2].h = 176;

	gSpriteSaltar[2].x = 296;
	gSpriteSaltar[2].y = 424;
	gSpriteSaltar[2].w = 106;
	gSpriteSaltar[2].h = 90;

//	gSpriteSaltar[4].x = 719;
//	gSpriteSaltar[4].y = 5408;
//	gSpriteSaltar[4].w = 146;
//	gSpriteSaltar[4].h = 123;

	gSpriteSaltar[3].x = 404;
	gSpriteSaltar[3].y = 424;
	gSpriteSaltar[3].w = 88;
	gSpriteSaltar[3].h = 97;

//	gSpriteSaltar[6].x = 1007;
//	gSpriteSaltar[6].y = 5409;
//	gSpriteSaltar[6].w = 140;
//	gSpriteSaltar[6].h = 122;

	gSpriteSaltar[4].x = 493;
	gSpriteSaltar[4].y = 425;
	gSpriteSaltar[4].w = 109;
	gSpriteSaltar[4].h = 166;

//	gSpriteSaltar[8].x = 145;
//	gSpriteSaltar[8].y = 5583;
//	gSpriteSaltar[8].w = 135;
//	gSpriteSaltar[8].h = 144;

	gSpriteSaltar[5].x = 4;
	gSpriteSaltar[5].y = 481;
	gSpriteSaltar[5].w = 88;
	gSpriteSaltar[5].h = 119;

//	gSpriteSaltar[10].x = 599;
//	gSpriteSaltar[10].y = 5634;
//	gSpriteSaltar[10].w = 114;
//	gSpriteSaltar[10].h = 101;
}
void View_Jugador_CapAmerica::getSpritesAgachar() {
	gSpriteAgachar[0].x = 4;
	gSpriteAgachar[0].y = 481;
	gSpriteAgachar[0].w = 88;
	gSpriteAgachar[0].h = 119;
}

void View_Jugador_CapAmerica::getSpritesCambioPersonaje() {
	gSpriteCambiarPersonaje[0].x = 97;
	gSpriteCambiarPersonaje[0].y = 581;
	gSpriteCambiarPersonaje[0].w = 100;
	gSpriteCambiarPersonaje[0].h = 163;
}


void View_Jugador_CapAmerica::render(int camX, int camY, SDL_Renderer * gRenderer) {

	contador++;
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
				contador=0;
				currentClip = &gSpriteCambiarPersonaje[0];

			}else if (this->jugador->estado->getVelY() != 0){
				contador=0;
				currentClip = &gSpriteSaltar[frame / MAXFRAMESALTA];
				minFrames = MINFRAMESALTA;
				maxFrames = MAXFRAMESALTA;
				if (frame / maxFrames >= maxFrames) {
					frame = minFrames;

				}
				if (this->jugador->estado->getVelY() >= 18){

					frame = 0;
				}
			}else if ((this->jugador->estado->getVelY() == 0) && (this->jugador->estado->getVelX() == 0) && (contador>100)){
				currentClip = &gSpriteAnimacion[frame / 8];
				minFrames = 0;
				maxFrames = 8;
				++frame;
				if (frame / maxFrames >= maxFrames) {
									frame = minFrames;
									contador=0;
								}


			}else{

				currentClip = &gSpriteCaminar[frame / MAXFRAMECAMINA];
				minFrames = MINFRAMECAMINA;
				maxFrames = MAXFRAMECAMINA;
				if (frame / maxFrames >= maxFrames) {
					frame = minFrames;


				}

			}
			if ((this->jugador->getVelX() != 0) || (this->jugador->getVelY() != 0)) {
				contador=0;
				++frame;

			}
			this->texturaJugador->render(this->jugador->getPosX() - camX,	this->jugador->getPosY() - camY,currentClip, 0, NULL,this->jugador->getDireccion(), gRenderer);
		}
	}
}


