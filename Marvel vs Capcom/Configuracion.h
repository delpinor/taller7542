/*
 * Configuracion.h
 *
 *  Created on: Apr 4, 2019
 *      Author: jorge
 */

#ifndef CONFIGURACION_H_
#define CONFIGURACION_H_

#include <iostream>
#include "ParserConfig.h"
#include "Helper/StringHelper.h"
#include "Helper/VectorHelper.h"
#include "Helper/NumericHelper.h"
#include "Helper/FileHelper.h"
#include "Logger/Logger.h"


//---- VALORES DEFAULT DE CONFIGURACION----//
#define nivel_log_default "DEBUG"

#define ruta_archivo_default "default.json"

#define alto_ventana_default "600"
#define ancho_ventana_default "800"

#define nombre_personaje_default "default"
#define alto_personaje_default "200"
#define ancho_personaje_default "130"
#define ruta_imagen_personaje_default "Images/default.png"
#define zIndex_personaje_default "99"
#define cantidad_minima_personajes_default 4

#define ruta_imagen_fondoPantalla_default "Images/z1.png"
#define zIndex_fondoPantalla_default "1"

#define alto_nivel_default "12"
#define ancho_nivel_default "13"
#define MAXIMO_JUGADORES 4
#define NUM_JUGADORES_DEFAUT 2

#define batalla_cantidad_default "3"
#define batalla_tiempo_default "99"

//----------------------------------------//

class Configuracion {


private:
	std::map< int, std::map<std::string, std::string> > mapPersonajes;
	std::map<int, std::map<std::string, std::string> > mapFondoPantalla;
	std::map<std::string, std::string>  mapNivel;
	std::string nivelLog;
	std::string anchoVentana, altoVentana;
	int num_jugadores;
	std::vector<string> nombresPersonajes;
	std::map<std::string, std::string>  mapBatalla;
	void ValidarConfigs(std::vector<string> *nombresPersonajes);

public:
	Configuracion(char* filepath);
	std::map< int, std::map<std::string, std::string> > get_Config_Personajes();
	std::map< int, std::map<std::string, std::string> > get_Config_FondosPantalla();
	std::map<std::string, std::string> get_Config_Nivel();
	LOGGER_NIVEL get_Config_NivelLog();
	int get_Config_AnchoVentana();
	int get_Config_AltoVentana();
	int get_NumJugadores();
	std::map<std::string, std::string> get_Config_Batalla();
	virtual ~Configuracion();
};

#endif /* CONFIGURACION_H_ */
