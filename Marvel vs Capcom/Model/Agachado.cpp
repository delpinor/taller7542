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
