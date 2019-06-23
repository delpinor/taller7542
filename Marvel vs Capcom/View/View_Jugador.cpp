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
		//printf("se pone gris la imagen!!!!\n");
		this->grisar_imagen();
	}
	if ((this->jugador->estado->getVelY() == 0)
			&& !(this->jugador->estado->estaSaltando())) {
		std::cout << "tipoGolpe: " << this->jugador->getTipoGolpe()
				<< std::endl;
		if (this->jugador->estaAgachado()) {
			if (this->jugador->getTipoGolpe() != TIPO_GOLPE::NADA) {
				if (this->jugador->isIniciarGolpe()) {
					std::cout << "se inicia la patada: " << std::endl;
					frame = 0;
					this->jugador->setIniciarGolpe(false);
				}
				if (this->jugador->getTipoGolpe() == TIPO_GOLPE::GOLPE_PATADON) {
					gSpriteGolpear = gSpritePatadonAgachado;
					maxFrame = MAXFRAMEPATADONAGACHADO;
					factor = FACTORPATADONAGACHADO;
					std::cout << "PATADON parado" << std::endl;
				} else if (this->jugador->getTipoGolpe() == TIPO_GOLPE::GOLPE_PATADA) {
					gSpriteGolpear = gSpritePatadaAgachado;
					maxFrame = MAXFRAMEPATADAAGACHADO;
					factor = FACTORPATADAAGACHADO;
					std::cout << "patada saltando" << std::endl;
				}
				if (frame / factor <= maxFrame) {
					currentClip = &gSpriteGolpear[frame / factor];
					++frame;
				} else {
					std::cout << "golpe terminado" << std::endl;
					this->jugador->setTipoGolpe(TIPO_GOLPE::NADA);
				}
			} else
				currentClip = &gSpriteAgachar[0];
		} else if (this->jugador->getTipoGolpe() != TIPO_GOLPE::NADA) {
			if (this->jugador->isIniciarGolpe()) {
				std::cout << "se inicia la patada: " << std::endl;
				frame = 0;
				this->jugador->setIniciarGolpe(false);
			}
			if (this->jugador->getTipoGolpe() == TIPO_GOLPE::GOLPE_PATADON) {
				gSpriteGolpear = gSpritePatadon;
				maxFrame = MAXFRAMEPATADON;
				factor = FACTORPATADON;
				std::cout << "PATADON parado" << std::endl;
			} else if (this->jugador->getTipoGolpe() == TIPO_GOLPE::GOLPE_PATADA) {
				gSpriteGolpear = gSpritePatada;
				maxFrame = MAXFRAMEPATADA;
				factor = FACTORPATADA;
				std::cout << "patada parado" << std::endl;
			}
			if (frame / factor <= maxFrame) {
				currentClip = &gSpriteGolpear[frame / factor];
				++frame;
			} else {
				std::cout << "golpe terminado" << std::endl;
				this->jugador->setTipoGolpe(TIPO_GOLPE::NADA);
			}

		} else if ((this->jugador->estado->getVelX() != 0)) {

			if (frame / FACTORCAMINA > MAXFRAMECAMINA) {
				frame = MINFRAMECAMINA;
			}
			currentClip = &gSpriteCaminar[frame / FACTORCAMINA];
			++frame;
		} else if ((this->jugador->estado->getVelX() == 0)) {
			if (frame / FACTORANIMACION > MAXFRAMEANIMACION) {
				frame = MINFRAMEANIMACION;
			}
			currentClip = &gSpriteAnimacion[frame / FACTORANIMACION];
			++frame;
		}
	}else {
		if (this->jugador->estado->estaSaltando()) {
			if (this->jugador->getTipoGolpe() != TIPO_GOLPE::NADA) {
				if (this->jugador->isIniciarGolpe()) {
					std::cout << "se inicia la patada: " << std::endl;
					frame = 0;
					this->jugador->setIniciarGolpe(false);
				}
				if (this->jugador->getTipoGolpe() == TIPO_GOLPE::GOLPE_PATADON){
					gSpriteGolpear = gSpritePatadonSaltando;
					maxFrame = MAXFRAMEPATADONSALTANDO;
					factor = FACTORPATADONSALTANDO;
					std::cout << "PATADON parado" << std::endl;
				} else if (this->jugador->getTipoGolpe() == TIPO_GOLPE::GOLPE_PATADA) {
					gSpriteGolpear = gSpritePatadaSaltando;
					maxFrame = MAXFRAMEPATADASALTANDO;
					factor = FACTORPATADASALTANDO;
					std::cout << "patada saltando" << std::endl;
				}
				if (frame / factor <= maxFrame) {
					currentClip = &gSpriteGolpear[frame / factor];
					++frame;
				} else {
					std::cout << "golpe terminado" << std::endl;
					this->jugador->setTipoGolpe(TIPO_GOLPE::NADA);
				}
			} else {
				if (this->jugador->estado->getVelY() >= 18) {
					frame = 0;
				}
				if (frame / FACTORSALTA > MAXFRAMESALTA) {
					frame = MINFRAMESALTA;
				}
				currentClip = &gSpriteSaltar[frame / FACTORSALTA];
				++frame;
			}
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

void View_Jugador::getSpriteByGolpe(SDL_Rect* currentClip, int &frame, TIPO_GOLPE tipoGolpe){
	switch (tipoGolpe){
	case TIPO_GOLPE::GOLPE_PATADON:
		if (frame / FACTORPATADON <= MAXFRAMEPATADON ){
			currentClip = &gSpritePatadon[frame / FACTORPATADON];
			++frame;
		} else
			frame = 0;
		break;
	case TIPO_GOLPE::GOLPE_PATADA:
		if (frame / FACTORPATADA <= MAXFRAMEPATADA ){
			currentClip = &gSpritePatada[frame / FACTORPATADA];
			++frame;
		} else
			frame = 0;
		break;
	case TIPO_GOLPE::GOLPE_PINION:
//		return &gSpritePinion[frame / FACTORPATADON];
		break;
	case TIPO_GOLPE::GOLPE_PINIA:
//		return &gSpritePinia[frame / FACTORPATADA];
		break;
	}
}
