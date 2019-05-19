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
}

void View_Jugador_ChunLi::getSpritesCaminar() {
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
	CANTSPRITECLIPSALTA = 6;
	MINFRAMESALTA = 0;
	MAXFRAMESALTA = 5;
	this->gSpriteSaltar = new SDL_Rect[CANTSPRITECLIPSALTA];

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

void View_Jugador_ChunLi::getSpritesAgachar() {
	this->gSpriteAgachar = new SDL_Rect[1];

	gSpriteAgachar[0].x = 898;
	gSpriteAgachar[0].y = 234;
	gSpriteAgachar[0].w = 93;
	gSpriteAgachar[0].h = 93;
}

void View_Jugador_ChunLi::getSpritesCambioPersonaje() {

	this->gSpriteCambiarPersonaje = new SDL_Rect[1];

	gSpriteCambiarPersonaje[0].x = 97;
	gSpriteCambiarPersonaje[0].y = 581;
	gSpriteCambiarPersonaje[0].w = 100;
	gSpriteCambiarPersonaje[0].h = 163;
}

