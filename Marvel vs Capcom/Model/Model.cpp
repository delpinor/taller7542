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
	this->equipos = new Equipo[2];
//this->equipos[0].setJugadorActivo(0);
	//this->equipos[1].setJugadorActivo(1);
}
// mejorar , esta harcodeado la asignación

void Model::set_Equipos(){
// this->equipos[0].agregar_Jugador(0,jugadores[0]);
	//cout<<"se agrego el jugador: "<< jugadores[0].get_nombre()<<endl;
	//this->equipos[1].agregar_Jugador(0,jugadores[1]);
	//cout<<"se agrego el jugador: "<< jugadores[1].get_nombre()<<endl;
	//no se que hace lo siguiente revisar
	this->equipos[0].setJugadorActivo(0);
	this->equipos[1].setJugadorActivo(1);

}
std::string Model::get_pathImagenJugador( int indice_jugador){

return jugadores[indice_jugador].get_path();

}
std::string Model::GetPathFondoParallax(int zIndex){
	return fondos[zIndex];
}
void Model::CargarFondos(std::map<int, std::map<std::string, std::string> > &mapFondoPantalla){
	for (map <int, map<string, string>>::iterator it = mapFondoPantalla.begin(); it != mapFondoPantalla.end(); ++it){
							map<string, string> &internal_map = it->second;
							fondos[std::stoi(internal_map["zIndex"])] =  internal_map["rutaArchivoImagen"];
	}
}
void Model::cargar_Jugadores (std::map< int, std::map<std::string, std::string> > &mapPersonajes){

int ancho, alto, zindex;
std::string nombre, path;

	for (map <int, map<string, string>>::iterator it = mapPersonajes.begin(); it != mapPersonajes.end(); ++it){

		   map<string, string> &internal_map = it->second;
		   cout<< "id: "<<it->first<<endl;
		  ancho=atoi((internal_map["ancho"]).c_str()); //
		   cout<< "ancho: "<<internal_map["ancho"]<<endl;
		   alto=atoi((internal_map["alto"]).c_str());
		   zindex=atoi((internal_map["zindex"]).c_str());

		   nombre=internal_map["nombre"];
		   path=internal_map["rutaArchivoImagen"];


	Jugador jugador(ancho,alto,zindex,nombre,path);

		jugadores[it->first]=std::move(jugador);

	}
		Logger::Log(LOGGER_NIVEL::INFO, "Model::CargaJugadores", "Carga iniciada");
		for (map <int, Jugador>::iterator it =this->jugadores.begin(); it != jugadores.end(); ++it){
		    Logger::Log(LOGGER_NIVEL::INFO, "Model::CargaJugadores", "id: " + it->first );
		    Logger::Log(LOGGER_NIVEL::INFO, "Model::CargaJugadores", "Nombre: " + it->second.get_nombre());
		    Logger::Log(LOGGER_NIVEL::INFO, "Model::CargaJugadores", "Alto: " + it->second.get_alto());
		    Logger::Log(LOGGER_NIVEL::INFO, "Model::CargaJugadores", "Ancho: " + it->second.get_ancho());
		    Logger::Log(LOGGER_NIVEL::INFO, "Model::CargaJugadores", "zindex: " + it->second.get_zindex());
		    Logger::Log(LOGGER_NIVEL::INFO, "Model::CargaJugadores", "Path: " + it->second.get_path());
		}
		Logger::Log(LOGGER_NIVEL::INFO, "Model::CargaJugadores", "Fin de carga");
}

Model::~Model() {
	delete[] this->equipos;
}

void Model::update() {
	for (int i = 0; i < 2; ++i) {
		this->equipos[i].update(i);
	}
	this->moverJuego();
}


void Model::moverJuego() {

	for (int i = 0; i < CANTJUGADORESTOTALES; ++i) {
		this->equipos[i].move();
	}
}

void Model::setCamara(SDL_Rect * camara) {
	this->camara = camara;
}

Equipo* Model::getEquipoNro(int i) {
	return &(this->equipos[i]);
}


