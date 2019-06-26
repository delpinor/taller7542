#include "View_Jugador_SpidermanBlack.h"

#include <sstream>
View_Jugador_SpidermanBlack::View_Jugador_SpidermanBlack() {

}

void View_Jugador_SpidermanBlack::initialize(Jugador *model,
		LTexture * texturaJugador) {
	this->texturaJugador = texturaJugador;
//	this->gSpriteGolpear = new SDL_Rect[CANTSPRITECLIP];
	this->jugador = model;
	getSpritesCaminar();
	getSpritesSaltar();
	getSpritesAgachar();
	getSpritesAnimacion();
	this->zIndex = model->get_zindex();
	getSpritesCambioPersonaje();
	texturaJugador->setColor(80, 140, 0);
}

