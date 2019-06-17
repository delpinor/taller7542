#include "View_Jugador_CapAmerica.h"

#include <sstream>
View_Jugador_CapAmerica::View_Jugador_CapAmerica() {

}

void View_Jugador_CapAmerica::initialize(Jugador *model,
		LTexture * texturaJugador) {
	this->texturaJugador = texturaJugador;

	CANTSPRITECLIP = 6;

	this->gSpriteGolpear = new SDL_Rect[CANTSPRITECLIP];

	this->jugador = model;
	getSpritesCaminar();
	getSpritesSaltar();
	getSpritesAgachar();
	getSpritesAnimacion();
	getSpritesPatadaFuerte();
	this->zIndex = model->get_zindex();
	getSpritesCambioPersonaje();
	this->texturaJugador->setColor(this->jugador->getR(),  this->jugador->getG() , this->jugador->getB());

	this->sonido_salto=new EfectoSonido(1);
		this->sonido_ataque_pu=new EfectoSonido(1);
		this->sonido_defensa=new EfectoSonido(1);
		this->sonido_cambio=new EfectoSonido(1);
		//this->sonido_ataque_pu->init();
		this->sonido_ataque_pu->loadMedia("../Sonidos/cap_atk1.wav");
		this->sonido_salto->loadMedia("../Sonidos/salto_captain.wav");
	this->sonido_cambio->loadMedia("../Sonidos/cambio_captain.wav");

}

void  View_Jugador_CapAmerica::reproducir_sonido_salto(){

		this->sonido_salto->reproducir_sonido();


}
void  View_Jugador_CapAmerica::reproducir_sonido_cambio(){

		this->sonido_cambio->reproducir_sonido();

}
	void  View_Jugador_CapAmerica::reproducir_sonido_ataque_pu(){

		this->sonido_ataque_pu->reproducir_sonido();

}
void  View_Jugador_CapAmerica::reproducir_sonido_defensa(){

		this->sonido_defensa->reproducir_sonido();


}

void View_Jugador_CapAmerica::getSpritesCaminar() {
	CANTSPRITECLIPCAMINA = 12;
	MINFRAMECAMINA = 0;
	MAXFRAMECAMINA = 11;
	this->gSpriteCaminar = new SDL_Rect[CANTSPRITECLIPCAMINA];

	gSpriteCaminar[0].x = 0;
	gSpriteCaminar[0].y = 190;
	gSpriteCaminar[0].w = 261;
	gSpriteCaminar[0].h = 150;

	gSpriteCaminar[1].x = 0;
	gSpriteCaminar[1].y = 190;
	gSpriteCaminar[1].w = 261;
	gSpriteCaminar[1].h = 150;

	gSpriteCaminar[2].x = 184;
	gSpriteCaminar[2].y = 190;
	gSpriteCaminar[2].w = 261;
	gSpriteCaminar[2].h = 150;

	gSpriteCaminar[3].x = 184;
	gSpriteCaminar[3].y = 190;
	gSpriteCaminar[3].w = 261;
	gSpriteCaminar[3].h = 150;

	gSpriteCaminar[4].x = 379;
	gSpriteCaminar[4].y = 190;
	gSpriteCaminar[4].w = 261;
	gSpriteCaminar[4].h = 150;

	gSpriteCaminar[5].x = 379;
	gSpriteCaminar[5].y = 190;
	gSpriteCaminar[5].w = 261;
	gSpriteCaminar[5].h = 150;

	gSpriteCaminar[6].x = 592;
	gSpriteCaminar[6].y = 190;
	gSpriteCaminar[6].w = 261;
	gSpriteCaminar[6].h = 150;

	gSpriteCaminar[7].x = 592;
	gSpriteCaminar[7].y = 190;
	gSpriteCaminar[7].w = 261;
	gSpriteCaminar[7].h = 150;

	gSpriteCaminar[8].x = 766;
	gSpriteCaminar[8].y = 190;
	gSpriteCaminar[8].w = 261;
	gSpriteCaminar[8].h = 150;

	gSpriteCaminar[9].x = 766;
	gSpriteCaminar[9].y = 190;
	gSpriteCaminar[9].w = 261;
	gSpriteCaminar[9].h = 150;

	gSpriteCaminar[10].x = 971;
	gSpriteCaminar[10].y = 190;
	gSpriteCaminar[10].w = 261;
	gSpriteCaminar[10].h = 150;

	gSpriteCaminar[11].x = 971;
	gSpriteCaminar[11].y = 190;
	gSpriteCaminar[11].w = 261;
	gSpriteCaminar[11].h = 150;
//
//	gSpriteCaminar[6].x = 1170;
//	gSpriteCaminar[6].y = 190;
//	gSpriteCaminar[6].w = 261;
//	gSpriteCaminar[6].h = 150;
//
//	gSpriteCaminar[7].x = 1403;
//	gSpriteCaminar[7].y = 190;
//	gSpriteCaminar[7].w = 261;
//	gSpriteCaminar[7].h = 150;
//
//	gSpriteCaminar[8].x = 1602;
//	gSpriteCaminar[8].y = 190;
//	gSpriteCaminar[8].w = 261;
//	gSpriteCaminar[8].h = 150;
//
//	gSpriteCaminar[9].x = 1815;
//	gSpriteCaminar[9].y = 190;
//	gSpriteCaminar[9].w = 261;
//	gSpriteCaminar[9].h = 150;
//
//	gSpriteCaminar[10].x = 2040;
//	gSpriteCaminar[10].y = 190;
//	gSpriteCaminar[10].w = 261;
//	gSpriteCaminar[10].h = 150;
//
//	gSpriteCaminar[11].x = 2286;
//	gSpriteCaminar[11].y = 190;
//	gSpriteCaminar[11].w = 261;
//	gSpriteCaminar[11].h = 150;
}

void View_Jugador_CapAmerica::getSpritesAnimacion() {
	CANTSPRITEANIMACION = 9;
	MINFRAMEANIMACION = 0;
	MAXFRAMEANIMACION = 8;
	this->gSpriteAnimacion = new SDL_Rect[CANTSPRITEANIMACION];

		gSpriteAnimacion[0].x = 0;
		gSpriteAnimacion[0].y = 11;
		gSpriteAnimacion[0].w = 261;
		gSpriteAnimacion[0].h = 150;

		gSpriteAnimacion[1].x = 180;
		gSpriteAnimacion[1].y = 11;
		gSpriteAnimacion[1].w = 261;
		gSpriteAnimacion[1].h = 150;

		gSpriteAnimacion[2].x = 371;
		gSpriteAnimacion[2].y = 11;
		gSpriteAnimacion[2].w = 261;
		gSpriteAnimacion[2].h = 150;

		gSpriteAnimacion[3].x = 588;
		gSpriteAnimacion[3].y = 11;
		gSpriteAnimacion[3].w = 261;
		gSpriteAnimacion[3].h = 150;

		gSpriteAnimacion[4].x = 784;
		gSpriteAnimacion[4].y = 11;
		gSpriteAnimacion[4].w = 261;
		gSpriteAnimacion[4].h = 150;

		gSpriteAnimacion[5].x = 961;
		gSpriteAnimacion[5].y = 11;
		gSpriteAnimacion[5].w = 261;
		gSpriteAnimacion[5].h = 150;

		gSpriteAnimacion[6].x = 1169;
		gSpriteAnimacion[6].y = 11;
		gSpriteAnimacion[6].w = 261;
		gSpriteAnimacion[6].h = 150;

		gSpriteAnimacion[7].x = 1380;
		gSpriteAnimacion[7].y = 11;
		gSpriteAnimacion[7].w = 261;
		gSpriteAnimacion[7].h = 150;

		gSpriteAnimacion[8].x = 1595;
		gSpriteAnimacion[8].y = 11;
		gSpriteAnimacion[8].w = 261;
		gSpriteAnimacion[8].h = 150;

}

void View_Jugador_CapAmerica::getSpritesSaltar() {
	CANTSPRITECLIPSALTA = 6;
	MINFRAMESALTA = 0;
	MAXFRAMESALTA = 5;
	this->gSpriteSaltar = new SDL_Rect[CANTSPRITECLIPSALTA];

	gSpriteSaltar[0].x = 17;
	gSpriteSaltar[0].y = 363;
	gSpriteSaltar[0].w = 261;
	gSpriteSaltar[0].h = 150;

	gSpriteSaltar[1].x = 211;
	gSpriteSaltar[1].y = 357;
	gSpriteSaltar[1].w = 261;
	gSpriteSaltar[1].h = 150;

	gSpriteSaltar[2].x = 409;
	gSpriteSaltar[2].y = 364;
	gSpriteSaltar[2].w = 261;
	gSpriteSaltar[2].h = 150;

	gSpriteSaltar[3].x = 627;
	gSpriteSaltar[3].y = 384;
	gSpriteSaltar[3].w = 261;
	gSpriteSaltar[3].h = 150;

	gSpriteSaltar[4].x = 855;
	gSpriteSaltar[4].y = 374;
	gSpriteSaltar[4].w = 261;
	gSpriteSaltar[4].h = 150;

	gSpriteSaltar[5].x = 17;
	gSpriteSaltar[5].y = 363;
	gSpriteSaltar[5].w = 261;
	gSpriteSaltar[5].h = 150;
}

void View_Jugador_CapAmerica::getSpritesAgachar() {
	this->gSpriteAgachar = new SDL_Rect[1];

	gSpriteAgachar[0].x = 17;
	gSpriteAgachar[0].y = 363;
	gSpriteAgachar[0].w = 261;
	gSpriteAgachar[0].h = 150;
}

void View_Jugador_CapAmerica::getSpritesPatadaFuerte() {
	CANTSPRITECLIPPATADON = 6;
	MINFRAMEPATADON = 0;
	MAXFRAMEPATADON = 5;
	this->gSpritePatadadon = new SDL_Rect[CANTSPRITECLIPPATADON];

	gSpritePatadadon[0].x = 323;
	gSpritePatadadon[0].y = 1297;
	gSpritePatadadon[0].w = 261;
	gSpritePatadadon[0].h = 150;

	gSpritePatadadon[1].x = 543;
	gSpritePatadadon[1].y = 1296;
	gSpritePatadadon[1].w = 261;
	gSpritePatadadon[1].h = 150;

	gSpritePatadadon[2].x = 744;
	gSpritePatadadon[2].y = 1293;
	gSpritePatadadon[2].w = 261;
	gSpritePatadadon[2].h = 150;

	gSpritePatadadon[3].x = 948;
	gSpritePatadadon[3].y = 1296;
	gSpritePatadadon[3].w = 261;
	gSpritePatadadon[3].h = 150;

	gSpritePatadadon[4].x = 1183;
	gSpritePatadadon[4].y = 1295;
	gSpritePatadadon[4].w = 261;
	gSpritePatadadon[4].h = 150;

	gSpritePatadadon[5].x = 119;
	gSpritePatadadon[5].y = 1490;
	gSpritePatadadon[5].w = 261;
	gSpritePatadadon[5].h = 150;

}

void View_Jugador_CapAmerica::getSpritesCambioPersonaje() {

	this->gSpriteCambiarPersonaje = new SDL_Rect[1];

	gSpriteCambiarPersonaje[0].x = 97;
	gSpriteCambiarPersonaje[0].y = 581;
	gSpriteCambiarPersonaje[0].w = 100;
	gSpriteCambiarPersonaje[0].h = 163;
}

