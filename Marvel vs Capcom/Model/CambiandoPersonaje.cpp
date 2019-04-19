/*
 * CambiandoPersonaje.cpp
 *
 *  Created on: 18 abr. 2019
 *      Author: maciel
 */
#include "../View/View.h"
#include "CambiandoPersonaje.h"

CambiandoPersonaje::CambiandoPersonaje() {
	// TODO Auto-generated constructor stub

}

CambiandoPersonaje::~CambiandoPersonaje() {
	// TODO Auto-generated destructor stub
}

void CambiandoPersonaje::move(){
	this->mPosX += this->mVelX * aceleracion;
}

bool CambiandoPersonaje::isFueraDePantalla(){
	return (mPosX > ANCHO_NIVEL)||(mPosX < 0);
}

bool CambiandoPersonaje::estaActivo() {
	return true;
}
bool CambiandoPersonaje::estaAgachado() {
	return false;
}

bool CambiandoPersonaje::estaCambiandoPersonaje(){
	return true;
}
