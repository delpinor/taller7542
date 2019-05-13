#include "View_Jugador_VenomBlack.h"
#include "../Logger/Logger.h"
#include <sstream>
View_Jugador_VenomBlack::View_Jugador_VenomBlack() {

}

void View_Jugador_VenomBlack::initialize(Jugador * model, LTexture * texturaJugador) {
	this->texturaJugador = texturaJugador;
	CANTSPRITECLIPCAMINA = 10;
	MINFRAMECAMINA = 0;
	MAXFRAMECAMINA = 9;
	CANTSPRITECLIPSALTA = 6;
	MINFRAMESALTA = 0;
	MAXFRAMESALTA = 5;
	CANTSPRITEANIMACION = 7;
	MINFRAMEANIMACION = 0;
	MAXFRAMEANIMACION = 6;
	texturaJugador->setColor(120,150,20);
	this->gSpriteCaminar= new SDL_Rect [ CANTSPRITECLIPCAMINA];
	this->gSpriteCambiarPersonaje= new SDL_Rect[1];
	this->gSpriteSaltar= new SDL_Rect  [ CANTSPRITECLIPSALTA];
	this->gSpriteAgachar= new SDL_Rect[1];
	this->gSpriteGolpear= new SDL_Rect [ CANTSPRITECLIP];
	this->gSpriteAnimacion= new SDL_Rect[CANTSPRITEANIMACION];
	this->jugador = model;
	this->zIndex = model->get_zindex();

	getSpritesCaminar();
	getSpritesSaltar();
	getSpritesAgachar();
	getSpritesCambioPersonaje();
	getSpritesAnimacion();
}

void View_Jugador_VenomBlack::getSpritesAnimacion() {

	gSpriteAnimacion[0].x = 4;
	gSpriteAnimacion[0].y = 843;
	gSpriteAnimacion[0].w = 131;
	gSpriteAnimacion[0].h = 93;

	gSpriteAnimacion[1].x = 168;
	gSpriteAnimacion[1].y = 843;
	gSpriteAnimacion[1].w = 215;
	gSpriteAnimacion[1].h = 93;

	gSpriteAnimacion[2].x = 168;
	gSpriteAnimacion[2].y = 843;
	gSpriteAnimacion[2].w = 215;
	gSpriteAnimacion[2].h = 93;

	gSpriteAnimacion[3].x = 168;
	gSpriteAnimacion[3].y = 843;
	gSpriteAnimacion[3].w = 215;
	gSpriteAnimacion[3].h = 93;

	gSpriteAnimacion[4].x = 4;
	gSpriteAnimacion[4].y = 1070;
	gSpriteAnimacion[4].w = 157;
	gSpriteAnimacion[4].h = 100;

	gSpriteAnimacion[5].x = 4;
	gSpriteAnimacion[5].y = 1070;
	gSpriteAnimacion[5].w = 157;
	gSpriteAnimacion[5].h = 100;

	gSpriteAnimacion[6].x = 410;
	gSpriteAnimacion[6].y = 837;
	gSpriteAnimacion[6].w = 146;
	gSpriteAnimacion[6].h = 99;

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
	gSpriteSaltar[0].x = 205;
	gSpriteSaltar[0].y = 5415;
	gSpriteSaltar[0].w = 137;
	gSpriteSaltar[0].h = 153;

	gSpriteSaltar[1].x = 351;
	gSpriteSaltar[1].y = 5406;
	gSpriteSaltar[1].w = 137;
	gSpriteSaltar[1].h = 160;

	gSpriteSaltar[2].x = 561;
	gSpriteSaltar[2].y = 5421;
	gSpriteSaltar[2].w = 152;
	gSpriteSaltar[2].h = 123;

	gSpriteSaltar[3].x = 864;
	gSpriteSaltar[3].y = 5420;
	gSpriteSaltar[3].w = 140;
	gSpriteSaltar[3].h = 123;

	gSpriteSaltar[4].x = 145;
	gSpriteSaltar[4].y = 5586;
	gSpriteSaltar[4].w = 140;
	gSpriteSaltar[4].h = 141;

	gSpriteSaltar[5].x = 145;
	gSpriteSaltar[5].y = 5586;
	gSpriteSaltar[5].w = 140;
	gSpriteSaltar[5].h = 141;
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

//void View_Jugador_VenomBlack::render(int camX, int camY,
//		SDL_Renderer * gRenderer) {
//	SDL_Rect* currentClip;
//	contador++;
//	if (this->jugador->estaAgachado()) {
//
//		currentClip = &gSpriteAgachar[0];
//		this->texturaJugador->render(this->jugador->getPosX() - camX,
//				this->jugador->getPosY() - camY, currentClip, 0, NULL,
//				this->jugador->getDireccion(), gRenderer);
//		contador = 0;
//
//	} else {
//
//		if (this->jugador->estaActivo()) {
//
//			int maxFrames;
//			int minFrames;
//			if (this->jugador->estaCambiandoPersonaje()) {
//				contador = 0;
//				currentClip = &gSpriteCambiarPersonaje[0];
//				Logger::Log(LOGGER_NIVEL::DEBUG,"view VenomBlack:: cambiando personaje", " ");
//
//			} else if (this->jugador->estado->getVelY() != 0) {
//				if (this->jugador->estado->getVelY() >= 18) {
//					frame = 0;
//				}
//				minFrames = MINFRAMESALTA;
//				maxFrames = MAXFRAMESALTA;
//				if (frame / maxFrames >= maxFrames + 1) {
//					frame = minFrames;
//				}
//				contador = 0;
//				currentClip = &gSpriteSaltar[frame / MAXFRAMESALTA];
//			} else if ((this->jugador->estaActivo())
//					&& (this->jugador->estado->getVelY() == 0)
//					&& (this->jugador->estado->getVelX() == 0)
//					&& (contador > 100)) {
//				minFrames = MINFRAMEANIMACION;
//				maxFrames = MAXFRAMEANIMACION;
//				++frame;
//				Logger::Log(LOGGER_NIVEL::DEBUG, "view VenomBlack:: animacion"," ");
//				if (frame / maxFrames >= maxFrames + 1) {
//					frame = minFrames;
//					contador = 0;
//				}
//				currentClip = &gSpriteAnimacion[frame / MAXFRAMEANIMACION];
//			} else {
//				minFrames = MINFRAMECAMINA;
//				maxFrames = MAXFRAMECAMINA;
//				if (frame / maxFrames >= maxFrames + 1) {
//					frame = minFrames;
//				}
//				currentClip = &gSpriteCaminar[frame / MAXFRAMECAMINA];
//			}
//			if ((this->jugador->getVelX() != 0)
//					|| (this->jugador->getVelY() != 0)) {
//				++frame;
//				contador = 0;
//			}
//			this->texturaJugador->render(this->jugador->getPosX() - camX,
//					this->jugador->getPosY() - camY, currentClip, 0, NULL,
//					this->jugador->getDireccion(), gRenderer);
//		}
//	}
//}
View_Jugador_VenomBlack::~View_Jugador_VenomBlack(){
}

