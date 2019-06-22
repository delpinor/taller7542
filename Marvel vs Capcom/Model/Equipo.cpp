/*
 * Equipo.cpp
 *
 *  Created on: 2 abr. 2019
 *      Author: maciel
 */

#include "Equipo.h"

using namespace std;

Equipo::Equipo() {
}

void Equipo::agregar_Jugador(int num, Jugador * jugador){
	this->jugadores[num]=jugador;
}
void Equipo::setRondasGanadas(int rondas){
	this->rondasGanadas = rondas;
}
int Equipo::getRondasGanadas(){
	return this->rondasGanadas;
}
void Equipo::inicializar(int numeroEquipo){
	this->numeroEquipo = numeroEquipo;
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
	if (!this->getJugadorActivo()->estaCambiandoPersonaje() & cambio != NULL)
	if (!this->getJugadorActivo()->estaCambiandoPersonaje() && cambio != NULL)
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

void Equipo::move(SDL_Rect* camara){
	for (int i = 0; i < 2; ++i) {
		this->jugadores[i]->move(this->equipoRival->getJugadorActivo(), camara);
	}
	if (getJugadorActivo()->estado->estaSaltando()
			&& getJugadorActivo()->estado->getVelY() == 0) {
		if (!getJugadorActivo()->isDebeTerminarSalto()) {
			getJugadorActivo()->setDebeTerminarSalto(true);
		} else {
			getJugadorActivo()->setDebeTerminarSalto(false);
			getJugadorActivo()->terminarSalto();
		}
	}
	if (getJugadorActivo()->getTipoGolpe() != TIPO_GOLPE::NADA){
		if (contadorGolpe < 10){
			std::cout << "pegando patada!!!!!!!!!!!!!!!!" << std::endl;
			contadorGolpe++;
		}
		else{
			getJugadorActivo()->setTipoGolpe(TIPO_GOLPE::NADA);
			contadorGolpe = 0;
		}
	}
	if (this->getJugadorActivo()->isFueraDePantalla()){
		this->cambiarPersonaje(camara);
	}
}

void Equipo::moveCliente(SDL_Rect* camara){
	for (int i = 0; i < 2; ++i) {
//		this->jugadores[i]->move(this->equipoRival->getJugadorActivo(), camara);
		this->jugadores[nroJugadorActivo]->updateDirection(*this->equipoRival->getJugadorActivo());
	}
}

void Equipo::cambiarPersonaje(SDL_Rect* camara){

	int jugadorInactivo = this->getNumeroJugadorInactivo();
	int posXActual = this->getJugadorActivo()->estado->getPosX();
	this->setJugadorActivo(jugadorInactivo);
	this->getJugadorActivo()->estado->setPosY(100);
	this->getJugadorActivo()->estado->setPosX(posXActual);
}

void Equipo::iniciarCambioPersonaje(){
		if(	!this->jugadores[getNumeroJugadorInactivo()]->murio())
			this->jugadores[this->nroJugadorActivo]->cambiarPersonaje();
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

void Equipo::jugadorActivoAumentaVelocidadEnY(int vel) {
	this->jugadores[this->nroJugadorActivo]->aumentarVelocidadY(vel);
}

void Equipo::jugadorActivoSalta() {
	this->jugadores[this->nroJugadorActivo]->Saltar();
}
void Equipo::jugadorActivoPinia(Jugador * rival) {
	this->jugadores[this->nroJugadorActivo]->Pinia(rival);
}
void Equipo::jugadorActivoPinion(Jugador * rival) {
	this->jugadores[this->nroJugadorActivo]->Pinion(rival);
}
void Equipo::jugadorActivoPatada(Jugador * rival) {
	this->jugadores[this->nroJugadorActivo]->Patada(rival);
}
void Equipo::jugadorActivoPatadon(Jugador * rival) {
	this->jugadores[this->nroJugadorActivo]->Patadon(rival);
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

void Equipo::jugadorActivoSePara() {
	this->jugadores[this->nroJugadorActivo]->Parar();
}

int Equipo::getCantidadJugadores() {
	return 2;
}

void Equipo::setEquipoRival(Equipo* equipo_rival){
	this->equipoRival = equipo_rival;
}

Equipo* Equipo::getEquipoRival(){
	return this->equipoRival;
}
bool Equipo::estaVivo(){
	cout
	<< "Equipo - estaVivo:  | "
	<< endl;
	if(this->getCantidadJugadoresVivos() == 0){
		return false;
	}
	else{
		return true;
	}
}

void Equipo::inicializarVida(){
	this->jugadores[0]->inicializarVida();
	this->jugadores[1]->inicializarVida();
}
int Equipo::getVidaTotal(){
	return this->jugadores[0]->GetVida() + this->jugadores[1]->GetVida();
}
int Equipo::getCantidadJugadoresVivos(){
	int cantidadVivos = 0;
	for(int i = 0; i < 2; i++){
		if(this->jugadores[i]->estaVivo()){
			cantidadVivos++;
		}
	}
	return cantidadVivos;
}
