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

#define CANTJUGADORESTOTALES 2
#define LOCALES 1

Model::Model() {

	this->equipos = new Equipo[2];
}
// mejorar , esta harcodeado la asignación

void Model::set_equipos_with_jugador(int nroEquipo, int nroJugadorEquipo, int nroJugador){
// this->equipos[0].agregar_Jugador(0,jugadores[0]);
	//cout<<"se agrego el jugador: "<< jugadores[0].get_nombre()<<endl;
	//this->equipos[1].agregar_Jugador(0,jugadores[1]);
	//cout<<"se agrego el jugador: "<< jugadores[1].get_nombre()<<endl;
	//no se que hace lo siguiente revisar
	this->equipos[nroEquipo].agregar_Jugador(nroJugadorEquipo, jugadoresEquipo1[nroJugador]);


//	this->equipos[0]->setJugadorActivo(0);
//	this->equipos[1]->setJugadorActivo(1);
}

void Model::inicializar(){
	for (int i = 0; i<2; i++){
		this->equipos[i].inicializar();
	}
}

std::string Model::get_pathImagenJugador(int equipo, int indice_jugador){
	return jugadoresEquipo1[indice_jugador]->get_path();
}


void Model::cargar_Jugadores (std::map< int, std::map<std::string, std::string> > &mapPersonajes){

int ancho, alto, zindex;
std::string nombre, path;
int i = 0;
	for (map <int, map<string, string>>::iterator it = mapPersonajes.begin(); it != mapPersonajes.end(); ++it){
		if (i >= 2)
			break;
		   map<string, string> &internal_map = it->second;
		   cout<< "id: "<<it->first<<endl;
		  ancho=atoi((internal_map["ancho"]).c_str()); //
		   cout<< "ancho: "<<internal_map["ancho"]<<endl;
		   alto=atoi((internal_map["alto"]).c_str());
		   zindex=atoi((internal_map["zindex"]).c_str());

		   nombre=internal_map["nombre"];
		   path=internal_map["rutaArchivoImagen"];


	//Jugador jugador(ancho,alto,zindex,nombre,path);

	jugadoresEquipo1.insert(std::make_pair(i, new Jugador(ancho,alto,zindex,nombre,path)));
	//jugadoresEquipo2.insert(std::pair<int, Jugador>(i, jugador));
//		jugadoresEquipo1[it->first]=std::move(jugador);
//		jugadoresEquipo2[it->first]=std::move(jugador);
	i++;
	}
//	cout << "mapa de personajes equipo1 ************" << endl;
//		for (map <int, Jugador>::iterator it =this->jugadoresEquipo1.begin(); it != jugadoresEquipo1.end(); ++it){
//		    cout << "id: " << it->first << endl;
//
//		    cout<< "Nombre: "<<it->second.get_nombre()<<endl;
//		    cout<< "Alto: "<<it->second.get_alto()<<endl;
//		    cout<< "Ancho: "<<it->second.get_ancho()<<endl;
//		    cout<< "zindex: "<<it->second.get_zindex()<<endl;
//		    cout<< "Path: "<<it->second.get_path()<<endl;
//
//
//		    }
//	cout << "mapa de personajes equipo2************" << endl;
//		for (map <int, Jugador>::iterator it =this->jugadoresEquipo1.begin(); it != jugadoresEquipo1.end(); ++it){
//		    cout << "id: " << it->first << endl;
//			cout<< "Nombre: "<<it->second.get_nombre()<<endl;
//			cout<< "Alto: "<<it->second.get_alto()<<endl;
//		    cout<< "Ancho: "<<it->second.get_ancho()<<endl;
//		    cout<< "zindex: "<<it->second.get_zindex()<<endl;
//		    cout<< "Path: "<<it->second.get_path()<<endl;


//			}
//		Equipo equipo1(jugadoresEquipo1);
//		this->equipos[0] = &equipo1;
//		Equipo equipo2(jugadoresEquipo2);
//		this->equipos[1] = &equipo2;
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


