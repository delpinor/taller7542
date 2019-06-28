#include "View_Jugador.h"
#define DISTANCIAPISO 360

#include <sstream>
int contador=0;
View_Jugador::View_Jugador() {
}

void View_Jugador::initialize(Jugador * model, LTexture * texturaJugador) {
	this->texturaJugador = texturaJugador;
	this->jugador = model;
	this->zIndex = model->get_zindex();
}
void View_Jugador::silenciar_efectos(){
	if (silencio){
		silencio=false;
	}else{
		silencio=true;
	}
}
void View_Jugador::reproducir_efecto_sonido( int tipo_golpe){

      if(!silencio){
		  switch (tipo_golpe)
		      {
			 case GOLPE_PATADON:
				 reproducir_sonido_ataque_patada();
				break;
			 case GOLPE_PATADA:
				 reproducir_sonido_ataque_patada();
				break;
			 case GOLPE_PINIA:
				 reproducir_sonido_ataque_pu();
				break;
			 case GOLPE_PINION:
				 reproducir_sonido_ataque_pu();
				break;
			case ACTIVAR_DEFENSA:
				 reproducir_sonido_defensa();
				break;
			 case RECIBIR_DANIO:
				 reproducir_sonido_recibir_danio();
				break;
		      }
      }


}
void View_Jugador::render(int camX, int camY, SDL_Renderer * gRenderer) {
	SDL_Rect* currentClip;
	SDL_Rect* currentClipPoder;
	if(this->jugador->get_estado_desconexion()==false){
		//printf("No se pone gris la imagen!!!!\n");
		this->desgrisar_imagen();
	}else{
		//printf("se pone gris la imagen!!!!\n");
		this->grisar_imagen();
	}
	if (this->jugador->getTipoGolpe() == TIPO_GOLPE::DESACTIVAR_DEFENSA) {
		this->jugador->setTipoGolpe(TIPO_GOLPE::NADA);
	}
	if(this->jugador->isIniciarGolpe()){

		reproducir_efecto_sonido( this->jugador->getTipoGolpe());

						std::cout << "se inicia el golpeee!: " << std::endl;
						frame = 0;
						this->jugador->setIniciarGolpe(false);

	}
	if (this->jugador->getTipoGolpe() == TIPO_GOLPE::GOLPE_VOLAR) {

		if (frame / FACTORJUGADORLANZADO <= MAXFRAMEJUGADORLANZADO) {
			currentClip = &gSpriteJugadorLanzado[frame / FACTORJUGADORLANZADO];
			++frame;
		} else {
			std::cout << "golpe terminado" << std::endl;
			this->jugador->setTipoGolpe(TIPO_GOLPE::NADA);
		}
	} else if ((this->jugador->estado->getVelY() == 0)
			&& !(this->jugador->estado->estaSaltando())) {
		if (this->jugador->estaAgachado()) {
			if (this->jugador->getTipoGolpe() != TIPO_GOLPE::NADA) {
				std::cout << "tipoGolpe: " << this->jugador->getTipoGolpe() << std::endl;

				if (this->jugador->getTipoGolpe() == TIPO_GOLPE::GOLPE_PATADON) {
					gSpriteGolpear = gSpritePatadonAgachado;
					maxFrame = MAXFRAMEPATADONAGACHADO;
					factor = FACTORPATADONAGACHADO;
					std::cout << "PATADON agachado" << std::endl;
				} else if (this->jugador->getTipoGolpe() == TIPO_GOLPE::GOLPE_PATADA) {
					gSpriteGolpear = gSpritePatadaAgachado;
					maxFrame = MAXFRAMEPATADAAGACHADO;
					factor = FACTORPATADAAGACHADO;
					std::cout << "patada agachado" << std::endl;
				} else if (this->jugador->getTipoGolpe() == TIPO_GOLPE::ACTIVAR_DEFENSA) {
					gSpriteGolpear = gSpriteDefensaAgachado;
					maxFrame = 1;
					factor = 1;
					frame = 0;
					if(!silencio)
					reproducir_efecto_sonido( this->jugador->getTipoGolpe());
					std::cout << "defensa agachado" << std::endl;
				}else if (this->jugador->getTipoGolpe() == TIPO_GOLPE::RECIBIR_DANIO) {
					gSpriteGolpear = gSpriteRecibirDanio;
					maxFrame = 1;
					factor = 1;
					frame = 0;
					contador++;
					if (contador==5){

						this->jugador->setTipoGolpe(TIPO_GOLPE::NADA);
						contador=0;
					}
				}
				else if (this->jugador->getTipoGolpe() == TIPO_GOLPE::GOLPE_PINIA) {
					gSpriteGolpear = gSpritePiniaAgachado;
					maxFrame = MAXFRAMEPINIAAGACHADO;
					factor = FACTORPINIAAGACHADO;
					std::cout << "pinia agachado" << std::endl;
				}
				else if (this->jugador->getTipoGolpe() == TIPO_GOLPE::GOLPE_PINION) {
					gSpriteGolpear = gSpritePinionAgachado;
					maxFrame = MAXFRAMEPINIONAGACHADO;
					factor = FACTORPINIONAGACHADO;
					std::cout << "pinion agachado" << std::endl;
				}
				if (frame / factor <= maxFrame) {
					currentClip = &gSpriteGolpear[frame / factor];
					++frame;
				} else {
					this->jugador->setTipoGolpe(TIPO_GOLPE::NADA);
				}
			} else
				currentClip = &gSpriteAgachar[0];
		} else if (this->jugador->getTipoGolpe() != TIPO_GOLPE::NADA) {
			std::cout << "tipoGolpe: " << this->jugador->getTipoGolpe() << std::endl;

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
			}else if (this->jugador->getTipoGolpe() == TIPO_GOLPE::ACTIVAR_DEFENSA) {
				gSpriteGolpear = gSpriteDefensa;
				maxFrame = 1;
				factor = 1;
				frame = 0;
				if(!silencio)
				reproducir_efecto_sonido( this->jugador->getTipoGolpe());
				std::cout << "defensa parado" << std::endl;
			}else if (this->jugador->getTipoGolpe() == TIPO_GOLPE::RECIBIR_DANIO) {
				gSpriteGolpear = gSpriteRecibirDanio;
				maxFrame = 1;
				factor = 1;
				frame = 0;
				contador++;
				if (contador==5){

					this->jugador->setTipoGolpe(TIPO_GOLPE::NADA);
					contador=0;


					std::cout << "recibir danio" << std::endl;
				}
			}else if (this->jugador->getTipoGolpe() == TIPO_GOLPE::GOLPE_PINIA) {
				gSpriteGolpear = gSpritePinia;
				maxFrame = MAXFRAMEPINIA;
				factor = FACTORPINIA;
				std::cout << "pinia parado" << std::endl;
			}else if (this->jugador->getTipoGolpe() == TIPO_GOLPE::GOLPE_PINION) {
				gSpriteGolpear = gSpritePinion;
				maxFrame = MAXFRAMEPINION;
				factor = FACTORPINION;
				std::cout << "pinion parado" << std::endl;
			} else if (this->jugador->getTipoGolpe() == TIPO_GOLPE::GOLPE_PODER) {
				gSpriteGolpear = gSpriteLanzarPoder;
				maxFrame = MAXFRAMELANZARPODER;
				factor = FACTORLANZARPODER;
				std::cout << "podeeerrrrr" << std::endl;
			}else if (this->jugador->getTipoGolpe() == TIPO_GOLPE::GOLPE_ARROJAR) {
				gSpriteGolpear = gSpriteLanzarJugador;
				maxFrame = MAXFRAMELANZARJUGADOR;
				factor = FACTORLANZARJUGADOR;
				std::cout << "arrojand jugadorr" << std::endl;
			}

			if (frame / factor <= maxFrame) {
				currentClip = &gSpriteGolpear[frame / factor];
				++frame;

			} else {
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
	} else {
		std::cout << "en el aireeeeeee !!!!!" << std::endl;
		if (this->jugador->estado->estaSaltando()) {
			if(!silencio)
			reproducir_sonido_salto();
			if (this->jugador->getTipoGolpe() != TIPO_GOLPE::NADA) {
				std::cout << "tipoGolpe: " << this->jugador->getTipoGolpe() << std::endl;

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
				else if (this->jugador->getTipoGolpe() == TIPO_GOLPE::GOLPE_PINIA) {
					gSpriteGolpear = gSpritePiniaSaltando;
					maxFrame = MAXFRAMEPINIASALTANDO;
					factor = FACTORPINIASALTANDO;
					std::cout << "pinia saltando" << std::endl;
				}
				else if (this->jugador->getTipoGolpe() == TIPO_GOLPE::GOLPE_PINION) {
					gSpriteGolpear = gSpritePinionSaltando;
					maxFrame = MAXFRAMEPINIONSALTANDO;
					factor = FACTORPINIONSALTANDO;
					std::cout << "pinion saltando" << std::endl;
				}
				else if (this->jugador->getTipoGolpe() == TIPO_GOLPE::ACTIVAR_DEFENSA) {
					gSpriteGolpear = gSpriteDefensaSaltando;
					maxFrame = 1;
					factor = 1;
					frame = 0;
					if(!silencio)
					reproducir_efecto_sonido( this->jugador->getTipoGolpe());
					std::cout << "defensa saltando" << std::endl;
				}else if (this->jugador->getTipoGolpe() == TIPO_GOLPE::RECIBIR_DANIO) {
					gSpriteGolpear = gSpriteRecibirDanio;
					maxFrame = 1;
					factor = 6;
					frame = 0;
					contador++;
					if (contador==5){

						this->jugador->setTipoGolpe(TIPO_GOLPE::NADA);
						contador=0;

						std::cout << "recibir danio" << std::endl;
					}
				}
				if (frame / factor <= maxFrame) {
					currentClip = &gSpriteGolpear[frame / factor];
					++frame;
				} else {
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
		} else if (this->jugador->estaCambiandoPersonaje()){
			currentClip = &gSpriteCambiarPersonaje[0];
			if(!silencio)
			reproducir_sonido_cambio();
			}
		else
			currentClip = &gSpriteCambiarPersonaje[0];
	}

	if (this->jugador->estaActivo()) {
			this->texturaJugador->render(this->jugador->getPosX() - camX,
					this->jugador->getPosY()-camY -DISTANCIAPISO, currentClip, 0, NULL,
					this->jugador->getDireccion(), gRenderer);
		}

	if (this->jugador->poderActivo()) {
		currentClipPoder= &gSpritePoder[0];
		if (this->jugador->getSentidoPoder() == 1) {
			this->texturaJugador->render(this->jugador->getPosXPoder() - camX,
					this->jugador->getPosYPoder()-camY-DISTANCIAPISO, currentClipPoder, 0, NULL,
					SDL_FLIP_NONE, gRenderer);
		} else {
				this->texturaJugador->render(
						this->jugador->getPosXPoder() -camX,
						this->jugador->getPosYPoder()-camY-DISTANCIAPISO, currentClipPoder, 0,
						NULL, SDL_FLIP_HORIZONTAL, gRenderer);
		}

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


