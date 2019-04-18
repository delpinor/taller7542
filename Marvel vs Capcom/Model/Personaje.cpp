/*
 * Personaje.cpp
 *
 *  Created on: Apr 4, 2019
 *      Author: jorge
 */

#include "Personaje.h"

Personaje::Personaje(std::string nom, std::map<std::string, std::string>  *valores){
	this->nombre=nom;
	this->pathImagen=(*valores)["filepath"];
	this->height=std::stoi((*valores)["height"]);
	this->width=std::stoi((*valores)["filepath"]);
	this->zindex=std::stoi((*valores)["filepath"]);

}

Personaje::~Personaje() {
	// TODO Auto-generated destructor stub
}

