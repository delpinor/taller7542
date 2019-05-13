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
	contador++;
	if (this->jugador->estaAgachado()) {
		contador = 0;
		currentClip = &gSpriteAgachar[0];
		this->texturaJugador->render(this->jugador->getPosX() - camX,
				this->jugador->getPosY() - camY, currentClip, 0, NULL,
				this->jugador->getDireccion(), gRenderer);

	} else {

		if (this->jugador->estaActivo()) {

			int maxFrames;
			int minFrames;
			if (this->jugador->estaCambiandoPersonaje()) {
				contador = 0;
				Logger::Log(LOGGER_NIVEL::DEBUG,
						"view CapAmerica:: cambiando personaje", " ");
				currentClip = &gSpriteCambiarPersonaje[0];

			} else if (this->jugador->estado->getVelY() != 0) {
				if (this->jugador->estado->getVelY() >= 18) {
					frame = 0;
				}
				contador = 0;
				minFrames = MINFRAMESALTA;
				maxFrames = MAXFRAMESALTA;
				if (frame / maxFrames >= maxFrames + 1) {
					frame = minFrames;
				}
				currentClip = &gSpriteSaltar[frame / MAXFRAMESALTA];

			} else if ((this->jugador->estaActivo())
					&& (this->jugador->estado->getVelY() == 0)
					&& (this->jugador->estado->getVelX() == 0)
					&& (contador > 100)) {
				Logger::Log(LOGGER_NIVEL::DEBUG, "view CapAmerica:: animacion",
						" ");
				currentClip = &gSpriteAnimacion[frame / MAXFRAMEANIMACION];
				minFrames = MINFRAMEANIMACION;
				maxFrames = MAXFRAMEANIMACION;
				if (frame / maxFrames >= maxFrames + 1) {
					frame = minFrames;
					contador = 0;
				}
				++frame;
			} else {
				minFrames = MINFRAMECAMINA;
				maxFrames = MAXFRAMECAMINA;
				if (frame / maxFrames >= maxFrames + 1) {
					frame = minFrames;
				}
				currentClip = &gSpriteCaminar[frame / MAXFRAMECAMINA];
			}
			if ((this->jugador->getVelX() != 0)
					|| (this->jugador->getVelY() != 0)) {
				++frame;
				contador = 0;
			}
			this->texturaJugador->render(this->jugador->getPosX() - camX,
					this->jugador->getPosY() - camY, currentClip, 0, NULL,
					this->jugador->getDireccion(), gRenderer);

		}
	}
}

int View_Jugador::getZIndex() {
	return this->zIndex;
}

