#include "View_Jugador_ChunLiBlack.h"

#include <sstream>
View_Jugador_ChunLiBlack::View_Jugador_ChunLiBlack() {

}

void View_Jugador_ChunLiBlack::initialize(Jugador *model, // @suppress("Member declaration not found")
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
	texturaJugador->setColor(80, 140, 0);
}

