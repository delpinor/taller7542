/*
 * Configuracion.h
 *
 *  Created on: Apr 4, 2019
 *      Author: jorge
 */

#ifndef CONFIGURACION_H_
#define CONFIGURACION_H_

#include "ParserConfig.h"

class Configuracion {


private:
	std::map< int, std::map<std::string, std::string> > mapPersonajes;
	std::map<int, std::map<std::string, std::string> > mapFondoPantalla;
	std::map<std::string, std::string>  mapNivel;
	string nivelLog;
	int anchoVentana, altoVentana;

public:
	Configuracion(char* filepath);
	std::map< int, std::map<std::string, std::string> > get_Config_Personajes();
	std::map< int, std::map<std::string, std::string> > get_Config_FondosPantalla();
	std::map<std::string, std::string> get_Config_Nivel();
	std::string get_Config_NivelLog();
	int get_Config_AnchoVentana();
	int get_Config_AltoVentana();
	virtual ~Configuracion();
};

#endif /* CONFIGURACION_H_ */
