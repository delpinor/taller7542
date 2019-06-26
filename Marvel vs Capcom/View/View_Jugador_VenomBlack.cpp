#include "View_Jugador_VenomBlack.h"
#include "../Logger/Logger.h"
#include <sstream>
View_Jugador_VenomBlack::View_Jugador_VenomBlack() {

}

void View_Jugador_VenomBlack::initialize(Jugador * model, LTexture * texturaJugador) {
	this->texturaJugador = texturaJugador;
	texturaJugador->setColor(120,150,20);
//	this->gSpriteGolpear= new SDL_Rect [ CANTSPRITECLIP];
	this->jugador = model;
	this->zIndex = model->get_zindex();
	getSpritesCaminar();
	getSpritesSaltar();
	getSpritesAgachar();
	getSpritesCambioPersonaje();
	getSpritesAnimacion();
}
