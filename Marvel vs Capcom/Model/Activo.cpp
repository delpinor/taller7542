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
	Estado::move();
}

void Activo::moveVertical() {
	Estado::moveVertical();
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
bool Activo::estaSaltando(){
	return this->saltando;
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
void Activo::setEstaSaltando(bool saltando){
	this->saltando = saltando;
}
