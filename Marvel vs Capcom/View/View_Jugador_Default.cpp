/*
 * ViewJugadorDefault.cpp
 *
 *  Created on: 13 abr. 2019
 *      Author: maciel
 */

#include "View_Jugador_Default.h"

View_Jugador_Default::View_Jugador_Default() {
	// TODO Auto-generated constructor stub

}

void View_Jugador_Default::initialize(Jugador *model,
		LTexture * texturaJugador) {
	this->texturaJugador = texturaJugador;
	SDL_Rect gSprite[1];
	CANTSPRITECLIPCAMINA = 1;
	CANTSPRITECLIP = 1;
	MINFRAMECAMINA = 0;
	MAXFRAMECAMINA = 1;
	CANTSPRITECLIPSALTA = 1;
	MINFRAMESALTA = 0;
	MAXFRAMESALTA = 1;
	CANTSPRITEANIMACION = 1;
	MINFRAMEANIMACION = 0;
	MAXFRAMEANIMACION = 1;
	this->gSpriteCaminar = gSprite;
	this->gSpriteCambiarPersonaje = gSprite;
	this->gSpriteSaltar = gSprite;
	this->gSpriteAgachar = gSprite;
	this->gSpriteGolpear = gSprite;
	this->gSpriteAnimacion = gSprite;
	this->gSprite = gSprite;
	this->jugador = model;

	this->zIndex = model->get_zindex();
	getSprites();
}

void View_Jugador_Default::getSprites() {
	gSprite[0].x = 0;
	gSprite[0].y = 0;
	gSprite[0].w = 128;
	gSprite[0].h = 128;

}
