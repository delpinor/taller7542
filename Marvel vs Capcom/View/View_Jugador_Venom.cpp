#include "View_Jugador_Venom.h"

#include <sstream>
View_Jugador_Venom::View_Jugador_Venom() {

}

void View_Jugador_Venom::initialize(Jugador * model,
		LTexture * texturaJugador) {
	this->texturaJugador = texturaJugador;
	this->gSpriteGolpear = new SDL_Rect[CANTSPRITECLIP];
	this->jugador = model;
	this->zIndex = model->get_zindex();
	getSpritesCaminar();
	getSpritesSaltar();
	getSpritesAgachar();
	getSpritesCambioPersonaje();
	getSpritesAnimacion();
	getSpritesPatadaFuerte();
	this->texturaJugador->setColor(this->jugador->getR(),  this->jugador->getG() , this->jugador->getB());

	this->sonido_salto=new EfectoSonido(1);
		this->sonido_ataque_pu=new EfectoSonido(1);
		this->sonido_defensa=new EfectoSonido(1);
		this->sonido_cambio=new EfectoSonido(1);
		this->sonido_ataque_pu->loadMedia("../Sonidos/venom_atk1.wav");
			this->sonido_salto->loadMedia("../Sonidos/salto_venom.wav");
	this->sonido_cambio->loadMedia("../Sonidos/cambio_venom.wav");
}
void View_Jugador_Venom::reproducir_sonido_salto(){

		this->sonido_salto->reproducir_sonido();


}
void  View_Jugador_Venom::reproducir_sonido_cambio(){

		this->sonido_cambio->reproducir_sonido();


}
	void  View_Jugador_Venom::reproducir_sonido_ataque_pu(){

		this->sonido_ataque_pu->reproducir_sonido();


}
void   View_Jugador_Venom::reproducir_sonido_defensa(){

		this->sonido_defensa->reproducir_sonido();


}

void View_Jugador_Venom::getSpritesAnimacion() {
	CANTSPRITEANIMACION = 13;
	MINFRAMEANIMACION = 0;
	MAXFRAMEANIMACION = 12;

	this->gSpriteAnimacion = new SDL_Rect[CANTSPRITEANIMACION];
	gSpriteAnimacion[0].x = 42;
	gSpriteAnimacion[0].y = 610;
	gSpriteAnimacion[0].w = 261;
	gSpriteAnimacion[0].h = 150;

	gSpriteAnimacion[1].x = 288;
	gSpriteAnimacion[1].y = 610;
	gSpriteAnimacion[1].w = 261;
	gSpriteAnimacion[1].h = 150;

	gSpriteAnimacion[2].x = 537;
	gSpriteAnimacion[2].y = 610;
	gSpriteAnimacion[2].w = 261;
	gSpriteAnimacion[2].h = 150;

	gSpriteAnimacion[3].x = 761;
	gSpriteAnimacion[3].y = 610;
	gSpriteAnimacion[3].w = 261;
	gSpriteAnimacion[3].h = 150;

	gSpriteAnimacion[4].x = 1013;
	gSpriteAnimacion[4].y = 610;
	gSpriteAnimacion[4].w = 261;
	gSpriteAnimacion[4].h = 150;

	gSpriteAnimacion[5].x = 1267;
	gSpriteAnimacion[5].y = 610;
	gSpriteAnimacion[5].w = 261;
	gSpriteAnimacion[5].h = 150;

	gSpriteAnimacion[6].x = 1524;
	gSpriteAnimacion[6].y = 610;
	gSpriteAnimacion[6].w = 261;
	gSpriteAnimacion[6].h = 150;

	gSpriteAnimacion[7].x = 35;
	gSpriteAnimacion[7].y = 843;
	gSpriteAnimacion[7].w = 261;
	gSpriteAnimacion[7].h = 150;

	gSpriteAnimacion[8].x = 293;
	gSpriteAnimacion[8].y = 843;
	gSpriteAnimacion[8].w = 261;
	gSpriteAnimacion[8].h = 150;

	gSpriteAnimacion[9].x = 534;
	gSpriteAnimacion[9].y = 843;
	gSpriteAnimacion[9].w = 261;
	gSpriteAnimacion[9].h = 150;

	gSpriteAnimacion[10].x = 776;
	gSpriteAnimacion[10].y = 843;
	gSpriteAnimacion[10].w = 261;
	gSpriteAnimacion[10].h = 150;

	gSpriteAnimacion[11].x = 1041;
	gSpriteAnimacion[11].y = 843;
	gSpriteAnimacion[11].w = 261;
	gSpriteAnimacion[11].h = 150;

	gSpriteAnimacion[12].x = 1273;
	gSpriteAnimacion[12].y = 843;
	gSpriteAnimacion[12].w = 261;
	gSpriteAnimacion[12].h = 150;

}

void View_Jugador_Venom::getSpritesCaminar() {
	CANTSPRITECLIPCAMINA = 10;
	MINFRAMECAMINA = 0;
	MAXFRAMECAMINA = 9;

	this->gSpriteCaminar = new SDL_Rect[CANTSPRITECLIPCAMINA];
	gSpriteCaminar[9].x = 18;
	gSpriteCaminar[9].y = 1256;
	gSpriteCaminar[9].w = 261;
	gSpriteCaminar[9].h = 150;

	gSpriteCaminar[8].x = 296;
	gSpriteCaminar[8].y = 1256;
	gSpriteCaminar[8].w = 261;
	gSpriteCaminar[8].h = 150;

	gSpriteCaminar[7].x = 552;
	gSpriteCaminar[7].y = 1256;
	gSpriteCaminar[7].w = 261;
	gSpriteCaminar[7].h = 150;

	gSpriteCaminar[6].x = 830;
	gSpriteCaminar[6].y = 1256;
	gSpriteCaminar[6].w = 261;
	gSpriteCaminar[6].h = 150;

	gSpriteCaminar[5].x = 1099;
	gSpriteCaminar[5].y = 1256;
	gSpriteCaminar[5].w = 261;
	gSpriteCaminar[5].h = 150;

	gSpriteCaminar[4].x = 1365;
	gSpriteCaminar[4].y = 1256;
	gSpriteCaminar[4].w = 261;
	gSpriteCaminar[4].h = 150;

	gSpriteCaminar[3].x = 1596;
	gSpriteCaminar[3].y = 1256;
	gSpriteCaminar[3].w = 261;
	gSpriteCaminar[3].h = 150;

	gSpriteCaminar[2].x = 1863;
	gSpriteCaminar[2].y = 1256;
	gSpriteCaminar[2].w = 261;
	gSpriteCaminar[2].h = 150;

	gSpriteCaminar[1].x = 0;
	gSpriteCaminar[1].y = 1465;
	gSpriteCaminar[1].w = 261;
	gSpriteCaminar[1].h = 150;

	gSpriteCaminar[0].x = 307;
	gSpriteCaminar[0].y = 1465;
	gSpriteCaminar[0].w = 261;
	gSpriteCaminar[0].h = 150;
}

void View_Jugador_Venom::getSpritesSaltar() {
	CANTSPRITECLIPSALTA = 4;
	MINFRAMESALTA = 0;
	MAXFRAMESALTA = 5;

	this->gSpriteSaltar = new SDL_Rect[CANTSPRITECLIPSALTA];
	gSpriteSaltar[0].x = 24;
	gSpriteSaltar[0].y = 1924;
	gSpriteSaltar[0].w = 261;
	gSpriteSaltar[0].h = 150;

//	gSpriteSaltar[1].x = 24;
//	gSpriteSaltar[1].y = 1924;
//	gSpriteSaltar[1].w = 261;
//	gSpriteSaltar[1].h = 150;

	gSpriteSaltar[1].x = 870;
	gSpriteSaltar[1].y = 1924;
	gSpriteSaltar[1].w = 261;
	gSpriteSaltar[1].h = 150;

	gSpriteSaltar[2].x = 559;
	gSpriteSaltar[2].y = 1928;
	gSpriteSaltar[2].w = 261;
	gSpriteSaltar[2].h = 150;

//	gSpriteSaltar[4].x = 870;
//	gSpriteSaltar[4].y = 1936;
//	gSpriteSaltar[4].w = 261;
//	gSpriteSaltar[4].h = 150;

	gSpriteSaltar[3].x = 1137;
	gSpriteSaltar[3].y = 1921;
	gSpriteSaltar[3].w = 261;
	gSpriteSaltar[3].h = 150;
}

void View_Jugador_Venom::getSpritesAgachar() {
	this->gSpriteAgachar = new SDL_Rect[1];
	gSpriteAgachar[0].x = 19;
	gSpriteAgachar[0].y = 2097;
	gSpriteAgachar[0].w = 261;
	gSpriteAgachar[0].h = 150;
}

void View_Jugador_Venom::getSpritesCambioPersonaje() {
	this->gSpriteCambiarPersonaje = new SDL_Rect[1];
	gSpriteCambiarPersonaje[0].x = 34;
	gSpriteCambiarPersonaje[0].y = 1924;
	gSpriteCambiarPersonaje[0].w = 261;
	gSpriteCambiarPersonaje[0].h = 150;
}

void View_Jugador_Venom::getSpritesPatadaFuerte() {
	CANTSPRITECLIPPATADON = 8;
	MINFRAMEPATADON = 0;
	MAXFRAMEPATADON = 7;
	this->gSpritePatadadon = new SDL_Rect[CANTSPRITECLIPPATADON];

	gSpritePatadadon[0].x = 24;
	gSpritePatadadon[0].y = 2541;
	gSpritePatadadon[0].w = 261;
	gSpritePatadadon[0].h = 150;

	gSpritePatadadon[1].x = 304;
	gSpritePatadadon[1].y = 2541;
	gSpritePatadadon[1].w = 261;
	gSpritePatadadon[1].h = 150;

	gSpritePatadadon[2].x = 601;
	gSpritePatadadon[2].y = 2541;
	gSpritePatadadon[2].w = 304;
	gSpritePatadadon[2].h = 150;

	gSpritePatadadon[3].x = 1020;
	gSpritePatadadon[3].y = 2541;
	gSpritePatadadon[3].w = 337;
	gSpritePatadadon[3].h = 150;

	gSpritePatadadon[4].x = 44;
	gSpritePatadadon[4].y = 2799;
	gSpritePatadadon[4].w = 321;
	gSpritePatadadon[4].h = 150;

	gSpritePatadadon[5].x = 425;
	gSpritePatadadon[5].y = 2799;
	gSpritePatadadon[5].w = 261;
	gSpritePatadadon[5].h = 150;

	gSpritePatadadon[6].x = 755;
	gSpritePatadadon[6].y = 2799;
	gSpritePatadadon[6].w = 261;
	gSpritePatadadon[6].h = 150;

	gSpritePatadadon[7].x = 1059;
	gSpritePatadadon[7].y = 2799;
	gSpritePatadadon[7].w = 261;
	gSpritePatadadon[7].h = 150;

}

View_Jugador_Venom::~View_Jugador_Venom() {
}

