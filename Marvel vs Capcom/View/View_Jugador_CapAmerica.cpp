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

void View_Jugador_CapAmerica::getSpritesAnimacion() {
	CANTSPRITEANIMACION = 9;
	MINFRAMEANIMACION = 0;
	MAXFRAMEANIMACION = 8;
	FACTORANIMACION = 8;
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

void View_Jugador_CapAmerica::getSpritesCaminar() {
	CANTSPRITECLIPCAMINA = 6;
	MINFRAMECAMINA = 0;
	MAXFRAMECAMINA = 5;
	FACTORCAMINA = 10;
	this->gSpriteCaminar = new SDL_Rect[CANTSPRITECLIPCAMINA];

	gSpriteCaminar[0].x = 0;
	gSpriteCaminar[0].y = 190;
	gSpriteCaminar[0].w = 261;
	gSpriteCaminar[0].h = 150;

	gSpriteCaminar[1].x = 184;
	gSpriteCaminar[1].y = 190;
	gSpriteCaminar[1].w = 261;
	gSpriteCaminar[1].h = 150;

	gSpriteCaminar[2].x = 379;
	gSpriteCaminar[2].y = 190;
	gSpriteCaminar[2].w = 261;
	gSpriteCaminar[2].h = 150;

	gSpriteCaminar[3].x = 592;
	gSpriteCaminar[3].y = 190;
	gSpriteCaminar[3].w = 261;
	gSpriteCaminar[3].h = 150;

	gSpriteCaminar[4].x = 766;
	gSpriteCaminar[4].y = 190;
	gSpriteCaminar[4].w = 261;
	gSpriteCaminar[4].h = 150;

	gSpriteCaminar[5].x = 971;
	gSpriteCaminar[5].y = 190;
	gSpriteCaminar[5].w = 261;
	gSpriteCaminar[5].h = 150;

}



void View_Jugador_CapAmerica::getSpritesSaltar() {
	CANTSPRITECLIPSALTA = 7;
	MINFRAMESALTA = 0;
	MAXFRAMESALTA = 6;
	FACTORSALTA = 2;
	this->gSpriteSaltar = new SDL_Rect[CANTSPRITECLIPSALTA];

//	gSpriteSaltar[0].x = 17;
//	gSpriteSaltar[0].y = 363;
//	gSpriteSaltar[0].w = 261;
//	gSpriteSaltar[0].h = 150;

	gSpriteSaltar[0].x = 211;
	gSpriteSaltar[0].y = 357;
	gSpriteSaltar[0].w = 261;
	gSpriteSaltar[0].h = 150;

	gSpriteSaltar[1].x = 409;
	gSpriteSaltar[1].y = 364;
	gSpriteSaltar[1].w = 261;
	gSpriteSaltar[1].h = 150;

	gSpriteSaltar[2].x = 855;
	gSpriteSaltar[2].y = 374;
	gSpriteSaltar[2].w = 261;
	gSpriteSaltar[2].h = 150;

	gSpriteSaltar[3].x = 627;
	gSpriteSaltar[3].y = 384;
	gSpriteSaltar[3].w = 261;
	gSpriteSaltar[3].h = 150;

	gSpriteSaltar[4].x = 855;
	gSpriteSaltar[4].y = 374;
	gSpriteSaltar[4].w = 261;
	gSpriteSaltar[2].h = 150;

	gSpriteSaltar[5].x = 211;
	gSpriteSaltar[5].y = 357;
	gSpriteSaltar[5].w = 261;
	gSpriteSaltar[5].h = 150;

	gSpriteSaltar[6].x = 17;
	gSpriteSaltar[6].y = 363;
	gSpriteSaltar[6].w = 261;
	gSpriteSaltar[6].h = 157;
}

void View_Jugador_CapAmerica::getSpritesAgachar() {
	this->gSpriteAgachar = new SDL_Rect[1];

	gSpriteAgachar[0].x = 17;
	gSpriteAgachar[0].y = 363;
	gSpriteAgachar[0].w = 261;
	gSpriteAgachar[0].h = 150;
}

void View_Jugador_CapAmerica::getSpritesCambioPersonaje() {

	this->gSpriteCambiarPersonaje = new SDL_Rect[1];

	gSpriteCambiarPersonaje[0].x = 211;
	gSpriteCambiarPersonaje[0].y = 357;
	gSpriteCambiarPersonaje[0].w = 261;
	gSpriteCambiarPersonaje[0].h = 150;
}

void View_Jugador_CapAmerica::getSpritesPatadaFuerte() {
	CANTSPRITECLIPPATADON = 6;
	MINFRAMEPATADON = 0;
	MAXFRAMEPATADON = 5;
	FACTORPATADON = 6;
	this->gSpritePatadon = new SDL_Rect[CANTSPRITECLIPPATADON];

	gSpritePatadon[0].x = 323;
	gSpritePatadon[0].y = 1297;
	gSpritePatadon[0].w = 261;
	gSpritePatadon[0].h = 150;

	gSpritePatadon[1].x = 543;
	gSpritePatadon[1].y = 1296;
	gSpritePatadon[1].w = 261;
	gSpritePatadon[1].h = 150;

	gSpritePatadon[2].x = 744;
	gSpritePatadon[2].y = 1293;
	gSpritePatadon[2].w = 261;
	gSpritePatadon[2].h = 150;

	gSpritePatadon[3].x = 948;
	gSpritePatadon[3].y = 1296;
	gSpritePatadon[3].w = 261;
	gSpritePatadon[3].h = 150;

	gSpritePatadon[4].x = 1183;
	gSpritePatadon[4].y = 1295;
	gSpritePatadon[4].w = 261;
	gSpritePatadon[4].h = 150;

	gSpritePatadon[5].x = 119;
	gSpritePatadon[5].y = 1490;
	gSpritePatadon[5].w = 261;
	gSpritePatadon[5].h = 150;

}
