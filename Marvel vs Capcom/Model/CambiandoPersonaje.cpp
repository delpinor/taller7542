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

void CambiandoPersonaje::moveVertical() {
}

bool CambiandoPersonaje::isFueraDePantalla(){
	return (mPosY < 0);
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
//métodos para cliente
void CambiandoPersonaje::setEstaActivo(bool activo){
	this->activo = activo;
}
void CambiandoPersonaje::setEstaAgachado(bool agachado){
	this->agachado = agachado;
}
void CambiandoPersonaje::setEstaFueraDePantalla(bool fueraDePantalla){
	this->fueraDePantalla = fueraDePantalla;
}
void CambiandoPersonaje::setEstaCambiandoPersonaje(bool cambiandoPersonaje){
	this->cambiandoPersonaje = cambiandoPersonaje;
}
