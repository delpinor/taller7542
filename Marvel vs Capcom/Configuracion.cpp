/*
 * Configuracion.cpp
 *
 *  Created on: Apr 4, 2019
 *      Author: jorge
 */

#include "Configuracion.h"

Configuracion::Configuracion(char* filepath) {
	int error;
	ParserConfig parser;

	parser.parsear_archivo(filepath);
	error = parser.devolver_Map_Personajes(&mapPersonajes);
	error = parser.devolver_Map_Fondo(&mapFondoPantalla);
	error = parser.devolver_Tam_Imagen(&anchoVentana,&altoVentana);
	error = parser.devolver_Map_Nivel(&mapNivel);
	nivelLog = parser.devolver_Tipo_Log();
}

std::map< int, std::map<std::string, std::string> > Configuracion::get_Config_Personajes(){
	return mapPersonajes;
}

std::map< int, std::map<std::string, std::string> > Configuracion::get_Config_FondosPantalla(){
	return mapFondoPantalla;
}

std::map<std::string, std::string> Configuracion::get_Config_Nivel(){
	return mapNivel;
}

std::string Configuracion::get_Config_NivelLog(){
	return nivelLog;
}

int Configuracion::get_Config_AnchoVentana(){
	return anchoVentana;
}

int Configuracion::get_Config_AltoVentana(){
	return altoVentana;
}

Configuracion::~Configuracion() {
	// TODO Auto-generated destructor stub
}

