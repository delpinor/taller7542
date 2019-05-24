#include "Model.h"
#include "../View/ViewModel.h"
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

#define CANTJUGADORESTOTALES 2
#define LOCALES 1

Model::Model() {
	this->alto_Pantalla = 0;
	this->ancho_Pantalla = 0;
	this->camara = NULL;
	this->equipos[0] = new Equipo();
	this->equipos[1] = new Equipo();
}

void Model::set_equipos_with_jugador(int nroEquipo, int nroJugadorEquipo, int nroJugador){
	if (nroEquipo==1){

		jugadoresEquipo1[nroJugador]->setDireccion(SDL_FLIP_HORIZONTAL);
	}
	this->equipos[nroEquipo]->agregar_Jugador(nroJugadorEquipo, jugadoresEquipo1[nroJugador]);


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
		std::map<int, std::map<std::string, std::string> > &mapPersonajes) {

	int ancho, alto, zindex;
	std::string nombre, path;
	int i = 0;
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
		jugadoresEquipo1.insert(std::make_pair(i,new Jugador(ancho, alto, zindex, nombre, path)));
		i++;
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

void Model::updateCliente() {
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
	this->equipos[0]->getJugadorActivo()->estado->setPosX(this->camara->x);
	this->equipos[1]->getJugadorActivo()->estado->setPosX(this->camara->x + this->camara->w -
	this->equipos[1]->getJugadorActivo()->get_ancho());
}
ModeloEstado Model::GetModelEstado(){
	ModeloEstado unModeloEstado;
		unModeloEstado.camara.posX = this->camara->x;
		unModeloEstado.camara.posY = this->camara->y;

		unModeloEstado.jugadoresEquipo1.equipo = 0;
		unModeloEstado.jugadoresEquipo1.isActivo = this->getEquipoNro(0)->getJugadorActivo()->estaActivo();
		unModeloEstado.jugadoresEquipo1.isAgachado = this->getEquipoNro(0)->getJugadorActivo()->estaAgachado();
		unModeloEstado.jugadoresEquipo1.isCambiandoPersonaje = this->getEquipoNro(0)->getJugadorActivo()->estaCambiandoPersonaje();
		unModeloEstado.jugadoresEquipo1.posX = this->getEquipoNro(0)->getJugadorActivo()->getPosX();
		unModeloEstado.jugadoresEquipo1.posY = this->getEquipoNro(0)->getJugadorActivo()->getPosY();
		unModeloEstado.jugadoresEquipo1.velX = this->getEquipoNro(0)->getJugadorActivo()->getVelX();
		unModeloEstado.jugadoresEquipo1.velY = this->getEquipoNro(0)->getJugadorActivo()->getVelY();


		unModeloEstado.jugadoresEquipo2.equipo = 1;
		unModeloEstado.jugadoresEquipo2.isActivo = this->getEquipoNro(1)->getJugadorActivo()->estaActivo();
		unModeloEstado.jugadoresEquipo2.isAgachado = this->getEquipoNro(1)->getJugadorActivo()->estaAgachado();
		unModeloEstado.jugadoresEquipo2.isCambiandoPersonaje = this->getEquipoNro(1)->getJugadorActivo()->estaCambiandoPersonaje();
		unModeloEstado.jugadoresEquipo2.posX = this->getEquipoNro(1)->getJugadorActivo()->getPosX();
		unModeloEstado.jugadoresEquipo2.posY = this->getEquipoNro(1)->getJugadorActivo()->getPosY();
		unModeloEstado.jugadoresEquipo2.velX = this->getEquipoNro(1)->getJugadorActivo()->getVelX();
		unModeloEstado.jugadoresEquipo2.velY = this->getEquipoNro(1)->getJugadorActivo()->getVelY();

		return unModeloEstado;
}

Equipo* Model::getEquipoNro(int i) {
	return this->equipos[i];
}

