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
	getSpritesPatadaFuerte();
	this->texturaJugador->setColor(this->jugador->getR(),  this->jugador->getG() , this->jugador->getB());
}

void View_Jugador_ChunLi::getSpritesAnimacion() {
	CANTSPRITEANIMACION = 7;
	MINFRAMEANIMACION = 0;
	MAXFRAMEANIMACION = 6;
	FACTORANIMACION = 6;
	this->gSpriteAnimacion = new SDL_Rect[CANTSPRITEANIMACION];

	gSpriteAnimacion[0].x = 15;
	gSpriteAnimacion[0].y = 15;
	gSpriteAnimacion[0].w = 261;
	gSpriteAnimacion[0].h = 150;

	gSpriteAnimacion[1].x = 194;
	gSpriteAnimacion[1].y = 15;
	gSpriteAnimacion[1].w = 261;
	gSpriteAnimacion[1].h = 150;

	gSpriteAnimacion[2].x = 372;
	gSpriteAnimacion[2].y = 15;
	gSpriteAnimacion[2].w = 261;
	gSpriteAnimacion[2].h = 150;

	gSpriteAnimacion[3].x = 567;
	gSpriteAnimacion[3].y = 15;
	gSpriteAnimacion[3].w = 261;
	gSpriteAnimacion[3].h = 150;

	gSpriteAnimacion[4].x = 788;
	gSpriteAnimacion[4].y = 15;
	gSpriteAnimacion[4].w = 261;
	gSpriteAnimacion[4].h = 150;

	gSpriteAnimacion[5].x = 1013;
	gSpriteAnimacion[5].y = 15;
	gSpriteAnimacion[5].w = 261;
	gSpriteAnimacion[5].h = 150;

	gSpriteAnimacion[6].x = 1221;
	gSpriteAnimacion[6].y = 15;
	gSpriteAnimacion[6].w = 261;
	gSpriteAnimacion[6].h = 150;

}

void View_Jugador_ChunLi::getSpritesCaminar() {
	CANTSPRITECLIPCAMINA = 11;
	MINFRAMECAMINA = 0;
	MAXFRAMECAMINA = 10;
	FACTORCAMINA = 7;
	this->gSpriteCaminar = new SDL_Rect[CANTSPRITECLIPCAMINA];

	gSpriteCaminar[0].x = 16;
	gSpriteCaminar[0].y = 181;
	gSpriteCaminar[0].w = 261;
	gSpriteCaminar[0].h = 150;

	gSpriteCaminar[1].x = 196;
	gSpriteCaminar[1].y = 181;
	gSpriteCaminar[1].w = 261;
	gSpriteCaminar[1].h = 150;

	gSpriteCaminar[2].x = 385;
	gSpriteCaminar[2].y = 181;
	gSpriteCaminar[2].w = 261;
	gSpriteCaminar[2].h = 150;

	gSpriteCaminar[3].x = 579;
	gSpriteCaminar[3].y = 181;
	gSpriteCaminar[3].w = 261;
	gSpriteCaminar[3].h = 150;

	gSpriteCaminar[4].x = 779;
	gSpriteCaminar[4].y = 181;
	gSpriteCaminar[4].w = 261;
	gSpriteCaminar[4].h = 150;

	gSpriteCaminar[5].x = 1017;
	gSpriteCaminar[5].y = 181;
	gSpriteCaminar[5].w = 261;
	gSpriteCaminar[5].h = 150;

	gSpriteCaminar[6].x = 1225;
	gSpriteCaminar[6].y = 181;
	gSpriteCaminar[6].w = 261;
	gSpriteCaminar[6].h = 150;

	gSpriteCaminar[7].x = 1434;
	gSpriteCaminar[7].y = 181;
	gSpriteCaminar[7].w = 261;
	gSpriteCaminar[7].h = 150;

	gSpriteCaminar[8].x = 1645;
	gSpriteCaminar[8].y = 181;
	gSpriteCaminar[8].w = 261;
	gSpriteCaminar[8].h = 150;

	gSpriteCaminar[9].x = 1844;
	gSpriteCaminar[9].y = 181;
	gSpriteCaminar[9].w = 261;
	gSpriteCaminar[9].h = 150;

	gSpriteCaminar[10].x = 2066;
	gSpriteCaminar[10].y = 181;
	gSpriteCaminar[10].w = 261;
	gSpriteCaminar[10].h = 150;

}



void View_Jugador_ChunLi::getSpritesSaltar() {
	CANTSPRITECLIPSALTA = 9;
	MINFRAMESALTA = 0;
	MAXFRAMESALTA = 8;
	FACTORSALTA = 8;
	this->gSpriteSaltar = new SDL_Rect[CANTSPRITECLIPSALTA];

	gSpriteSaltar[0].x = 297;
	gSpriteSaltar[0].y = 2697;
	gSpriteSaltar[0].w = 261;
	gSpriteSaltar[0].h = 150;

	gSpriteSaltar[1].x = 556;
	gSpriteSaltar[1].y = 2697;
	gSpriteSaltar[1].w = 261;
	gSpriteSaltar[1].h = 150;

	gSpriteSaltar[2].x = 789;
	gSpriteSaltar[2].y = 2697;
	gSpriteSaltar[2].w = 261;
	gSpriteSaltar[2].h = 150;

	gSpriteSaltar[3].x = 1045;
	gSpriteSaltar[3].y = 2697;
	gSpriteSaltar[3].w = 261;
	gSpriteSaltar[3].h = 150;

	gSpriteSaltar[4].x = 1267;
	gSpriteSaltar[4].y = 2697;
	gSpriteSaltar[4].w = 261;
	gSpriteSaltar[4].h = 150;

	gSpriteSaltar[5].x = 1495;
	gSpriteSaltar[5].y = 2697;
	gSpriteSaltar[5].w = 65;
	gSpriteSaltar[5].h = 150;

	gSpriteSaltar[6].x = 1719;
	gSpriteSaltar[6].y = 2697;
	gSpriteSaltar[6].w = 261;
	gSpriteSaltar[6].h = 150;

	gSpriteSaltar[7].x = 1945;
	gSpriteSaltar[7].y = 2697;
	gSpriteSaltar[7].w = 261;
	gSpriteSaltar[7].h = 150;

	gSpriteSaltar[8].x = 2145;
	gSpriteSaltar[8].y = 2697;
	gSpriteSaltar[8].w = 261;
	gSpriteSaltar[8].h = 150;
}

void View_Jugador_ChunLi::getSpritesAgachar() {
	this->gSpriteAgachar = new SDL_Rect[1];

	gSpriteAgachar[0].x = 1543;
	gSpriteAgachar[0].y = 15;
	gSpriteAgachar[0].w = 261;
	gSpriteAgachar[0].h = 150;
}

void View_Jugador_ChunLi::getSpritesCambioPersonaje() {

	this->gSpriteCambiarPersonaje = new SDL_Rect[1];

	gSpriteCambiarPersonaje[0].x = 297;
	gSpriteCambiarPersonaje[0].y = 2697;
	gSpriteCambiarPersonaje[0].w = 261;
	gSpriteCambiarPersonaje[0].h = 150;
}

void View_Jugador_ChunLi::getSpritesPatadaFuerte() {
	CANTSPRITECLIPPATADON = 12;
	MINFRAMEPATADON = 0;
	MAXFRAMEPATADON = 11;
	FACTORPATADON = 5;
	this->gSpritePatadadon = new SDL_Rect[CANTSPRITECLIPPATADON];

	gSpritePatadadon[0].x = 71;
	gSpritePatadadon[0].y = 2271;
	gSpritePatadadon[0].w = 261;
	gSpritePatadadon[0].h = 150;

	gSpritePatadadon[1].x = 313;
	gSpritePatadadon[1].y = 2271;
	gSpritePatadadon[1].w = 261;
	gSpritePatadadon[1].h = 150;

	gSpritePatadadon[2].x = 563;
	gSpritePatadadon[2].y = 2271;
	gSpritePatadadon[2].w = 261;
	gSpritePatadadon[2].h = 150;

	gSpritePatadadon[3].x = 810;
	gSpritePatadadon[3].y = 2271;
	gSpritePatadadon[3].w = 261;
	gSpritePatadadon[3].h = 150;

	gSpritePatadadon[4].x = 1035;
	gSpritePatadadon[4].y = 2271;
	gSpritePatadadon[4].w = 261;
	gSpritePatadadon[4].h = 150;

	gSpritePatadadon[5].x = 1283;
	gSpritePatadadon[5].y = 2271;
	gSpritePatadadon[5].w = 261;
	gSpritePatadadon[5].h = 150;

	gSpritePatadadon[6].x = 1513;
	gSpritePatadadon[6].y = 2271;
	gSpritePatadadon[6].w = 261;
	gSpritePatadadon[6].h = 150;

	gSpritePatadadon[7].x = 1782;
	gSpritePatadadon[7].y = 2271;
	gSpritePatadadon[7].w = 261;
	gSpritePatadadon[7].h = 150;

	gSpritePatadadon[8].x = 2078;
	gSpritePatadadon[8].y = 2271;
	gSpritePatadadon[8].w = 261;
	gSpritePatadadon[8].h = 150;

	gSpritePatadadon[9].x = 62;
	gSpritePatadadon[9].y = 2496;
	gSpritePatadadon[9].w = 261;
	gSpritePatadadon[9].h = 150;

	gSpritePatadadon[10].x = 326;
	gSpritePatadadon[10].y = 2496;
	gSpritePatadadon[10].w = 261;
	gSpritePatadadon[10].h = 150;

	gSpritePatadadon[11].x = 582;
	gSpritePatadadon[11].y = 2496;
	gSpritePatadadon[11].w = 261;
	gSpritePatadadon[11].h = 150;

}
