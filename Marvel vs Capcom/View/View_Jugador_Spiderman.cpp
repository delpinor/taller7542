#include "View_Jugador_Spiderman.h"

#include <sstream>
View_Jugador_Spiderman::View_Jugador_Spiderman() {

}

void View_Jugador_Spiderman::initialize(Jugador *model,
		LTexture * texturaJugador) {
	this->texturaJugador = texturaJugador;

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

		this->sonido_ataque_pu->loadMedia("../Sonidos/spider_Atk2.wav");
			this->sonido_salto->loadMedia("../Sonidos/salto_spider.wav");
	this->sonido_cambio->loadMedia("../Sonidos/cambio_spider.wav");
}
void  View_Jugador_Spiderman::reproducir_sonido_salto(){

		this->sonido_salto->reproducir_sonido();


}
void  View_Jugador_Spiderman::reproducir_sonido_cambio(){

		this->sonido_cambio->reproducir_sonido();


}
	void  View_Jugador_Spiderman::reproducir_sonido_ataque_pu(){

		this->sonido_ataque_pu->reproducir_sonido();


}
void   View_Jugador_Spiderman::reproducir_sonido_defensa(){

		this->sonido_defensa->reproducir_sonido();


}


void View_Jugador_Spiderman::getSpritesAnimacion() {
	CANTSPRITEANIMACION = 10;
	MINFRAMEANIMACION = 0;
	MAXFRAMEANIMACION = 9;
	FACTORANIMACION = 9;
	this->gSpriteAnimacion = new SDL_Rect[CANTSPRITEANIMACION];

	gSpriteAnimacion[0].x = 31;
	gSpriteAnimacion[0].y = 3;
	gSpriteAnimacion[0].w = 261;
	gSpriteAnimacion[0].h = 150;

	gSpriteAnimacion[1].x = 246;
	gSpriteAnimacion[1].y = 3;
	gSpriteAnimacion[1].w = 261;
	gSpriteAnimacion[1].h = 150;

	gSpriteAnimacion[2].x = 453;
	gSpriteAnimacion[2].y = 3;
	gSpriteAnimacion[2].w = 261;
	gSpriteAnimacion[2].h = 150;

	gSpriteAnimacion[3].x = 658;
	gSpriteAnimacion[3].y = 3;
	gSpriteAnimacion[3].w = 261;
	gSpriteAnimacion[3].h = 150;

	gSpriteAnimacion[4].x = 877;
	gSpriteAnimacion[4].y = 3;
	gSpriteAnimacion[4].w = 261;
	gSpriteAnimacion[4].h = 150;

	gSpriteAnimacion[5].x = 1078;
	gSpriteAnimacion[5].y = 3;
	gSpriteAnimacion[5].w = 261;
	gSpriteAnimacion[5].h = 150;

	gSpriteAnimacion[6].x = 1286;
	gSpriteAnimacion[6].y = 3;
	gSpriteAnimacion[6].w = 261;
	gSpriteAnimacion[6].h = 150;

	gSpriteAnimacion[7].x = 1500;
	gSpriteAnimacion[7].y = 3;
	gSpriteAnimacion[7].w = 261;
	gSpriteAnimacion[7].h = 150;

	gSpriteAnimacion[8].x = 1707;
	gSpriteAnimacion[8].y = 3;
	gSpriteAnimacion[8].w = 261;
	gSpriteAnimacion[8].h = 150;

	gSpriteAnimacion[9].x = 1924;
	gSpriteAnimacion[9].y = 3;
	gSpriteAnimacion[9].w = 261;
	gSpriteAnimacion[9].h = 150;

}

void View_Jugador_Spiderman::getSpritesCaminar() {
	CANTSPRITECLIPCAMINA = 12;
	MINFRAMECAMINA = 0;
	MAXFRAMECAMINA = 11;
	FACTORCAMINA = 6;
	this->gSpriteCaminar = new SDL_Rect[CANTSPRITECLIPCAMINA];

	gSpriteCaminar[0].x = 24;
	gSpriteCaminar[0].y = 156;
	gSpriteCaminar[0].w = 261;
	gSpriteCaminar[0].h = 150;

	gSpriteCaminar[1].x = 234;
	gSpriteCaminar[1].y = 156;
	gSpriteCaminar[1].w = 261;
	gSpriteCaminar[1].h = 150;

	gSpriteCaminar[2].x = 467;
	gSpriteCaminar[2].y = 156;
	gSpriteCaminar[2].w = 261;
	gSpriteCaminar[2].h = 150;

	gSpriteCaminar[3].x = 666;
	gSpriteCaminar[3].y = 156;
	gSpriteCaminar[3].w = 261;
	gSpriteCaminar[3].h = 150;

	gSpriteCaminar[4].x = 884;
	gSpriteCaminar[4].y = 156;
	gSpriteCaminar[4].w = 261;
	gSpriteCaminar[4].h = 150;

	gSpriteCaminar[5].x = 1074;
	gSpriteCaminar[5].y = 156;
	gSpriteCaminar[5].w = 261;
	gSpriteCaminar[5].h = 150;

	gSpriteCaminar[6].x = 1273;
	gSpriteCaminar[6].y = 156;
	gSpriteCaminar[6].w = 261;
	gSpriteCaminar[6].h = 150;

	gSpriteCaminar[7].x = 1501;
	gSpriteCaminar[7].y = 156;
	gSpriteCaminar[7].w = 261;
	gSpriteCaminar[7].h = 150;

	gSpriteCaminar[8].x = 1700;
	gSpriteCaminar[8].y = 156;
	gSpriteCaminar[8].w = 261;
	gSpriteCaminar[8].h = 150;

	gSpriteCaminar[9].x = 1911;
	gSpriteCaminar[9].y = 156;
	gSpriteCaminar[9].w = 261;
	gSpriteCaminar[9].h = 150;

	gSpriteCaminar[10].x = 2084;
	gSpriteCaminar[10].y = 156;
	gSpriteCaminar[10].w = 261;
	gSpriteCaminar[10].h = 150;

	gSpriteCaminar[11].x = 2154;
	gSpriteCaminar[11].y = 3;
	gSpriteCaminar[11].w = 261;
	gSpriteCaminar[11].h = 150;

}

void View_Jugador_Spiderman::getSpritesSaltar() {
	CANTSPRITECLIPSALTA = 7;
	MINFRAMESALTA = 0;
	MAXFRAMESALTA = 6;
	FACTORSALTA = 2;
	this->gSpriteSaltar = new SDL_Rect[CANTSPRITECLIPSALTA];

	gSpriteSaltar[0].x = 448;
	gSpriteSaltar[0].y = 328;
	gSpriteSaltar[0].w = 261;
	gSpriteSaltar[0].h = 150;

	gSpriteSaltar[1].x = 658;
	gSpriteSaltar[1].y = 341;
	gSpriteSaltar[1].w = 261;
	gSpriteSaltar[1].h = 150;

	gSpriteSaltar[2].x = 880;
	gSpriteSaltar[2].y = 352;
	gSpriteSaltar[2].w = 261;
	gSpriteSaltar[2].h = 150;

	gSpriteSaltar[3].x = 880;
	gSpriteSaltar[3].y = 352;
	gSpriteSaltar[3].w = 261;
	gSpriteSaltar[3].h = 150;

	gSpriteSaltar[4].x = 1499;
	gSpriteSaltar[4].y = 327;
	gSpriteSaltar[4].w = 261;
	gSpriteSaltar[4].h = 150;

	gSpriteSaltar[5].x = 1698;
	gSpriteSaltar[5].y = 324;
	gSpriteSaltar[5].w = 261;
	gSpriteSaltar[5].h = 150;

	gSpriteSaltar[6].x = 1898;
	gSpriteSaltar[6].y = 320;
	gSpriteSaltar[6].w = 261;
	gSpriteSaltar[6].h = 150;


}
void View_Jugador_Spiderman::getSpritesAgachar() {

	this->gSpriteAgachar = new SDL_Rect[1];
	gSpriteAgachar[0].x = 55;
	gSpriteAgachar[0].y = 1619;
	gSpriteAgachar[0].w = 261;
	gSpriteAgachar[0].h = 150;
}

void View_Jugador_Spiderman::getSpritesCambioPersonaje() {

	this->gSpriteCambiarPersonaje = new SDL_Rect[1];
	gSpriteCambiarPersonaje[0].x = 228;
	gSpriteCambiarPersonaje[0].y = 331;
	gSpriteCambiarPersonaje[0].w = 261;
	gSpriteCambiarPersonaje[0].h = 150;
}

void View_Jugador_Spiderman::getSpritesPatadaFuerte() {
	CANTSPRITECLIPPATADON = 8;
	MINFRAMEPATADON = 0;
	MAXFRAMEPATADON = 7;
	FACTORPATADON = 7;
	this->gSpritePatadon = new SDL_Rect[CANTSPRITECLIPPATADON];

	gSpritePatadon[0].x = 43;
	gSpritePatadon[0].y = 803;
	gSpritePatadon[0].w = 261;
	gSpritePatadon[0].h = 150;

	gSpritePatadon[1].x = 291;
	gSpritePatadon[1].y = 803;
	gSpritePatadon[1].w = 261;
	gSpritePatadon[1].h = 150;

	gSpritePatadon[2].x = 563;
	gSpritePatadon[2].y = 803;
	gSpritePatadon[2].w = 261;
	gSpritePatadon[2].h = 150;

	gSpritePatadon[3].x = 848;
	gSpritePatadon[3].y = 803;
	gSpritePatadon[3].w = 261;
	gSpritePatadon[3].h = 150;

	gSpritePatadon[4].x = 1113;
	gSpritePatadon[4].y = 803;
	gSpritePatadon[4].w = 261;
	gSpritePatadon[4].h = 150;

	gSpritePatadon[5].x = 1380;
	gSpritePatadon[5].y = 803;
	gSpritePatadon[5].w = 261;
	gSpritePatadon[5].h = 150;

	gSpritePatadon[6].x = 1667;
	gSpritePatadon[6].y = 803;
	gSpritePatadon[6].w = 261;
	gSpritePatadon[6].h = 150;

	gSpritePatadon[7].x = 1966;
	gSpritePatadon[7].y = 803;
	gSpritePatadon[7].w = 261;
	gSpritePatadon[7].h = 150;

}

