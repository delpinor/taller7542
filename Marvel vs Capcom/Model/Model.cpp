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

	this->equipos[nroEquipo]->agregar_Jugador(nroJugadorEquipo, jugadoresEquipo1[nroJugador]);


}

void Model::cargar_Tam_Pantalla(int &ancho, int &alto) {
	Logger::Log(LOGGER_NIVEL::DEBUG, "Mode::CargarTamañoPantalla", "Ancho: " + std::to_string(ancho));
	Logger::Log(LOGGER_NIVEL::DEBUG, "Mode::CargarTamañoPantalla", "Alto: " + std::to_string(alto));
	this->alto_Pantalla = alto;
	this->ancho_Pantalla = ancho;
}
void Model::inicializar(){
	for (int i = 0; i<2; i++){
		this->equipos[i]->inicializar();
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
std::string Model::GetPathFondoParallax(int zIndex) {
	return fondos[zIndex];
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
		  ancho=atoi((internal_map["ancho"]).c_str()); //
		   alto=atoi((internal_map["alto"]).c_str());
		   zindex=atoi((internal_map["zindex"]).c_str());

		nombre = internal_map["nombre"];
		path = internal_map["rutaArchivoImagen"];
		Jugador jugador(ancho, alto, zindex, nombre, path);
		Logger::Log(LOGGER_NIVEL::INFO, "Model::CargaJugadores", "Nombre: " + nombre);
		Logger::Log(LOGGER_NIVEL::DEBUG, "Model::CargaJugadores", "Path: " + path);
		Logger::Log(LOGGER_NIVEL::DEBUG, "Model::CargaJugadores", "Alto: " + std::to_string(alto));
		Logger::Log(LOGGER_NIVEL::DEBUG, "Model::CargaJugadores", "Ancho: " + std::to_string(ancho));
	jugadoresEquipo1.insert(std::make_pair(i, new Jugador(ancho,alto,zindex,nombre,path)));
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

void Model::moverJuego() {

	for (int i = 0; i < CANTJUGADORESTOTALES; ++i) {
		this->equipos[i]->move();
	}
}

void Model::setCamara(SDL_Rect * camara) {
	this->camara = camara;
}

Equipo* Model::getEquipoNro(int i) {
	return this->equipos[i];
}

