/*
 * Saltando.cpp
 *
 *  Created on: 13 jun. 2019
 *      Author: maciel
 */

#include "Saltando.h"
#include <iostream>

Saltando::Saltando() {
	// TODO Auto-generated constructor stub

}

void Saltando::move() {
	std::cout << "saltandooooooooooooooooooooo" << std::endl;
	Estado::move();
}

void Saltando::moveVertical() {
	Estado::moveVertical();
}

bool Saltando::estaActivo() {
	return true;
}
bool Saltando::estaAgachado() {
	return false;
}
bool Saltando::isFueraDePantalla(){
	return false;
}
bool Saltando::estaCambiandoPersonaje(){
	return false;
}
bool Saltando::estaSaltando(){
	return true;
}
void Saltando::setEstaActivo(bool activo){
	this->activo = activo;
}
void Saltando::setEstaAgachado(bool agachado){
	this->agachado = agachado;
}
void Saltando::setEstaFueraDePantalla(bool fueraDePantalla){
	this->fueraDePantalla = fueraDePantalla;
}
void Saltando::setEstaCambiandoPersonaje(bool cambiandoPersonaje){
	this->cambiandoPersonaje = cambiandoPersonaje;
}
void Saltando::setEstaSaltando(bool saltando){
	this->saltando = saltando;
}
Saltando::~Saltando() {
	// TODO Auto-generated destructor stub
}

