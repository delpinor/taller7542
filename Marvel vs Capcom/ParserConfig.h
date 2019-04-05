/*
 * ParserConfig.h
 *
 *  Created on: Mar 31, 2019
 *      Author: jorge
 */

#ifndef PARSERCONFIG_H_
#define PARSERCONFIG_H_

#include <iostream>
#include <string>
#include <fstream>
#include <jsoncpp/json/json.h>
#include <map>
#include "Exception.h"
using namespace std;
#define Log_Default  "DEBUG"
#define OK 0
#define ERROR -1
#define archivo_default "default.json"
class ParserConfig {



private:

	 Json::Value configuracion;

public:

	/* constructor que toma como parametro el filepath del archivo configuracion*/

	ParserConfig();
	int parsear_archivo(char* filepath);
	Json::Value* getConfiguracion();
	int devolver_Map_Personajes(std::map<int, std::map<std::string, std::string> > *mapPersonajes);
	int devolver_Map_Fondo(std::map<int, std::map<std::string, std::string> > *mapBackground);
	string devolver_Tipo_Log();
	int devolver_Tam_Imagen(int *ancho, int *alto);
	int devolver_Map_Nivel(std::map<std::string, std::string> *mapNivel);

	virtual ~ParserConfig();





};

#endif /* PARSERCONFIG_H_ */
