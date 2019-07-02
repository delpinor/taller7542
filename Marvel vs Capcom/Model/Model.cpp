#include "Model.h"
#include "../View/ViewModel.h"
#include "../View/View.h"
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <list>
#include <iostream>
#include <string>
#include <unistd.h>
#include "../Logger/Logger.h"
#include "../Model/GeneralPantalla.h"
#include "../Enums/Personajes.h"

#define CANTJUGADORESTOTALES 2
#define LOCALES 1

Model::Model() {
	this->alto_Pantalla = 0;
	this->ancho_Pantalla = 0;
	this->camara = NULL;
	this->equipos[0] = new Equipo();
	this->equipos[1] = new Equipo();
	this->tiempoJuego = 0;
}
int Model::GetTiempoJuego(){
	return tiempoJuego;
}
void Model::SetTiempoJuego(int tiempo){
	tiempoJuego = tiempo;
}
void Model::set_equipos_with_jugador(int nroEquipo, int nroJugadorEquipo, int personajeId){
	if (nroEquipo==1){

		jugadoresEquipo1[personajeId]->setDireccion(SDL_FLIP_HORIZONTAL);
	}
	//this->equipos[nroEquipo]->agregar_Jugador(nroJugadorEquipo, jugadoresEquipo1[personajeId]);
	this->equipos[nroEquipo]->agregar_Jugador(nroJugadorEquipo, this->crearJugador(personajeId));

}


Jugador* Model::crearJugador(int personajeId){
	//Jugador* jActual = jugadoresEquipo1[personajeId];
//	int ancho, alto, zIndex;
//	std::string nombre, path;
//	ancho = jActual->get_ancho();
//	alto = jActual->get_alto();
//	zIndex = jActual->get_zindex();
//	nombre = jActual->getNombre();
//	path = jActual->getPathImagen();

	int ancho, alto, zIndex;
	std::string nombre, path;
	bool inmortal;
	ancho = jugadoresEquipo1[personajeId]->get_ancho();
	alto = jugadoresEquipo1[personajeId]->get_alto();
	zIndex = jugadoresEquipo1[personajeId]->get_zindex();
	nombre = jugadoresEquipo1[personajeId]->getNombre();
	path = jugadoresEquipo1[personajeId]->getPathImagen();
	inmortal = jugadoresEquipo1[personajeId]->esInmortal();

	Jugador* jNuevo = new Jugador(ancho, alto, zIndex, nombre, path, inmortal);
	return jNuevo;
}
void Model::ajustarCamara(){

	// Este codigo se puede mejorar.
		int posXJugador1 = this->getEquipoNro(0)->getJugadorActivo()->estado->getPosX();
		//int posYJugador1 = this->getEquipoNro(0)->getJugadorActivo()->getPosY();
		int posXJugador2 = this->getEquipoNro(1)->getJugadorActivo()->estado->getPosX();
	//	int posYJugador2 = this->getEquipoNro(1)->getJugadorActivo()->getPosY();
		//
		int collideW = this->getEquipoNro(0)->getJugadorActivo()->getCollideW();

		int jugadorW = this->getEquipoNro(0)->getJugadorActivo()->get_ancho();

		cout << "POS 1 X: " << posXJugador1 << endl;
		cout << "POS 2 X: " << posXJugador2 << endl;
		cout << "Cam X: " << camara->x << endl;
		cout << "Ancho collide: " << collideW << endl;
		cout << "====================" << endl;


		//Chequeo que los jugadores no se salgan del escenario
		if (posXJugador1 + jugadorW - collideW > ANCHO_NIVEL)
			this->getEquipoNro(0)->getJugadorActivo()->estado->setPosX(ANCHO_NIVEL - jugadorW + collideW);

		if (posXJugador2 + jugadorW - collideW > ANCHO_NIVEL)
			this->getEquipoNro(1)->getJugadorActivo()->estado->setPosX(ANCHO_NIVEL - jugadorW + collideW);

		if (posXJugador1 + collideW < 0) {
			this->getEquipoNro(0)->getJugadorActivo()->estado->setPosX(-collideW);
			posXJugador1 = -collideW;
		}
		if (posXJugador2 + collideW < 0) {
			this->getEquipoNro(1)->getJugadorActivo()->estado->setPosX(-collideW);
			posXJugador2 = -collideW;
		}

		//Muevo la cámara si algún jugador se está saliendo de ella
		if (posXJugador1 + jugadorW - collideW > this->camara->x + this->camara->w)
			this->camara->x += this->getEquipoNro(0)->getJugadorActivo()->estado->getVelX();
		else if (posXJugador1 + collideW< this->camara->x)
			this->camara->x = posXJugador1+collideW;

		if (posXJugador2 + jugadorW - collideW> this->camara->x + this->camara->w)
			this->camara->x += this->getEquipoNro(1)->getJugadorActivo()->estado->getVelX();
		else if (posXJugador2 + collideW< this->camara->x)
			this->camara->x = posXJugador2+collideW;

		//Keep the this->camara->in bounds
		if (this->camara->x < 0) {
			this->camara->x = 0;
		}
		if (this->camara->y < 0) {
			this->camara->y = 0;
		}
		if (this->camara->x > ANCHO_NIVEL - this->camara->w) {
			this->camara->x = ANCHO_NIVEL - this->camara->w;
		}
		if (this->camara->y > ALTO_NIVEL - this->camara->h) {
			this->camara->y = ALTO_NIVEL - this->camara->h;
		}

}
void Model::cargar_Tam_Pantalla(int &ancho, int &alto) {
	Logger::Log(LOGGER_NIVEL::DEBUG, "Mode::CargarTamañoPantalla", "Ancho: " + std::to_string(ancho));
	Logger::Log(LOGGER_NIVEL::DEBUG, "Mode::CargarTamañoPantalla", "Alto: " + std::to_string(alto));
	this->alto_Pantalla = alto;
	this->ancho_Pantalla = ancho;
	GeneralPantalla::GetInstancia()->SetResolucion(alto*1.2, ancho*1.2);
}
void Model::inicializar(){
	Logger::Log(LOGGER_NIVEL::DEBUG, "Model::se inicializan los equipos "," ");
	for (int i = 0; i<2; i++){
		this->equipos[i]->inicializar(i);
	}
	this->equipos[0]->setEquipoRival(equipos[1]);
	this->equipos[1]->setEquipoRival(equipos[0]);
	if ((this->equipos[0]->jugadores[0]->getNombre() == this->equipos[1]->jugadores[0]->getNombre() )|| (this->equipos[0]->jugadores[0]->getNombre() == this->equipos[1]->jugadores[1]->getNombre() )){
		this->equipos[0]->jugadores[0]->setColor(255,0,0);
	}
	if ((this->equipos[0]->jugadores[1]->getNombre() == this->equipos[1]->jugadores[0]->getNombre() )|| (this->equipos[0]->jugadores[1]->getNombre() == this->equipos[1]->jugadores[1]->getNombre() )){
		this->equipos[0]->jugadores[1]->setColor(255,0,0);
	}
	if (this->equipos[0]->jugadores[0]->getNombre() == this->equipos[0]->jugadores[1]->getNombre() ){
			this->equipos[0]->jugadores[1]->setColor(255,255,0);
		}
	if (this->equipos[1]->jugadores[0]->getNombre() == this->equipos[1]->jugadores[1]->getNombre() ){
			this->equipos[1]->jugadores[0]->setColor(255,0,255);
		}

}

int Model::get_alto_Pantalla() {
	return this->alto_Pantalla;
}
int Model::get_ancho_Pantalla() {
	return this->ancho_Pantalla;
}

std::string Model::get_pathImagenJugador(int equipo, int indice_jugador){

	return this->equipos[equipo]->jugadores[indice_jugador]->getPathImagen();
}
int Model::GetAltoJugador(int equipo, int indice_jugador){

	return this->equipos[equipo]->jugadores[indice_jugador]->get_alto();
}
int Model::GetAnchoJugador(int equipo, int indice_jugador){

	return this->equipos[equipo]->jugadores[indice_jugador]->get_ancho();
}
std::string Model::GetPathFondoParallax(int zIndex) {
	return fondos[zIndex];
}
string Model::GetPathFondoParallaxByOrden(int orden){

	if(fondos.size() >= orden){

		int i = 1;
		for (auto iter = fondos.rbegin(); iter != fondos.rend(); ++iter) {
			if(i == orden){
				return iter->second;
			}
			i = i + 1;
		}
	}
	else{
		return "";
	}
}

int Model::GetZIndexFondoParallaxByOrden(int orden){

	if(fondos.size() >= orden){

		int i = 1;
		for (auto iter = fondos.rbegin(); iter != fondos.rend(); ++iter) {
			if(i == orden){
				return iter->first;
			}
			i = i + 1;
		}
	}
	else{
		return -1;
	}
}

void Model::CargarFondos(std::map<int, std::map<std::string, std::string> > &mapFondoPantalla) {
	Logger::Log(LOGGER_NIVEL::INFO, "Model::CargaFondos", "Carga iniciada");
	int zIndex;
	std::string ruta;
	for (map<int, map<string, string>>::iterator it = mapFondoPantalla.begin();	it != mapFondoPantalla.end(); ++it) {
		map<string, string> &internal_map = it->second;
		zIndex = std::stoi(internal_map["zIndex"]);
		ruta = internal_map["rutaArchivoImagen"];
		fondos[zIndex] =	ruta;
		Logger::Log(LOGGER_NIVEL::DEBUG, "Model::CargaFondos", "Ruta: " + ruta);
		Logger::Log(LOGGER_NIVEL::DEBUG, "Model::CargaFondos", "ZIndex: " + std::to_string(zIndex));
	}
	Logger::Log(LOGGER_NIVEL::DEBUG, "Model::CargaFondos", "Carga finalizada");
}
void Model::cargar_Jugadores(
		std::map<int, std::map<std::string, std::string> > &mapPersonajes, bool modoTest) {

	int ancho, alto, zindex;
	std::string nombre, path;
	Logger::Log(LOGGER_NIVEL::INFO, "Model::CargaJugadores", "Carga iniciada");
	for (map <int, map<string, string>>::iterator it = mapPersonajes.begin(); it != mapPersonajes.end(); ++it){
		map<string, string> &internal_map = it->second;
		ancho = atoi((internal_map["ancho"]).c_str()); //
		alto = atoi((internal_map["alto"]).c_str());
		zindex = atoi((internal_map["zIndex"]).c_str());

		nombre = internal_map["nombre"];
		path = internal_map["rutaArchivoImagen"];
		//		Jugador jugador(ancho, alto, zindex, nombre, path);
		Logger::Log(LOGGER_NIVEL::INFO, "Model::CargaJugadores", "Nombre: " + nombre);
		Logger::Log(LOGGER_NIVEL::DEBUG, "Model::CargaJugadores", "Path: " + path);
		Logger::Log(LOGGER_NIVEL::DEBUG, "Model::CargaJugadores", "Alto: " + std::to_string(alto));
		Logger::Log(LOGGER_NIVEL::DEBUG, "Model::CargaJugadores", "Ancho: " + std::to_string(ancho));
		Logger::Log(LOGGER_NIVEL::DEBUG, "Model::CargaJugadores", "zindex: " + std::to_string(zindex));
		int personajeId = Personaje::getPersonajeId(nombre);
		bool inmortal = modoTest;
		jugadoresEquipo1.insert(std::make_pair(personajeId,new Jugador(ancho, alto, zindex, nombre, path, inmortal)));
	}
	Logger::Log(LOGGER_NIVEL::DEBUG, "Model::CargaJugadores", "Carga Finalizada");
}

Model::~Model() {
	this->equipos[0] = NULL;
	this->equipos[1] = NULL;

}

void Model::update() {
	for (int i = 0; i < 2; ++i) {
		this->equipos[i]->update(i);
	}
	this->moverJuego();
}

void Model::updateCliente(bool servidor_vivo) {

	if (servidor_vivo==false){

			this->equipos[0]->getJugadorActivo()->set_desconectado();
			this->equipos[1]->getJugadorActivo()->set_desconectado();

		}else{

			this->equipos[0]->getJugadorActivo()->set_conectado();
			this->equipos[1]->getJugadorActivo()->set_conectado();
		}
	this->moverJuegoCliente();
}

void Model::moverJuego() {
	for (int i = 0; i < CANTJUGADORESTOTALES; ++i) {
		this->equipos[i]->move(this->camara);
	}
}

void Model::moverJuegoCliente() {
	for (int i = 0; i < CANTJUGADORESTOTALES; ++i) {
		this->equipos[i]->moveCliente(this->camara);
	}
}

void Model::setCamara(SDL_Rect * camara) {
	this->camara = camara;
}

void Model::inicializarPosicionesEquipos(){
	this->equipos[0]->getJugadorActivo()->estado->setPosX(50);
	this->equipos[1]->getJugadorActivo()->estado->setPosX(600);//- this->equipos[1]->getJugadorActivo()->get_ancho());
}
ModeloInGame Model::GetModeloInGame(){
	ModeloInGame inGame;
	inGame.tiempo = this->GetTiempoJuego();
	inGame.personajesEquipo0[0].vida = this->getEquipoNro(0)->getJugadorNro(0)->GetVida();
	inGame.personajesEquipo0[1].vida = this->getEquipoNro(0)->getJugadorNro(1)->GetVida();
	inGame.personajesEquipo1[0].vida = this->getEquipoNro(1)->getJugadorNro(0)->GetVida();
	inGame.personajesEquipo1[1].vida = this->getEquipoNro(1)->getJugadorNro(1)->GetVida();
	return inGame;
}
ModeloEstado Model::GetModelEstado(){
	ModeloEstado unModeloEstado;
	unModeloEstado.camara.posX = this->camara->x;
	unModeloEstado.camara.posY = this->camara->y;

	unModeloEstado.jugadoresEquipo1.equipo = 0;
	unModeloEstado.jugadoresEquipo1.isActivo = this->getEquipoNro(0)->getJugadorActivo()->estaActivo();
	unModeloEstado.jugadoresEquipo1.isAgachado = this->getEquipoNro(0)->getJugadorActivo()->estaAgachado();
	unModeloEstado.jugadoresEquipo1.isCambiandoPersonaje = this->getEquipoNro(0)->getJugadorActivo()->estaCambiandoPersonaje();
	unModeloEstado.jugadoresEquipo1.isSaltando = this->getEquipoNro(0)->getJugadorActivo()->estaSaltando();
	if (this->getEquipoNro(0)->getJugadorActivo()->getTipoGolpe() == TIPO_GOLPE::DESACTIVAR_DEFENSA)
		cout << "Tipo GolpeEnviado jugador 0: " << this->getEquipoNro(0)->getJugadorActivo()->getTipoGolpe() << endl;
	unModeloEstado.jugadoresEquipo1.tipoGolpe = this->getEquipoNro(0)->getJugadorActivo()->getTipoGolpe();
	unModeloEstado.jugadoresEquipo1.posX = this->getEquipoNro(0)->getJugadorActivo()->getPosX();
	unModeloEstado.jugadoresEquipo1.posY = this->getEquipoNro(0)->getJugadorActivo()->getPosY();
	unModeloEstado.jugadoresEquipo1.velX = this->getEquipoNro(0)->getJugadorActivo()->getVelX();
	unModeloEstado.jugadoresEquipo1.velY = this->getEquipoNro(0)->getJugadorActivo()->getVelY();
	unModeloEstado.jugadoresEquipo1.posYpoder = this->getEquipoNro(0)->getJugadorActivo()->getPosYPoder();
	unModeloEstado.jugadoresEquipo1.posXpoder = this->getEquipoNro(0)->getJugadorActivo()->getPosXPoder();
	unModeloEstado.jugadoresEquipo1.poderActivo = this->getEquipoNro(0)->getJugadorActivo()->poderActivo();
	unModeloEstado.jugadoresEquipo1.sentidoPoder = this->getEquipoNro(0)->getJugadorActivo()->getSentidoPoder();

	unModeloEstado.jugadoresEquipo2.equipo = 1;
	unModeloEstado.jugadoresEquipo2.isActivo = this->getEquipoNro(1)->getJugadorActivo()->estaActivo();
	unModeloEstado.jugadoresEquipo2.isAgachado = this->getEquipoNro(1)->getJugadorActivo()->estaAgachado();
	unModeloEstado.jugadoresEquipo2.isCambiandoPersonaje = this->getEquipoNro(1)->getJugadorActivo()->estaCambiandoPersonaje();
	unModeloEstado.jugadoresEquipo2.isSaltando = this->getEquipoNro(1)->getJugadorActivo()->estaSaltando();
	if (this->getEquipoNro(1)->getJugadorActivo()->getTipoGolpe() == TIPO_GOLPE::DESACTIVAR_DEFENSA)
		cout << "Tipo GolpeEnviado jugador 1: " << this->getEquipoNro(1)->getJugadorActivo()->getTipoGolpe() << endl;
	unModeloEstado.jugadoresEquipo2.tipoGolpe = this->getEquipoNro(1)->getJugadorActivo()->getTipoGolpe();
	unModeloEstado.jugadoresEquipo2.posX = this->getEquipoNro(1)->getJugadorActivo()->getPosX();
	unModeloEstado.jugadoresEquipo2.posY = this->getEquipoNro(1)->getJugadorActivo()->getPosY();
	unModeloEstado.jugadoresEquipo2.velX = this->getEquipoNro(1)->getJugadorActivo()->getVelX();
	unModeloEstado.jugadoresEquipo2.velY = this->getEquipoNro(1)->getJugadorActivo()->getVelY();
	unModeloEstado.jugadoresEquipo2.posYpoder = this->getEquipoNro(1)->getJugadorActivo()->getPosYPoder();
	unModeloEstado.jugadoresEquipo2.posXpoder = this->getEquipoNro(1)->getJugadorActivo()->getPosXPoder();
	unModeloEstado.jugadoresEquipo2.poderActivo = this->getEquipoNro(1)->getJugadorActivo()->poderActivo();
	unModeloEstado.jugadoresEquipo2.sentidoPoder = this->getEquipoNro(1)->getJugadorActivo()->getSentidoPoder();

	return unModeloEstado;
}

Equipo* Model::getEquipoNro(int i) {
	return this->equipos[i];
}

std::list<int> Model::GetIdsPersonajes(){
	std::list<int> idsPersonajes;
	for (map <int, Jugador*>::iterator it = this->jugadoresEquipo1.begin(); it != this->jugadoresEquipo1.end(); ++it){
		idsPersonajes.push_back(it->first);
		//cout << "MODEL - GetIdsPersonajes: Personaje "<< it->first << " | "  << TimeHelper::getStringLocalTimeNow() << endl;
	}

	//cout << "MODEL - GetIdsPersonajes: La cantidad de idsPersonajes es "<< idsPersonajes.size() << " | "  << TimeHelper::getStringLocalTimeNow() << endl;
	//cout << "MODEL - GetIdsPersonajes: La cantidad de jugadoresEquipo1 es"<< this->jugadoresEquipo1.size() << " | "  << TimeHelper::getStringLocalTimeNow() << endl;

	return idsPersonajes;
};
bool Model::EquiposEstanVivos(){
	cout
	<< "MODEL - EquiposEstanVivos:  | "
	<< TimeHelper::getStringLocalTimeNow() << endl;
	if(!this->getEquipoNro(0)->estaVivo() || !this->getEquipoNro(1)->estaVivo() ){
		return false;
	}
	else{
		return true;
	}
}

void Model::InicializarVidas(){
	this->getEquipoNro(0)->inicializarVida();
	this->getEquipoNro(1)->inicializarVida();
}

int Model::GetNroEquipoVivo(){
	if(this->getEquipoNro(0)->estaVivo()){
		return 0;
	}
	else{
		return 1;
	}
}
int Model::GetVidaEquipo(int nroEquipo){
	return this->getEquipoNro(nroEquipo)->getVidaTotal();
}
int Model::GetEquipoCantidadJugadoresVivos(int nroEquipo){
	return this->getEquipoNro(nroEquipo)->getCantidadJugadoresVivos();
}

void Model::setModoTest(bool valor){
	this->getEquipoNro(0)->setModoTest(valor);
	this->getEquipoNro(1)->setModoTest(valor);
}
