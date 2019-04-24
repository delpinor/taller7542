#include "View_Jugador_VenomBlack.h"

#include <sstream>
View_Jugador_VenomBlack::View_Jugador_VenomBlack() {

}

void View_Jugador_VenomBlack::initialize(Jugador * model, LTexture * texturaJugador) {
	this->texturaJugador = texturaJugador;
	texturaJugador->setColor(40,40,40);
	this->model = model;
	this->zIndex = model->get_zindex();

	getSpritesCaminar();
	getSpritesSaltar();
	getSpritesAgachar();
	getSpritesCambioPersonaje();
}

void View_Jugador_VenomBlack::getSpritesCaminar() {
	gSpriteCaminar[9].x = 3;
	gSpriteCaminar[9].y = 3248;
	gSpriteCaminar[9].w = 138;
	gSpriteCaminar[9].h = 123;

	gSpriteCaminar[8].x = 148;
	gSpriteCaminar[8].y = 3248;
	gSpriteCaminar[8].w = 138;
	gSpriteCaminar[8].h = 123;

	gSpriteCaminar[7].x = 285;
	gSpriteCaminar[7].y = 3248;
	gSpriteCaminar[7].w = 138;
	gSpriteCaminar[7].h = 123;

	gSpriteCaminar[6].x = 436;
	gSpriteCaminar[6].y = 3248;
	gSpriteCaminar[6].w = 138;
	gSpriteCaminar[6].h = 123;

	gSpriteCaminar[5].x = 595;
	gSpriteCaminar[5].y = 3248;
	gSpriteCaminar[5].w = 139;
	gSpriteCaminar[5].h = 123;

	gSpriteCaminar[4].x = 754;
	gSpriteCaminar[4].y = 3248;
	gSpriteCaminar[4].w = 138;
	gSpriteCaminar[4].h = 123;

	gSpriteCaminar[3].x = 885;
	gSpriteCaminar[3].y = 3248;
	gSpriteCaminar[3].w = 138;
	gSpriteCaminar[3].h = 123;

	gSpriteCaminar[2].x = 1022;
	gSpriteCaminar[2].y = 3248;
	gSpriteCaminar[2].w = 138;
	gSpriteCaminar[2].h = 123;

	gSpriteCaminar[1].x = 4;
	gSpriteCaminar[1].y = 3391;
	gSpriteCaminar[1].w = 138;
	gSpriteCaminar[1].h = 123;

	gSpriteCaminar[0].x = 163;
	gSpriteCaminar[0].y = 3383;
	gSpriteCaminar[0].w = 141;
	gSpriteCaminar[0].h = 131;
}

void View_Jugador_VenomBlack::getSpritesSaltar() {
	gSpriteSaltar[0].x = 2;
	gSpriteSaltar[0].y = 5433;
	gSpriteSaltar[0].w = 132;
	gSpriteSaltar[0].h = 149;

	gSpriteSaltar[1].x = 196;
	gSpriteSaltar[1].y = 5405;
	gSpriteSaltar[1].w = 149;
	gSpriteSaltar[1].h = 170;

//	gSpriteSaltar[2].x = 355;
//	gSpriteSaltar[2].y = 5399;
//	gSpriteSaltar[2].w = 135;
//	gSpriteSaltar[2].h = 176;

	gSpriteSaltar[2].x = 556;
	gSpriteSaltar[2].y = 5405;
	gSpriteSaltar[2].w = 159;
	gSpriteSaltar[2].h = 137;

//	gSpriteSaltar[4].x = 719;
//	gSpriteSaltar[4].y = 5408;
//	gSpriteSaltar[4].w = 146;
//	gSpriteSaltar[4].h = 123;

	gSpriteSaltar[3].x = 869;
	gSpriteSaltar[3].y = 5414;
	gSpriteSaltar[3].w = 132;
	gSpriteSaltar[3].h = 101;

//	gSpriteSaltar[6].x = 1007;
//	gSpriteSaltar[6].y = 5409;
//	gSpriteSaltar[6].w = 140;
//	gSpriteSaltar[6].h = 122;

	gSpriteSaltar[4].x = 16;
	gSpriteSaltar[4].y = 5579;
	gSpriteSaltar[4].w = 119;
	gSpriteSaltar[4].h = 146;

//	gSpriteSaltar[8].x = 145;
//	gSpriteSaltar[8].y = 5583;
//	gSpriteSaltar[8].w = 135;
//	gSpriteSaltar[8].h = 144;

	gSpriteSaltar[5].x = 422;
	gSpriteSaltar[5].y = 5633;
	gSpriteSaltar[5].w = 159;
	gSpriteSaltar[5].h = 96;

//	gSpriteSaltar[10].x = 599;
//	gSpriteSaltar[10].y = 5634;
//	gSpriteSaltar[10].w = 114;
//	gSpriteSaltar[10].h = 101;
}

void View_Jugador_VenomBlack::getSpritesAgachar() {
	gSpriteAgachar[0].x = 2;
	gSpriteAgachar[0].y = 5433;
	gSpriteAgachar[0].w = 132;
	gSpriteAgachar[0].h = 149;
}

void View_Jugador_VenomBlack::getSpritesCambioPersonaje() {
	gSpriteCambiarPersonaje[0].x = 196;
	gSpriteCambiarPersonaje[0].y = 5405;
	gSpriteCambiarPersonaje[0].w = 149;
	gSpriteCambiarPersonaje[0].h = 170;
}

void View_Jugador_VenomBlack::render(int camX, int camY, SDL_Renderer * gRenderer) {
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

		this->texturaJugador->render(this->model->getPosX() - camX,
				this->model->getPosY() - camY, currentClip, 0, NULL,
			this->model->getDireccion(), gRenderer);
			}
		}
}
View_Jugador_VenomBlack::~View_Jugador_VenomBlack(){


}

