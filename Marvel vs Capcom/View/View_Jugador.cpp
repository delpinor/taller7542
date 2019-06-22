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
	if ((this->jugador->estado->getVelY() == 0)) {
		std::cout << "tipoGolpe: " << this->jugador->getTipoGolpe() << std::endl;
		if (this->jugador->getTipoGolpe() == TIPO_GOLPE::GOLPE_PATADON){
			if (this->jugador->isIniciarGolpe()){
				std::cout << "se inicia la patada: " << std::endl;
				frame = 0;
				this->jugador->setIniciarGolpe(false);
			}
			std::cout << "frame pegando patadon: " << frame << std::endl;
			if (frame / MAXFRAMEPATADON <= MAXFRAMEPATADON ) {
				currentClip = &gSpritePatadadon[frame / MAXFRAMEPATADON];
				++frame;
			} else {
				std::cout << "golpe terminado" << std::endl;
				this->jugador->setTipoGolpe(TIPO_GOLPE::NADA);
			}
		} else if (this->jugador->getTipoGolpe() == TIPO_GOLPE::GOLPE_PATADA){
			if (this->jugador->isIniciarGolpe()){
				std::cout << "se inicia la patada debil: " << std::endl;
				frame = 0;
				this->jugador->setIniciarGolpe(false);
			}
			std::cout << "frame pegando patadon: " << frame << std::endl;
			if (frame / MAXFRAMEPATADITA <= MAXFRAMEPATADITA ) {
				currentClip = &gSpritePatadadebil[frame / MAXFRAMEPATADITA	];
				++frame;
			} else {
				std::cout << "golpe terminado" << std::endl;
				this->jugador->setTipoGolpe(TIPO_GOLPE::NADA);
			}
		}else if (this->jugador->getTipoGolpe() == TIPO_GOLPE::GOLPE_PINIA){
			if (this->jugador->isIniciarGolpe()){
				std::cout << "se inicia la piña debil: " << std::endl;
				frame = 0;
				this->jugador->setIniciarGolpe(false);
			}
			std::cout << "frame pegando piña debil: " << frame << std::endl;
			if (frame / MAXFRAMEPINADEBIL <= MAXFRAMEPINADEBIL ) {
				currentClip = &gSpritePinaDebil[frame / MAXFRAMEPINADEBIL	];
				++frame;
			} else {
				std::cout << "golpe terminado" << std::endl;
				this->jugador->setTipoGolpe(TIPO_GOLPE::NADA);
			}

		}else if (this->jugador->getTipoGolpe() == TIPO_GOLPE::GOLPE_PINION ){
			if (this->jugador->isIniciarGolpe()){
				std::cout << "se inicia la piña FUERTE: " << std::endl;
				frame = 0;
				this->jugador->setIniciarGolpe(false);
			}
			std::cout << "frame pegando piña fuerte: " << frame << std::endl;
			if (frame / MAXFRAMEPINAFUERTE <= MAXFRAMEPINAFUERTE ) {
				currentClip = &gSpritePinaFuerte[frame / MAXFRAMEPINAFUERTE	];
				++frame;
			} else {
				std::cout << "golpe terminado" << std::endl;
				this->jugador->setTipoGolpe(TIPO_GOLPE::NADA);
			}
		}else if (this->jugador->getTipoGolpe() == TIPO_GOLPE::GOLPE_PINION_AGACHADO ){
			if (this->jugador->isIniciarGolpe()){
				std::cout << "se inicia la piña FUERTE AGACHADO: " << std::endl;
				frame = 0;
				this->jugador->setIniciarGolpe(false);
			}
			std::cout << "frame pegando piña fuerte: " << frame << std::endl;
			if (frame / MAXFRAMEPINAFUERTE_agachado<= MAXFRAMEPINAFUERTE_agachado ) {
				currentClip = &gSpritePinaFuerte_agachado[frame / MAXFRAMEPINAFUERTE_agachado	];
				++frame;
			} else {
				std::cout << "golpe agachado terminado" << std::endl;
				this->jugador->setTipoGolpe(TIPO_GOLPE::NADA);
			}
		}else if (this->jugador->getTipoGolpe() == TIPO_GOLPE::GOLPE_DEFENSA ){
			if (this->jugador->isIniciarGolpe()){
				std::cout << "se inicia la DEFENSA parado: " << std::endl;
				frame = 0;
				this->jugador->setIniciarGolpe(false);
			}
			std::cout << "frame se esta defendiendo: " << frame << std::endl;
			if (frame / MAXFRAMEDEFENSA <= MAXFRAMEDEFENSA ) {
				currentClip = &gSpriteDefensa[frame / MAXFRAMEDEFENSA	];
				++frame;
			} else {
				std::cout << "DEFENSA terminadA" << std::endl;
				this->jugador->setTipoGolpe(TIPO_GOLPE::NADA);
			}
		}
		else if (this->jugador->getTipoGolpe() == TIPO_GOLPE::GOLPE_PATADA_AGACHADO ){
					if (this->jugador->isIniciarGolpe()){
						std::cout << "se inicia la patada agachado: " << std::endl;
						frame = 0;
						this->jugador->setIniciarGolpe(false);
					}
					std::cout << "frame esta haciendo la patada agachado: " << frame << std::endl;
					if (frame / MAXFRAMEPATADITA_agachado <= MAXFRAMEPATADITA_agachado ) {
						currentClip = &gSpritePatadadebil_agachado[frame / MAXFRAMEPATADITA_agachado	];
						++frame;
					} else {
						std::cout << "patada debil agachado terminado" << std::endl;
						this->jugador->setTipoGolpe(TIPO_GOLPE::NADA);
					}
				}
		else if (this->jugador->estaAgachado()){
			currentClip = &gSpriteAgachar[0];
		} else if ((this->jugador->estado->getVelX() != 0)){

			if (frame / MAXFRAMECAMINA >= MAXFRAMECAMINA ) {
				frame = MINFRAMECAMINA;
			}
			currentClip = &gSpriteCaminar[frame / MAXFRAMECAMINA];
			++frame;
		} else if ((this->jugador->estado->getVelX() == 0)) {
			currentClip = &gSpriteAnimacion[frame / MAXFRAMEANIMACION];
			if (frame / MAXFRAMEANIMACION >= MAXFRAMEANIMACION ) {
				frame = MINFRAMEANIMACION;
			}
			++frame;
		}
	}else {
		if (this->jugador->estado->estaSaltando()) {
			if (this->jugador->estado->getVelY() >= 18) {
				reproducir_sonido_salto();
				frame = 0;
			}
			if (frame / MAXFRAMESALTA >= MAXFRAMESALTA) {
				frame = MINFRAMESALTA;
			}
			currentClip = &gSpriteSaltar[frame / MAXFRAMESALTA];
			++frame;
		} else if (this->jugador->estaCambiandoPersonaje()){
				currentClip = &gSpriteCambiarPersonaje[0];
				reproducir_sonido_cambio();
			}else
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

