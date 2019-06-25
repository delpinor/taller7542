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

}
void View_Jugador_CapAmerica::getSpritesPatadaDebil(){
	CANTSPRITECLIPPATADITA = 5;
	this->gSpritePatadadebil = new SDL_Rect[CANTSPRITECLIPPATADITA];
	MAXFRAMEPATADITA=4;
	gSpritePatadadebil[0].x = 323;
	gSpritePatadadebil[0].y = 1297;
	gSpritePatadadebil[0].w = 261;
	gSpritePatadadebil[0].h = 150;

	gSpritePatadadebil[1].x = 113;
	gSpritePatadadebil[1].y = 1297;
	gSpritePatadadebil[1].w = 261;
	gSpritePatadadebil[1].h = 150;

	gSpritePatadadebil[2].x = 113;
	gSpritePatadadebil[2].y = 1297;
	gSpritePatadadebil[2].w = 261;
	gSpritePatadadebil[2].h = 150;

	gSpritePatadadebil[3].x = 113;
	gSpritePatadadebil[3].y = 1297;
	gSpritePatadadebil[3].w = 261;
	gSpritePatadadebil[3].h = 150;

	gSpritePatadadebil[4].x = 113;
	gSpritePatadadebil[4].y = 1297;
	gSpritePatadadebil[4].w = 261;
	gSpritePatadadebil[4].h = 150;







}
void View_Jugador_CapAmerica::getSpritesPinaFuerte(){
	CANTSPRITEPINAFUERTE = 8;
			this->gSpritePinaFuerte= new SDL_Rect[CANTSPRITEPINAFUERTE];
			MAXFRAMEPINAFUERTE=7;

			gSpritePinaFuerte[0].x = 72;
			gSpritePinaFuerte[0].y =  918;
			gSpritePinaFuerte[0].w = 261;
			gSpritePinaFuerte[0].h = 150;

			gSpritePinaFuerte[1].x = 320;
			gSpritePinaFuerte[1].y =  918;
			gSpritePinaFuerte[1].w = 261;
			gSpritePinaFuerte[1].h = 150;

			gSpritePinaFuerte[2].x = 600;
			gSpritePinaFuerte[2].y =  918;
			gSpritePinaFuerte[2].w = 261;
			gSpritePinaFuerte[2].h = 150;

			gSpritePinaFuerte[3].x = 900;
			gSpritePinaFuerte[3].y =  918;
			gSpritePinaFuerte[3].w = 261;
			gSpritePinaFuerte[3].h = 150;

			gSpritePinaFuerte[4].x = 900;
			gSpritePinaFuerte[4].y =  918;
			gSpritePinaFuerte[4].w = 261;
			gSpritePinaFuerte[4].h = 150;

			gSpritePinaFuerte[5].x = 1230;
			gSpritePinaFuerte[5].y =  918;
			gSpritePinaFuerte[5].w = 261;
			gSpritePinaFuerte[5].h = 150;

			gSpritePinaFuerte[6].x = 1230;
			gSpritePinaFuerte[6].y =  918;
			gSpritePinaFuerte[6].w = 261;
			gSpritePinaFuerte[6].h = 150;

			gSpritePinaFuerte[7].x = 72;
			gSpritePinaFuerte[7].y =  918;
			gSpritePinaFuerte[7].w = 261;
			gSpritePinaFuerte[7].h = 150;


}
void View_Jugador_CapAmerica::getSpritesPinaDebil(){

	CANTSPRITEPINADEBIL = 7;
		this->gSpritePinaDebil = new SDL_Rect[CANTSPRITEPINADEBIL];
		MAXFRAMEPINADEBIL=6;

		gSpritePinaDebil[0].x = 0;
		gSpritePinaDebil[0].y = 752;
		gSpritePinaDebil[0].w = 261;
		gSpritePinaDebil[0].h = 150;

		gSpritePinaDebil[1].x = 490;
		gSpritePinaDebil[1].y = 752;
		gSpritePinaDebil[1].w = 261;
		gSpritePinaDebil[1].h = 150;

		gSpritePinaDebil[2].x = 490;
		gSpritePinaDebil[2].y = 752;
		gSpritePinaDebil[2].w = 261;
		gSpritePinaDebil[2].h = 150;

		gSpritePinaDebil[3].x = 240;
		gSpritePinaDebil[3].y = 752;
		gSpritePinaDebil[3].w = 261;
		gSpritePinaDebil[3].h = 150;

		gSpritePinaDebil[4].x = 240;
		gSpritePinaDebil[4].y = 752;
		gSpritePinaDebil[4].w = 261;
		gSpritePinaDebil[4].h = 150;


		gSpritePinaDebil[5].x = 240;
		gSpritePinaDebil[5].y = 752;
		gSpritePinaDebil[5].w = 261;
		gSpritePinaDebil[5].h = 150;

		gSpritePinaDebil[6].x = 490;
		gSpritePinaDebil[6].y = 752;
		gSpritePinaDebil[6].w = 261;
		gSpritePinaDebil[6].h = 150;




}
void View_Jugador_CapAmerica::getSpritesDefensa(){

	CANTSPRITEDEFENSA = 8;
		this->gSpriteDefensa = new SDL_Rect[CANTSPRITEDEFENSA];
		MAXFRAMEDEFENSA=7;

		gSpriteDefensa [0].x = 0;
		gSpriteDefensa [0].y = 752;
		gSpriteDefensa [0].w = 261;
		gSpriteDefensa [0].h = 150;

		gSpriteDefensa [1].x = 0;
		gSpriteDefensa [1].y = 752;
		gSpriteDefensa [1].w = 261;
		gSpriteDefensa [1].h = 150;

		gSpriteDefensa [2].x = 0;
		gSpriteDefensa [2].y = 752;
		gSpriteDefensa [2].w = 261;
		gSpriteDefensa [2].h = 150;

		gSpriteDefensa [3].x = 0;
		gSpriteDefensa [3].y = 752;
		gSpriteDefensa [3].w = 261;
		gSpriteDefensa [3].h = 150;

		gSpriteDefensa [4].x = 0;
		gSpriteDefensa [4].y = 752;
		gSpriteDefensa [4].w = 261;
		gSpriteDefensa [4].h = 150;

		gSpriteDefensa [5].x = 0;
		gSpriteDefensa [5].y = 752;
		gSpriteDefensa [5].w = 261;
		gSpriteDefensa [5].h = 150;

		gSpriteDefensa [6].x = 0;
		gSpriteDefensa [6].y = 752;
		gSpriteDefensa [6].w = 261;
		gSpriteDefensa [6].h = 150;

		gSpriteDefensa [7].x = 0;
		gSpriteDefensa [7].y = 752;
		gSpriteDefensa [7].w = 261;
		gSpriteDefensa [7].h = 150;







}
void View_Jugador_CapAmerica::getSpritesPatadaFuerte_agachado(){
	CANTSPRITECLIPPATADON_agachado= 9;

		MAXFRAMEPATADON_agachado= 8;
		this->gSpritePatadadon_agachado = new SDL_Rect[CANTSPRITECLIPPATADON_agachado];

		gSpritePatadadon_agachado[0].x = 17;
		gSpritePatadadon_agachado[0].y = 363;
		gSpritePatadadon_agachado[0].w = 261;
		gSpritePatadadon_agachado[0].h = 150;

		gSpritePatadadon_agachado[1].x = 785;
		gSpritePatadadon_agachado[1].y = 1657;
		gSpritePatadadon_agachado[1].w = 261;
		gSpritePatadadon_agachado[1].h = 150;

		gSpritePatadadon_agachado[2].x = 1505;
		gSpritePatadadon_agachado[2].y = 1657;
		gSpritePatadadon_agachado[2].w = 261;
		gSpritePatadadon_agachado[2].h = 150;

		gSpritePatadadon_agachado[3].x = 1236;
		gSpritePatadadon_agachado[3].y = 1657;
		gSpritePatadadon_agachado[3].w = 261;
		gSpritePatadadon_agachado[3].h = 150;

		gSpritePatadadon_agachado[4].x = 1010;
		gSpritePatadadon_agachado[4].y = 1657;
		gSpritePatadadon_agachado[4].w = 261;
		gSpritePatadadon_agachado[4].h = 150;

		gSpritePatadadon_agachado[5].x = 785;
		gSpritePatadadon_agachado[5].y = 1657;
		gSpritePatadadon_agachado[5].w = 261;
		gSpritePatadadon_agachado[5].h = 150;

		gSpritePatadadon_agachado[6].x = 1505;
		gSpritePatadadon_agachado[6].y = 1657;
		gSpritePatadadon_agachado[6].w = 261;
		gSpritePatadadon_agachado[6].h = 150;

		gSpritePatadadon_agachado[7].x = 1236;
		gSpritePatadadon_agachado[7].y = 1657;
		gSpritePatadadon_agachado[7].w = 261;
		gSpritePatadadon_agachado[7].h = 150;

		gSpritePatadadon_agachado[8].x = 1010;
		gSpritePatadadon_agachado[8].y = 1657;
		gSpritePatadadon_agachado[8].w = 261;
		gSpritePatadadon_agachado[8].h = 150;



}
void View_Jugador_CapAmerica::getSpritesPatadaDebil_agachado(){
	CANTSPRITECLIPPATADITA_agachado= 6;
	this->gSpritePatadadebil_agachado = new SDL_Rect[CANTSPRITECLIPPATADITA_agachado];
	MAXFRAMEPATADITA_agachado = 5;


	gSpritePatadadebil_agachado[0].x = 17;
	gSpritePatadadebil_agachado[0].y = 363;
	gSpritePatadadebil_agachado[0].w = 261;
	gSpritePatadadebil_agachado[0].h = 150;

	gSpritePatadadebil_agachado[1].x = 900;
	gSpritePatadadebil_agachado[1].y = 587;
	gSpritePatadadebil_agachado[1].w = 261;
	gSpritePatadadebil_agachado[1].h = 150;

	gSpritePatadadebil_agachado[2].x = 900;
	gSpritePatadadebil_agachado[2].y = 587;
	gSpritePatadadebil_agachado[2].w = 261;
	gSpritePatadadebil_agachado[2].h = 150;

	gSpritePatadadebil_agachado[3].x = 900;
	gSpritePatadadebil_agachado[3].y = 587;
	gSpritePatadadebil_agachado[3].w = 261;
	gSpritePatadadebil_agachado[3].h = 150;

	gSpritePatadadebil_agachado[4].x = 900;
	gSpritePatadadebil_agachado[4].y = 587;
	gSpritePatadadebil_agachado[4].w = 261;
	gSpritePatadadebil_agachado[4].h = 150;

	gSpritePatadadebil_agachado[5].x = 17;
	gSpritePatadadebil_agachado[5].y = 363;
	gSpritePatadadebil_agachado[5].w = 261;
	gSpritePatadadebil_agachado[5].h = 150;


}
void View_Jugador_CapAmerica::getSpritesPinaFuerte_agachado(){
	CANTSPRITEPINAFUERTE_agachado= 9;
		this->gSpritePinaFuerte_agachado = new SDL_Rect[CANTSPRITEPINAFUERTE_agachado];
		MAXFRAMEPINAFUERTE_agachado= 8;


		gSpritePinaFuerte_agachado[0].x = 17;
		gSpritePinaFuerte_agachado[0].y = 363;
		gSpritePinaFuerte_agachado[0].w = 261;
		gSpritePinaFuerte_agachado[0].h = 150;

		gSpritePinaFuerte_agachado[1].x = 1150;
		gSpritePinaFuerte_agachado[1].y = 572;
		gSpritePinaFuerte_agachado[1].w = 261;
		gSpritePinaFuerte_agachado[1].h = 150;

		gSpritePinaFuerte_agachado[2].x = 1614;
		gSpritePinaFuerte_agachado[2].y = 572;
		gSpritePinaFuerte_agachado[2].w = 261;
		gSpritePinaFuerte_agachado[2].h = 150;

		gSpritePinaFuerte_agachado[3].x = 1857;
		gSpritePinaFuerte_agachado[3].y = 572;
		gSpritePinaFuerte_agachado[3].w = 261;
		gSpritePinaFuerte_agachado[3].h = 150;

		gSpritePinaFuerte_agachado[4].x = 1857;
		gSpritePinaFuerte_agachado[4].y = 572;
		gSpritePinaFuerte_agachado[4].w = 261;
		gSpritePinaFuerte_agachado[4].h = 150;

		gSpritePinaFuerte_agachado[5].x = 1857;
		gSpritePinaFuerte_agachado[5].y = 572;
		gSpritePinaFuerte_agachado[5].w = 261;
		gSpritePinaFuerte_agachado[5].h = 150;

		gSpritePinaFuerte_agachado[6].x = 1857;
		gSpritePinaFuerte_agachado[6].y = 572;
		gSpritePinaFuerte_agachado[6].w = 261;
		gSpritePinaFuerte_agachado[6].h = 150;

		gSpritePinaFuerte_agachado[7].x = 2105;
		gSpritePinaFuerte_agachado[7].y = 572;
		gSpritePinaFuerte_agachado[7].w = 261;
		gSpritePinaFuerte_agachado[7].h = 150;

		gSpritePinaFuerte_agachado[8].x = 17;
		gSpritePinaFuerte_agachado[8].y = 363;
		gSpritePinaFuerte_agachado[8].w = 261;
		gSpritePinaFuerte_agachado[8].h = 150;


}
void View_Jugador_CapAmerica::getSpritesPinaDebil_agachado(){

	CANTSPRITEPINADEBIL_agachado= 6;
			this->gSpritePinaDebil_agachado = new SDL_Rect[CANTSPRITEPINADEBIL_agachado];
			MAXFRAMEPINADEBIL_agachado= 5;

			gSpritePinaDebil_agachado [0].x = 17;
			gSpritePinaDebil_agachado [0].y = 363;
			gSpritePinaDebil_agachado [0].w = 261;
			gSpritePinaDebil_agachado [0].h = 150;

			gSpritePinaDebil_agachado [1].x = 1150;
			gSpritePinaDebil_agachado [1].y = 576;
			gSpritePinaDebil_agachado [1].w = 261;
			gSpritePinaDebil_agachado [1].h = 150;

			gSpritePinaDebil_agachado [2].x = 1150;
			gSpritePinaDebil_agachado [2].y = 576;
			gSpritePinaDebil_agachado [2].w = 261;
			gSpritePinaDebil_agachado [2].h = 150;

			gSpritePinaDebil_agachado [3].x = 1150;
			gSpritePinaDebil_agachado [3].y = 576;
			gSpritePinaDebil_agachado [3].w = 261;
			gSpritePinaDebil_agachado [3].h = 150;

			gSpritePinaDebil_agachado [4].x = 1150;
			gSpritePinaDebil_agachado [4].y = 576;
			gSpritePinaDebil_agachado [4].w = 261;
			gSpritePinaDebil_agachado [4].h = 150;

			gSpritePinaDebil_agachado [5].x = 17;
			gSpritePinaDebil_agachado [5].y = 363;
			gSpritePinaDebil_agachado [5].w = 261;
			gSpritePinaDebil_agachado [5].h = 150;



}
void View_Jugador_CapAmerica::getSpritesDefensa_agachado(){

}

void View_Jugador_CapAmerica::getSpritesCambioPersonaje() {

	this->gSpriteCambiarPersonaje = new SDL_Rect[1];

	gSpriteCambiarPersonaje[0].x = 97;
	gSpriteCambiarPersonaje[0].y = 581;
	gSpriteCambiarPersonaje[0].w = 100;
	gSpriteCambiarPersonaje[0].h = 163;
}
