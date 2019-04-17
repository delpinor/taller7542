#include "Activo.h"
#include "../View/View.h"
#include "GeneralPantalla.h"

Activo::Activo() {
	//ctor
}


Activo::~Activo() {
	//dtor
}

void Activo::move() {
	if (this->cambiandoPersonaje) {
		this->mPosX += this->mVelX * aceleracion;
	} else {
		this->mPosX += this->mVelX * aceleracion;
		if ((mPosX < 0) || (mPosX + ANCHO_JUGADOR >= ANCHO_NIVEL)) {
			mPosX -= mVelX * aceleracion;
		}
		mVelY -= aceleracion;
		mPosY -= mVelY;
		if ((mPosY < 0) || (mPosY + ALTO_JUGADOR >= ALTO_NIVEL)) {
			mPosY += mVelY;
			mVelY = 0;
		}
	}
}

bool Activo::isFueraDePantalla(){
	return (mPosX > ANCHO_NIVEL);
}

bool Activo::estaActivo() {
	return true;
}

