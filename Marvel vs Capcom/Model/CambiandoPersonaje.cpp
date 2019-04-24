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
	mPosY -= mVelY;
}

bool CambiandoPersonaje::isFueraDePantalla(){
//	return (mPosX > ANCHO_NIVEL)||(mPosX < 0);
	return (mPosY < 0);
}

bool CambiandoPersonaje::estaActivo() {
	return true;
}
bool CambiandoPersonaje::estaAgachado() {
	return false;
}
bool CambiandoPersonaje::estaEnEspera() {
	return false;
}

bool CambiandoPersonaje::estaCambiandoPersonaje(){
	return true;
}
