#include "Inactivo.h"

#define VELOCIDAD_JUGADOR 3

Inactivo::Inactivo() {
	//ctor
}

Inactivo::~Inactivo() {
	//dtor
}

void Inactivo::moveVertical() {
}

void Inactivo::move() {

}
bool Inactivo::estaActivo() {
	return false;
}

void Inactivo::acelerar() {
	return;
}
bool Inactivo::estaAgachado() {
	return false;
}

bool Inactivo::isFueraDePantalla(){
	return false;
}

bool Inactivo::estaCambiandoPersonaje(){
	return false;
}
//métodos para cliente
void Inactivo::setEstaActivo(bool activo){
	this->activo = activo;
}
void Inactivo::setEstaAgachado(bool agachado){
	this->agachado = agachado;
}
void Inactivo::setEstaFueraDePantalla(bool fueraDePantalla){
	this->fueraDePantalla = fueraDePantalla;
}
void Inactivo::setEstaCambiandoPersonaje(bool cambiandoPersonaje){
	this->cambiandoPersonaje = cambiandoPersonaje;
}
