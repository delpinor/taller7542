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
	getSpritesPatadaDebil();
	getSpritesPatadaDebilSaltando();
	getSpritesPatadaFuerteSaltando();
	getSpritesPatadaDebilAgachado();
	getSpritesPatadaFuerteAgachado();
	getSpritesPiniaDebil();
	getSpritesPiniaFuerte();
	getSpritesPinaFuerteSaltando();
	getSpritesPinaDebilSaltando();
	getSpritesPinaFuerteAgachado();
	getSpritesPinaDebilAgachado();
	getSpritesDefensa();
	getSpritesDefensaAgachado();
	getSpritesDefensaSaltando();
	getSpritesRecibirDanio();
	getSpritesPoder();
	getSpritesArrojando();
	getSpritesVolando();
	this->texturaJugador->setColor(this->jugador->getR(),  this->jugador->getG() , this->jugador->getB());

	this->sonido_salto=new EfectoSonido(1);
		this->sonido_ataque_pu=new EfectoSonido(1);
		this->sonido_defensa=new EfectoSonido(1);
		this->sonido_cambio=new EfectoSonido(1);
		this->sonido_danio=new EfectoSonido(1);
		this->sonido_ataque_patada=new EfectoSonido(1);


		this->sonido_ataque_patada->loadMedia("../Sonidos/chun_patada.wav");
		this->sonido_defensa->loadMedia("../Sonidos/chun_defensa.wav");
		this->sonido_danio->loadMedia("../Sonidos/chun_danio.wav");
		this->sonido_ataque_pu->loadMedia("../Sonidos/chun_punio.wav");
		this->sonido_salto->loadMedia("../Sonidos/salto_chun.wav");
		this->sonido_cambio->loadMedia("../Sonidos/cambio_chun.wav");

}
void  View_Jugador_ChunLi::reproducir_sonido_salto(){

		this->sonido_salto->reproducir_sonido();


}
void  View_Jugador_ChunLi::reproducir_sonido_cambio(){

		this->sonido_cambio->reproducir_sonido();


}
	void  View_Jugador_ChunLi::reproducir_sonido_ataque_pu(){

		this->sonido_ataque_pu->reproducir_sonido();


}
void   View_Jugador_ChunLi::reproducir_sonido_defensa(){

		this->sonido_defensa->reproducir_sonido();


}

void View_Jugador_ChunLi::reproducir_sonido_ataque_patada(){
	this->sonido_ataque_patada->reproducir_sonido();

}

void View_Jugador_ChunLi::reproducir_sonido_recibir_danio(){
	this->sonido_danio->reproducir_sonido();


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
	FACTORSALTA = 2;
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
	FACTORPATADON = 4;
	this->gSpritePatadon = new SDL_Rect[CANTSPRITECLIPPATADON];

	gSpritePatadon[0].x = 71;
	gSpritePatadon[0].y = 2271;
	gSpritePatadon[0].w = 261;
	gSpritePatadon[0].h = 150;

	gSpritePatadon[1].x = 313;
	gSpritePatadon[1].y = 2271;
	gSpritePatadon[1].w = 261;
	gSpritePatadon[1].h = 150;

	gSpritePatadon[2].x = 563;
	gSpritePatadon[2].y = 2271;
	gSpritePatadon[2].w = 261;
	gSpritePatadon[2].h = 150;

	gSpritePatadon[3].x = 810;
	gSpritePatadon[3].y = 2271;
	gSpritePatadon[3].w = 261;
	gSpritePatadon[3].h = 150;

	gSpritePatadon[4].x = 1035;
	gSpritePatadon[4].y = 2271;
	gSpritePatadon[4].w = 261;
	gSpritePatadon[4].h = 150;

	gSpritePatadon[5].x = 1283;
	gSpritePatadon[5].y = 2271;
	gSpritePatadon[5].w = 261;
	gSpritePatadon[5].h = 150;

	gSpritePatadon[6].x = 1513;
	gSpritePatadon[6].y = 2271;
	gSpritePatadon[6].w = 261;
	gSpritePatadon[6].h = 150;

	gSpritePatadon[7].x = 1782;
	gSpritePatadon[7].y = 2271;
	gSpritePatadon[7].w = 261;
	gSpritePatadon[7].h = 150;

	gSpritePatadon[8].x = 2078;
	gSpritePatadon[8].y = 2271;
	gSpritePatadon[8].w = 261;
	gSpritePatadon[8].h = 150;

	gSpritePatadon[9].x = 62;
	gSpritePatadon[9].y = 2496;
	gSpritePatadon[9].w = 261;
	gSpritePatadon[9].h = 150;

	gSpritePatadon[10].x = 326;
	gSpritePatadon[10].y = 2496;
	gSpritePatadon[10].w = 261;
	gSpritePatadon[10].h = 150;

	gSpritePatadon[11].x = 582;
	gSpritePatadon[11].y = 2496;
	gSpritePatadon[11].w = 261;
	gSpritePatadon[11].h = 150;

}

void View_Jugador_ChunLi::getSpritesPatadaDebil() {
	CANTSPRITECLIPPATADA = 9;
	MINFRAMEPATADA = 0;
	MAXFRAMEPATADA = 8;
	FACTORPATADA = 5;
	this->gSpritePatada = new SDL_Rect[CANTSPRITECLIPPATADA];

	gSpritePatada[0].x = 222;
	gSpritePatada[0].y = 950;
	gSpritePatada[0].w = 261;
	gSpritePatada[0].h = 150;

	gSpritePatada[1].x = 451;
	gSpritePatada[1].y = 950;
	gSpritePatada[1].w = 261;
	gSpritePatada[1].h = 150;

	gSpritePatada[2].x = 684;
	gSpritePatada[2].y = 950;
	gSpritePatada[2].w = 261;
	gSpritePatada[2].h = 150;

	gSpritePatada[3].x = 925;
	gSpritePatada[3].y = 950;
	gSpritePatada[3].w = 261;
	gSpritePatada[3].h = 150;

	gSpritePatada[4].x = 1163;
	gSpritePatada[4].y = 950;
	gSpritePatada[4].w = 261;
	gSpritePatada[4].h = 150;

	gSpritePatada[5].x = 1389;
	gSpritePatada[5].y = 950;
	gSpritePatada[5].w = 261;
	gSpritePatada[5].h = 150;

	gSpritePatada[6].x = 1623;
	gSpritePatada[6].y = 950;
	gSpritePatada[6].w = 261;
	gSpritePatada[6].h = 150;

	gSpritePatada[7].x = 1868;
	gSpritePatada[7].y = 950;
	gSpritePatada[7].w = 261;
	gSpritePatada[7].h = 150;

	gSpritePatada[8].x = 2110;
	gSpritePatada[8].y = 950;
	gSpritePatada[8].w = 261;
	gSpritePatada[8].h = 150;

}

void View_Jugador_ChunLi::getSpritesPatadaDebilSaltando() {
	CANTSPRITECLIPPATADASALTANDO = 3;
	MINFRAMEPATADASALTANDO = 0;
	MAXFRAMEPATADASALTANDO = 2;
	FACTORPATADASALTANDO = 2;
	this->gSpritePatadaSaltando = new SDL_Rect[CANTSPRITECLIPPATADASALTANDO];

	gSpritePatadaSaltando[0].x = 32;
	gSpritePatadaSaltando[0].y = 1626;
	gSpritePatadaSaltando[0].w = 261;
	gSpritePatadaSaltando[0].h = 150;

	gSpritePatadaSaltando[1].x = 288;
	gSpritePatadaSaltando[1].y = 1614;
	gSpritePatadaSaltando[1].w = 261;
	gSpritePatadaSaltando[1].h = 150;

	gSpritePatadaSaltando[2].x = 610;
	gSpritePatadaSaltando[2].y = 1620;
	gSpritePatadaSaltando[2].w = 261;
	gSpritePatadaSaltando[2].h = 150;

}

void View_Jugador_ChunLi::getSpritesPatadaFuerteSaltando() {
	CANTSPRITECLIPPATADONSALTANDO = 3;
	MINFRAMEPATADONSALTANDO = 0;
	MAXFRAMEPATADONSALTANDO = 2;
	FACTORPATADONSALTANDO = 2;
	this->gSpritePatadonSaltando = new SDL_Rect[CANTSPRITECLIPPATADONSALTANDO];

	gSpritePatadonSaltando[0].x = 9;
	gSpritePatadonSaltando[0].y = 585;
	gSpritePatadonSaltando[0].w = 261;
	gSpritePatadonSaltando[0].h = 150;

	gSpritePatadonSaltando[1].x = 199;
	gSpritePatadonSaltando[1].y = 585;
	gSpritePatadonSaltando[1].w = 261;
	gSpritePatadonSaltando[1].h = 150;

	gSpritePatadonSaltando[2].x = 436;
	gSpritePatadonSaltando[2].y = 585;
	gSpritePatadonSaltando[2].w = 261;
	gSpritePatadonSaltando[2].h = 150;

}

void View_Jugador_ChunLi::getSpritesPatadaDebilAgachado() {
	CANTSPRITECLIPPATADAAGACHADO = 3;
	MINFRAMEPATADAAGACHADO = 0;
	MAXFRAMEPATADAAGACHADO = 2;
	FACTORPATADAAGACHADO = 2;
	this->gSpritePatadaAgachado = new SDL_Rect[CANTSPRITECLIPPATADAAGACHADO];

	gSpritePatadaAgachado[0].x = 32;
	gSpritePatadaAgachado[0].y = 1626;
	gSpritePatadaAgachado[0].w = 261;
	gSpritePatadaAgachado[0].h = 150;

	gSpritePatadaAgachado[1].x = 288;
	gSpritePatadaAgachado[1].y = 1614;
	gSpritePatadaAgachado[1].w = 261;
	gSpritePatadaAgachado[1].h = 150;

	gSpritePatadaAgachado[2].x = 610;
	gSpritePatadaAgachado[2].y = 1620;
	gSpritePatadaAgachado[2].w = 261;
	gSpritePatadaAgachado[2].h = 150;

}

void View_Jugador_ChunLi::getSpritesPatadaFuerteAgachado() {
	CANTSPRITECLIPPATADONAGACHADO = 3;
	MINFRAMEPATADONAGACHADO = 0;
	MAXFRAMEPATADONAGACHADO = 2;
	FACTORPATADONAGACHADO = 2;
	this->gSpritePatadonAgachado = new SDL_Rect[CANTSPRITECLIPPATADONAGACHADO];

	gSpritePatadonAgachado[0].x = 9;
	gSpritePatadonAgachado[0].y = 585;
	gSpritePatadonAgachado[0].w = 261;
	gSpritePatadonAgachado[0].h = 150;

	gSpritePatadonAgachado[1].x = 199;
	gSpritePatadonAgachado[1].y = 585;
	gSpritePatadonAgachado[1].w = 261;
	gSpritePatadonAgachado[1].h = 150;

	gSpritePatadonAgachado[2].x = 436;
	gSpritePatadonAgachado[2].y = 585;
	gSpritePatadonAgachado[2].w = 261;
	gSpritePatadonAgachado[2].h = 150;

}

void View_Jugador_ChunLi::getSpritesPiniaDebil() {
	CANTSPRITECLIPPINIA = 5;
	MINFRAMEPINIA = 0;
	MAXFRAMEPINIA = 4;
	FACTORPINIA = 3;
	this->gSpritePinia = new SDL_Rect[CANTSPRITECLIPPINIA];

	gSpritePinia[0].x = 37;
	gSpritePinia[0].y = 1168;
	gSpritePinia[0].w = 261;
	gSpritePinia[0].h = 150;

	gSpritePinia[1].x = 299;
	gSpritePinia[1].y = 1168;
	gSpritePinia[1].w = 261;
	gSpritePinia[1].h = 150;

	gSpritePinia[2].x = 589;
	gSpritePinia[2].y = 1168;
	gSpritePinia[2].w = 261;
	gSpritePinia[2].h = 150;

	gSpritePinia[3].x = 881;
	gSpritePinia[3].y = 1168;
	gSpritePinia[3].w = 261;
	gSpritePinia[3].h = 150;

	gSpritePinia[4].x = 1193;
	gSpritePinia[4].y = 1168;
	gSpritePinia[4].w = 261;
	gSpritePinia[4].h = 150;

}

void View_Jugador_ChunLi::getSpritesPiniaFuerte() {
	CANTSPRITECLIPPINION = 5;
	MINFRAMEPINION = 0;
	MAXFRAMEPINION = 4;
	FACTORPINION = 3;
	this->gSpritePinion = new SDL_Rect[CANTSPRITECLIPPINION];

	gSpritePinion[0].x = 35;
	gSpritePinion[0].y = 1392;
	gSpritePinion[0].w = 261;
	gSpritePinion[0].h = 150;

	gSpritePinion[1].x = 332;
	gSpritePinion[1].y = 1392;
	gSpritePinion[1].w = 261;
	gSpritePinion[1].h = 150;

	gSpritePinion[2].x = 635;
	gSpritePinion[2].y = 1392;
	gSpritePinion[2].w = 261;
	gSpritePinion[2].h = 150;

	gSpritePinion[3].x = 958;
	gSpritePinion[3].y = 1392;
	gSpritePinion[3].w = 261;
	gSpritePinion[3].h = 150;

	gSpritePinion[4].x = 1280;
	gSpritePinion[4].y = 1392;
	gSpritePinion[4].w = 261;
	gSpritePinion[4].h = 150;

}
void View_Jugador_ChunLi::getSpritesPinaFuerteSaltando() {

	CANTSPRITECLIPPINIONSALTANDO = 3;
	MINFRAMEPINIONSALTANDO = 0;
	MAXFRAMEPINIONSALTANDO = 2;
	FACTORPINIONSALTANDO = 3;
	this->gSpritePinionSaltando = new SDL_Rect[CANTSPRITECLIPPINIONSALTANDO];

	gSpritePinionSaltando[0].x = 341;
	gSpritePinionSaltando[0].y = 1392;
	gSpritePinionSaltando[0].w = 261;
	gSpritePinionSaltando[0].h = 150;

	gSpritePinionSaltando[1].x = 656;
	gSpritePinionSaltando[1].y = 1392;
	gSpritePinionSaltando[1].w = 261;
	gSpritePinionSaltando[1].h = 150;

	gSpritePinionSaltando[2].x = 969;
	gSpritePinionSaltando[2].y = 1392;
	gSpritePinionSaltando[2].w = 261;
	gSpritePinionSaltando[2].h = 150;

}
void View_Jugador_ChunLi::getSpritesPinaDebilSaltando() {
	CANTSPRITECLIPPINIASALTANDO = 3;
	MINFRAMEPINIASALTANDO = 0;
	MAXFRAMEPINIASALTANDO = 2;
	FACTORPINIASALTANDO = 3;
	this->gSpritePiniaSaltando = new SDL_Rect[CANTSPRITECLIPPINIASALTANDO];

	gSpritePiniaSaltando[0].x = 35;
	gSpritePiniaSaltando[0].y = 1168;
	gSpritePiniaSaltando[0].w = 261;
	gSpritePiniaSaltando[0].h = 150;

	gSpritePiniaSaltando[1].x = 298;
	gSpritePiniaSaltando[1].y = 1168;
	gSpritePiniaSaltando[1].w = 261;
	gSpritePiniaSaltando[1].h = 150;

	gSpritePiniaSaltando[2].x = 1196;
	gSpritePiniaSaltando[2].y = 1168;
	gSpritePiniaSaltando[2].w = 261;
	gSpritePiniaSaltando[2].h = 150;

}
void View_Jugador_ChunLi::getSpritesPinaDebilAgachado() {

	CANTSPRITECLIPPINIAAGACHADO = 3;
	MINFRAMEPINIAAGACHADO = 0;
	MAXFRAMEPINIAAGACHADO = 2;
	FACTORPINIAAGACHADO = 3;
	this->gSpritePiniaAgachado = new SDL_Rect[CANTSPRITECLIPPINIAAGACHADO];

	gSpritePiniaAgachado[0].x = 35;
	gSpritePiniaAgachado[0].y = 1168;
	gSpritePiniaAgachado[0].w = 261;
	gSpritePiniaAgachado[0].h = 150;

	gSpritePiniaAgachado[1].x = 298;
	gSpritePiniaAgachado[1].y = 1168;
	gSpritePiniaAgachado[1].w = 261;
	gSpritePiniaAgachado[1].h = 150;

	gSpritePiniaAgachado[2].x = 1196;
	gSpritePiniaAgachado[2].y = 1168;
	gSpritePiniaAgachado[2].w = 261;
	gSpritePiniaAgachado[2].h = 150;

}
void View_Jugador_ChunLi::getSpritesPinaFuerteAgachado() {
	CANTSPRITECLIPPINIONAGACHADO = 3;
	MINFRAMEPINIONAGACHADO = 0;
	MAXFRAMEPINIONAGACHADO = 2;
	FACTORPINIONAGACHADO = 3;
	this->gSpritePinionAgachado = new SDL_Rect[CANTSPRITECLIPPINIONAGACHADO];

	gSpritePinionAgachado[0].x = 341;
	gSpritePinionAgachado[0].y = 1392;
	gSpritePinionAgachado[0].w = 261;
	gSpritePinionAgachado[0].h = 150;

	gSpritePinionAgachado[1].x = 656;
	gSpritePinionAgachado[1].y = 1392;
	gSpritePinionAgachado[1].w = 261;
	gSpritePinionAgachado[1].h = 150;

	gSpritePinionAgachado[2].x = 969;
	gSpritePinionAgachado[2].y = 1392;
	gSpritePinionAgachado[2].w = 261;
	gSpritePinionAgachado[2].h = 150;
}
void View_Jugador_ChunLi::getSpritesDefensa(){
	CANTSPRITECLIPDEFENSA = 1;
	MINFRAMEDEFENSA = 0;
	MAXFRAMEDEFENSA = 0;
	FACTORDEFENSA = 1;
	this->gSpriteDefensa = new SDL_Rect[CANTSPRITECLIPDEFENSA];

	gSpriteDefensa[0].x = 1842;
	gSpriteDefensa[0].y = 950;
	gSpriteDefensa[0].w = 261;
	gSpriteDefensa[0].h = 150;
}
void View_Jugador_ChunLi::getSpritesDefensaAgachado(){
	CANTSPRITECLIPDEFENSA = 1;
	MINFRAMEDEFENSA = 0;
	MAXFRAMEDEFENSA = 0;
	FACTORDEFENSA = 1;
	this->gSpriteDefensaAgachado= new SDL_Rect[CANTSPRITECLIPDEFENSA];

	gSpriteDefensaAgachado[0].x = 1842;
	gSpriteDefensaAgachado[0].y = 950;
	gSpriteDefensaAgachado[0].w = 261;
	gSpriteDefensaAgachado[0].h = 150;
}
void View_Jugador_ChunLi::getSpritesDefensaSaltando(){
	this->gSpriteDefensaSaltando = new SDL_Rect[1];
		gSpriteDefensaSaltando[0].x = 1842;
		gSpriteDefensaSaltando[0].y = 950;
		gSpriteDefensaSaltando[0].w = 261;
		gSpriteDefensaSaltando[0].h = 150;

}
void View_Jugador_ChunLi::getSpritesRecibirDanio() {
	this->gSpriteRecibirDanio = new SDL_Rect[1];

	gSpriteRecibirDanio[0].x = 315;
	gSpriteRecibirDanio[0].y = 2492;
	gSpriteRecibirDanio[0].w = 261;
	gSpriteRecibirDanio[0].h = 150;
}
void View_Jugador_ChunLi::getSpritesPoder(){
	CANTSPRITECLIPPODER = 7;
	MINFRAMEPODER = 0;
	MAXFRAMEPODER = 6;
	FACTORPODER = 3;
	this->gSpritePoder = new SDL_Rect[CANTSPRITECLIPPODER];

	gSpritePoder[0].x = 4;
	gSpritePoder[0].y = 384;
	gSpritePoder[0].w = 261;
	gSpritePoder[0].h = 150;

	gSpritePoder[1].x = 202;
	gSpritePoder[1].y = 384;
	gSpritePoder[1].w = 261;
	gSpritePoder[1].h = 150;

	gSpritePoder[2].x = 416;
	gSpritePoder[2].y = 384;
	gSpritePoder[2].w = 261;
	gSpritePoder[2].h = 150;

	gSpritePoder[3].x = 633;
	gSpritePoder[3].y = 384;
	gSpritePoder[3].w = 261;
	gSpritePoder[3].h = 150;

	gSpritePoder[4].x = 828;
	gSpritePoder[4].y = 384;
	gSpritePoder[4].w = 261;
	gSpritePoder[4].h = 150;

	gSpritePoder[5].x = 1073;
	gSpritePoder[5].y = 384;
	gSpritePoder[5].w = 261;
	gSpritePoder[5].h = 150;

	gSpritePoder[6].x = 1320;
	gSpritePoder[6].y = 384;
	gSpritePoder[6].w = 261;
	gSpritePoder[6].h = 150;
}

void View_Jugador_ChunLi::getSpritesArrojando(){
	CANTSPRITECLIPLANZARJUGADOR = 8;
	MINFRAMELANZARJUGADOR = 0;
	MAXFRAMELANZARJUGADOR = 7;
	FACTORLANZARJUGADOR = 3;
	this->gSpriteLanzarJugador = new SDL_Rect[CANTSPRITECLIPLANZARJUGADOR];

	gSpriteLanzarJugador[0].x = 4;
	gSpriteLanzarJugador[0].y = 384;
	gSpriteLanzarJugador[0].w = 261;
	gSpriteLanzarJugador[0].h = 150;

	gSpriteLanzarJugador[1].x = 202;
	gSpriteLanzarJugador[1].y = 384;
	gSpriteLanzarJugador[1].w = 261;
	gSpriteLanzarJugador[1].h = 150;

	gSpriteLanzarJugador[2].x = 416;
	gSpriteLanzarJugador[2].y = 384;
	gSpriteLanzarJugador[2].w = 261;
	gSpriteLanzarJugador[2].h = 150;

	gSpriteLanzarJugador[3].x = 633;
	gSpriteLanzarJugador[3].y = 384;
	gSpriteLanzarJugador[3].w = 261;
	gSpriteLanzarJugador[3].h = 150;

	gSpriteLanzarJugador[4].x = 828;
	gSpriteLanzarJugador[4].y = 384;
	gSpriteLanzarJugador[4].w = 261;
	gSpriteLanzarJugador[4].h = 150;

	gSpriteLanzarJugador[5].x = 1073;
	gSpriteLanzarJugador[5].y = 384;
	gSpriteLanzarJugador[5].w = 261;
	gSpriteLanzarJugador[5].h = 150;

	gSpriteLanzarJugador[6].x = 1320;
	gSpriteLanzarJugador[6].y = 384;
	gSpriteLanzarJugador[6].w = 261;
	gSpriteLanzarJugador[6].h = 150;
}

void View_Jugador_ChunLi::getSpritesVolando() {
	CANTSPRITECLIPJUGADORLANZADO = 9;
	MINFRAMEJUGADORLANZADO = 0;
	MAXFRAMEJUGADORLANZADO = 8;
	FACTORJUGADORLANZADO = 6;
	this->gSpriteJugadorLanzado = new SDL_Rect[CANTSPRITECLIPJUGADORLANZADO];

	gSpriteJugadorLanzado[0].x = 39;
	gSpriteJugadorLanzado[0].y = 2946;
	gSpriteJugadorLanzado[0].w = 261;
	gSpriteJugadorLanzado[0].h = 150;

	gSpriteJugadorLanzado[1].x = 316;
	gSpriteJugadorLanzado[1].y = 2946;
	gSpriteJugadorLanzado[1].w = 261;
	gSpriteJugadorLanzado[1].h = 150;

	gSpriteJugadorLanzado[2].x = 597;
	gSpriteJugadorLanzado[2].y = 2946;
	gSpriteJugadorLanzado[2].w = 261;
	gSpriteJugadorLanzado[2].h = 150;

	gSpriteJugadorLanzado[3].x = 841;
	gSpriteJugadorLanzado[3].y = 2946;
	gSpriteJugadorLanzado[3].w = 261;
	gSpriteJugadorLanzado[3].h = 150;

	gSpriteJugadorLanzado[4].x = 1120;
	gSpriteJugadorLanzado[4].y = 2946;
	gSpriteJugadorLanzado[4].w = 261;
	gSpriteJugadorLanzado[4].h = 150;

	gSpriteJugadorLanzado[5].x = 1378;
	gSpriteJugadorLanzado[5].y = 2946;
	gSpriteJugadorLanzado[5].w = 261;
	gSpriteJugadorLanzado[5].h = 150;

	gSpriteJugadorLanzado[6].x = 1733;
	gSpriteJugadorLanzado[6].y = 2946;
	gSpriteJugadorLanzado[6].w = 261;
	gSpriteJugadorLanzado[6].h = 150;

	gSpriteJugadorLanzado[7].x = 2053;
	gSpriteJugadorLanzado[7].y = 2946;
	gSpriteJugadorLanzado[7].w = 261;
	gSpriteJugadorLanzado[7].h = 150;

	gSpriteJugadorLanzado[8].x = 2079;
	gSpriteJugadorLanzado[8].y = 3121;
	gSpriteJugadorLanzado[8].w = 261;
	gSpriteJugadorLanzado[8].h = 150;
}

