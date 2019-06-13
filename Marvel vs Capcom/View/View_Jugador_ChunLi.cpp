#include "View_Jugador_ChunLi.h"

#include <sstream>
View_Jugador_ChunLi::View_Jugador_ChunLi() {

}

void View_Jugador_ChunLi::initialize(Jugador *model,
		LTexture * texturaJugador) {
	this->texturaJugador = texturaJugador;

	CANTSPRITECLIP = 6;

	this->gSpriteGolpear = new SDL_Rect[CANTSPRITECLIP];

	this->jugador = model;
	getSpritesCaminar();
	getSpritesSaltar();
	getSpritesAgachar();
	getSpritesAnimacion();
	this->zIndex = model->get_zindex();
	getSpritesCambioPersonaje();
	this->texturaJugador->setColor(this->jugador->getR(),  this->jugador->getG() , this->jugador->getB());
}

void View_Jugador_ChunLi::getSpritesCaminar() {
	CANTSPRITECLIPCAMINA = 11;
	MINFRAMECAMINA = 0;
	MAXFRAMECAMINA = 10;
	this->gSpriteCaminar = new SDL_Rect[CANTSPRITECLIPCAMINA];

	gSpriteCaminar[0].x = 32;
	gSpriteCaminar[0].y = 328;
	gSpriteCaminar[0].w = 83;
	gSpriteCaminar[0].h = 93;

	gSpriteCaminar[1].x = 127;
	gSpriteCaminar[1].y = 328;
	gSpriteCaminar[1].w = 83;
	gSpriteCaminar[1].h = 93;

	gSpriteCaminar[2].x = 206;
	gSpriteCaminar[2].y = 328;
	gSpriteCaminar[2].w = 83;
	gSpriteCaminar[2].h = 93;

	gSpriteCaminar[3].x = 283;
	gSpriteCaminar[3].y = 328;
	gSpriteCaminar[3].w = 83;
	gSpriteCaminar[3].h = 93;

	gSpriteCaminar[4].x = 366;
	gSpriteCaminar[4].y = 328;
	gSpriteCaminar[4].w = 83;
	gSpriteCaminar[4].h = 93;

	gSpriteCaminar[5].x = 450;
	gSpriteCaminar[5].y = 328;
	gSpriteCaminar[5].w = 83;
	gSpriteCaminar[5].h = 93;

	gSpriteCaminar[6].x = 538;
	gSpriteCaminar[6].y = 328;
	gSpriteCaminar[6].w = 83;
	gSpriteCaminar[6].h = 93;

	gSpriteCaminar[7].x = 615;
	gSpriteCaminar[7].y = 328;
	gSpriteCaminar[7].w = 83;
	gSpriteCaminar[7].h = 93;

	gSpriteCaminar[8].x = 690;
	gSpriteCaminar[8].y = 328;
	gSpriteCaminar[8].w = 83;
	gSpriteCaminar[8].h = 93;

	gSpriteCaminar[9].x = 763;
	gSpriteCaminar[9].y = 328;
	gSpriteCaminar[9].w = 83;
	gSpriteCaminar[9].h = 93;

	gSpriteCaminar[10].x = 838;
	gSpriteCaminar[10].y = 328;
	gSpriteCaminar[10].w = 83;
	gSpriteCaminar[10].h = 93;

}

void View_Jugador_ChunLi::getSpritesAnimacion() {
	CANTSPRITEANIMACION = 7;
	MINFRAMEANIMACION = 0;
	MAXFRAMEANIMACION = 6;
	this->gSpriteAnimacion = new SDL_Rect[CANTSPRITEANIMACION];

		gSpriteAnimacion[0].x = 27;
		gSpriteAnimacion[0].y = 228;
		gSpriteAnimacion[0].w = 93;
		gSpriteAnimacion[0].h = 93;

		gSpriteAnimacion[1].x = 126;
		gSpriteAnimacion[1].y = 228;
		gSpriteAnimacion[1].w = 93;
		gSpriteAnimacion[1].h = 93;

		gSpriteAnimacion[2].x = 224;
		gSpriteAnimacion[2].y = 228;
		gSpriteAnimacion[2].w = 93;
		gSpriteAnimacion[2].h = 93;

		gSpriteAnimacion[3].x = 320;
		gSpriteAnimacion[3].y = 228;
		gSpriteAnimacion[3].w = 93;
		gSpriteAnimacion[3].h = 93;

		gSpriteAnimacion[4].x = 414;
		gSpriteAnimacion[4].y = 228;
		gSpriteAnimacion[4].w = 93;
		gSpriteAnimacion[4].h = 93;

		gSpriteAnimacion[5].x = 506;
		gSpriteAnimacion[5].y = 228;
		gSpriteAnimacion[5].w = 93;
		gSpriteAnimacion[5].h = 93;

		gSpriteAnimacion[6].x = 598;
		gSpriteAnimacion[6].y = 228;
		gSpriteAnimacion[6].w = 93;
		gSpriteAnimacion[6].h = 93;


}

void View_Jugador_ChunLi::getSpritesSaltar() {
	CANTSPRITECLIPSALTA = 9;
	MINFRAMESALTA = 0;
	MAXFRAMESALTA = 8;
	this->gSpriteSaltar = new SDL_Rect[CANTSPRITECLIPSALTA];

	gSpriteSaltar[0].x = 94;
	gSpriteSaltar[0].y = 526;
	gSpriteSaltar[0].w = 65;
	gSpriteSaltar[0].h = 116;

	gSpriteSaltar[1].x = 154;
	gSpriteSaltar[1].y = 526;
	gSpriteSaltar[1].w = 65;
	gSpriteSaltar[1].h = 116;

	gSpriteSaltar[2].x = 219;
	gSpriteSaltar[2].y = 526;
	gSpriteSaltar[2].w = 65;
	gSpriteSaltar[2].h = 116;

	gSpriteSaltar[3].x = 292;
	gSpriteSaltar[3].y = 526;
	gSpriteSaltar[3].w = 65;
	gSpriteSaltar[3].h = 116;

	gSpriteSaltar[4].x = 362;
	gSpriteSaltar[4].y = 526;
	gSpriteSaltar[4].w = 65;
	gSpriteSaltar[4].h = 116;

	gSpriteSaltar[5].x = 434;
	gSpriteSaltar[5].y = 526;
	gSpriteSaltar[5].w = 65;
	gSpriteSaltar[5].h = 116;

	gSpriteSaltar[6].x = 506;
	gSpriteSaltar[6].y = 526;
	gSpriteSaltar[6].w = 65;
	gSpriteSaltar[6].h = 116;

	gSpriteSaltar[7].x = 561;
	gSpriteSaltar[7].y = 526;
	gSpriteSaltar[7].w = 65;
	gSpriteSaltar[7].h = 116;

	gSpriteSaltar[8].x = 626;
	gSpriteSaltar[8].y = 526;
	gSpriteSaltar[8].w = 65;
	gSpriteSaltar[8].h = 116;
}

void View_Jugador_ChunLi::getSpritesAgachar() {
	this->gSpriteAgachar = new SDL_Rect[1];

	gSpriteAgachar[0].x = 898;
	gSpriteAgachar[0].y = 234;
	gSpriteAgachar[0].w = 93;
	gSpriteAgachar[0].h = 93;
}

void View_Jugador_ChunLi::getSpritesCambioPersonaje() {

	this->gSpriteCambiarPersonaje = new SDL_Rect[1];

	gSpriteCambiarPersonaje[0].x = 89;
	gSpriteCambiarPersonaje[0].y = 525;
	gSpriteCambiarPersonaje[0].w = 73;
	gSpriteCambiarPersonaje[0].h = 108;
}

