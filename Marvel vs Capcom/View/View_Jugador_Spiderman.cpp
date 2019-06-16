#include "View_Jugador_Spiderman.h"

#include <sstream>
View_Jugador_Spiderman::View_Jugador_Spiderman() {

}

void View_Jugador_Spiderman::initialize(Jugador *model,
		LTexture * texturaJugador) {
	this->texturaJugador = texturaJugador;
	this->gSpriteGolpear = new SDL_Rect[CANTSPRITECLIP];
	this->jugador = model;
	getSpritesCaminar();
	getSpritesSaltar();
	getSpritesAgachar();
	getSpritesAnimacion();
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

	this->gSpriteAnimacion = new SDL_Rect[CANTSPRITEANIMACION];

	gSpriteAnimacion[0].x = 16;
	gSpriteAnimacion[0].y = 0;
	gSpriteAnimacion[0].w = 109;
	gSpriteAnimacion[0].h = 114;

	gSpriteAnimacion[1].x = 127;
	gSpriteAnimacion[1].y = 0;
	gSpriteAnimacion[1].w = 109;
	gSpriteAnimacion[1].h = 114;

	gSpriteAnimacion[2].x = 247;
	gSpriteAnimacion[2].y = 0;
	gSpriteAnimacion[2].w = 109;
	gSpriteAnimacion[2].h = 114;

	gSpriteAnimacion[3].x = 361;
	gSpriteAnimacion[3].y = 0;
	gSpriteAnimacion[3].w = 109;
	gSpriteAnimacion[3].h = 114;

	gSpriteAnimacion[4].x = 482;
	gSpriteAnimacion[4].y = 0;
	gSpriteAnimacion[4].w = 109;
	gSpriteAnimacion[4].h = 114;

	gSpriteAnimacion[5].x = 603;
	gSpriteAnimacion[5].y = 0;
	gSpriteAnimacion[5].w = 109;
	gSpriteAnimacion[5].h = 114;

	gSpriteAnimacion[6].x = 723;
	gSpriteAnimacion[6].y = 0;
	gSpriteAnimacion[6].w = 109;
	gSpriteAnimacion[6].h = 114;

	gSpriteAnimacion[7].x = 837;
	gSpriteAnimacion[7].y = 0;
	gSpriteAnimacion[7].w = 109;
	gSpriteAnimacion[7].h = 114;

	gSpriteAnimacion[8].x = 953;
	gSpriteAnimacion[8].y = 0;
	gSpriteAnimacion[8].w = 109;
	gSpriteAnimacion[8].h = 114;

	gSpriteAnimacion[9].x = 1064;
	gSpriteAnimacion[9].y = 0;
	gSpriteAnimacion[9].w = 109;
	gSpriteAnimacion[9].h = 114;

}

void View_Jugador_Spiderman::getSpritesCaminar() {
	CANTSPRITECLIPCAMINA = 12;
	MINFRAMECAMINA = 0;
	MAXFRAMECAMINA = 11;
	this->gSpriteCaminar = new SDL_Rect[CANTSPRITECLIPCAMINA];

	gSpriteCaminar[0].x = 18;
	gSpriteCaminar[0].y = 118;
	gSpriteCaminar[0].w = 89;
	gSpriteCaminar[0].h = 103;

	gSpriteCaminar[1].x = 119;
	gSpriteCaminar[1].y = 118;
	gSpriteCaminar[1].w = 89;
	gSpriteCaminar[1].h = 103;

	gSpriteCaminar[2].x = 212;
	gSpriteCaminar[2].y = 118;
	gSpriteCaminar[2].w = 89;
	gSpriteCaminar[2].h = 103;

	gSpriteCaminar[3].x = 302;
	gSpriteCaminar[3].y = 118;
	gSpriteCaminar[3].w = 89;
	gSpriteCaminar[3].h = 103;

	gSpriteCaminar[4].x = 392;
	gSpriteCaminar[4].y = 118;
	gSpriteCaminar[4].w = 89;
	gSpriteCaminar[4].h = 103;

	gSpriteCaminar[5].x = 475;
	gSpriteCaminar[5].y = 118;
	gSpriteCaminar[5].w = 89;
	gSpriteCaminar[5].h = 103;

	gSpriteCaminar[6].x = 565;
	gSpriteCaminar[6].y = 118;
	gSpriteCaminar[6].w = 89;
	gSpriteCaminar[6].h = 103;

	gSpriteCaminar[7].x = 656;
	gSpriteCaminar[7].y = 118;
	gSpriteCaminar[7].w = 89;
	gSpriteCaminar[7].h = 103;

	gSpriteCaminar[8].x = 745;
	gSpriteCaminar[8].y = 118;
	gSpriteCaminar[8].w = 89;
	gSpriteCaminar[8].h = 103;

	gSpriteCaminar[9].x = 830;
	gSpriteCaminar[9].y = 118;
	gSpriteCaminar[9].w = 89;
	gSpriteCaminar[9].h = 103;

	gSpriteCaminar[10].x = 914;
	gSpriteCaminar[10].y = 118;
	gSpriteCaminar[10].w = 88;
	gSpriteCaminar[10].h = 103;

	gSpriteCaminar[11].x = 999;
	gSpriteCaminar[11].y = 118;
	gSpriteCaminar[11].w = 89;
	gSpriteCaminar[11].h = 103;

}

void View_Jugador_Spiderman::getSpritesSaltar() {
	CANTSPRITECLIPSALTA = 7;
	MINFRAMESALTA = 0;
	MAXFRAMESALTA = 6;
	this->gSpriteSaltar = new SDL_Rect[CANTSPRITECLIPSALTA];

	gSpriteSaltar[0].x = 184;
	gSpriteSaltar[0].y = 220;
	gSpriteSaltar[0].w = 107;
	gSpriteSaltar[0].h = 110;

	gSpriteSaltar[1].x = 287;
	gSpriteSaltar[1].y = 220;
	gSpriteSaltar[1].w = 107;
	gSpriteSaltar[1].h = 110;

	gSpriteSaltar[2].x = 395;
	gSpriteSaltar[2].y = 220;
	gSpriteSaltar[2].w = 107;
	gSpriteSaltar[2].h = 110;

	gSpriteSaltar[3].x = 395;
	gSpriteSaltar[3].y = 220;
	gSpriteSaltar[3].w = 107;
	gSpriteSaltar[3].h = 110;

	gSpriteSaltar[4].x = 603;
	gSpriteSaltar[4].y = 220;
	gSpriteSaltar[4].w = 107;
	gSpriteSaltar[4].h = 110;

	gSpriteSaltar[5].x = 706;
	gSpriteSaltar[5].y = 220;
	gSpriteSaltar[5].w = 107;
	gSpriteSaltar[5].h = 110;

	gSpriteSaltar[6].x = 812;
	gSpriteSaltar[6].y = 220;
	gSpriteSaltar[6].w = 107;
	gSpriteSaltar[6].h = 110;


}
void View_Jugador_Spiderman::getSpritesAgachar() {

	this->gSpriteAgachar = new SDL_Rect[1];
	gSpriteAgachar[0].x = 12;
	gSpriteAgachar[0].y = 1282;
	gSpriteAgachar[0].w = 86;
	gSpriteAgachar[0].h = 102;
}

void View_Jugador_Spiderman::getSpritesCambioPersonaje() {

	this->gSpriteCambiarPersonaje = new SDL_Rect[1];
	gSpriteCambiarPersonaje[0].x = 110;
	gSpriteCambiarPersonaje[0].y = 226;
	gSpriteCambiarPersonaje[0].w = 82;
	gSpriteCambiarPersonaje[0].h = 141;
}

