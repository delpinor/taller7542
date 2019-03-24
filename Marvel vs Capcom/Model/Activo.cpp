#include "Activo.h"
#include "../View/View.h"

Activo::Activo() {
	//ctor
}

Activo::~Activo() {
	//dtor
}

void Activo::move() {
	this->mPosX += this->mVelX * aceleracion;
	if ((mPosX < 0) || (mPosX + ANCHO_JUGADOR >= ANCHO_NIVEL)) {
		mPosX -= mVelX * aceleracion;
	}
	mPosY += mVelY * aceleracion;
	if ((mPosY < 0) || (mPosY + ALTO_JUGADOR >= ALTO_NIVEL)) {
		mPosY -= mVelY * aceleracion;
	}
}
bool Activo::estaActivo() {
	return true;
}

