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
	std::cout << "RENDERISZAAAAR!!!!!!!" << std::endl;
	if(this->jugador->get_estado_desconexion()==false){
		//printf("No se pone gris la imagen!!!!\n");
		this->desgrisar_imagen();
	}else{
		//printf("se pone gris la imagen!!!!\n");
		this->grisar_imagen();
	}
	if ((this->jugador->estado->getVelY() == 0) && !(this->jugador->estado->estaSaltando())) {
		std::cout << "tipoGolpe: " << this->jugador->getTipoGolpe() << std::endl;
		if (this->jugador->getTipoGolpe() == TIPO_GOLPE::GOLPE_PATADON){
			if (this->jugador->isIniciarGolpe()){
				std::cout << "se inicia la patada: " << std::endl;
				frame = 0;
				this->jugador->setIniciarGolpe(false);
			}
			std::cout << "frame pegando patadon: " << frame << std::endl;
			if (frame / FACTORPATADON <= MAXFRAMEPATADON ) {
				currentClip = &gSpritePatadadon[frame / FACTORPATADON];
				++frame;
			} else {
				std::cout << "golpe terminado" << std::endl;
				this->jugador->setTipoGolpe(TIPO_GOLPE::NADA);
			}
		} else if (this->jugador->estaAgachado()){
			currentClip = &gSpriteAgachar[0];
		} else if ((this->jugador->estado->getVelX() != 0)){

			if (frame / FACTORCAMINA > MAXFRAMECAMINA ) {
				frame = MINFRAMECAMINA;
			}
			std::cout << "frame CAMINAAAAAAA: " << frame << std::endl;
			currentClip = &gSpriteCaminar[frame / FACTORCAMINA];
			++frame;
		} else if ((this->jugador->estado->getVelX() == 0)) {
			if (frame / FACTORANIMACION > MAXFRAMEANIMACION ) {
				frame = MINFRAMEANIMACION;
			}
			currentClip = &gSpriteAnimacion[frame / FACTORANIMACION];
			++frame;
		}
	}else {
		if (this->jugador->estado->estaSaltando()) {
			if (this->jugador->estado->getVelY() >= 18) {
				frame = 0;
			}
			if (frame / FACTORSALTA > MAXFRAMESALTA) {
				frame = MINFRAMESALTA;
			}
			currentClip = &gSpriteSaltar[frame / FACTORSALTA];
			++frame;
		} else if (this->jugador->estaCambiandoPersonaje())
			currentClip = &gSpriteCambiarPersonaje[0];
		else
			currentClip = &gSpriteCambiarPersonaje[0];
		}

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
	this->texturaJugador->setColor(this->jugador->getR(),this->jugador->getG(),this->jugador->getB());

}
int View_Jugador::getZIndex() {
	return this->zIndex;
}

