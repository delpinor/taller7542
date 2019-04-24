#include "EnEspera.h"

#define VELOCIDAD_JUGADOR 3

EnEspera::EnEspera() {
	//ctor
}

EnEspera::~EnEspera() {
	//dtor
}

void EnEspera::move() {

}
bool EnEspera::estaActivo() {
	return false;
}

void EnEspera::acelerar() {
	return;
}
bool EnEspera::estaAgachado() {
	return false;
}
bool EnEspera::estaEnEspera() {
	return true;
}
bool EnEspera::isFueraDePantalla(){
	return false;
}

bool EnEspera::estaCambiandoPersonaje(){
	return false;
}
