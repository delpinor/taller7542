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
	getSpritesPatadaDebil();
	getSpritesPinaDebil();
	getSpritesPinaFuerte();
	getSpritesDefensa();
	getSpritesPatadaDebil_agachado();
	getSpritesPinaFuerte_agachado();
	getSpritesPinaDebil_agachado();
	getSpritesPatadaFuerte_agachado();
	getSpritesDefensaAgachado();
	getSpritesDefensaSaltando();
	getSpritesPatadaDebilSaltando();
	getSpritesPatadaFuerteSaltando();
	getSpritesPinaFuerteSaltando();
	getSpritesPinaDebilSaltando();
	getSpritesRecibirDanio();
	getSpritesPoder();
	getSpritesLanzarPoder();
	getSpritesVolando();
	getSpritesArrojando();
	getSpritesPoderEspecial();

	this->zIndex = model->get_zindex();
	getSpritesCambioPersonaje();
	this->texturaJugador->setColor(this->jugador->getR(), this->jugador->getG(),
			this->jugador->getB());

		//efectos de sonido
		this->sonido_salto=new EfectoSonido(1);
		this->sonido_ataque_pu=new EfectoSonido(1);
		this->sonido_defensa=new EfectoSonido(1);
		this->sonido_cambio=new EfectoSonido(1);
		this->sonido_danio=new EfectoSonido(1);
		this->sonido_ataque_patada=new EfectoSonido(1);
		this->sonido_poder=new EfectoSonido(1);
		this->sonido_agarre=new EfectoSonido(1);

		this->sonido_poder->loadMedia("../Sonidos/cap_poder.wav");
		this->sonido_agarre->loadMedia("../Sonidos/cap_agarre.wav");

		this->sonido_ataque_pu->loadMedia("../Sonidos/cap_punio.wav");
		this->sonido_salto->loadMedia("../Sonidos/salto_captain.wav");
		this->sonido_cambio->loadMedia("../Sonidos/cambio_captain.wav");
		this->sonido_ataque_patada->loadMedia("../Sonidos/cap_patada.wav");
		this->sonido_defensa->loadMedia("../Sonidos/cap_defensa.wav");
		this->sonido_danio->loadMedia("../Sonidos/cap_dmg.wav");









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

void View_Jugador_CapAmerica::reproducir_sonido_salto() {

	this->sonido_salto->reproducir_sonido();

}
void View_Jugador_CapAmerica::reproducir_sonido_cambio() {

	this->sonido_cambio->reproducir_sonido();

}
void View_Jugador_CapAmerica::reproducir_sonido_ataque_pu() {

	this->sonido_ataque_pu->reproducir_sonido();

}
void View_Jugador_CapAmerica::reproducir_sonido_defensa() {

	this->sonido_defensa->reproducir_sonido();

}
void View_Jugador_CapAmerica::reproducir_sonido_ataque_patada(){
	this->sonido_ataque_patada->reproducir_sonido();

}

void View_Jugador_CapAmerica::reproducir_sonido_recibir_danio(){
	this->sonido_danio->reproducir_sonido();


}
void View_Jugador_CapAmerica::reproducir_sonido_poder(){
	this->sonido_poder->reproducir_sonido();

}

void View_Jugador_CapAmerica::reproducir_sonido_agarre(){
	this->sonido_agarre->reproducir_sonido();


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
	FACTORSALTA = 4;
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
	gSpriteSaltar[4].h = 150;

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
	CANTSPRITECLIPPATADON = 5;
	MINFRAMEPATADON = 0;
	MAXFRAMEPATADON = 4;
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

}
void View_Jugador_CapAmerica::getSpritesPatadaDebil() {
	CANTSPRITECLIPPATADA = 5;
	MINFRAMEPATADA = 0;
	MAXFRAMEPATADA = 4;
	FACTORPATADA = 3;
	this->gSpritePatada = new SDL_Rect[CANTSPRITECLIPPATADA];

	gSpritePatada[0].x = 323;
	gSpritePatada[0].y = 1297;
	gSpritePatada[0].w = 261;
	gSpritePatada[0].h = 150;

	gSpritePatada[1].x = 113;
	gSpritePatada[1].y = 1297;
	gSpritePatada[1].w = 261;
	gSpritePatada[1].h = 150;

	gSpritePatada[2].x = 113;
	gSpritePatada[2].y = 1297;
	gSpritePatada[2].w = 261;
	gSpritePatada[2].h = 150;

	gSpritePatada[3].x = 113;
	gSpritePatada[3].y = 1297;
	gSpritePatada[3].w = 261;
	gSpritePatada[3].h = 150;

	gSpritePatada[4].x = 113;
	gSpritePatada[4].y = 1297;
	gSpritePatada[4].w = 261;
	gSpritePatada[4].h = 150;

}
void View_Jugador_CapAmerica::getSpritesPinaFuerte() {

	CANTSPRITECLIPPINION = 8;
	MINFRAMEPINION = 0;
	MAXFRAMEPINION = 7;
	FACTORPINION = 4;
	this->gSpritePinion = new SDL_Rect[CANTSPRITECLIPPINION];

	gSpritePinion[0].x = 72;
	gSpritePinion[0].y = 918;
	gSpritePinion[0].w = 261;
	gSpritePinion[0].h = 150;

	gSpritePinion[1].x = 320;
	gSpritePinion[1].y = 918;
	gSpritePinion[1].w = 261;
	gSpritePinion[1].h = 150;

	gSpritePinion[2].x = 600;
	gSpritePinion[2].y = 918;
	gSpritePinion[2].w = 261;
	gSpritePinion[2].h = 150;

	gSpritePinion[3].x = 900;
	gSpritePinion[3].y = 918;
	gSpritePinion[3].w = 261;
	gSpritePinion[3].h = 150;

	gSpritePinion[4].x = 900;
	gSpritePinion[4].y = 918;
	gSpritePinion[4].w = 261;
	gSpritePinion[4].h = 150;

	gSpritePinion[5].x = 1230;
	gSpritePinion[5].y = 918;
	gSpritePinion[5].w = 261;
	gSpritePinion[5].h = 150;

	gSpritePinion[6].x = 1230;
	gSpritePinion[6].y = 918;
	gSpritePinion[6].w = 261;
	gSpritePinion[6].h = 150;

	gSpritePinion[7].x = 72;
	gSpritePinion[7].y = 918;
	gSpritePinion[7].w = 261;
	gSpritePinion[7].h = 150;

}
void View_Jugador_CapAmerica::getSpritesPinaDebil() {
	CANTSPRITECLIPPINIA = 7;
	MINFRAMEPINIA = 0;
	MAXFRAMEPINIA = 6;
	FACTORPINIA = 4;
	this->gSpritePinia = new SDL_Rect[CANTSPRITECLIPPINIA];

	gSpritePinia[0].x = 0;
	gSpritePinia[0].y = 752;
	gSpritePinia[0].w = 261;
	gSpritePinia[0].h = 150;

	gSpritePinia[1].x = 490;
	gSpritePinia[1].y = 752;
	gSpritePinia[1].w = 261;
	gSpritePinia[1].h = 150;

	gSpritePinia[2].x = 490;
	gSpritePinia[2].y = 752;
	gSpritePinia[2].w = 261;
	gSpritePinia[2].h = 150;

	gSpritePinia[3].x = 240;
	gSpritePinia[3].y = 752;
	gSpritePinia[3].w = 261;
	gSpritePinia[3].h = 150;

	gSpritePinia[4].x = 240;
	gSpritePinia[4].y = 752;
	gSpritePinia[4].w = 261;
	gSpritePinia[4].h = 150;

	gSpritePinia[5].x = 240;
	gSpritePinia[5].y = 752;
	gSpritePinia[5].w = 261;
	gSpritePinia[5].h = 150;

	gSpritePinia[6].x = 490;
	gSpritePinia[6].y = 752;
	gSpritePinia[6].w = 261;
	gSpritePinia[6].h = 150;

}
void View_Jugador_CapAmerica::getSpritesDefensa() {

	this->gSpriteDefensa = new SDL_Rect[1];

	gSpriteDefensa[0].x = 0;
	gSpriteDefensa[0].y = 752;
	gSpriteDefensa[0].w = 261;
	gSpriteDefensa[0].h = 150;
}
void View_Jugador_CapAmerica::getSpritesDefensaSaltando() {
	this->gSpriteDefensaSaltando = new SDL_Rect[1];
	gSpriteDefensaSaltando[0].x = 0;
	gSpriteDefensaSaltando[0].y = 572;
	gSpriteDefensaSaltando[0].w = 261;
	gSpriteDefensaSaltando[0].h = 150;
}

void View_Jugador_CapAmerica::getSpritesDefensaAgachado() {
	this->gSpriteDefensaAgachado = new SDL_Rect[1];
	gSpriteDefensaAgachado[0].x = 275;
	gSpriteDefensaAgachado[0].y = 570;
	gSpriteDefensaAgachado[0].w = 261;
	gSpriteDefensaAgachado[0].h = 150;
}
void View_Jugador_CapAmerica::getSpritesPatadaFuerte_agachado() {
	CANTSPRITECLIPPATADONAGACHADO = 9;
	MINFRAMEPATADONAGACHADO = 0;
	MAXFRAMEPATADONAGACHADO = 8;
	FACTORPATADONAGACHADO = 3;
	this->gSpritePatadonAgachado = new SDL_Rect[CANTSPRITECLIPPATADONAGACHADO];

	gSpritePatadonAgachado[0].x = 17;
	gSpritePatadonAgachado[0].y = 363;
	gSpritePatadonAgachado[0].w = 261;
	gSpritePatadonAgachado[0].h = 150;

	gSpritePatadonAgachado[1].x = 785;
	gSpritePatadonAgachado[1].y = 1657;
	gSpritePatadonAgachado[1].w = 261;
	gSpritePatadonAgachado[1].h = 150;

	gSpritePatadonAgachado[2].x = 1505;
	gSpritePatadonAgachado[2].y = 1657;
	gSpritePatadonAgachado[2].w = 261;
	gSpritePatadonAgachado[2].h = 150;

	gSpritePatadonAgachado[3].x = 1236;
	gSpritePatadonAgachado[3].y = 1657;
	gSpritePatadonAgachado[3].w = 261;
	gSpritePatadonAgachado[3].h = 150;

	gSpritePatadonAgachado[4].x = 1010;
	gSpritePatadonAgachado[4].y = 1657;
	gSpritePatadonAgachado[4].w = 261;
	gSpritePatadonAgachado[4].h = 150;

	gSpritePatadonAgachado[5].x = 785;
	gSpritePatadonAgachado[5].y = 1657;
	gSpritePatadonAgachado[5].w = 261;
	gSpritePatadonAgachado[5].h = 150;

	gSpritePatadonAgachado[6].x = 1505;
	gSpritePatadonAgachado[6].y = 1657;
	gSpritePatadonAgachado[6].w = 261;
	gSpritePatadonAgachado[6].h = 150;

	gSpritePatadonAgachado[7].x = 1236;
	gSpritePatadonAgachado[7].y = 1657;
	gSpritePatadonAgachado[7].w = 261;
	gSpritePatadonAgachado[7].h = 150;

	gSpritePatadonAgachado[8].x = 1010;
	gSpritePatadonAgachado[8].y = 1657;
	gSpritePatadonAgachado[8].w = 261;
	gSpritePatadonAgachado[8].h = 150;

}
void View_Jugador_CapAmerica::getSpritesPatadaDebil_agachado() {
	CANTSPRITECLIPPATADAAGACHADO = 6;
	MINFRAMEPATADAAGACHADO = 0;
	MAXFRAMEPATADAAGACHADO = 5;
	FACTORPATADAAGACHADO = 3;
	this->gSpritePatadaAgachado = new SDL_Rect[CANTSPRITECLIPPATADAAGACHADO];

	gSpritePatadaAgachado[0].x = 17;
	gSpritePatadaAgachado[0].y = 363;
	gSpritePatadaAgachado[0].w = 261;
	gSpritePatadaAgachado[0].h = 150;

	gSpritePatadaAgachado[1].x = 900;
	gSpritePatadaAgachado[1].y = 587;
	gSpritePatadaAgachado[1].w = 261;
	gSpritePatadaAgachado[1].h = 150;

	gSpritePatadaAgachado[2].x = 900;
	gSpritePatadaAgachado[2].y = 587;
	gSpritePatadaAgachado[2].w = 261;
	gSpritePatadaAgachado[2].h = 150;

	gSpritePatadaAgachado[3].x = 900;
	gSpritePatadaAgachado[3].y = 587;
	gSpritePatadaAgachado[3].w = 261;
	gSpritePatadaAgachado[3].h = 150;

	gSpritePatadaAgachado[4].x = 900;
	gSpritePatadaAgachado[4].y = 587;
	gSpritePatadaAgachado[4].w = 261;
	gSpritePatadaAgachado[4].h = 150;

	gSpritePatadaAgachado[5].x = 17;
	gSpritePatadaAgachado[5].y = 363;
	gSpritePatadaAgachado[5].w = 261;
	gSpritePatadaAgachado[5].h = 150;

}
void View_Jugador_CapAmerica::getSpritesPinaFuerte_agachado() {
	CANTSPRITECLIPPINIONAGACHADO = 9;
	MINFRAMEPINIONAGACHADO = 0;
	MAXFRAMEPINIONAGACHADO = 8;
	FACTORPINIONAGACHADO = 3;
	this->gSpritePinionAgachado = new SDL_Rect[CANTSPRITECLIPPINIONAGACHADO];

	gSpritePinionAgachado[0].x = 17;
	gSpritePinionAgachado[0].y = 363;
	gSpritePinionAgachado[0].w = 261;
	gSpritePinionAgachado[0].h = 150;

	gSpritePinionAgachado[1].x = 1150;
	gSpritePinionAgachado[1].y = 572;
	gSpritePinionAgachado[1].w = 261;
	gSpritePinionAgachado[1].h = 150;

	gSpritePinionAgachado[2].x = 1614;
	gSpritePinionAgachado[2].y = 572;
	gSpritePinionAgachado[2].w = 261;
	gSpritePinionAgachado[2].h = 150;

	gSpritePinionAgachado[3].x = 1857;
	gSpritePinionAgachado[3].y = 572;
	gSpritePinionAgachado[3].w = 261;
	gSpritePinionAgachado[3].h = 150;

	gSpritePinionAgachado[4].x = 1857;
	gSpritePinionAgachado[4].y = 572;
	gSpritePinionAgachado[4].w = 261;
	gSpritePinionAgachado[4].h = 150;

	gSpritePinionAgachado[5].x = 1857;
	gSpritePinionAgachado[5].y = 572;
	gSpritePinionAgachado[5].w = 261;
	gSpritePinionAgachado[5].h = 150;

	gSpritePinionAgachado[6].x = 1857;
	gSpritePinionAgachado[6].y = 572;
	gSpritePinionAgachado[6].w = 261;
	gSpritePinionAgachado[6].h = 150;

	gSpritePinionAgachado[7].x = 2105;
	gSpritePinionAgachado[7].y = 572;
	gSpritePinionAgachado[7].w = 261;
	gSpritePinionAgachado[7].h = 150;

	gSpritePinionAgachado[8].x = 17;
	gSpritePinionAgachado[8].y = 363;
	gSpritePinionAgachado[8].w = 261;
	gSpritePinionAgachado[8].h = 150;

}
void View_Jugador_CapAmerica::getSpritesPinaDebil_agachado() {

	CANTSPRITECLIPPINIAAGACHADO = 6;
	MINFRAMEPINIAAGACHADO = 0;
	MAXFRAMEPINIAAGACHADO = 5;
	FACTORPINIAAGACHADO = 2;
	this->gSpritePiniaAgachado = new SDL_Rect[CANTSPRITECLIPPINIAAGACHADO];

	gSpritePiniaAgachado[0].x = 17;
	gSpritePiniaAgachado[0].y = 363;
	gSpritePiniaAgachado[0].w = 261;
	gSpritePiniaAgachado[0].h = 150;

	gSpritePiniaAgachado[1].x = 1150;
	gSpritePiniaAgachado[1].y = 576;
	gSpritePiniaAgachado[1].w = 261;
	gSpritePiniaAgachado[1].h = 150;

	gSpritePiniaAgachado[2].x = 1150;
	gSpritePiniaAgachado[2].y = 576;
	gSpritePiniaAgachado[2].w = 261;
	gSpritePiniaAgachado[2].h = 150;

	gSpritePiniaAgachado[3].x = 1150;
	gSpritePiniaAgachado[3].y = 576;
	gSpritePiniaAgachado[3].w = 261;
	gSpritePiniaAgachado[3].h = 150;

	gSpritePiniaAgachado[4].x = 1150;
	gSpritePiniaAgachado[4].y = 576;
	gSpritePiniaAgachado[4].w = 261;
	gSpritePiniaAgachado[4].h = 150;

	gSpritePiniaAgachado[5].x = 17;
	gSpritePiniaAgachado[5].y = 363;
	gSpritePiniaAgachado[5].w = 261;
	gSpritePiniaAgachado[5].h = 150;

}
void View_Jugador_CapAmerica::getSpritesPatadaDebilSaltando() {
	CANTSPRITECLIPPATADASALTANDO = 3;
	MINFRAMEPATADASALTANDO = 0;
	MAXFRAMEPATADASALTANDO = 2;
	FACTORPATADASALTANDO = 2;
	this->gSpritePatadaSaltando = new SDL_Rect[CANTSPRITECLIPPATADASALTANDO];

	gSpritePatadaSaltando[0].x = 323;
	gSpritePatadaSaltando[0].y = 1297;
	gSpritePatadaSaltando[0].w = 261;
	gSpritePatadaSaltando[0].h = 150;

	gSpritePatadaSaltando[1].x = 113;
	gSpritePatadaSaltando[1].y = 1297;
	gSpritePatadaSaltando[1].w = 261;
	gSpritePatadaSaltando[1].h = 150;

	gSpritePatadaSaltando[2].x = 113;
	gSpritePatadaSaltando[2].y = 1297;
	gSpritePatadaSaltando[2].w = 261;
	gSpritePatadaSaltando[2].h = 150;

}

void View_Jugador_CapAmerica::getSpritesPatadaFuerteSaltando() {
	CANTSPRITECLIPPATADONSALTANDO = 5;
	MINFRAMEPATADONSALTANDO = 0;
	MAXFRAMEPATADONSALTANDO = 4;
	FACTORPATADONSALTANDO = 2;
	this->gSpritePatadonSaltando = new SDL_Rect[CANTSPRITECLIPPATADONSALTANDO];

	gSpritePatadonSaltando[0].x = 323;
	gSpritePatadonSaltando[0].y = 1297;
	gSpritePatadonSaltando[0].w = 261;
	gSpritePatadonSaltando[0].h = 150;

	gSpritePatadonSaltando[1].x = 543;
	gSpritePatadonSaltando[1].y = 1296;
	gSpritePatadonSaltando[1].w = 261;
	gSpritePatadonSaltando[1].h = 150;

	gSpritePatadonSaltando[2].x = 744;
	gSpritePatadonSaltando[2].y = 1293;
	gSpritePatadonSaltando[2].w = 261;
	gSpritePatadonSaltando[2].h = 150;

	gSpritePatadonSaltando[3].x = 948;
	gSpritePatadonSaltando[3].y = 1296;
	gSpritePatadonSaltando[3].w = 261;
	gSpritePatadonSaltando[3].h = 150;

	gSpritePatadonSaltando[4].x = 1183;
	gSpritePatadonSaltando[4].y = 1295;
	gSpritePatadonSaltando[4].w = 261;
	gSpritePatadonSaltando[4].h = 150;

}

void View_Jugador_CapAmerica::getSpritesPinaFuerteSaltando() {

	CANTSPRITECLIPPINIONSALTANDO = 8;
	MINFRAMEPINIONSALTANDO = 0;
	MAXFRAMEPINIONSALTANDO = 7;
	FACTORPINIONSALTANDO = 2;
	this->gSpritePinionSaltando = new SDL_Rect[CANTSPRITECLIPPINIONSALTANDO];

	gSpritePinionSaltando[0].x = 72;
	gSpritePinionSaltando[0].y = 918;
	gSpritePinionSaltando[0].w = 261;
	gSpritePinionSaltando[0].h = 150;

	gSpritePinionSaltando[1].x = 320;
	gSpritePinionSaltando[1].y = 918;
	gSpritePinionSaltando[1].w = 261;
	gSpritePinionSaltando[1].h = 150;

	gSpritePinionSaltando[2].x = 600;
	gSpritePinionSaltando[2].y = 918;
	gSpritePinionSaltando[2].w = 261;
	gSpritePinionSaltando[2].h = 150;

	gSpritePinionSaltando[3].x = 900;
	gSpritePinionSaltando[3].y = 918;
	gSpritePinionSaltando[3].w = 261;
	gSpritePinionSaltando[3].h = 150;

	gSpritePinionSaltando[4].x = 900;
	gSpritePinionSaltando[4].y = 918;
	gSpritePinionSaltando[4].w = 261;
	gSpritePinionSaltando[4].h = 150;

	gSpritePinionSaltando[5].x = 1230;
	gSpritePinionSaltando[5].y = 918;
	gSpritePinionSaltando[5].w = 261;
	gSpritePinionSaltando[5].h = 150;

	gSpritePinionSaltando[6].x = 1230;
	gSpritePinionSaltando[6].y = 918;
	gSpritePinionSaltando[6].w = 261;
	gSpritePinionSaltando[6].h = 150;

	gSpritePinionSaltando[7].x = 72;
	gSpritePinionSaltando[7].y = 918;
	gSpritePinionSaltando[7].w = 261;
	gSpritePinionSaltando[7].h = 150;

}
void View_Jugador_CapAmerica::getSpritesPinaDebilSaltando() {
	CANTSPRITECLIPPINIASALTANDO = 3;
	MINFRAMEPINIASALTANDO = 0;
	MAXFRAMEPINIASALTANDO = 2;
	FACTORPINIASALTANDO = 2;
	this->gSpritePiniaSaltando = new SDL_Rect[CANTSPRITECLIPPINIASALTANDO];

	gSpritePiniaSaltando[0].x = 490;
	gSpritePiniaSaltando[0].y = 752;
	gSpritePiniaSaltando[0].w = 261;
	gSpritePiniaSaltando[0].h = 150;

	gSpritePiniaSaltando[1].x = 240;
	gSpritePiniaSaltando[1].y = 752;
	gSpritePiniaSaltando[1].w = 261;
	gSpritePiniaSaltando[1].h = 150;

	gSpritePiniaSaltando[2].x = 240;
	gSpritePiniaSaltando[2].y = 752;
	gSpritePiniaSaltando[2].w = 261;
	gSpritePiniaSaltando[2].h = 150;

		gSpritePiniaSaltando[1].x = 240;
		gSpritePiniaSaltando[1].y = 752;
		gSpritePiniaSaltando[1].w = 261;
		gSpritePiniaSaltando[1].h = 150;

		gSpritePiniaSaltando[2].x = 240;
		gSpritePiniaSaltando[2].y = 752;
		gSpritePiniaSaltando[2].w = 261;
		gSpritePiniaSaltando[2].h = 150;





}
void View_Jugador_CapAmerica::getSpritesRecibirDanio() {
	this->gSpriteRecibirDanio = new SDL_Rect[1];

	gSpriteRecibirDanio[0].x = 762;
	gSpriteRecibirDanio[0].y = 758;
	gSpriteRecibirDanio[0].w = 261;
	gSpriteRecibirDanio[0].h = 150;
}

void View_Jugador_CapAmerica::getSpritesLanzarPoder(){
	CANTSPRITECLIPLANZARPODER = 3;
	MINFRAMELANZARPODER = 0;
	MAXFRAMELANZARPODER = 2;
	FACTORLANZARPODER = 5;
	this->gSpriteLanzarPoder = new SDL_Rect[CANTSPRITECLIPLANZARPODER];

	gSpriteLanzarPoder[0].x = 81;
	gSpriteLanzarPoder[0].y = 1088;
	gSpriteLanzarPoder[0].w = 261;
	gSpriteLanzarPoder[0].h = 150;

	gSpriteLanzarPoder[1].x = 383;
	gSpriteLanzarPoder[1].y = 1088;
	gSpriteLanzarPoder[1].w = 261;
	gSpriteLanzarPoder[1].h = 150;

	gSpriteLanzarPoder[2].x = 1048;
	gSpriteLanzarPoder[2].y = 1088;
	gSpriteLanzarPoder[2].w = 261;
	gSpriteLanzarPoder[2].h = 150;

//	gSpriteLanzarPoder[3].x = 81;
//	gSpriteLanzarPoder[3].y = 1081;
//	gSpriteLanzarPoder[3].w = 261;
//	gSpriteLanzarPoder[3].h = 150;
//
//	gSpriteLanzarPoder[4].x = 81;
//	gSpriteLanzarPoder[4].y = 1081;
//	gSpriteLanzarPoder[4].w = 261;
//	gSpriteLanzarPoder[4].h = 150;
//
//	gSpriteLanzarPoder[5].x = 81;
//	gSpriteLanzarPoder[5].y = 1081;
//	gSpriteLanzarPoder[5].w = 261;
//	gSpriteLanzarPoder[5].h = 150;

}

void View_Jugador_CapAmerica::getSpritesPoder(){
	CANTSPRITECLIPPODER = 7;
	MINFRAMEPODER = 0;
	MAXFRAMEPODER = 6;
	FACTORPODER = 8;
	this->gSpritePoder = new SDL_Rect[CANTSPRITECLIPPODER];

	gSpritePoder[0].x = 758;
	gSpritePoder[0].y = 1104;
	gSpritePoder[0].w = 261;
	gSpritePoder[0].h = 150;

	gSpritePoder[1].x = 758;
	gSpritePoder[1].y = 1104;
	gSpritePoder[1].w = 261;
	gSpritePoder[1].h = 150;

	gSpritePoder[2].x = 758;
	gSpritePoder[2].y = 1104;
	gSpritePoder[2].w = 261;
	gSpritePoder[2].h = 150;

	gSpritePoder[3].x = 758;
	gSpritePoder[3].y = 1104;
	gSpritePoder[3].w = 261;
	gSpritePoder[3].h = 150;

	gSpritePoder[4].x = 758;
	gSpritePoder[4].y = 1104;
	gSpritePoder[4].w = 261;
	gSpritePoder[4].h = 150;

	gSpritePoder[5].x = 758;
	gSpritePoder[5].y = 1104;
	gSpritePoder[5].w = 261;
	gSpritePoder[5].h = 150;

	gSpritePoder[6].x = 758;
	gSpritePoder[6].y = 1104;
	gSpritePoder[6].w = 261;
	gSpritePoder[6].h = 150;
}

void View_Jugador_CapAmerica::getSpritesVolando() {
	CANTSPRITECLIPJUGADORLANZADO = 7;
	MINFRAMEJUGADORLANZADO = 0;
	MAXFRAMEJUGADORLANZADO = 6;
	FACTORJUGADORLANZADO = 9;
	this->gSpriteJugadorLanzado = new SDL_Rect[CANTSPRITECLIPJUGADORLANZADO];

	gSpriteJugadorLanzado[0].x = 84;
	gSpriteJugadorLanzado[0].y = 1870;
	gSpriteJugadorLanzado[0].w = 261;
	gSpriteJugadorLanzado[0].h = 150;

	gSpriteJugadorLanzado[1].x = 300;
	gSpriteJugadorLanzado[1].y = 1870;
	gSpriteJugadorLanzado[1].w = 261;
	gSpriteJugadorLanzado[1].h = 150;

	gSpriteJugadorLanzado[2].x = 566;
	gSpriteJugadorLanzado[2].y = 1870;
	gSpriteJugadorLanzado[2].w = 261;
	gSpriteJugadorLanzado[2].h = 150;

	gSpriteJugadorLanzado[3].x = 778;
	gSpriteJugadorLanzado[3].y = 1870;
	gSpriteJugadorLanzado[3].w = 261;
	gSpriteJugadorLanzado[3].h = 150;

	gSpriteJugadorLanzado[4].x = 1002;
	gSpriteJugadorLanzado[4].y = 1870;
	gSpriteJugadorLanzado[4].w = 261;
	gSpriteJugadorLanzado[4].h = 150;

	gSpriteJugadorLanzado[5].x = 1246;
	gSpriteJugadorLanzado[5].y = 1870;
	gSpriteJugadorLanzado[5].w = 261;
	gSpriteJugadorLanzado[5].h = 150;

	gSpriteJugadorLanzado[6].x = 1458;
	gSpriteJugadorLanzado[6].y = 1870;
	gSpriteJugadorLanzado[6].w = 261;
	gSpriteJugadorLanzado[6].h = 150;

}


void View_Jugador_CapAmerica::getSpritesArrojando(){
	CANTSPRITECLIPLANZARJUGADOR = 8;
	MINFRAMELANZARJUGADOR = 0;
	MAXFRAMELANZARJUGADOR = 7;
	FACTORLANZARJUGADOR = 3;
	this->gSpriteLanzarJugador = new SDL_Rect[CANTSPRITECLIPLANZARJUGADOR];

	gSpriteLanzarJugador[0].x = 72;
		gSpriteLanzarJugador[0].y = 918;
		gSpriteLanzarJugador[0].w = 261;
		gSpriteLanzarJugador[0].h = 150;

		gSpriteLanzarJugador[1].x = 320;
		gSpriteLanzarJugador[1].y = 918;
		gSpriteLanzarJugador[1].w = 261;
		gSpriteLanzarJugador[1].h = 150;

		gSpriteLanzarJugador[2].x = 600;
		gSpriteLanzarJugador[2].y = 918;
		gSpriteLanzarJugador[2].w = 261;
		gSpriteLanzarJugador[2].h = 150;

		gSpriteLanzarJugador[3].x = 900;
		gSpriteLanzarJugador[3].y = 918;
		gSpriteLanzarJugador[3].w = 261;
		gSpriteLanzarJugador[3].h = 150;

		gSpriteLanzarJugador[4].x = 900;
		gSpriteLanzarJugador[4].y = 918;
		gSpriteLanzarJugador[4].w = 261;
		gSpriteLanzarJugador[4].h = 150;

		gSpriteLanzarJugador[5].x = 1230;
		gSpriteLanzarJugador[5].y = 918;
		gSpriteLanzarJugador[5].w = 261;
		gSpriteLanzarJugador[5].h = 150;

		gSpriteLanzarJugador[6].x = 1230;
		gSpriteLanzarJugador[6].y = 918;
		gSpriteLanzarJugador[6].w = 261;
		gSpriteLanzarJugador[6].h = 150;

		gSpriteLanzarJugador[7].x = 72;
		gSpriteLanzarJugador[7].y = 918;
		gSpriteLanzarJugador[7].w = 261;
		gSpriteLanzarJugador[7].h = 150;
}
void View_Jugador_CapAmerica::getSpritesPoderEspecial(){
	CANTSPRITECLIPPODER_especial = 7;
	MINFRAMEPODER_especial = 0;
	MAXFRAMEPODER_especial = 6;
	FACTORPODER_especial = 8;
	this->gSpritePoderEspecial = new SDL_Rect[CANTSPRITECLIPPODER_especial];

	gSpritePoderEspecial[0].x = 758;
	gSpritePoderEspecial[0].y = 1104;
	gSpritePoderEspecial[0].w = 261;
	gSpritePoderEspecial[0].h = 150;

}

