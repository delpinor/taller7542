#include "Agachado.h"

#define VELOCIDAD_JUGADOR 3

Agachado::Agachado() {
	//ctor
}

Agachado::~Agachado() {
	//dtor
}

void Agachado::move() {
}
void Agachado::moveVertical() {
}

bool Agachado::estaActivo() {
	return false;
}
bool Agachado::estaAgachado() {
	return true;
}

void Agachado::acelerar() {
	return;
}

bool Agachado::isFueraDePantalla(){
	return false;
}
bool Agachado::estaCambiandoPersonaje(){
	return false;
}
//métodos para cliente
void Agachado::setEstaActivo(bool activo){
	this->activo = activo;
}
void Agachado::setEstaAgachado(bool agachado){
	this->agachado = agachado;
}
void Agachado::setEstaFueraDePantalla(bool fueraDePantalla){
	this->fueraDePantalla = fueraDePantalla;
}
void Agachado::setEstaCambiandoPersonaje(bool cambiandoPersonaje){
	this->cambiandoPersonaje = cambiandoPersonaje;
}
