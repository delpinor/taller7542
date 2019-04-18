/*
 * ViewJugadorDefault.cpp
 *
 *  Created on: 13 abr. 2019
 *      Author: maciel
 */

#include "View_Jugador_Default.h"

View_Jugador_Default::View_Jugador_Default() {
	// TODO Auto-generated constructor stub

}

void View_Jugador_Default::initialize(Jugador *model, LTexture * texturaJugador) {
	this->texturaJugador = texturaJugador;
	this->model = model;

	getSprites();
}

void View_Jugador_Default::getSprites() {
	gSprite[0].x = 0;
	gSprite[0].y = 0;
	gSprite[0].w = 128;
	gSprite[0].h = 128;

}


void View_Jugador_Default::render(int camX, int camY, SDL_Renderer * gRenderer) {
	if (this->model->estaActivo()){
			SDL_Rect* currentClip;
			currentClip = &gSprite[0];

			this->texturaJugador->render(this->model->getPosX() - camX,
					this->model->getPosY() - camY, currentClip, 0, NULL,
				this->model->getDireccion(), gRenderer);
		}
	if (this->model->estaAgachado()){
				SDL_Rect* currentClip;
				currentClip = &gSprite[0];

				this->texturaJugador->render(this->model->getPosX() - camX,
						this->model->getPosY() - camY, currentClip, 0, NULL,
					this->model->getDireccion(), gRenderer);
			}
}
