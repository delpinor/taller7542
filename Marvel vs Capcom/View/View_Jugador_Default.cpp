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
	CANTSPRITECLIPCAMINA = 1;
	CANTSPRITECLIP = 1;
	MINFRAMECAMINA = 0;
	MAXFRAMECAMINA = 1;
	CANTSPRITECLIPSALTA = 1;
	MINFRAMESALTA = 0;
	MAXFRAMESALTA = 1;
	CANTSPRITEANIMACION = 2;
	MINFRAMEANIMACION = 0;
	MAXFRAMEANIMACION = 1;

	this->gSpriteCaminar= new SDL_Rect [ 1];
	this->gSpriteCambiarPersonaje= new SDL_Rect[1];
	this->gSpriteSaltar= new SDL_Rect  [ 1];
	this->gSpriteAgachar= new SDL_Rect[1];
	this->gSpriteGolpear= new SDL_Rect [ 1];
	this->gSpriteAnimacion= new SDL_Rect[1];
	this->jugador = model;
	getSprites();
	this->zIndex = model->get_zindex();

}

void View_Jugador_Default::getSprites() {
	gSpriteCaminar[0].x = 0;
	gSpriteCaminar[0].y = 0;
	gSpriteCaminar[0].w = 128;
	gSpriteCaminar[0].h = 128;
	gSpriteCambiarPersonaje[0].x = 0;
	gSpriteCambiarPersonaje[0].y = 0;
	gSpriteCambiarPersonaje[0].w = 128;
	gSpriteCambiarPersonaje[0].h = 128;
	gSpriteSaltar[0].x = 0;
	gSpriteSaltar[0].y = 0;
	gSpriteSaltar[0].w = 128;
	gSpriteSaltar[0].h = 128;
	gSpriteAgachar[0].x = 0;
	gSpriteAgachar[0].y = 0;
	gSpriteAgachar[0].w = 128;
	gSpriteAgachar[0].h = 128;
	gSpriteGolpear[0].x = 0;
	gSpriteGolpear[0].y = 0;
	gSpriteGolpear[0].w = 128;
	gSpriteGolpear[0].h = 128;
	gSpriteAnimacion[0].x = 0;
	gSpriteAnimacion[0].y = 0;
	gSpriteAnimacion[0].w = 128;
	gSpriteAnimacion[0].h = 128;
	gSpriteAnimacion[1].x = 0;
	gSpriteAnimacion[1].y = 0;
	gSpriteAnimacion[1].w = 128;
	gSpriteAnimacion[1].h = 128;
}
