#include "View_Jugador_CapAmericaBlack.h"

#include <sstream>
View_Jugador_CapAmericaBlack::View_Jugador_CapAmericaBlack() {

}

void View_Jugador_CapAmericaBlack::initialize(Jugador *model,
		LTexture * texturaJugador) {
	this->texturaJugador = texturaJugador;
	CANTSPRITECLIP = 6;
	texturaJugador->setColor(80, 140, 0);
	this->gSpriteGolpear = new SDL_Rect[CANTSPRITECLIP];
	this->jugador = model;
	getSpritesCaminar();
	getSpritesSaltar();
	getSpritesAgachar();
	getSpritesCambioPersonaje();
	getSpritesAnimacion();
	this->zIndex = model->get_zindex();
}

void View_Jugador_CapAmericaBlack::getSpritesCaminar() {
	CANTSPRITECLIPCAMINA = 12;
	MINFRAMECAMINA = 0;
	MAXFRAMECAMINA = 11;
	this->gSpriteCaminar = new SDL_Rect[CANTSPRITECLIPCAMINA];
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

void View_Jugador_CapAmericaBlack::getSpritesAnimacion() {
	CANTSPRITEANIMACION = 6;
	MINFRAMEANIMACION = 0;
	MAXFRAMEANIMACION = 5;
	this->gSpriteAnimacion = new SDL_Rect[CANTSPRITEANIMACION];

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

void View_Jugador_CapAmericaBlack::getSpritesSaltar() {
	CANTSPRITECLIPSALTA = 6;
	MINFRAMESALTA = 0;
	MAXFRAMESALTA = 5;
	this->gSpriteSaltar = new SDL_Rect[CANTSPRITECLIPSALTA];

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

	this->gSpriteAgachar = new SDL_Rect[1];

	gSpriteAgachar[0].x = 4;
	gSpriteAgachar[0].y = 481;
	gSpriteAgachar[0].w = 88;
	gSpriteAgachar[0].h = 119;
}

void View_Jugador_CapAmericaBlack::getSpritesCambioPersonaje() {

	this->gSpriteCambiarPersonaje = new SDL_Rect[1];

	gSpriteCambiarPersonaje[0].x = 97;
	gSpriteCambiarPersonaje[0].y = 581;
	gSpriteCambiarPersonaje[0].w = 100;
	gSpriteCambiarPersonaje[0].h = 163;
}
