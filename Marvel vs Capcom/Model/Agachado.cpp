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
	return true;
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
