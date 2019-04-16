#include "Inactivo.h"

#define VELOCIDAD_JUGADOR 3

Inactivo::Inactivo() {
	//ctor
}

Inactivo::~Inactivo() {
	//dtor
}

void Inactivo::move() {

}
bool Inactivo::estaActivo() {
	return false;
}

void Inactivo::acelerar() {
	return;
}

bool Inactivo::isFueraDePantalla(){
	return false;
}
