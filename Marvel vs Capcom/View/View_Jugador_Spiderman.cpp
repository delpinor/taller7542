#include "View_Jugador_Spiderman.h"

#include <sstream>
View_Jugador_Spiderman::View_Jugador_Spiderman() {

}

void View_Jugador_Spiderman::initialize(Jugador *model, LTexture * texturaJugador) {
	this->texturaJugador = texturaJugador;
	this->jugador = model;
	getSpritesCaminar();
	getSpritesSaltar();
	getSpritesAgachar();
	this->zIndex = model->get_zindex();
	getSpritesCambioPersonaje();
}

void View_Jugador_Spiderman::getSpritesCaminar() {
	gSpriteCaminar[0].x = 18;
	gSpriteCaminar[0].y = 134;
	gSpriteCaminar[0].w = 103;
	gSpriteCaminar[0].h = 106;

	gSpriteCaminar[1].x = 127;
	gSpriteCaminar[1].y = 134;
	gSpriteCaminar[1].w = 103;
	gSpriteCaminar[1].h = 106;

	gSpriteCaminar[2].x = 239;
	gSpriteCaminar[2].y = 134;
	gSpriteCaminar[2].w = 103;
	gSpriteCaminar[2].h = 106;

	gSpriteCaminar[3].x = 342;
	gSpriteCaminar[3].y = 134;
	gSpriteCaminar[3].w = 103;
	gSpriteCaminar[3].h = 106;

	gSpriteCaminar[4].x = 445;
	gSpriteCaminar[4].y = 134;
	gSpriteCaminar[4].w = 103;
	gSpriteCaminar[4].h = 106;

	gSpriteCaminar[5].x = 548;
	gSpriteCaminar[5].y = 134;
	gSpriteCaminar[5].w = 103;
	gSpriteCaminar[5].h = 106;

	gSpriteCaminar[6].x = 660;
	gSpriteCaminar[6].y = 134;
	gSpriteCaminar[6].w = 103;
	gSpriteCaminar[6].h = 106;

	gSpriteCaminar[7].x = 772;
	gSpriteCaminar[7].y = 134;
	gSpriteCaminar[7].w = 103;
	gSpriteCaminar[7].h = 106;

	gSpriteCaminar[8].x = 874;
	gSpriteCaminar[8].y = 134;
	gSpriteCaminar[8].w = 103;
	gSpriteCaminar[8].h = 106;

	gSpriteCaminar[9].x = 983;
	gSpriteCaminar[9].y = 134;
	gSpriteCaminar[9].w = 103;
	gSpriteCaminar[9].h = 106;

	gSpriteCaminar[10].x = 1101;
	gSpriteCaminar[10].y = 134;
	gSpriteCaminar[10].w = 103;
	gSpriteCaminar[10].h = 106;

	gSpriteCaminar[11].x = 1225;
	gSpriteCaminar[11].y = 134;
	gSpriteCaminar[11].w = 103;
	gSpriteCaminar[11].h = 106;

}

void View_Jugador_Spiderman::getSpritesSaltar() {
//	gSpriteSaltar[0].x = 8;
//	gSpriteSaltar[0].y = 464;
//	gSpriteSaltar[0].w = 112;
//	gSpriteSaltar[0].h = 70;

	gSpriteSaltar[0].x = 120;
	gSpriteSaltar[0].y = 246;
	gSpriteSaltar[0].w = 100;
	gSpriteSaltar[0].h = 148;

	gSpriteSaltar[1].x = 235;
	gSpriteSaltar[1].y = 246;
	gSpriteSaltar[1].w = 100;
	gSpriteSaltar[1].h = 148;

	gSpriteSaltar[2].x = 338;
	gSpriteSaltar[2].y = 246;
	gSpriteSaltar[2].w = 100;
	gSpriteSaltar[2].h = 148;

	gSpriteSaltar[3].x = 444;
	gSpriteSaltar[3].y = 246;
	gSpriteSaltar[3].w = 100;
	gSpriteSaltar[3].h = 148;

	gSpriteSaltar[4].x = 553;
	gSpriteSaltar[4].y = 246;
	gSpriteSaltar[4].w = 100;
	gSpriteSaltar[4].h = 148;

	gSpriteSaltar[5].x = 655;
	gSpriteSaltar[5].y = 246;
	gSpriteSaltar[5].w = 100;
	gSpriteSaltar[5].h = 148;

	gSpriteSaltar[6].x = 755;
	gSpriteSaltar[6].y = 246;
	gSpriteSaltar[6].w = 100;
	gSpriteSaltar[6].h = 148;

	gSpriteSaltar[7].x = 870;
	gSpriteSaltar[7].y = 246;
	gSpriteSaltar[7].w = 100;
	gSpriteSaltar[7].h = 148;

	gSpriteSaltar[8].x = 982;
	gSpriteSaltar[8].y = 246;
	gSpriteSaltar[8].w = 100;
	gSpriteSaltar[8].h = 148;

	gSpriteSaltar[9].x = 1091;
	gSpriteSaltar[9].y = 246;
	gSpriteSaltar[9].w = 100;
	gSpriteSaltar[9].h = 148;

	gSpriteSaltar[10].x = 1485;
	gSpriteSaltar[10].y = 398;
	gSpriteSaltar[10].w = 100;
	gSpriteSaltar[10].h = 148;

	gSpriteSaltar[11].x = 1603;
	gSpriteSaltar[11].y = 376;
	gSpriteSaltar[11].w = 100;
	gSpriteSaltar[11].h = 148;

//	gSpriteSaltar[13].x = 1362;
//	gSpriteSaltar[13].y = 423;
//	gSpriteSaltar[13].w = 100;
//	gSpriteSaltar[13].h = 68;
//
//	gSpriteSaltar[14].x = 1460;
//	gSpriteSaltar[14].y = 396;
//	gSpriteSaltar[14].w = 100;
//	gSpriteSaltar[14].h = 91;
}
void View_Jugador_Spiderman::getSpritesAgachar() {
	gSpriteAgachar[0].x = 1604;
	gSpriteAgachar[0].y = 392;
	gSpriteAgachar[0].w = 103;
	gSpriteAgachar[0].h = 106;
}

void View_Jugador_Spiderman::getSpritesCambioPersonaje() {
	gSpriteCambiarPersonaje[0].x = 120;
	gSpriteCambiarPersonaje[0].y = 264;
	gSpriteCambiarPersonaje[0].w = 100;
	gSpriteCambiarPersonaje[0].h = 148;
}


void View_Jugador_Spiderman::render(int camX, int camY, SDL_Renderer * gRenderer) {

	if (this->jugador->estaAgachado()){
		SDL_Rect* currentClip;
		currentClip = &gSpriteAgachar[0];

		this->texturaJugador->render(this->jugador->getPosX() - camX,	this->jugador->getPosY() - camY,currentClip, 0, NULL,this->jugador->getDireccion(), gRenderer);


	}else{

	if (this->jugador->estaActivo()){
			SDL_Rect* currentClip;
			int maxFrames;
			int minFrames;
			if(this->jugador->estaCambiandoPersonaje()){
				currentClip = &gSpriteCambiarPersonaje[0];
			}
			else if (this->jugador->estado->getVelY() != 0){
				if (this->jugador->estado->getVelY() >= 17)
					frame = 0;
				minFrames = MINFRAMESALTA;
				maxFrames = MAXFRAMESALTA;
				if (frame / maxFrames >= maxFrames)
					frame = minFrames;
				currentClip = &gSpriteSaltar[frame / MAXFRAMESALTA];
				frame = frame + 3;
			}
			else{
				minFrames = MINFRAMECAMINA;
				maxFrames = MAXFRAMECAMINA;
				if (frame / maxFrames >= maxFrames)
						frame = minFrames;
				currentClip = &gSpriteCaminar[frame / MAXFRAMECAMINA];
			}
			if ((this->jugador->getVelX() != 0) || (this->jugador->getVelY() != 0)) {
				++frame;

			}
			this->texturaJugador->render(this->jugador->getPosX() - camX,	this->jugador->getPosY() - camY,currentClip, 0, NULL,this->jugador->getDireccion(), gRenderer);
		}
	}
}

