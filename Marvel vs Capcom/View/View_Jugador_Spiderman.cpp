#include "View_Jugador_Spiderman.h"

#include <sstream>
View_Jugador_Spiderman::View_Jugador_Spiderman() {

}

void View_Jugador_Spiderman::initialize(Jugador *model,
		LTexture * texturaJugador) {
	this->texturaJugador = texturaJugador;
	CANTSPRITECLIP = 6;

		this->gSpriteGolpear = new SDL_Rect[CANTSPRITECLIP];

	this->jugador = model;
	getSpritesCaminar();
	getSpritesSaltar();
	getSpritesAgachar();
	getSpritesAnimacion();
	getSpritesCambioPersonaje();

	//Patadas
	getSpritesPatadaDebil();
	getSpritesPatadaDebilSaltando();
	getSpritesPatadaDebilAgachado();

	getSpritesPatadaFuerte();
	getSpritesPatadaFuerteSaltando();
	getSpritesPatadaFuerteAgachado();
	//Piñas
	getSpritesPiniaDebil();
	getSpritesPiniaDebilAgachado();
	getSpritesPiniaDebilSaltando();

	getSpritesPiniaFuerte();
	getSpritesPiniaFuerteAgachado();
	getSpritesPiniaFuerteSaltando();

	//Defensa
	getSpritesDefensa();
	getSpritesDefensaAgachado();
	getSpritesDefensaSaltando();
	getSpritesRecibirGolpe();

	//---->Habilidades
	getSpritesLanzarJugador();
	getSpritesJugadorLanzado();
	getSpritesLanzarPoder();
	getSpritesPoder();

	this->zIndex = model->get_zindex();
	this->texturaJugador->setColor(this->jugador->getR(),  this->jugador->getG() , this->jugador->getB());

	this->sonido_salto=new EfectoSonido(1);
		this->sonido_ataque_pu=new EfectoSonido(1);
		this->sonido_defensa=new EfectoSonido(1);
		this->sonido_cambio=new EfectoSonido(1);
		this->sonido_danio=new EfectoSonido(1);
			this->sonido_ataque_patada=new EfectoSonido(1);

			this->sonido_ataque_patada->loadMedia("../Sonidos/spider_patada.wav");
			this->sonido_defensa->loadMedia("../Sonidos/spider_defensa.wav");
			this->sonido_danio->loadMedia("../Sonidos/spider_danio.wav");


		this->sonido_ataque_pu->loadMedia("../Sonidos/spider_punio.wav");
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
void View_Jugador_Spiderman::reproducir_sonido_ataque_patada(){
	this->sonido_ataque_patada->reproducir_sonido();

}

void	View_Jugador_Spiderman::reproducir_sonido_recibir_danio(){
	this->sonido_danio->reproducir_sonido();


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

	gSpriteAnimacion[4].x = 875;
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

	gSpriteCaminar[1].x = 230;
	gSpriteCaminar[1].y = 156;
	gSpriteCaminar[1].w = 261;
	gSpriteCaminar[1].h = 150;

	gSpriteCaminar[2].x = 460;
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
	CANTSPRITECLIPSALTA = 8;
	MINFRAMESALTA = 0;
	MAXFRAMESALTA = 7;
	FACTORSALTA = 10;
	this->gSpriteSaltar = new SDL_Rect[CANTSPRITECLIPSALTA];

	gSpriteSaltar[0].x = 1;
	gSpriteSaltar[0].y = 297;
	gSpriteSaltar[0].w = 261;
	gSpriteSaltar[0].h = 150;

	gSpriteSaltar[1].x = 225;
	gSpriteSaltar[1].y = 327;
	gSpriteSaltar[1].w = 261;
	gSpriteSaltar[1].h = 150;

	gSpriteSaltar[2].x = 453;
	gSpriteSaltar[2].y = 302;
	gSpriteSaltar[2].w = 261;
	gSpriteSaltar[2].h = 150;

	gSpriteSaltar[3].x = 663;
	gSpriteSaltar[3].y = 303;
	gSpriteSaltar[3].w = 261;
	gSpriteSaltar[3].h = 150;

	gSpriteSaltar[4].x = 1291;
	gSpriteSaltar[4].y = 307;
	gSpriteSaltar[4].w = 261;
	gSpriteSaltar[4].h = 150;

	gSpriteSaltar[5].x = 1493;
	gSpriteSaltar[5].y = 321;
	gSpriteSaltar[5].w = 261;
	gSpriteSaltar[5].h = 150;

	gSpriteSaltar[6].x = 1705;
	gSpriteSaltar[6].y = 305;
	gSpriteSaltar[6].w = 261;
	gSpriteSaltar[6].h = 150;

	gSpriteSaltar[7].x = 453;
	gSpriteSaltar[7].y = 302;
	gSpriteSaltar[7].w = 261;
	gSpriteSaltar[7].h = 150;

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
	FACTORPATADON = 8;
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
void View_Jugador_Spiderman::getSpritesPatadaDebil() {
	CANTSPRITECLIPPATADA = 5;
	MINFRAMEPATADA = 0;
	MAXFRAMEPATADA = 4;
	FACTORPATADA = 10;
	this->gSpritePatada = new SDL_Rect[CANTSPRITECLIPPATADA];

	gSpritePatada[0].x = 6;
	gSpritePatada[0].y = 653;
	gSpritePatada[0].w = 261;
	gSpritePatada[0].h = 150;

	gSpritePatada[1].x = 253;
	gSpritePatada[1].y = 653;
	gSpritePatada[1].w = 261;
	gSpritePatada[1].h = 150;

	gSpritePatada[2].x = 540;
	gSpritePatada[2].y = 653;
	gSpritePatada[2].w = 261;
	gSpritePatada[2].h = 150;

	gSpritePatada[3].x = 808;
	gSpritePatada[3].y = 653;
	gSpritePatada[3].w = 261;
	gSpritePatada[3].h = 150;

	gSpritePatada[4].x = 1023;
	gSpritePatada[4].y = 653;
	gSpritePatada[4].w = 261;
	gSpritePatada[4].h = 150;

}
void View_Jugador_Spiderman::getSpritesPatadaDebilSaltando() {
	CANTSPRITECLIPPATADASALTANDO = 3;
	MINFRAMEPATADASALTANDO = 0;
	MAXFRAMEPATADASALTANDO = 2;
	FACTORPATADASALTANDO = 10;
	this->gSpritePatadaSaltando = new SDL_Rect[CANTSPRITECLIPPATADASALTANDO];

	gSpritePatadaSaltando[0].x = 799;
	gSpritePatadaSaltando[0].y = 643;
	gSpritePatadaSaltando[0].w = 261;
	gSpritePatadaSaltando[0].h = 150;

	gSpritePatadaSaltando[1].x = 539;
	gSpritePatadaSaltando[1].y = 643;
	gSpritePatadaSaltando[1].w = 261;
	gSpritePatadaSaltando[1].h = 150;

	gSpritePatadaSaltando[2].x = 799;
	gSpritePatadaSaltando[2].y = 643;
	gSpritePatadaSaltando[2].w = 261;
	gSpritePatadaSaltando[2].h = 150;

}
void View_Jugador_Spiderman::getSpritesPatadaFuerteSaltando() {
	CANTSPRITECLIPPATADONSALTANDO = 4;
	MINFRAMEPATADONSALTANDO = 0;
	MAXFRAMEPATADONSALTANDO = 3;
	FACTORPATADONSALTANDO = 10;
	this->gSpritePatadonSaltando = new SDL_Rect[CANTSPRITECLIPPATADONSALTANDO];

	gSpritePatadonSaltando[0].x = 72;
	gSpritePatadonSaltando[0].y = 1305;
	gSpritePatadonSaltando[0].w = 261;
	gSpritePatadonSaltando[0].h = 150;

	gSpritePatadonSaltando[1].x = 333;
	gSpritePatadonSaltando[1].y = 1305;
	gSpritePatadonSaltando[1].w = 261;
	gSpritePatadonSaltando[1].h = 150;

	gSpritePatadonSaltando[2].x = 647;
	gSpritePatadonSaltando[2].y = 1305;
	gSpritePatadonSaltando[2].w = 261;
	gSpritePatadonSaltando[2].h = 150;

	gSpritePatadonSaltando[3].x = 72;
	gSpritePatadonSaltando[3].y = 1305;
	gSpritePatadonSaltando[3].w = 261;
	gSpritePatadonSaltando[3].h = 150;

}
void View_Jugador_Spiderman::getSpritesPatadaFuerteAgachado() {
	CANTSPRITECLIPPATADONAGACHADO = 5;
	MINFRAMEPATADONAGACHADO = 0;
	MAXFRAMEPATADONAGACHADO = 4;
	FACTORPATADONAGACHADO = 10;
	this->gSpritePatadonAgachado= new SDL_Rect[CANTSPRITECLIPPATADONAGACHADO];

	gSpritePatadonAgachado[0].x = 7;
	gSpritePatadonAgachado[0].y = 1763;
	gSpritePatadonAgachado[0].w = 261;
	gSpritePatadonAgachado[0].h = 150;

	gSpritePatadonAgachado[1].x = 268;
	gSpritePatadonAgachado[1].y = 1763;
	gSpritePatadonAgachado[1].w = 261;
	gSpritePatadonAgachado[1].h = 150;

	gSpritePatadonAgachado[2].x = 529;
	gSpritePatadonAgachado[2].y = 1763;
	gSpritePatadonAgachado[2].w = 261;
	gSpritePatadonAgachado[2].h = 150;

	gSpritePatadonAgachado[3].x = 790;
	gSpritePatadonAgachado[3].y = 1763;
	gSpritePatadonAgachado[3].w = 261;
	gSpritePatadonAgachado[3].h = 150;

	gSpritePatadonAgachado[4].x = 1052;
	gSpritePatadonAgachado[4].y = 1763;
	gSpritePatadonAgachado[4].w = 261;
	gSpritePatadonAgachado[4].h = 150;


}
void View_Jugador_Spiderman::getSpritesPatadaDebilAgachado(){
	CANTSPRITECLIPPATADAAGACHADO = 5;
	MINFRAMEPATADAAGACHADO = 0;
	MAXFRAMEPATADAAGACHADO = 4;
	FACTORPATADAAGACHADO = 4;
	this->gSpritePatadaAgachado= new SDL_Rect[CANTSPRITECLIPPATADAAGACHADO];

	gSpritePatadaAgachado[0].x = 37;
	gSpritePatadaAgachado[0].y = 957;
	gSpritePatadaAgachado[0].w = 261;
	gSpritePatadaAgachado[0].h = 150;

	gSpritePatadaAgachado[1].x = 289;
	gSpritePatadaAgachado[1].y = 957;
	gSpritePatadaAgachado[1].w = 261;
	gSpritePatadaAgachado[1].h = 150;

	gSpritePatadaAgachado[2].x = 568;
	gSpritePatadaAgachado[2].y = 957;
	gSpritePatadaAgachado[2].w = 261;
	gSpritePatadaAgachado[2].h = 150;

	gSpritePatadaAgachado[3].x = 849;
	gSpritePatadaAgachado[3].y = 957;
	gSpritePatadaAgachado[3].w = 261;
	gSpritePatadaAgachado[3].h = 150;

	gSpritePatadaAgachado[4].x = 1104;
	gSpritePatadaAgachado[4].y = 957;
	gSpritePatadaAgachado[4].w = 261;
	gSpritePatadaAgachado[4].h = 150;
}
void View_Jugador_Spiderman::getSpritesPiniaDebil(){
	CANTSPRITECLIPPINIA = 5;
	MINFRAMEPINIA = 0;
	MAXFRAMEPINIA = 4;
	FACTORPINIA = 10;
	this->gSpritePinia = new SDL_Rect[CANTSPRITECLIPPINIA];

	gSpritePinia[0].x = 23;
	gSpritePinia[0].y = 479;
	gSpritePinia[0].w = 261;
	gSpritePinia[0].h = 150;

	gSpritePinia[1].x = 235;
	gSpritePinia[1].y = 479;
	gSpritePinia[1].w = 261;
	gSpritePinia[1].h = 150;

	gSpritePinia[2].x = 452;
	gSpritePinia[2].y = 479;
	gSpritePinia[2].w = 261;
	gSpritePinia[2].h = 150;

	gSpritePinia[3].x = 676;
	gSpritePinia[3].y = 479;
	gSpritePinia[3].w = 261;
	gSpritePinia[3].h = 150;

	gSpritePinia[4].x = 895;
	gSpritePinia[4].y = 479;
	gSpritePinia[4].w = 261;
	gSpritePinia[4].h = 150;


}
void View_Jugador_Spiderman::getSpritesPiniaFuerte(){
	CANTSPRITECLIPPINION = 6;
	MINFRAMEPINION = 0;
	MAXFRAMEPINION = 5;
	FACTORPINION = 8;
	this->gSpritePinion = new SDL_Rect[CANTSPRITECLIPPINION];

	gSpritePinion[0].x = 895;
	gSpritePinion[0].y = 479;
	gSpritePinion[0].w = 261;
	gSpritePinion[0].h = 150;

	gSpritePinion[1].x = 1094;
	gSpritePinion[1].y = 479;
	gSpritePinion[1].w = 261;
	gSpritePinion[1].h = 150;

	gSpritePinion[2].x = 1315;
	gSpritePinion[2].y = 479;
	gSpritePinion[2].w = 261;
	gSpritePinion[2].h = 150;

	gSpritePinion[3].x = 1506;
	gSpritePinion[3].y = 660;
	gSpritePinion[3].w = 261;
	gSpritePinion[3].h = 150;

	gSpritePinion[4].x = 1700;
	gSpritePinion[4].y = 479;
	gSpritePinion[4].w = 261;
	gSpritePinion[4].h = 150;

	gSpritePinion[5].x = 1988;
	gSpritePinion[5].y = 479;
	gSpritePinion[5].w = 261;
	gSpritePinion[5].h = 150;


}
void View_Jugador_Spiderman::getSpritesPiniaFuerteAgachado(){
	CANTSPRITECLIPPINIONAGACHADO = 6;
	MINFRAMEPINIONAGACHADO = 0;
	MAXFRAMEPINIONAGACHADO = 5;
	FACTORPINIONAGACHADO = 8;
	this->gSpritePinionAgachado = new SDL_Rect[CANTSPRITECLIPPINIONAGACHADO];

	gSpritePinionAgachado[0].x = 57;
	gSpritePinionAgachado[0].y = 2069;
	gSpritePinionAgachado[0].w = 261;
	gSpritePinionAgachado[0].h = 150;

	gSpritePinionAgachado[1].x = 318;
	gSpritePinionAgachado[1].y = 2069;
	gSpritePinionAgachado[1].w = 261;
	gSpritePinionAgachado[1].h = 150;

	gSpritePinionAgachado[2].x = 579;
	gSpritePinionAgachado[2].y = 2069;
	gSpritePinionAgachado[2].w = 261;
	gSpritePinionAgachado[2].h = 150;

	gSpritePinionAgachado[3].x = 840;
	gSpritePinionAgachado[3].y = 2069;
	gSpritePinionAgachado[3].w = 261;
	gSpritePinionAgachado[3].h = 150;

	gSpritePinionAgachado[4].x = 1101;
	gSpritePinionAgachado[4].y = 2069;
	gSpritePinionAgachado[4].w = 261;
	gSpritePinionAgachado[4].h = 150;

	gSpritePinionAgachado[5].x = 1362;
	gSpritePinionAgachado[5].y = 2069;
	gSpritePinionAgachado[5].w = 261;
	gSpritePinionAgachado[5].h = 150;


}
void View_Jugador_Spiderman::getSpritesPiniaDebilAgachado(){
	CANTSPRITECLIPPINIAAGACHADO = 5;
	MINFRAMEPINIAAGACHADO = 0;
	MAXFRAMEPINIAAGACHADO = 4;
	FACTORPINIAAGACHADO = 10;
	this->gSpritePiniaAgachado = new SDL_Rect[CANTSPRITECLIPPINIAAGACHADO];

	gSpritePiniaAgachado[0].x = 58;
	gSpritePiniaAgachado[0].y = 1919;
	gSpritePiniaAgachado[0].w = 261;
	gSpritePiniaAgachado[0].h = 150;

	gSpritePiniaAgachado[1].x = 319;
	gSpritePiniaAgachado[1].y = 1919;
	gSpritePiniaAgachado[1].w = 261;
	gSpritePiniaAgachado[1].h = 150;

	gSpritePiniaAgachado[2].x = 580;
	gSpritePiniaAgachado[2].y = 1919;
	gSpritePiniaAgachado[2].w = 261;
	gSpritePiniaAgachado[2].h = 150;

	gSpritePiniaAgachado[3].x = 841;
	gSpritePiniaAgachado[3].y = 1919;
	gSpritePiniaAgachado[3].w = 261;
	gSpritePiniaAgachado[3].h = 150;

	gSpritePiniaAgachado[4].x = 1102;
	gSpritePiniaAgachado[4].y = 1919;
	gSpritePiniaAgachado[4].w = 261;
	gSpritePiniaAgachado[4].h = 150;


}
void View_Jugador_Spiderman::getSpritesPiniaFuerteSaltando(){
	CANTSPRITECLIPPINIONSALTANDO = 6;
	MINFRAMEPINIONSALTANDO = 0;
	MAXFRAMEPINIONSALTANDO = 5;
	FACTORPINIONSALTANDO = 8;
	this->gSpritePinionSaltando = new SDL_Rect[CANTSPRITECLIPPINIONSALTANDO];

	gSpritePinionSaltando[0].x = 59;
	gSpritePinionSaltando[0].y = 2619;
	gSpritePinionSaltando[0].w = 261;
	gSpritePinionSaltando[0].h = 150;

	gSpritePinionSaltando[1].x = 320;
	gSpritePinionSaltando[1].y = 2619;
	gSpritePinionSaltando[1].w = 261;
	gSpritePinionSaltando[1].h = 150;

	gSpritePinionSaltando[2].x = 581;
	gSpritePinionSaltando[2].y = 2619;
	gSpritePinionSaltando[2].w = 261;
	gSpritePinionSaltando[2].h = 150;

	gSpritePinionSaltando[3].x = 842;
	gSpritePinionSaltando[3].y = 2619;
	gSpritePinionSaltando[3].w = 261;
	gSpritePinionSaltando[3].h = 150;

	gSpritePinionSaltando[4].x = 1103;
	gSpritePinionSaltando[4].y = 2619;
	gSpritePinionSaltando[4].w = 261;
	gSpritePinionSaltando[4].h = 150;

	gSpritePinionSaltando[5].x = 1364;
	gSpritePinionSaltando[5].y = 2619;
	gSpritePinionSaltando[5].w = 261;
	gSpritePinionSaltando[5].h = 150;

}
void View_Jugador_Spiderman::getSpritesPiniaDebilSaltando(){
	CANTSPRITECLIPPINIASALTANDO = 3;
	MINFRAMEPINIASALTANDO = 0;
	MAXFRAMEPINIASALTANDO = 2;
	FACTORPINIASALTANDO = 4;
	this->gSpritePiniaSaltando = new SDL_Rect[CANTSPRITECLIPPINIASALTANDO];

	gSpritePiniaSaltando[0].x = 23;
	gSpritePiniaSaltando[0].y = 479;
	gSpritePiniaSaltando[0].w = 261;
	gSpritePiniaSaltando[0].h = 150;

	gSpritePiniaSaltando[1].x = 235;
	gSpritePiniaSaltando[1].y = 479;
	gSpritePiniaSaltando[1].w = 261;
	gSpritePiniaSaltando[1].h = 150;

	gSpritePiniaSaltando[2].x = 452;
	gSpritePiniaSaltando[2].y = 479;
	gSpritePiniaSaltando[2].w = 261;
	gSpritePiniaSaltando[2].h = 150;

//	gSpritePiniaSaltando[0].x = 59;
//	gSpritePiniaSaltando[0].y = 2291;
//	gSpritePiniaSaltando[0].w = 261;
//	gSpritePiniaSaltando[0].h = 150;
//
//	gSpritePiniaSaltando[1].x = 320;
//	gSpritePiniaSaltando[1].y = 2291;
//	gSpritePiniaSaltando[1].w = 261;
//	gSpritePiniaSaltando[1].h = 150;
//
//	gSpritePiniaSaltando[2].x = 581;
//	gSpritePiniaSaltando[2].y = 2291;
//	gSpritePiniaSaltando[2].w = 261;
//	gSpritePiniaSaltando[2].h = 150;
//
//	gSpritePiniaSaltando[3].x = 842;
//	gSpritePiniaSaltando[3].y = 2291;
//	gSpritePiniaSaltando[3].w = 261;
//	gSpritePiniaSaltando[3].h = 150;

}
void View_Jugador_Spiderman::getSpritesDefensa(){
	CANTSPRITECLIPDEFENSA = 1;
	MINFRAMEDEFENSA = 0;
	MAXFRAMEDEFENSA = 0;
	FACTORDEFENSA = 4;
	this->gSpriteDefensa = new SDL_Rect[CANTSPRITECLIPDEFENSA];

	gSpriteDefensa[0].x = 306;
	gSpriteDefensa[0].y = 2832;
	gSpriteDefensa[0].w = 261;
	gSpriteDefensa[0].h = 150;

//	gSpriteDefensa[1].x = 306;
//	gSpriteDefensa[1].y = 2832;
//	gSpriteDefensa[1].w = 261;
//	gSpriteDefensa[1].h = 150;
//
//	gSpriteDefensa[2].x = 567;
//	gSpriteDefensa[2].y = 2832;
//	gSpriteDefensa[2].w = 261;
//	gSpriteDefensa[2].h = 150;
//
//	gSpriteDefensa[3].x = 828;
//	gSpriteDefensa[3].y = 2832;
//	gSpriteDefensa[3].w = 261;
//	gSpriteDefensa[3].h = 150;


}
void View_Jugador_Spiderman::getSpritesDefensaAgachado(){
	CANTSPRITECLIPDEFENSAAGACHADO = 1;
	MINFRAMEDEFENSAAGACHADO = 0;
	MAXFRAMEDEFENSAAGACHADO = 0;
	FACTORDEFENSAAGACHADO = 5;
	this->gSpriteDefensaAgachado = new SDL_Rect[CANTSPRITECLIPDEFENSAAGACHADO];

	gSpriteDefensaAgachado[0].x = 306;
	gSpriteDefensaAgachado[0].y = 2832;
	gSpriteDefensaAgachado[0].w = 261;
	gSpriteDefensaAgachado[0].h = 150;

//	gSpriteDefensaAgachado[1].x = 306;
//	gSpriteDefensaAgachado[1].y = 2832;
//	gSpriteDefensaAgachado[1].w = 261;
//	gSpriteDefensaAgachado[1].h = 150;
//
//	gSpriteDefensaAgachado[2].x = 567;
//	gSpriteDefensaAgachado[2].y = 2832;
//	gSpriteDefensaAgachado[2].w = 261;
//	gSpriteDefensaAgachado[2].h = 150;
//
//	gSpriteDefensaAgachado[3].x = 828;
//	gSpriteDefensaAgachado[3].y = 2832;
//	gSpriteDefensaAgachado[3].w = 261;
//	gSpriteDefensaAgachado[3].h = 150;


}
void View_Jugador_Spiderman::getSpritesDefensaSaltando(){
	CANTSPRITECLIPDEFENSASALTANDO = 1;
	MINFRAMEDEFENSASALTANDO = 0;
	MAXFRAMEDEFENSASALTANDO = 0;
	FACTORDEFENSASALTANDO = 5;
	this->gSpriteDefensaSaltando = new SDL_Rect[CANTSPRITECLIPDEFENSASALTANDO];

	gSpriteDefensaSaltando[0].x = 306;
	gSpriteDefensaSaltando[0].y = 2832;
	gSpriteDefensaSaltando[0].w = 261;
	gSpriteDefensaSaltando[0].h = 150;

//	gSpriteDefensaSaltando[1].x = 306;
//	gSpriteDefensaSaltando[1].y = 2832;
//	gSpriteDefensaSaltando[1].w = 261;
//	gSpriteDefensaSaltando[1].h = 150;
//
//	gSpriteDefensaSaltando[2].x = 567;
//	gSpriteDefensaSaltando[2].y = 2832;
//	gSpriteDefensaSaltando[2].w = 261;
//	gSpriteDefensaSaltando[2].h = 150;
//
//	gSpriteDefensaSaltando[3].x = 828;
//	gSpriteDefensaSaltando[3].y = 2832;
//	gSpriteDefensaSaltando[3].w = 261;
//	gSpriteDefensaSaltando[3].h = 150;


}
void View_Jugador_Spiderman::getSpritesRecibirGolpe(){
	CANTSPRITECLIPRECIBIRGOLPE = 4;
	MINFRAMERECIBIRGOLPE = 0;
	MAXFRAMERECIBIRGOLPE = 3;
	FACTORRECIBIRGOLPE = 10;
	this->gSpriteRecibirDanio = new SDL_Rect[CANTSPRITECLIPRECIBIRGOLPE];

	gSpriteRecibirDanio[0].x = 53;
	gSpriteRecibirDanio[0].y = 3100;
	gSpriteRecibirDanio[0].w = 261;
	gSpriteRecibirDanio[0].h = 150;

	gSpriteRecibirDanio[1].x = 314;
	gSpriteRecibirDanio[1].y = 3100;
	gSpriteRecibirDanio[1].w = 261;
	gSpriteRecibirDanio[1].h = 150;

	gSpriteRecibirDanio[2].x = 575;
	gSpriteRecibirDanio[2].y = 3100;
	gSpriteRecibirDanio[2].w = 261;
	gSpriteRecibirDanio[2].h = 150;

	gSpriteRecibirDanio[3].x = 836;
	gSpriteRecibirDanio[3].y = 3100;
	gSpriteRecibirDanio[3].w = 261;
	gSpriteRecibirDanio[3].h = 150;

}
void View_Jugador_Spiderman::getSpritesLanzarJugador(){
	CANTSPRITECLIPLANZARJUGADOR = 4;
	MINFRAMELANZARJUGADOR = 0;
	MAXFRAMELANZARJUGADOR = 3;
	FACTORLANZARJUGADOR = 10;
	this->gSpriteLanzarJugador = new SDL_Rect[CANTSPRITECLIPLANZARJUGADOR];

	gSpriteLanzarJugador[0].x = 54;
	gSpriteLanzarJugador[0].y = 3400;
	gSpriteLanzarJugador[0].w = 261;
	gSpriteLanzarJugador[0].h = 150;

	gSpriteLanzarJugador[1].x = 315;
	gSpriteLanzarJugador[1].y = 3400;
	gSpriteLanzarJugador[1].w = 261;
	gSpriteLanzarJugador[1].h = 150;

	gSpriteLanzarJugador[2].x = 576;
	gSpriteLanzarJugador[2].y = 3400;
	gSpriteLanzarJugador[2].w = 261;
	gSpriteLanzarJugador[2].h = 150;

	gSpriteLanzarJugador[3].x = 837;
	gSpriteLanzarJugador[3].y = 3400;
	gSpriteLanzarJugador[3].w = 261;
	gSpriteLanzarJugador[3].h = 150;

}
void View_Jugador_Spiderman::getSpritesJugadorLanzado(){
	CANTSPRITECLIPJUGADORLANZADO = 7;
	MINFRAMEJUGADORLANZADO = 0;
	MAXFRAMEJUGADORLANZADO = 6;
	FACTORJUGADORLANZADO = 5;
	this->gSpriteJugadorLanzado = new SDL_Rect[CANTSPRITECLIPJUGADORLANZADO];

	gSpriteJugadorLanzado[0].x = 54;
	gSpriteJugadorLanzado[0].y = 3600;
	gSpriteJugadorLanzado[0].w = 261;
	gSpriteJugadorLanzado[0].h = 150;

	gSpriteJugadorLanzado[1].x = 315;
	gSpriteJugadorLanzado[1].y = 3600;
	gSpriteJugadorLanzado[1].w = 261;
	gSpriteJugadorLanzado[1].h = 150;

	gSpriteJugadorLanzado[2].x = 576;
	gSpriteJugadorLanzado[2].y = 3600;
	gSpriteJugadorLanzado[2].w = 261;
	gSpriteJugadorLanzado[2].h = 150;

	gSpriteJugadorLanzado[3].x = 837;
	gSpriteJugadorLanzado[3].y = 3600;
	gSpriteJugadorLanzado[3].w = 261;
	gSpriteJugadorLanzado[3].h = 150;

	gSpriteJugadorLanzado[4].x = 1098;
	gSpriteJugadorLanzado[4].y = 3600;
	gSpriteJugadorLanzado[4].w = 261;
	gSpriteJugadorLanzado[4].h = 150;


	gSpriteJugadorLanzado[5].x = 1359;
	gSpriteJugadorLanzado[5].y = 3600;
	gSpriteJugadorLanzado[5].w = 261;
	gSpriteJugadorLanzado[5].h = 150;

	gSpriteJugadorLanzado[6].x = 1620;
	gSpriteJugadorLanzado[6].y = 3600;
	gSpriteJugadorLanzado[6].w = 261;
	gSpriteJugadorLanzado[6].h = 150;

}
void View_Jugador_Spiderman::getSpritesLanzarPoder(){
	CANTSPRITECLIPLANZARPODER = 6;
	MINFRAMELANZARPODER = 0;
	MAXFRAMELANZARPODER = 5;
	FACTORLANZARPODER = 10;
	this->gSpriteLanzarPoder = new SDL_Rect[CANTSPRITECLIPLANZARPODER];

	gSpriteLanzarPoder[0].x = 55;
	gSpriteLanzarPoder[0].y = 3775;
	gSpriteLanzarPoder[0].w = 261;
	gSpriteLanzarPoder[0].h = 150;

	gSpriteLanzarPoder[1].x = 316;
	gSpriteLanzarPoder[1].y = 3775;
	gSpriteLanzarPoder[1].w = 261;
	gSpriteLanzarPoder[1].h = 150;

	gSpriteLanzarPoder[2].x = 577;
	gSpriteLanzarPoder[2].y = 3775;
	gSpriteLanzarPoder[2].w = 261;
	gSpriteLanzarPoder[2].h = 150;

	gSpriteLanzarPoder[3].x = 838;
	gSpriteLanzarPoder[3].y = 3775;
	gSpriteLanzarPoder[3].w = 261;
	gSpriteLanzarPoder[3].h = 150;

	gSpriteLanzarPoder[4].x = 1099;
	gSpriteLanzarPoder[4].y = 3775;
	gSpriteLanzarPoder[4].w = 261;
	gSpriteLanzarPoder[4].h = 150;

	gSpriteLanzarPoder[5].x = 1360;
	gSpriteLanzarPoder[5].y = 3775;
	gSpriteLanzarPoder[5].w = 261;
	gSpriteLanzarPoder[5].h = 150;

}
void View_Jugador_Spiderman::getSpritesPoder(){
	CANTSPRITECLIPPODER = 6;
	MINFRAMEPODER = 0;
	MAXFRAMEPODER = 5;
	FACTORPODER = 8;
	this->gSpritePoder = new SDL_Rect[CANTSPRITECLIPPODER];

//	gSpritePoder[0].x = 59;
//	gSpritePoder[0].y = 3983;
//	gSpritePoder[0].w = 261;
//	gSpritePoder[0].h = 150;

	gSpritePoder[0].x = 320;
	gSpritePoder[0].y = 3983;
	gSpritePoder[0].w = 261;
	gSpritePoder[0].h = 150;

	gSpritePoder[1].x = 581;
	gSpritePoder[1].y = 3983;
	gSpritePoder[1].w = 261;
	gSpritePoder[1].h = 150;

	gSpritePoder[2].x = 842;
	gSpritePoder[2].y = 3983;
	gSpritePoder[2].w = 261;
	gSpritePoder[2].h = 150;

	gSpritePoder[3].x = 1103;
	gSpritePoder[3].y = 3983;
	gSpritePoder[3].w = 261;
	gSpritePoder[3].h = 150;

	gSpritePoder[4].x = 1364;
	gSpritePoder[4].y = 3983;
	gSpritePoder[4].w = 261;
	gSpritePoder[4].h = 150;

	gSpritePoder[5].x = 1625;
	gSpritePoder[5].y = 3983;
	gSpritePoder[5].w = 261;
	gSpritePoder[5].h = 150;
}

