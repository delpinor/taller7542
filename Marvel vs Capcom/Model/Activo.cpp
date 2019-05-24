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
	quieto=false;

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
		quieto=true;
}

void Activo::moveVertical() {
	quieto=false;

		mVelY -= aceleracion;
		mPosY -= mVelY;
		if ((mPosY < 0) || (mPosY + ALTO_JUGADOR >= ALTO_NIVEL)) {
			mPosY += mVelY;
			mVelY = 0;
		}
		quieto=true;
}

bool Activo::estaQuieto(){

	return quieto;
}

bool Activo::isFueraDePantalla(){
	return (mPosY < 0);
}

bool Activo::estaActivo() {
	return true;
}
bool Activo::estaAgachado() {
	return this->agachado;
}
bool Activo::estaCambiandoPersonaje(){
	return this->cambiandoPersonaje;
}
//métodos para cliente

void Activo::setEstaActivo(bool activo){
	this->activo = activo;
}
void Activo::setEstaAgachado(bool agachado){
	this->agachado = agachado;
}
void Activo::setEstaFueraDePantalla(bool fueraDePantalla){
	this->fueraDePantalla = fueraDePantalla;
}
void Activo::setEstaCambiandoPersonaje(bool cambiandoPersonaje){
	this->cambiandoPersonaje = cambiandoPersonaje;
}

