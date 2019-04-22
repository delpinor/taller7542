#include "Estado.h"

#define VELOCIDAD_JUGADOR 3
#define VELOCIDAD_JUGADOR_SALTO 20

Estado::Estado() {
	this->posInitX = 10;
	this->posInitY = 480;
	this->mPosX = this->posInitX;
	this->mPosY = this->posInitY;
	this->mVelX = 0;
	this->mVelY = 0;
	this->aceleracion = 1;
	this->acelero = false;
}

Estado::~Estado() {
	//dtor
}

int Estado::getPosX() {
	return this->mPosX;
}
int Estado::getPosY() {
	return this->mPosY;
}
int Estado::getVelX() {
	return this->mVelX;
}
int Estado::getVelY() {
	return this->mVelY;
}

void Estado::setPosX(int PosX) {
	this->mPosX = PosX;
}
void Estado::setPosY(int PosY) {
	this->mPosY = PosY;
}

void Estado::setPosInitX(int posX) {
	this->posInitX = posX;
}
void Estado::setPosInitY(int posY) {
	this->posInitY = posY;
}

void Estado::setAceleracion(int ac) {
	this->aceleracion = ac;
}

void Estado::setVelocidadX(int velx) {
	this->mVelX = velx;

}
void Estado::setVelocidadY(int vely) {
	this->mVelY = vely;

}

void Estado::copiarEstado(Estado* estado) {
	this->posInitX = estado->posInitX;
	this->posInitY = estado->posInitY;
	this->mPosX = estado->mPosX;
	this->mPosY = estado->mPosY;
//	this->mPosX = estado->posInitX;
//	this->mPosY = estado->posInitY;
	this->mVelX = estado->mVelX;
	this->mVelY = estado->mVelY;
}

void Estado::copiarEstadoAgachar(Estado* estado) {
	this->posInitX = estado->posInitX;
	this->posInitY = estado->posInitY;
	this->mPosX = estado->mPosX;
	this->mPosY = estado->mPosY;
	this->mVelX = estado->mVelX;
	this->mVelY = estado->mVelY;
}

void Estado::copiarEstadoCambiarPersonaje(Estado* estado) {
	this->posInitX = estado->posInitX;
	this->posInitY = estado->posInitY;
	this->mPosX = estado->mPosX;
	this->mPosY = estado->mPosY;
	this->mVelX = estado->mVelX;
	this->mVelY = estado->mVelY;
}

void Estado::disminuirVelocidadX() {
	this->mVelX -= VELOCIDAD_JUGADOR;
	if (this->mVelX < -VELOCIDAD_JUGADOR) {
		this->mVelX = -VELOCIDAD_JUGADOR;
	}
}
void Estado::disminuirVelocidadY() {
	this->mVelY -= VELOCIDAD_JUGADOR;
	if (this->mVelY < -VELOCIDAD_JUGADOR) {
		this->mVelY = -VELOCIDAD_JUGADOR;
	}
}
void Estado::Agachar() {

}
void Estado::Parar() {

}
void Estado::aumentarVelocidadX() {
	this->mVelX += VELOCIDAD_JUGADOR;
	if (this->mVelX > VELOCIDAD_JUGADOR) {
		this->mVelX = VELOCIDAD_JUGADOR;
	}
}

void Estado::aumentarVelocidadX(int vel) {
	this->mVelX += vel;
}
void Estado::aumentarVelocidadY() {
	if (this->mVelY != 0)
		return;
	this->mVelY += VELOCIDAD_JUGADOR_SALTO;
	if (this->mVelY > VELOCIDAD_JUGADOR_SALTO) {
		this->mVelY = VELOCIDAD_JUGADOR_SALTO;
	}
}

void Estado::aumentarVelocidadY(int vel) {
	this->mVelY += vel;
}
void Estado::Saltar() {

}

void Estado::detenerVelocidad() {
	this->mVelX = 0;
	this->mVelY = 0;
}

void Estado::desacelerar() {
	this->aceleracion = 1;
	this->acelero = false;
}

int Estado::getAceleracion() {
	return this->aceleracion;

}
bool Estado::getAcelero() {
	return this->acelero;
}

//void Estado::setCambiandoPersonaje(bool cambiandoPersonaje) {
//	this->cambiandoPersonaje = cambiandoPersonaje;
//}
