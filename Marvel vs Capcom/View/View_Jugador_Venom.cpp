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
	CANTSPRITECLIPSALTA = 6;
	MINFRAMESALTA = 0;
	MAXFRAMESALTA = 5;

	this->gSpriteSaltar = new SDL_Rect[CANTSPRITECLIPSALTA];
	gSpriteSaltar[0].x = 24;
	gSpriteSaltar[0].y = 1924;
	gSpriteSaltar[0].w = 261;
	gSpriteSaltar[0].h = 150;

	gSpriteSaltar[1].x = 24;
	gSpriteSaltar[1].y = 1924;
	gSpriteSaltar[1].w = 261;
	gSpriteSaltar[1].h = 150;

	gSpriteSaltar[2].x = 559;
	gSpriteSaltar[2].y = 1928;
	gSpriteSaltar[2].w = 261;
	gSpriteSaltar[2].h = 150;

	gSpriteSaltar[3].x = 870;
	gSpriteSaltar[3].y = 1924;
	gSpriteSaltar[3].w = 261;
	gSpriteSaltar[3].h = 150;

	gSpriteSaltar[4].x = 870;
	gSpriteSaltar[4].y = 1936;
	gSpriteSaltar[4].w = 261;
	gSpriteSaltar[4].h = 150;

	gSpriteSaltar[5].x = 1137;
	gSpriteSaltar[5].y = 1921;
	gSpriteSaltar[5].w = 261;
	gSpriteSaltar[5].h = 150;
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

void View_Jugador_Venom::getSpritesPiniaDebil(){
	CANTSPRITEPINADEBIL = 5;
	MINFRAMEPINADEBIL = 0;
	MAXFRAMEPINADEBIL = 4;
	this->gSpritePinaDebil = new SDL_Rect[CANTSPRITEPINADEBIL];


	gSpritePinaDebil[0].x = 42;
	gSpritePinaDebil[0].y = 455;
	gSpritePinaDebil[0].w = 261;
	gSpritePinaDebil[0].h = 150;

	gSpritePinaDebil[1].x = 316;
	gSpritePinaDebil[1].y = 455;
	gSpritePinaDebil[1].w = 261;
	gSpritePinaDebil[1].h = 150;

	gSpritePinaDebil[2].x = 316;
	gSpritePinaDebil[2].y = 455;
	gSpritePinaDebil[2].w = 261;
	gSpritePinaDebil[2].h = 150;

	gSpritePinaDebil[3].x = 316;
	gSpritePinaDebil[3].y = 455;
	gSpritePinaDebil[3].w = 261;
	gSpritePinaDebil[3].h = 150;

	gSpritePinaDebil[3].x = 1208;
	gSpritePinaDebil[3].y = 455;
	gSpritePinaDebil[3].w = 261;
	gSpritePinaDebil[3].h = 150;
}

//TODO: ver que problemas va a traer el alto que es bastante grande, en caso de que deforme bastante y traiga complicaciones
//usar como pinia fuerte el de patadaFuerte
void View_Jugador_Venom::getSpritesPiniaFuerte(){
	CANTSPRITEPINAFUERTE = 7;
	MINFRAMEPINAFUERTE = 0;
	MAXFRAMEPINAFUERTE = 6;
	this->gSpritePinaFuerte = new SDL_Rect[CANTSPRITEPINAFUERTE];


	gSpritePinaFuerte[0].x = 58;
	gSpritePinaFuerte[0].y = 238;
	gSpritePinaFuerte[0].w = 261;
	gSpritePinaFuerte[0].h = 190;

	gSpritePinaFuerte[1].x = 315;
	gSpritePinaFuerte[1].y = 238;
	gSpritePinaFuerte[1].w = 261;
	gSpritePinaFuerte[1].h = 190;

	gSpritePinaFuerte[2].x = 579;
	gSpritePinaFuerte[2].y = 238;
	gSpritePinaFuerte[2].w = 261;
	gSpritePinaFuerte[2].h = 190;

	gSpritePinaFuerte[3].x = 870;
	gSpritePinaFuerte[3].y = 238;
	gSpritePinaFuerte[3].w = 261;
	gSpritePinaFuerte[3].h = 190;

	gSpritePinaFuerte[4].x = 1145;
	gSpritePinaFuerte[4].y = 238;
	gSpritePinaFuerte[4].w = 261;
	gSpritePinaFuerte[4].h = 190;

	gSpritePinaFuerte[5].x = 1400;
	gSpritePinaFuerte[5].y = 238;
	gSpritePinaFuerte[5].w = 261;
	gSpritePinaFuerte[5].h = 190;

	gSpritePinaFuerte[6].x = 1640;
	gSpritePinaFuerte[6].y = 238;
	gSpritePinaFuerte[6].w = 261;
	gSpritePinaFuerte[6].h = 190;
}

void View_Jugador_Venom::getSpritesPatadaDebil(){
	CANTSPRITECLIPPATADITA = 4;
	MINFRAMEPATADITA = 0;
	MAXFRAMEPATADITA = 3;
	this->gSpritePatadadebil = new SDL_Rect[CANTSPRITECLIPPATADITA];

	gSpritePatadadebil[0].x = 13;
	gSpritePatadadebil[0].y = 3435;
	gSpritePatadadebil[0].w = 261;
	gSpritePatadadebil[0].h = 150;

	gSpritePatadadebil[1].x = 321;
	gSpritePatadadebil[1].y = 3435;
	gSpritePatadadebil[1].w = 261;
	gSpritePatadadebil[1].h = 150;

	gSpritePatadadebil[2].x = 321;
	gSpritePatadadebil[2].y = 3435;
	gSpritePatadadebil[2].w = 261;
	gSpritePatadadebil[2].h = 150;

	gSpritePatadadebil[3].x = 895;
	gSpritePatadadebil[3].y = 3435;
	gSpritePatadadebil[3].w = 261;
	gSpritePatadadebil[3].h = 150;
}

void View_Jugador_Venom::getSpritesPiniaDebilAgachado(){
	CANTSPRITEPINADEBIL_agachado = 4;
	MINFRAMEPINADEBIL_agachado = 0;
	MAXFRAMEPINADEBIL_agachado = 3;
	this->gSpritePinaDebil_agachado = new SDL_Rect[CANTSPRITEPINADEBIL_agachado];

	gSpritePinaDebil_agachado[0].x = 2;
	gSpritePinaDebil_agachado[0].y = 3607;
	gSpritePinaDebil_agachado[0].w = 261;
	gSpritePinaDebil_agachado[0].h = 150;

	gSpritePinaDebil_agachado[1].x = 315;
	gSpritePinaDebil_agachado[1].y = 3607;
	gSpritePinaDebil_agachado[1].w = 261;
	gSpritePinaDebil_agachado[1].h = 150;

	gSpritePinaDebil_agachado[2].x = 315;
	gSpritePinaDebil_agachado[2].y = 3607;
	gSpritePinaDebil_agachado[2].w = 261;
	gSpritePinaDebil_agachado[2].h = 150;

	gSpritePinaDebil_agachado[3].x = 907;
	gSpritePinaDebil_agachado[3].y = 3607;
	gSpritePinaDebil_agachado[3].w = 261;
	gSpritePinaDebil_agachado[3].h = 150;

}
void View_Jugador_Venom::getSpritesPiniaFuerteAgachado(){
	CANTSPRITEPINAFUERTE_agachado = 8;
	MINFRAMEPINAFUERTE_agachado = 0;
	MAXFRAMEPINAFUERTE_agachado = 7;
	this->gSpritePinaFuerte_agachado = new SDL_Rect[CANTSPRITEPINAFUERTE_agachado];

	gSpritePinaFuerte_agachado[0].x = 1;
	gSpritePinaFuerte_agachado[0].y = 3897;
	gSpritePinaFuerte_agachado[0].w = 261;
	gSpritePinaFuerte_agachado[0].h = 150;

	gSpritePinaFuerte_agachado[1].x = 263;
	gSpritePinaFuerte_agachado[1].y = 3893;
	gSpritePinaFuerte_agachado[1].w = 261;
	gSpritePinaFuerte_agachado[1].h = 150;

	gSpritePinaFuerte_agachado[2].x = 610;
	gSpritePinaFuerte_agachado[2].y = 3893;
	gSpritePinaFuerte_agachado[2].w = 261;
	gSpritePinaFuerte_agachado[2].h = 150;

	gSpritePinaFuerte_agachado[3].x = 963;
	gSpritePinaFuerte_agachado[3].y = 3893;
	gSpritePinaFuerte_agachado[3].w = 285;
	gSpritePinaFuerte_agachado[3].h = 150;

	gSpritePinaFuerte_agachado[4].x = 1355;
	gSpritePinaFuerte_agachado[4].y = 3893;
	gSpritePinaFuerte_agachado[4].w = 261;
	gSpritePinaFuerte_agachado[4].h = 150;

	gSpritePinaFuerte_agachado[5].x = 1675;
	gSpritePinaFuerte_agachado[5].y = 3893;
	gSpritePinaFuerte_agachado[5].w = 261;
	gSpritePinaFuerte_agachado[5].h = 150;

	gSpritePinaFuerte_agachado[6].x = 1935;
	gSpritePinaFuerte_agachado[6].y = 3893;
	gSpritePinaFuerte_agachado[6].w = 261;
	gSpritePinaFuerte_agachado[6].h = 150;

	gSpritePinaFuerte_agachado[7].x = 2135;
	gSpritePinaFuerte_agachado[7].y = 3893;
	gSpritePinaFuerte_agachado[7].w = 261;
	gSpritePinaFuerte_agachado[7].h = 150;
}
void View_Jugador_Venom::getSpritesPatadaDebilAgachado(){
	CANTSPRITECLIPPATADITA_agachado = 4;
	MINFRAMEPATADITA_agachado = 0;
	MAXFRAMEPATADITA_agachado = 3;
	this->gSpritePatadadebil_agachado = new SDL_Rect[CANTSPRITECLIPPATADITA_agachado];

	gSpritePatadadebil_agachado[0].x = 40;
	gSpritePatadadebil_agachado[0].y = 1705;
	gSpritePatadadebil_agachado[0].w = 261;
	gSpritePatadadebil_agachado[0].h = 150;

	gSpritePatadadebil_agachado[1].x = 315;
	gSpritePatadadebil_agachado[1].y = 1705;
	gSpritePatadadebil_agachado[1].w = 261;
	gSpritePatadadebil_agachado[1].h = 150;

	gSpritePatadadebil_agachado[2].x = 600;
	gSpritePatadadebil_agachado[2].y = 1705;
	gSpritePatadadebil_agachado[2].w = 261;
	gSpritePatadadebil_agachado[2].h = 150;

	gSpritePatadadebil_agachado[3].x = 928;
	gSpritePatadadebil_agachado[3].y = 1705;
	gSpritePatadadebil_agachado[3].w = 261;
	gSpritePatadadebil_agachado[3].h = 150;
}
void View_Jugador_Venom::getSpritesPatadaFuerteAgachado(){
	CANTSPRITECLIPPATADON_agachado = 8;
	MINFRAMEPATADON_agachado = 0;
	MAXFRAMEPATADON_agachado = 7;
	this->gSpritePatadadon_agachado = new SDL_Rect[CANTSPRITECLIPPATADON_agachado];

	gSpritePatadadon_agachado[0].x = 1;
	gSpritePatadadon_agachado[0].y = 3897;
	gSpritePatadadon_agachado[0].w = 261;
	gSpritePatadadon_agachado[0].h = 150;

	gSpritePatadadon_agachado[1].x = 263;
	gSpritePatadadon_agachado[1].y = 3893;
	gSpritePatadadon_agachado[1].w = 261;
	gSpritePatadadon_agachado[1].h = 150;

	gSpritePatadadon_agachado[2].x = 610;
	gSpritePatadadon_agachado[2].y = 3893;
	gSpritePatadadon_agachado[2].w = 261;
	gSpritePatadadon_agachado[2].h = 150;

	gSpritePatadadon_agachado[3].x = 963;
	gSpritePatadadon_agachado[3].y = 3893;
	gSpritePatadadon_agachado[3].w = 285;
	gSpritePatadadon_agachado[3].h = 150;

	gSpritePatadadon_agachado[4].x = 1355;
	gSpritePatadadon_agachado[4].y = 3893;
	gSpritePatadadon_agachado[4].w = 261;
	gSpritePatadadon_agachado[4].h = 150;

	gSpritePatadadon_agachado[5].x = 1675;
	gSpritePatadadon_agachado[5].y = 3893;
	gSpritePatadadon_agachado[5].w = 261;
	gSpritePatadadon_agachado[5].h = 150;

	gSpritePatadadon_agachado[6].x = 1935;
	gSpritePatadadon_agachado[6].y = 3893;
	gSpritePatadadon_agachado[6].w = 261;
	gSpritePatadadon_agachado[6].h = 150;

	gSpritePatadadon_agachado[7].x = 2135;
	gSpritePatadadon_agachado[7].y = 3893;
	gSpritePatadadon_agachado[7].w = 261;
	gSpritePatadadon_agachado[7].h = 150;
}

void View_Jugador_Venom::getSpritesPiniaDebilSaltando(){
	CANTSPRITEPINADEBIL_saltando = 4;
	MINFRAMEPATADON_saltando = 0;
	MAXFRAMEPATADON_saltando = 3;
	this->gSpritePinaDebil_saltando = new SDL_Rect[CANTSPRITEPINADEBIL_saltando];

	gSpritePinaDebil_saltando[0].x = 30;
	gSpritePinaDebil_saltando[0].y = 1059;
	gSpritePinaDebil_saltando[0].w = 261;
	gSpritePinaDebil_saltando[0].h = 150;

	gSpritePinaDebil_saltando[1].x = 325;
	gSpritePinaDebil_saltando[1].y = 1059;
	gSpritePinaDebil_saltando[1].w = 261;
	gSpritePinaDebil_saltando[1].h = 150;

	gSpritePinaDebil_saltando[2].x = 573;
	gSpritePinaDebil_saltando[2].y = 1059;
	gSpritePinaDebil_saltando[2].w = 261;
	gSpritePinaDebil_saltando[2].h = 150;

	gSpritePinaDebil_saltando[3].x = 823;
	gSpritePinaDebil_saltando[3].y = 1059;
	gSpritePinaDebil_saltando[3].w = 261;
	gSpritePinaDebil_saltando[3].h = 150;
}
void View_Jugador_Venom::getSpritesPiniaFuerteSaltando(){
	CANTSPRITEPINAFUERTE_saltando = 11;
	MINFRAMEPATADON_saltando = 0;
	MAXFRAMEPATADON_saltando = 10;
	this->gSpritePinaFuerte_saltando = new SDL_Rect[CANTSPRITEPINAFUERTE_saltando];

	gSpritePinaFuerte_saltando[0].x = 25;
	gSpritePinaFuerte_saltando[0].y = 4057;
	gSpritePinaFuerte_saltando[0].w = 261;
	gSpritePinaFuerte_saltando[0].h = 150;

	gSpritePinaFuerte_saltando[1].x = 225;
	gSpritePinaFuerte_saltando[1].y = 4057;
	gSpritePinaFuerte_saltando[1].w = 261;
	gSpritePinaFuerte_saltando[1].h = 150;

	gSpritePinaFuerte_saltando[2].x = 420;
	gSpritePinaFuerte_saltando[2].y = 4057;
	gSpritePinaFuerte_saltando[2].w = 261;
	gSpritePinaFuerte_saltando[2].h = 150;

	gSpritePinaFuerte_saltando[3].x = 663;
	gSpritePinaFuerte_saltando[3].y = 4057;
	gSpritePinaFuerte_saltando[3].w = 261;
	gSpritePinaFuerte_saltando[3].h = 150;

	gSpritePinaFuerte_saltando[4].x = 965;
	gSpritePinaFuerte_saltando[4].y = 4057;
	gSpritePinaFuerte_saltando[4].w = 261;
	gSpritePinaFuerte_saltando[4].h = 150;

	gSpritePinaFuerte_saltando[5].x = 1245;
	gSpritePinaFuerte_saltando[5].y = 4057;
	gSpritePinaFuerte_saltando[5].w = 261;
	gSpritePinaFuerte_saltando[5].h = 150;

	gSpritePinaFuerte_saltando[6].x = 1540;
	gSpritePinaFuerte_saltando[6].y = 4057;
	gSpritePinaFuerte_saltando[6].w = 261;
	gSpritePinaFuerte_saltando[6].h = 150;

	gSpritePinaFuerte_saltando[7].x = 1835;
	gSpritePinaFuerte_saltando[7].y = 4057;
	gSpritePinaFuerte_saltando[7].w = 261;
	gSpritePinaFuerte_saltando[7].h = 150;

	gSpritePinaFuerte_saltando[8].x = 2068;
	gSpritePinaFuerte_saltando[8].y = 4057;
	gSpritePinaFuerte_saltando[8].w = 261;
	gSpritePinaFuerte_saltando[8].h = 150;

	gSpritePinaFuerte_saltando[9].x = 2275;
	gSpritePinaFuerte_saltando[9].y = 4057;
	gSpritePinaFuerte_saltando[9].w = 261;
	gSpritePinaFuerte_saltando[9].h = 150;

	gSpritePinaFuerte_saltando[10].x = 2508;
	gSpritePinaFuerte_saltando[10].y = 4057;
	gSpritePinaFuerte_saltando[10].w = 261;
	gSpritePinaFuerte_saltando[10].h = 150;
}
void View_Jugador_Venom::getSpritesPatadaDebilSaltando(){
	CANTSPRITECLIPPATADITA_saltando = 4;
	MINFRAMEPATADON_saltando = 0;
	MAXFRAMEPATADON_saltando = 3;
	this->gSpritePatadadebil_saltando = new SDL_Rect[CANTSPRITECLIPPATADITA_saltando];

	gSpritePatadadebil_saltando[0].x = 5;
	gSpritePatadadebil_saltando[0].y = 2325;
	gSpritePatadadebil_saltando[0].w = 261;
	gSpritePatadadebil_saltando[0].h = 150;

	gSpritePatadadebil_saltando[1].x = 308;
	gSpritePatadadebil_saltando[1].y = 2325;
	gSpritePatadadebil_saltando[1].w = 261;
	gSpritePatadadebil_saltando[1].h = 150;

	gSpritePatadadebil_saltando[2].x = 595;
	gSpritePatadadebil_saltando[2].y = 2325;
	gSpritePatadadebil_saltando[2].w = 261;
	gSpritePatadadebil_saltando[2].h = 150;

	gSpritePatadadebil_saltando[3].x = 885;
	gSpritePatadadebil_saltando[3].y = 2325;
	gSpritePatadadebil_saltando[3].w = 261;
	gSpritePatadadebil_saltando[3].h = 150;
}
void View_Jugador_Venom::getSpritesPatadaFuerteSaltando(){
	CANTSPRITECLIPPATADON_saltando = 11;
	MINFRAMEPATADON_saltando = 0;
	MAXFRAMEPATADON_saltando = 10;
	this->gSpritePatadadon_saltando = new SDL_Rect[CANTSPRITECLIPPATADON_saltando];

	gSpritePatadadon_saltando[0].x = 25;
	gSpritePatadadon_saltando[0].y = 4057;
	gSpritePatadadon_saltando[0].w = 261;
	gSpritePatadadon_saltando[0].h = 150;

	gSpritePatadadon_saltando[1].x = 225;
	gSpritePatadadon_saltando[1].y = 4057;
	gSpritePatadadon_saltando[1].w = 261;
	gSpritePatadadon_saltando[1].h = 150;

	gSpritePatadadon_saltando[2].x = 420;
	gSpritePatadadon_saltando[2].y = 4057;
	gSpritePatadadon_saltando[2].w = 261;
	gSpritePatadadon_saltando[2].h = 150;

	gSpritePatadadon_saltando[3].x = 663;
	gSpritePatadadon_saltando[3].y = 4057;
	gSpritePatadadon_saltando[3].w = 261;
	gSpritePatadadon_saltando[3].h = 150;

	gSpritePatadadon_saltando[4].x = 965;
	gSpritePatadadon_saltando[4].y = 4057;
	gSpritePatadadon_saltando[4].w = 261;
	gSpritePatadadon_saltando[4].h = 150;

	gSpritePatadadon_saltando[5].x = 1245;
	gSpritePatadadon_saltando[5].y = 4057;
	gSpritePatadadon_saltando[5].w = 261;
	gSpritePatadadon_saltando[5].h = 150;

	gSpritePatadadon_saltando[6].x = 1540;
	gSpritePatadadon_saltando[6].y = 4057;
	gSpritePatadadon_saltando[6].w = 261;
	gSpritePatadadon_saltando[6].h = 150;

	gSpritePatadadon_saltando[7].x = 1835;
	gSpritePatadadon_saltando[7].y = 4057;
	gSpritePatadadon_saltando[7].w = 261;
	gSpritePatadadon_saltando[7].h = 150;

	gSpritePatadadon_saltando[8].x = 2068;
	gSpritePatadadon_saltando[8].y = 4057;
	gSpritePatadadon_saltando[8].w = 261;
	gSpritePatadadon_saltando[8].h = 150;

	gSpritePatadadon_saltando[9].x = 2275;
	gSpritePatadadon_saltando[9].y = 4057;
	gSpritePatadadon_saltando[9].w = 261;
	gSpritePatadadon_saltando[9].h = 150;

	gSpritePatadadon_saltando[10].x = 2508;
	gSpritePatadadon_saltando[10].y = 4057;
	gSpritePatadadon_saltando[10].w = 261;
	gSpritePatadadon_saltando[10].h = 150;

}

void View_Jugador_Venom::getSpritesDefensa(){
	this->gSpriteDefensa = new SDL_Rect[1];
	gSpriteDefensa[0].x = 695;
	gSpriteDefensa[0].y = 3028;
	gSpriteDefensa[0].w = 261;
	gSpriteDefensa[0].h = 150;
}

void View_Jugador_Venom::getSpritesDefensaSaltando(){
	this->gSpriteDefensa_agachado = new SDL_Rect[1];
	gSpriteDefensa_agachado[0].x = 368;
	gSpriteDefensa_agachado[0].y = 3045;
	gSpriteDefensa_agachado[0].w = 261;
	gSpriteDefensa_agachado[0].h = 150;
}

void View_Jugador_Venom::getSpritesDefensaAgachado(){
	this->gSpriteDefensa_saltando = new SDL_Rect[1];
	gSpriteDefensa_saltando[0].x = 53;
	gSpriteDefensa_saltando[0].y = 3040;
	gSpriteDefensa_saltando[0].w = 261;
	gSpriteDefensa_saltando[0].h = 150;
}

View_Jugador_Venom::~View_Jugador_Venom() {
}

