#include "View_Jugador_Venom.h"

#include <sstream>
View_Jugador_Venom::View_Jugador_Venom() {

}

void View_Jugador_Venom::initialize(Jugador * model,
		LTexture * texturaJugador) {
	this->texturaJugador = texturaJugador;
	this->jugador = model;
	this->zIndex = model->get_zindex();
	getSpritesCaminar();
	getSpritesSaltar();
	getSpritesAgachar();
	getSpritesCambioPersonaje();
	getSpritesAnimacion();
	//Parado
	getSpritesPiniaDebil();
	getSpritesPiniaFuerte();
	getSpritesPatadaDebil();
	getSpritesPatadaFuerte();
	getSpritesDefensa();
	//Agachado
	getSpritesPiniaDebilAgachado();
	getSpritesPiniaFuerteAgachado();
	getSpritesPatadaDebilAgachado();
	getSpritesPatadaFuerteAgachado();
	getSpritesDefensaAgachado();
	//Saltando
	getSpritesPiniaDebilSaltando();
	getSpritesPiniaFuerteSaltando();
	getSpritesPatadaDebilSaltando();
	getSpritesPatadaFuerteSaltando();
	getSpritesDefensaSaltando();
	//Daño
	getSpritesRecibirDanio();

	getSpritesPoder();
	this->texturaJugador->setColor(this->jugador->getR(), this->jugador->getG(),
			this->jugador->getB());

	this->sonido_salto = new EfectoSonido(1);
	this->sonido_ataque_pu = new EfectoSonido(1);
	this->sonido_defensa = new EfectoSonido(1);
	this->sonido_cambio = new EfectoSonido(1);
	this->sonido_danio=new EfectoSonido(1);
	this->sonido_ataque_patada=new EfectoSonido(1);


	this->sonido_ataque_patada->loadMedia("../Sonidos/venom_patada.wav");
	this->sonido_defensa->loadMedia("../Sonidos/venom_defensa.wav");
	this->sonido_danio->loadMedia("../Sonidos/venom_danio.wav");

	this->sonido_ataque_pu->loadMedia("../Sonidos/venom_punio.wav");
	this->sonido_salto->loadMedia("../Sonidos/salto_venom.wav");
	this->sonido_cambio->loadMedia("../Sonidos/cambio_venom.wav");
}
void View_Jugador_Venom::reproducir_sonido_salto() {

	this->sonido_salto->reproducir_sonido();

}
void View_Jugador_Venom::reproducir_sonido_cambio() {

	this->sonido_cambio->reproducir_sonido();

}
void View_Jugador_Venom::reproducir_sonido_ataque_pu() {

	this->sonido_ataque_pu->reproducir_sonido();

}
void View_Jugador_Venom::reproducir_sonido_defensa() {

	this->sonido_defensa->reproducir_sonido();

}

void View_Jugador_Venom::reproducir_sonido_ataque_patada(){
	this->sonido_ataque_patada->reproducir_sonido();

}

void	View_Jugador_Venom::reproducir_sonido_recibir_danio(){
	this->sonido_danio->reproducir_sonido();


}


void View_Jugador_Venom::getSpritesAnimacion() {
	CANTSPRITEANIMACION = 13;
	MINFRAMEANIMACION = 0;
	MAXFRAMEANIMACION = 12;
	FACTORANIMACION = 12;
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
	FACTORCAMINA = 9;
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
	MAXFRAMESALTA = 3;
	FACTORSALTA = 5;
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
	FACTORPATADON = 9;
	this->gSpritePatadon = new SDL_Rect[CANTSPRITECLIPPATADON];

	gSpritePatadon[0].x = 24;
	gSpritePatadon[0].y = 2541;
	gSpritePatadon[0].w = 261;
	gSpritePatadon[0].h = 150;

	gSpritePatadon[1].x = 304;
	gSpritePatadon[1].y = 2541;
	gSpritePatadon[1].w = 261;
	gSpritePatadon[1].h = 150;

	gSpritePatadon[2].x = 601;
	gSpritePatadon[2].y = 2541;
	gSpritePatadon[2].w = 304;
	gSpritePatadon[2].h = 150;

	gSpritePatadon[3].x = 1020;
	gSpritePatadon[3].y = 2541;
	gSpritePatadon[3].w = 337;
	gSpritePatadon[3].h = 150;

	gSpritePatadon[4].x = 44;
	gSpritePatadon[4].y = 2799;
	gSpritePatadon[4].w = 321;
	gSpritePatadon[4].h = 150;

	gSpritePatadon[5].x = 425;
	gSpritePatadon[5].y = 2799;
	gSpritePatadon[5].w = 261;
	gSpritePatadon[5].h = 150;

	gSpritePatadon[6].x = 755;
	gSpritePatadon[6].y = 2799;
	gSpritePatadon[6].w = 261;
	gSpritePatadon[6].h = 150;

	gSpritePatadon[7].x = 1059;
	gSpritePatadon[7].y = 2799;
	gSpritePatadon[7].w = 261;
	gSpritePatadon[7].h = 150;

}

void View_Jugador_Venom::getSpritesPiniaDebil() {
	CANTSPRITECLIPPINIA = 5;
	MINFRAMEPINIA = 0;
	MAXFRAMEPINIA = 4;
	FACTORPINIA = 7;
	this->gSpritePinia = new SDL_Rect[CANTSPRITECLIPPINIA];

	gSpritePinia[0].x = 42;
	gSpritePinia[0].y = 441;
	gSpritePinia[0].w = 261;
	gSpritePinia[0].h = 150;
	// dif de 15
	gSpritePinia[1].x = 301;
	gSpritePinia[1].y = 441;
	gSpritePinia[1].w = 261;
	gSpritePinia[1].h = 150;

	gSpritePinia[2].x = 301;
	gSpritePinia[2].y = 441;
	gSpritePinia[2].w = 261;
	gSpritePinia[2].h = 150;

	gSpritePinia[3].x = 301;
	gSpritePinia[3].y = 441;
	gSpritePinia[3].w = 261;
	gSpritePinia[3].h = 150;

	gSpritePinia[4].x = 1193;
	gSpritePinia[4].y = 441;
	gSpritePinia[4].w = 261;
	gSpritePinia[4].h = 150;
}

//TODO: ver que problemas va a traer el alto que es bastante grande, en caso de que deforme bastante y traiga complicaciones
//usar como pinia fuerte el de patadaFuerte
void View_Jugador_Venom::getSpritesPiniaFuerte() {
	CANTSPRITECLIPPINION = 7;
	MINFRAMEPINION = 0;
	MAXFRAMEPINION = 6;
	FACTORPINION = 7;
	this->gSpritePinion = new SDL_Rect[CANTSPRITECLIPPINION];

	gSpritePinion[0].x = 58;
	gSpritePinion[0].y = 238;
	gSpritePinion[0].w = 261;
	gSpritePinion[0].h = 190;

	gSpritePinion[1].x = 315;
	gSpritePinion[1].y = 238;
	gSpritePinion[1].w = 261;
	gSpritePinion[1].h = 190;

	gSpritePinion[2].x = 579;
	gSpritePinion[2].y = 238;
	gSpritePinion[2].w = 261;
	gSpritePinion[2].h = 190;

	gSpritePinion[3].x = 870;
	gSpritePinion[3].y = 238;
	gSpritePinion[3].w = 261;
	gSpritePinion[3].h = 190;

	gSpritePinion[4].x = 1145;
	gSpritePinion[4].y = 238;
	gSpritePinion[4].w = 261;
	gSpritePinion[4].h = 190;

	gSpritePinion[5].x = 1400;
	gSpritePinion[5].y = 238;
	gSpritePinion[5].w = 261;
	gSpritePinion[5].h = 190;

	gSpritePinion[6].x = 1640;
	gSpritePinion[6].y = 238;
	gSpritePinion[6].w = 261;
	gSpritePinion[6].h = 190;
}

void View_Jugador_Venom::getSpritesPatadaDebil() {
	CANTSPRITECLIPPATADA = 4;
	MINFRAMEPATADA = 0;
	MAXFRAMEPATADA = 3;
	FACTORPATADA = 4;
	this->gSpritePatada = new SDL_Rect[CANTSPRITECLIPPATADA];

	gSpritePatada[0].x = 13;
	gSpritePatada[0].y = 3435;
	gSpritePatada[0].w = 261;
	gSpritePatada[0].h = 150;

	gSpritePatada[1].x = 321;
	gSpritePatada[1].y = 3435;
	gSpritePatada[1].w = 261;
	gSpritePatada[1].h = 150;

	gSpritePatada[2].x = 321;
	gSpritePatada[2].y = 3435;
	gSpritePatada[2].w = 261;
	gSpritePatada[2].h = 150;

	gSpritePatada[3].x = 895;
	gSpritePatada[3].y = 3435;
	gSpritePatada[3].w = 261;
	gSpritePatada[3].h = 150;
}

void View_Jugador_Venom::getSpritesPiniaDebilAgachado() {
	CANTSPRITECLIPPINIAAGACHADO = 4;
	MINFRAMEPINIAAGACHADO = 0;
	MAXFRAMEPINIAAGACHADO = 3;
	FACTORPINIAAGACHADO = 8;
	this->gSpritePiniaAgachado = new SDL_Rect[CANTSPRITECLIPPINIAAGACHADO];

	gSpritePiniaAgachado[0].x = 2;
	gSpritePiniaAgachado[0].y = 3579;
	gSpritePiniaAgachado[0].w = 261;
	gSpritePiniaAgachado[0].h = 150;

	gSpritePiniaAgachado[1].x = 290;
	gSpritePiniaAgachado[1].y = 3579;
	gSpritePiniaAgachado[1].w = 261;
	gSpritePiniaAgachado[1].h = 150;

	gSpritePiniaAgachado[2].x = 290;
	gSpritePiniaAgachado[2].y = 3579;
	gSpritePiniaAgachado[2].w = 261;
	gSpritePiniaAgachado[2].h = 150;

	gSpritePiniaAgachado[3].x = 907;
	gSpritePiniaAgachado[3].y = 3579;
	gSpritePiniaAgachado[3].w = 261;
	gSpritePiniaAgachado[3].h = 150;

}
void View_Jugador_Venom::getSpritesPiniaFuerteAgachado() {
	CANTSPRITECLIPPINIONAGACHADO = 8;
	MINFRAMEPINIONAGACHADO = 0;
	MAXFRAMEPINIONAGACHADO = 7;
	FACTORPINIONAGACHADO = 10;
	this->gSpritePinionAgachado = new SDL_Rect[CANTSPRITECLIPPINIONAGACHADO];

	gSpritePinionAgachado[0].x = 1;
	gSpritePinionAgachado[0].y = 3897;
	gSpritePinionAgachado[0].w = 261;
	gSpritePinionAgachado[0].h = 150;

	gSpritePinionAgachado[1].x = 263;
	gSpritePinionAgachado[1].y = 3893;
	gSpritePinionAgachado[1].w = 261;
	gSpritePinionAgachado[1].h = 150;

	gSpritePinionAgachado[2].x = 597;
	gSpritePinionAgachado[2].y = 3893;
	gSpritePinionAgachado[2].w = 261;
	gSpritePinionAgachado[2].h = 150;

	gSpritePinionAgachado[3].x = 963;
	gSpritePinionAgachado[3].y = 3893;
	gSpritePinionAgachado[3].w = 285;
	gSpritePinionAgachado[3].h = 150;

	gSpritePinionAgachado[4].x = 1350;
	gSpritePinionAgachado[4].y = 3893;
	gSpritePinionAgachado[4].w = 261;
	gSpritePinionAgachado[4].h = 150;

	gSpritePinionAgachado[5].x = 1665;
	gSpritePinionAgachado[5].y = 3893;
	gSpritePinionAgachado[5].w = 261;
	gSpritePinionAgachado[5].h = 150;

	gSpritePinionAgachado[6].x = 1935;
	gSpritePinionAgachado[6].y = 3893;
	gSpritePinionAgachado[6].w = 261;
	gSpritePinionAgachado[6].h = 150;

	gSpritePinionAgachado[7].x = 2135;
	gSpritePinionAgachado[7].y = 3893;
	gSpritePinionAgachado[7].w = 261;
	gSpritePinionAgachado[7].h = 150;
}
void View_Jugador_Venom::getSpritesPatadaDebilAgachado() {
	CANTSPRITECLIPPATADAAGACHADO = 4;
	MINFRAMEPATADAAGACHADO = 0;
	MAXFRAMEPATADAAGACHADO = 3;
	FACTORPATADAAGACHADO = 8;
	this->gSpritePatadaAgachado = new SDL_Rect[CANTSPRITECLIPPATADAAGACHADO];

	gSpritePatadaAgachado[0].x = 40;
	gSpritePatadaAgachado[0].y = 1680;
	gSpritePatadaAgachado[0].w = 261;
	gSpritePatadaAgachado[0].h = 150;

	gSpritePatadaAgachado[1].x = 315;
	gSpritePatadaAgachado[1].y = 1680;
	gSpritePatadaAgachado[1].w = 261;
	gSpritePatadaAgachado[1].h = 150;

	gSpritePatadaAgachado[2].x = 600;
	gSpritePatadaAgachado[2].y = 1680;
	gSpritePatadaAgachado[2].w = 261;
	gSpritePatadaAgachado[2].h = 150;

	gSpritePatadaAgachado[3].x = 928;
	gSpritePatadaAgachado[3].y = 1680;
	gSpritePatadaAgachado[3].w = 261;
	gSpritePatadaAgachado[3].h = 150;
}
void View_Jugador_Venom::getSpritesPatadaFuerteAgachado() {
	CANTSPRITECLIPPATADONAGACHADO = 8;
	MINFRAMEPATADONAGACHADO = 0;
	MAXFRAMEPATADONAGACHADO = 7;
	FACTORPATADONAGACHADO = 10;
	this->gSpritePatadonAgachado = new SDL_Rect[CANTSPRITECLIPPATADONAGACHADO];

	gSpritePatadonAgachado[0].x = 1;
	gSpritePatadonAgachado[0].y = 3897;
	gSpritePatadonAgachado[0].w = 261;
	gSpritePatadonAgachado[0].h = 150;

	gSpritePatadonAgachado[1].x = 263;
	gSpritePatadonAgachado[1].y = 3893;
	gSpritePatadonAgachado[1].w = 261;
	gSpritePatadonAgachado[1].h = 150;

	gSpritePatadonAgachado[2].x = 610;
	gSpritePatadonAgachado[2].y = 3893;
	gSpritePatadonAgachado[2].w = 261;
	gSpritePatadonAgachado[2].h = 150;

	gSpritePatadonAgachado[3].x = 963;
	gSpritePatadonAgachado[3].y = 3893;
	gSpritePatadonAgachado[3].w = 285;
	gSpritePatadonAgachado[3].h = 150;

	gSpritePatadonAgachado[4].x = 1355;
	gSpritePatadonAgachado[4].y = 3893;
	gSpritePatadonAgachado[4].w = 261;
	gSpritePatadonAgachado[4].h = 150;

	gSpritePatadonAgachado[5].x = 1675;
	gSpritePatadonAgachado[5].y = 3893;
	gSpritePatadonAgachado[5].w = 261;
	gSpritePatadonAgachado[5].h = 150;

	gSpritePatadonAgachado[6].x = 1935;
	gSpritePatadonAgachado[6].y = 3893;
	gSpritePatadonAgachado[6].w = 261;
	gSpritePatadonAgachado[6].h = 150;

	gSpritePatadonAgachado[7].x = 2135;
	gSpritePatadonAgachado[7].y = 3893;
	gSpritePatadonAgachado[7].w = 261;
	gSpritePatadonAgachado[7].h = 150;
}

void View_Jugador_Venom::getSpritesPiniaDebilSaltando() {
	CANTSPRITECLIPPINIASALTANDO = 5;
	MINFRAMEPINIASALTANDO = 0;
	MAXFRAMEPINIASALTANDO = 4;
	FACTORPINIASALTANDO = 7;
	this->gSpritePiniaSaltando = new SDL_Rect[CANTSPRITECLIPPINIASALTANDO];

	gSpritePiniaSaltando[0].x = 30;
	gSpritePiniaSaltando[0].y = 1059;
	gSpritePiniaSaltando[0].w = 261;
	gSpritePiniaSaltando[0].h = 150;

	gSpritePiniaSaltando[1].x = 325;
	gSpritePiniaSaltando[1].y = 1059;
	gSpritePiniaSaltando[1].w = 261;
	gSpritePiniaSaltando[1].h = 150;

	gSpritePiniaSaltando[2].x = 325;
	gSpritePiniaSaltando[2].y = 1059;
	gSpritePiniaSaltando[2].w = 261;
	gSpritePiniaSaltando[2].h = 150;

	gSpritePiniaSaltando[3].x = 573;
	gSpritePiniaSaltando[3].y = 1059;
	gSpritePiniaSaltando[3].w = 261;
	gSpritePiniaSaltando[3].h = 150;

	gSpritePiniaSaltando[4].x = 823;
	gSpritePiniaSaltando[4].y = 1059;
	gSpritePiniaSaltando[4].w = 261;
	gSpritePiniaSaltando[4].h = 150;
}
void View_Jugador_Venom::getSpritesPiniaFuerteSaltando() {
	CANTSPRITECLIPPINIONSALTANDO = 4;
	MINFRAMEPINIONSALTANDO = 0;
	MAXFRAMEPINIONSALTANDO = 3;
	FACTORPINIONSALTANDO = 5;
	this->gSpritePinionSaltando = new SDL_Rect[CANTSPRITECLIPPINIONSALTANDO];

	gSpritePinionSaltando[0].x = 25;
	gSpritePinionSaltando[0].y = 4057;
	gSpritePinionSaltando[0].w = 261;
	gSpritePinionSaltando[0].h = 150;

//	gSpritePinionSaltando[1].x = 225;
//	gSpritePinionSaltando[1].y = 4057;
//	gSpritePinionSaltando[1].w = 261;
//	gSpritePinionSaltando[1].h = 150;

//	gSpritePinionSaltando[2].x = 420;
//	gSpritePinionSaltando[2].y = 4057;
//	gSpritePinionSaltando[2].w = 261;
//	gSpritePinionSaltando[2].h = 150;

	gSpritePinionSaltando[1].x = 663;
	gSpritePinionSaltando[1].y = 4057;
	gSpritePinionSaltando[1].w = 261;
	gSpritePinionSaltando[1].h = 150;

	gSpritePinionSaltando[2].x = 663;
	gSpritePinionSaltando[2].y = 4057;
	gSpritePinionSaltando[2].w = 261;
	gSpritePinionSaltando[2].h = 150;

//	gSpritePinionSaltando[2].x = 965;
//	gSpritePinionSaltando[2].y = 4057;
//	gSpritePinionSaltando[2].w = 261;
//	gSpritePinionSaltando[2].h = 150;

//	gSpritePinionSaltando[3].x = 1245;
//	gSpritePinionSaltando[3].y = 4057;
//	gSpritePinionSaltando[3].w = 261;
//	gSpritePinionSaltando[3].h = 150;

	gSpritePinionSaltando[3].x = 1540;
	gSpritePinionSaltando[3].y = 4057;
	gSpritePinionSaltando[3].w = 261;
	gSpritePinionSaltando[3].h = 150;

//	gSpritePinionSaltando[5].x = 1835;
//	gSpritePinionSaltando[5].y = 4057;
//	gSpritePinionSaltando[5].w = 261;
//	gSpritePinionSaltando[5].h = 150;

//	gSpritePinionSaltando[8].x = 2068;
//	gSpritePinionSaltando[8].y = 4057;
//	gSpritePinionSaltando[8].w = 261;
//	gSpritePinionSaltando[8].h = 150;
//
//	gSpritePinionSaltando[9].x = 2275;
//	gSpritePinionSaltando[9].y = 4057;
//	gSpritePinionSaltando[9].w = 261;
//	gSpritePinionSaltando[9].h = 150;
//
//	gSpritePinionSaltando[10].x = 2508;
//	gSpritePinionSaltando[10].y = 4057;
//	gSpritePinionSaltando[10].w = 261;
//	gSpritePinionSaltando[10].h = 150;
}
void View_Jugador_Venom::getSpritesPatadaDebilSaltando() {
	CANTSPRITECLIPPATADASALTANDO = 5;
	MAXFRAMEPATADASALTANDO = 0;
	MINFRAMEPATADASALTANDO = 4;
	FACTORPATADASALTANDO = 7;
	this->gSpritePatadaSaltando = new SDL_Rect[CANTSPRITECLIPPATADASALTANDO];

	gSpritePatadaSaltando[0].x = 2;
	gSpritePatadaSaltando[0].y = 2325;
	gSpritePatadaSaltando[0].w = 261;
	gSpritePatadaSaltando[0].h = 150;

	gSpritePatadaSaltando[1].x = 308;
	gSpritePatadaSaltando[1].y = 2325;
	gSpritePatadaSaltando[1].w = 261;
	gSpritePatadaSaltando[1].h = 150;

	gSpritePatadaSaltando[2].x = 308;
	gSpritePatadaSaltando[2].y = 2325;
	gSpritePatadaSaltando[2].w = 261;
	gSpritePatadaSaltando[2].h = 150;

	gSpritePatadaSaltando[3].x = 308;
	gSpritePatadaSaltando[3].y = 2325;
	gSpritePatadaSaltando[3].w = 261;
	gSpritePatadaSaltando[3].h = 150;

	gSpritePatadaSaltando[4].x = 308;
	gSpritePatadaSaltando[4].y = 2325;
	gSpritePatadaSaltando[4].w = 261;
	gSpritePatadaSaltando[4].h = 150;

//	gSpritePatadaSaltando[4].x = 595;
//	gSpritePatadaSaltando[4].y = 2325;
//	gSpritePatadaSaltando[4].w = 261;
//	gSpritePatadaSaltando[4].h = 150;

//	gSpritePatadaSaltando[4].x = 885;
//	gSpritePatadaSaltando[4].y = 2325;
//	gSpritePatadaSaltando[4].w = 261;
//	gSpritePatadaSaltando[4].h = 150;
}
void View_Jugador_Venom::getSpritesPatadaFuerteSaltando() {
	CANTSPRITECLIPPATADONSALTANDO = 4;
	MINFRAMEPATADONSALTANDO = 0;
	MAXFRAMEPATADONSALTANDO = 3;
	FACTORPATADONSALTANDO = 5;
	this->gSpritePatadonSaltando = new SDL_Rect[CANTSPRITECLIPPATADONSALTANDO];

	gSpritePatadonSaltando[0].x = 25;
	gSpritePatadonSaltando[0].y = 4057;
	gSpritePatadonSaltando[0].w = 261;
	gSpritePatadonSaltando[0].h = 150;

	gSpritePatadonSaltando[1].x = 663;
	gSpritePatadonSaltando[1].y = 4057;
	gSpritePatadonSaltando[1].w = 261;
	gSpritePatadonSaltando[1].h = 150;

	gSpritePatadonSaltando[2].x = 663;
	gSpritePatadonSaltando[2].y = 4057;
	gSpritePatadonSaltando[2].w = 261;
	gSpritePatadonSaltando[2].h = 150;

	gSpritePatadonSaltando[3].x = 1540;
	gSpritePatadonSaltando[3].y = 4057;
	gSpritePatadonSaltando[3].w = 261;
	gSpritePatadonSaltando[3].h = 150;
}

void View_Jugador_Venom::getSpritesDefensa() {
	this->gSpriteDefensa = new SDL_Rect[1];

	gSpriteDefensa[0].x = 1360;
	gSpriteDefensa[0].y = 2984;
	gSpriteDefensa[0].w = 261;
	gSpriteDefensa[0].h = 170;
}

void View_Jugador_Venom::getSpritesDefensaSaltando() {
	this->gSpriteDefensaAgachado = new SDL_Rect[1];

	gSpriteDefensaAgachado[0].x = 1132;
	gSpriteDefensaAgachado[0].y = 2994;
	gSpriteDefensaAgachado[0].w = 261;
	gSpriteDefensaAgachado[0].h = 150;
}

void View_Jugador_Venom::getSpritesDefensaAgachado() {
	this->gSpriteDefensaSaltando = new SDL_Rect[1];

	gSpriteDefensaSaltando[0].x = 1132;
	gSpriteDefensaSaltando[0].y = 2994;
	gSpriteDefensaSaltando[0].w = 261;
	gSpriteDefensaSaltando[0].h = 150;
}

void View_Jugador_Venom::getSpritesRecibirDanio() {
	this->gSpriteRecibirDanio = new SDL_Rect[1];

	gSpriteRecibirDanio[0].x = 253;
	gSpriteRecibirDanio[0].y = 2995;
	gSpriteRecibirDanio[0].w = 261;
	gSpriteRecibirDanio[0].h = 170;
}

void View_Jugador_Venom::getSpritesPoder(){
	CANTSPRITECLIPPODER = 7;
	MINFRAMEPODER = 0;
	MAXFRAMEPODER = 6;
	FACTORPODER = 8;
	this->gSpritePoder = new SDL_Rect[CANTSPRITECLIPPODER];

	gSpritePoder[0].x = 59;
	gSpritePoder[0].y = 3983;
	gSpritePoder[0].w = 261;
	gSpritePoder[0].h = 150;

	gSpritePoder[1].x = 320;
	gSpritePoder[1].y = 3983;
	gSpritePoder[1].w = 261;
	gSpritePoder[1].h = 150;

	gSpritePoder[2].x = 581;
	gSpritePoder[2].y = 3983;
	gSpritePoder[2].w = 261;
	gSpritePoder[2].h = 150;

	gSpritePoder[3].x = 842;
	gSpritePoder[3].y = 3983;
	gSpritePoder[3].w = 261;
	gSpritePoder[3].h = 150;

	gSpritePoder[4].x = 1103;
	gSpritePoder[4].y = 3983;
	gSpritePoder[4].w = 261;
	gSpritePoder[4].h = 150;

	gSpritePoder[5].x = 1364;
	gSpritePoder[5].y = 3983;
	gSpritePoder[5].w = 261;
	gSpritePoder[5].h = 150;

	gSpritePoder[6].x = 1625;
	gSpritePoder[6].y = 3983;
	gSpritePoder[6].w = 261;
	gSpritePoder[6].h = 150;
}


