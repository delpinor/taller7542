/*
 * EstadoCliente.cpp
 *
 *  Created on: 11 may. 2019
 *      Author: maciel
 */

#include "EstadoCliente.h"

EstadoCliente::EstadoCliente() {
	// TODO Auto-generated constructor stub
}
void EstadoCliente::move() {}
void EstadoCliente::moveVertical(){}

bool EstadoCliente::estaActivo(){
	return this->activo;
}
bool EstadoCliente::estaAgachado(){
	return this->agachado;
}
bool EstadoCliente::estaCambiandoPersonaje(){
	return this->cambiandoPersonaje;
}
bool EstadoCliente::isFueraDePantalla(){
	return this->fueraDePantalla;
}
void EstadoCliente::setEstaActivo(bool activo){
	this->activo = activo;
}
void EstadoCliente::setEstaAgachado(bool agachado){
	this->agachado = agachado;
}
void EstadoCliente::setEstaFueraDePantalla(bool fueraDePantalla){
	this->fueraDePantalla = fueraDePantalla;
}
void EstadoCliente::setEstaCambiandoPersonaje(bool cambiandoPersonaje){
	this->cambiandoPersonaje = cambiandoPersonaje;
}

EstadoCliente::~EstadoCliente() {
	// TODO Auto-generated destructor stub
}

