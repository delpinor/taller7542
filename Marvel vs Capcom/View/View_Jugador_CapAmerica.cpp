#include "View_Jugador_CapAmerica.h"

#include <sstream>
View_Jugador_CapAmerica::View_Jugador_CapAmerica() {

}

void View_Jugador_CapAmerica::initialize(Jugador *model, LTexture * texturaJugador) {
	this->texturaJugador = texturaJugador;
	CANTSPRITECLIPCAMINA = 12;
	CANTSPRITECLIP = 6;
	MINFRAMECAMINA = 0;
	MAXFRAMECAMINA = 11;
	CANTSPRITECLIPSALTA = 6;
	MINFRAMESALTA = 0;
	MAXFRAMESALTA = 5;
	CANTSPRITEANIMACION = 6;
	MINFRAMEANIMACION = 0;
	MAXFRAMEANIMACION = 5;
	this->gSpriteCaminar= new SDL_Rect [ CANTSPRITECLIPCAMINA];
	this->gSpriteCambiarPersonaje= new SDL_Rect[1];
	this->gSpriteSaltar= new SDL_Rect  [ CANTSPRITECLIPSALTA];
	this->gSpriteAgachar= new SDL_Rect[1];
	this->gSpriteGolpear= new SDL_Rect [ CANTSPRITECLIP];
	this->gSpriteAnimacion= new SDL_Rect[CANTSPRITEANIMACION];
	this->jugador = model;
	getSpritesCaminar();
	getSpritesSaltar();
	getSpritesAgachar();
	getSpritesAnimacion();
	this->zIndex = model->get_zindex();
	getSpritesCambioPersonaje();
}

void View_Jugador_CapAmerica::getSpritesCaminar() {

	this->gSpriteCaminar[0].x = 0;
	this->gSpriteCaminar[0].y = 150;
	this->gSpriteCaminar[0].w = 90;
	this->gSpriteCaminar[0].h = 130;

	this->gSpriteCaminar[1].x = 100;
	this->gSpriteCaminar[1].y = 150;
	this->gSpriteCaminar[1].w = 90;
	this->gSpriteCaminar[1].h = 130;

	this->gSpriteCaminar[2].x = 200;
	this->gSpriteCaminar[2].y = 150;
	this->gSpriteCaminar[2].w = 90;
	this->gSpriteCaminar[2].h = 130;

	this->gSpriteCaminar[3].x = 300;
	this->gSpriteCaminar[3].y = 150;
	this->gSpriteCaminar[3].w = 90;
	this->gSpriteCaminar[3].h = 130;

	this->gSpriteCaminar[4].x = 400;
	this->gSpriteCaminar[4].y = 150;
	this->gSpriteCaminar[4].w = 90;
	this->gSpriteCaminar[4].h = 130;

	this->gSpriteCaminar[5].x = 500;
	this->gSpriteCaminar[5].y = 150;
	this->gSpriteCaminar[5].w = 90;
	this->gSpriteCaminar[5].h = 130;

	this->gSpriteCaminar[6].x = 5;
	this->gSpriteCaminar[6].y = 280;
	this->gSpriteCaminar[6].w = 100;
	this->gSpriteCaminar[6].h = 130;


	this->gSpriteCaminar[7].x = 105;
	this->gSpriteCaminar[7].y = 280;
	this->gSpriteCaminar[7].w = 90;
	this->gSpriteCaminar[7].h = 130;

	this->gSpriteCaminar[8].x = 195;
	this->gSpriteCaminar[8].y = 280;
	this->gSpriteCaminar[8].w = 90;
	this->gSpriteCaminar[8].h = 130;

	this->gSpriteCaminar[9].x = 295;
	this->gSpriteCaminar[9].y = 280;
	this->gSpriteCaminar[9].w = 105;
	this->gSpriteCaminar[9].h = 130;

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



