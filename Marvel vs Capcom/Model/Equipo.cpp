/*
 * Equipo.cpp
 *
 *  Created on: 2 abr. 2019
 *      Author: maciel
 */

#include "Equipo.h"

using namespace std;

Equipo::Equipo() {
	//this->jugadores = new Jugador[2];
	//this->jugadores[0].setPersonaje(0); //testing
	//this->jugadores[1].setPersonaje(1); //testing
	//this->nroJugadorActivo = 1;
	//this->getJugadorActivo()->activar();
}

//revisar ,no usar!!
//Equipo::Equipo(std::map<int, Jugador> jugadores){
////	int i = 0;
////	for (std::map<int, Jugador>::iterator itr = jugadores.begin(); itr != jugadores.end(); itr++){
////		if (i >= 2)
////			break;
////		agregar_Jugador(i,itr->second);
////		i++;
////	}
//
////	agregar_Jugador(0,jugador);
////
////	agregar_Jugador(1,jugador);
//
//	//this->jugadores[0].setPersonaje(0); //testing
//		//this->jugadores[1].setPersonaje(1); //testing
//		//this->nroJugadorActivo = 1;
//		//this->getJugadorActivo()->activar();
//
//}
void Equipo::agregar_Jugador(int num, Jugador * jugador){
	this->jugadores[num]=jugador;
	//	this->getJugadorActivo()->activar();
}

void Equipo::inicializar(){
	this->setJugadorActivo(0);
}

Equipo::~Equipo() {
	delete this->jugadores;
}


Jugador* Equipo::getJugadorNro(int i) {
	return (this->jugadores[i]);
}
Jugador* Equipo::getJugadorActivo() {
	return (this->jugadores[this->nroJugadorActivo]);
}

Jugador* Equipo::getJugadorInactivo() {
	for (int i = 0; i < 2; ++i) {
		if (i != this->nroJugadorActivo)
			return (this->jugadores[i]);
	}
}

int Equipo::getNumeroJugadorInactivo() {
	for (int i = 0; i < 2; ++i) {
		if (i != this->nroJugadorActivo)
			return i;
	}
}

void Equipo::setJugadorActivo(int i) {
	this->nroJugadorActivo = i;
	this->getJugadorActivo()->activar();
	this->getJugadorInactivo()->desactivar();
}

void Equipo::agregarCambio(Command* cambio) {
	if (!this->cambiandoJugador & cambio != NULL)
		this->cambios.push(cambio);
	else
		cout << "cambiando jugador" << endl;
}

void Equipo::update(int i) {
	if (!this->cambios.empty()) {
		Command* cambio = this->cambios.front();
		cambio->execute(i);
		this->cambios.pop();
	}
}

void Equipo::move(){
	for (int i = 0; i < 2; ++i) {
		this->jugadores[i]->move();
	}
	if (this->getJugadorActivo()->isFueraDePantalla())
		this->cambiarPersonaje();
}

void Equipo::cambiarPersonaje(){
	int jugadorInactivo = this->getNumeroJugadorInactivo();
	this->setJugadorActivo(jugadorInactivo);
	setCambiandoPersonaje(false);
	this->getJugadorActivo()->estado->setPosY(10);
}

void Equipo::setCambiandoPersonaje(){
	this->setCambiandoPersonaje(true);
}


void Equipo::jugadorActivoAumentaVelocidadEnX() {
	this->jugadores[this->nroJugadorActivo]->aumentarVelocidadX();
}

void Equipo::jugadorActivoAumentaVelocidadEnX(int vel) {
	this->jugadores[this->nroJugadorActivo]->aumentarVelocidadX(vel);
}

void Equipo::jugadorActivoAumentaVelocidadEnY() {
	this->jugadores[this->nroJugadorActivo]->aumentarVelocidadY();
}

void Equipo::jugadorActivoSalta() {
	this->jugadores[this->nroJugadorActivo]->Saltar();
}

void Equipo::jugadorActivoDisminuyeVelocidadEnX() {
	this->jugadores[this->nroJugadorActivo]->disminuirVelocidadX();
}

void Equipo::jugadorActivoDisminuyeVelocidadEnY() {
	this->jugadores[this->nroJugadorActivo]->disminuirVelocidadY();
}

void Equipo::jugadorActivoSeAgacha() {
	this->jugadores[this->nroJugadorActivo]->Agachar();
}

int Equipo::getCantidadJugadores() {
	return 2;
}

bool Equipo::isCambiandoPersonaje(){
	return cambiandoJugador;
}

void Equipo::setCambiandoPersonaje(bool cambiandoJugador) {
	this->cambiandoJugador = cambiandoJugador;
	this->getJugadorActivo()->estado->setCambiandoPersonaje(cambiandoJugador);
}
