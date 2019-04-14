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
#include <sstream>
#include <jsoncpp/json/json.h>
#include <map>
#include "Exception.h"
using namespace std;
#define OK 0
#define ERRORMSG -1
#define archivo_default "default.json"
class ParserConfig {



private:

	 Json::Value configuracion;

public:

	/* constructor que toma como parametro el filepath del archivo configuracion*/

	ParserConfig();
	void parsear_archivo(char* filepath);
	Json::Value* getConfiguracion();
	void devolver_Map_Personajes(std::map<int, std::map<std::string, std::string> > *mapPersonajes);
	void devolver_Map_Fondo(std::map<int, std::map<std::string, std::string> > *mapBackground);
	std::string devolver_Tipo_Log();
	void devolver_Tam_Imagen(std::string *ancho, std::string *alto);
	void devolver_Map_Nivel(std::map<std::string, std::string> *mapNivel);

	virtual ~ParserConfig();





};

#endif /* PARSERCONFIG_H_ */
