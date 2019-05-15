#include "View_Jugador_CapAmericaBlack.h"

#include <sstream>
View_Jugador_CapAmericaBlack::View_Jugador_CapAmericaBlack() {

}

void View_Jugador_CapAmericaBlack::initialize(Jugador *model,
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
