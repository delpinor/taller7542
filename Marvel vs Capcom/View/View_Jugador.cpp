#include "View_Jugador.h"

#include <sstream>
View_Jugador::View_Jugador() {
}

void View_Jugador::initialize(Jugador * model, LTexture * texturaJugador) {
	this->texturaJugador = texturaJugador;
	this->jugador = model;
	this->zIndex = model->get_zindex();
}

void View_Jugador::render(int camX, int camY, SDL_Renderer * gRenderer) {
	SDL_Rect* currentClip;
	if(this->jugador->get_estado_desconexion()==false){
		//printf("No se pone gris la imagen!!!!\n");
		this->desgrisar_imagen();
	}else{
		printf("se pone gris la imagen!!!!\n");
		this->grisar_imagen();
	}
	if ((this->jugador->estado->getVelX() != 0)
			&& (this->jugador->estado->getVelY() == 0)) {


		if (frame / MAXFRAMECAMINA >= MAXFRAMECAMINA ) {
			frame = MINFRAMECAMINA;
		}
		currentClip = &gSpriteCaminar[frame / MAXFRAMECAMINA];
		++frame;
	}
	if (this->jugador->estado->getVelY() != 0) {
		if (this->jugador->estado->getVelY() >= 18) {
			frame = 0;
		}
		if (frame / MAXFRAMESALTA >= MAXFRAMESALTA) {
			frame = MINFRAMESALTA;
		}
		currentClip = &gSpriteSaltar[frame / MAXFRAMESALTA];
		++frame;
	}
	if ((this->jugador->estado->getVelY() == 0)
			&& (this->jugador->estado->getVelX() == 0)) {
		currentClip = &gSpriteAnimacion[frame / MAXFRAMEANIMACION];
		if (frame / MAXFRAMEANIMACION >= MAXFRAMEANIMACION ) {
			frame = MINFRAMEANIMACION;
		}
		++frame;
	}

	if (this->jugador->estaAgachado()){

		currentClip = &gSpriteAgachar[0];
	}
	if (this->jugador->estaCambiandoPersonaje())
		currentClip = &gSpriteCambiarPersonaje[0];
	if (this->jugador->estaActivo()) {
		this->texturaJugador->render(this->jugador->getPosX() - camX,
				this->jugador->getPosY() - camY, currentClip, 0, NULL,
				this->jugador->getDireccion(), gRenderer);
	}
}
void View_Jugador::grisar_imagen(){

	this->texturaJugador->setColor(55,55,55); //seto el color a gris

}
void View_Jugador::desgrisar_imagen(){

	this->texturaJugador->setColor(255,255,255); //seto el color a grisb

}
int View_Jugador::getZIndex() {
	return this->zIndex;
}

